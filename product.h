#ifndef PRODUCT_STR
#define PRODUCT_STR
typedef struct{
    char pname[30];  //제품 이름
    float weight;    //제품의 중량. kg으로 표현하기 위해 float로 설정
    int price;       //제품의 판매가격
    int srate;     //제품의 별점 평균 (1~5까지의 숫자)
    int nsrate;      //제품에 별점을 준 사람의 수
}Product;
#endif

int addProduct(Product *p);  //제품을 추가하는 함수
void readProduct(Product p);  //제품을 하나 출력하는 함수
int updateProduct(Product *p); // 등록된 제품 중 선택한 제품 하나의 정보를 업데이트 하는 함수
int deleteProduct(Product *p); // 등록된 제품 중 선택한 제품 하나를 삭제하는 함수
int loadProduct(Product *p[]);  // 파일에 저장된 제품 정보를 불러오는 함수 
void saveProduct(Product *p[],int count);  // 제품 정보를 파일에 저장하는 함수
void nameSearch(Product *p[],int count);   // 제품 이름으로 검색하여 제품을 찾는 함수
void srateSearch(Product *p,int count);  // 별점으로 검색하여 제품을 찾는 함수
void priceSearch(Product *p,int count);  // 가격으로 검색하여 제품을 찾는 함수
