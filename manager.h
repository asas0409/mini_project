#include "product.h" //Product구조체와 listProduct 함수에 필요한 readProduct 함수를 사용하기 위함.

int selectMenu();    //실행가능할 메뉴를 보여주고 그 중 실행할 메뉴를 선택하는 함수
void listProduct(Product *fruit[],int count);  //모든 상품을 보여주는 함수
int selectDataNo(Product *fruit[],int count);  //여러 개의 데이터 중 몇번째 데이터를 선택했는지 그 수를 반환해주는 함수
