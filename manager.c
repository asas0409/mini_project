#include <stdio.h>
#include "manager.h"



int selectMenu(){
	int menu;
	printf("\n****Select Menu****\n");
	printf("1.상품조회\n");
	printf("2.상품추가\n");
	printf("3.상품정보수정\n");
	printf("4.상품삭제\n");
	printf("5.저장\n");
	printf("6.이름으로 검색\n");
	printf("7.별점으로 검색\n");
	printf("8.가격으로 검색\n");
	printf("0.종료\n");
	printf("=>원하는 메뉴는? ");
	scanf("%d",&menu);
	getchar();
	return menu;	
}

void listProduct(Product *fruit[],int count){
	for(int i=0; i<count; i++){
		if(fruit[i]->price == -1) continue;	
		printf("\n%d번 상품\n",i+1);
		readProduct(*fruit[i]);
	}	
}

int selectDataNo(Product *fruit[],int count){
	int no;
	listProduct(fruit,count);
	printf("select Data Number(Cancel :0)? ");
      	scanf("%d", &no);
	getchar();
	return no;
}	
