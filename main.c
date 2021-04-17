#include <stdio.h>
#include <stdlib.h>
#include "manager.h" //product.h의 내용은 manager.h 내에 포함되어 있음
#define SIZE 20

int main(){
	#ifdef DEBUG
		printf("DEBUGMODE: %s %s %s %d\n", __DATE__, __TIME__, __FILE__, __LINE__);
	#endif
	Product *fruit[SIZE];
	int menu;
	int index = 0,count = 0;
	index=count=loadProduct(fruit);
	while(1){
	menu = selectMenu();
        if(menu==0) break;
        if(menu==1||menu==3||menu==4){
            if(count==0)
                continue;
        }
        if(menu==1){
            listProduct(fruit,index);
        }else if(menu==2){
	    fruit[index]=(Product *)malloc(sizeof(Product));
            count+=addProduct(fruit[index++]);
        }else if(menu==3){
	    int no;
	    no = selectDataNo(fruit,index);
	    if(no>0)
           	 updateProduct(fruit[no-1]);
	    else
		 printf("Canceled!\n");
        }else if(menu==4){
	    int no = selectDataNo(fruit,index);
	    if(no>0){
		    int delok;
		    printf("정말로 삭제하시겠습니까?(삭제:1) ");
		    scanf("%d",&delok);
		    if(delok==1){
           		 deleteProduct(fruit[no-1]);
               		 count--;
       		    }
            }
	}else if(menu==5){
		saveProduct(fruit,index);
	}
	}
    printf("종료됨!\n");
    return 0;
}


