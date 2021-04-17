#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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


int loadProduct(Product *p[]){
	FILE *fp;
	int i;
	fp = fopen("product.txt","rt");
	if(fp==NULL)
		printf("=>파일 없음\n");
	else{
		for(i=0;i<20;i++){
			p[i]=(Product *)malloc(sizeof(Product));
			fscanf(fp,"%[^\n]s",p[i]->pname);
			if(feof(fp))break;
			fscanf(fp,"%f",&(p[i]->weight));
			fscanf(fp,"%d",&(p[i]->price));
			fscanf(fp,"%d",&(p[i]->srate));
			fscanf(fp,"%d",&(p[i]->nsrate));
			fgetc(fp);
		}
		printf("=>로딩성공\n");
	}
	fclose(fp);
	return i;
}

void saveProduct(Product *p[],int count){
	FILE *fp;
	int i;
	fp = fopen("product.txt","wt");
	for(i=0;i<count;i++){
		if(p[i]->price==-1) continue;
		fprintf(fp,"%s\n",p[i]->pname);
		fprintf(fp,"%f\n",p[i]->weight);
		fprintf(fp,"%d\n",p[i]->price);
		fprintf(fp,"%d\n",p[i]->srate);
		fprintf(fp,"%d\n",p[i]->nsrate);
	}
	fclose(fp);
	printf("=>저장 성공\n");

}
void nameSearch(Product *p[],int count){
	char sn[30];
	int comp=0;
	printf("검색할 상품명 입력 : ");
	scanf("%[^\n]s",sn);
	for(int i=0;i<count;i++){
		if(p[i]->price==-1)continue;
		if(strstr(p[i]->pname,sn)){
			readProduct(*p[i]);
			comp++;
		}
	}
	if(comp==0)
		printf("=>없는 상품입니다.\n");

}

void srateSearch(Product *p[],int count){
	int star;
	int comp=0;
	printf("검색할 별점 입력 : ");
	scanf("%d",&star);
	for(int i=0;i<count;i++){
		if(p[i]->price==-1)continue;
		if(p[i]->srate==star){
			readProduct(*p[i]);
			comp++;
		}
	}
	if(comp==0)
		printf("=>없는 상품입니다.\n");

}
