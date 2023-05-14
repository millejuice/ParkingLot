#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
char carName[20]; // 차량 이름
int enterTimeH; // 들어온 시간
int enterTimeM; // 들어온 분
int hollyday; // 주말인지 아닌지 확인하는 방법
int pay; // 할인받기 전 요금
int discount; // 할인 요금
int change; // 거스름돈
int total_pay; // 총 계산해야할 요금

int exitTimeH;// 나가는 시간 요금 (평일,주말+공휴일)
int exitTimeM;
int row; // 주차 되어있는 행
int clomm; // 주차 되어있는 열
} parking;

//CRUD--------------------------------------
void addData(); //데이터 추가 함수
void readData();// 주차된 차들 리스트로 보는 함수
void fixeData();//데이터 수정 함수
void deleteData(); //데이터 삭제 함수
//---------------------------------------
void printMenu();
bool isWeekend();//주말인지 판단하는 함수
int vacant();//남은자리갯수 return하는 함수

int main(){
        while(1){
        int menu = printMenu();
        if(menu==1){

        }
        if(menu==2){

        }
        if(menu==3){

        }
        if(menu==0)break;

        }
        return 0;
}




int printMenu(){
int result;
printf("--------------주차 관리 시스템----------------\n");
printf("-                                           -\n");
printf("--------------메뉴를 선택하세요--------------\n ");
printf("1. 데이터 추가");
printf("2. 데이터 변경");
printf("3. 데이터 출력");//list형식
printf("4. 데이터 삭제");
printf("5. 요금 정산하기");
printf("6. 남은 자리 확인하기");
printf("7. 내 자동차 찾기");
printf("0. 종료");
scanf("%d",result);

return result;
}


