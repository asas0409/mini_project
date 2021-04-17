#include <stdio.h>
#include "product.h"

int addProduct(Product *p){
	printf("상품명은? ");
       	scanf("%[^\n]",p->pname);
       	printf("중량은? ");
       	scanf("%f", &(p->weight));
       	printf("가격은? ");
       	scanf("%d",&(p->price));
	p->srate = 0; //상품이 새로 추가되었을 때에 별점은 0으로 생각
	p->nsrate = 0; //상품이 새로 추가되었을 때에 별점을 준 사람은 0명으로 생각
       	return 1;	
}	
void readProduct(Product p){
	printf("상품명: %s\n",p.pname);
	printf("중량: %.2fkg\n",p.weight);
	printf("가격: %d원\n",p.price);
	printf("별점: %d\n",p.srate);
	printf("별점을 준 사람수: %d명\n",p.nsrate);
}	

int updateProduct(Product *p){
	printf("새 상품명은? ");
       	scanf("%[^\n]",p->pname);
       	printf("새 중량은? ");
       	scanf("%f", &(p->weight));
       	printf("새 가격은? ");
       	scanf("%d",&(p->price));
	p->srate = 0;  //상품의 이름, 가격, 중량을 바꾸면 그것은 이전과는 다른 새로운 상품이기 때문에 별점을 다시 0으로 주었습니다. 
	p->nsrate = 0;  //별점을 준 사람 수 역시 위와 같은 이유로 0명으로 주었습니다.   추후에 다른 기능들을 추가할 때  별점만 따로 부여하는 함수를 하나 더 만들 계획입니다.
	printf("=>수정성공!\n");
	return 1;
}	
int deleteProduct(Product *p){
	p->price = -1;
	printf("=>삭제됨!\n");
	return 1;
}


