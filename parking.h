#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    // 사용해야하는 변수
    char carName[20]; // 차량 이름
    int enterTime;    // 들어온 시간 4자리
    int enterTimeH;   // 들어온 시간
    int enterTimeM;   // 들어온 분
    int place;        // 주차되어있는 위치
    int row;          // 주차 되어있는 행
    int clomm;        // 주차 되어있는 열
    int pay;          // 지불할 금액
    int exitTimeH;    // 나가는 시간 요금 (평일,주말+공휴일)
    int exitTimeM;    //
    int total_pay;    // 총 계산해야할 요금
    int change;       // 거스름돈
    //-------------------------------
    // 아직 사용되지 않은 변수

    int weekend;  // 남은 자리 갯수
    int discount; // 할인 요금

} parking;

int addData(parking *s, parking *a, int count); // 데이터를 출력하는 함수
int fixData(parking *s, parking *a, int count); // 데이터를 수정하는 함수
void deleteData(parking* p,int count);//데이터 삭제하는 함수
void vacant(int count, parking *plist);
void payment(parking *plist);
void findMyCar(parking *p, int count);
void payNchange(parking *p, int count);
int selectData(parking *a, int count); // 리스트를 출력하고 + 사용자에게 데이터를 입력받고 수정하는 함수
void listData(parking *a, int count);  // 리스트를 출력하는 함수
void readData(parking a);              // 데이터를 읽어서 하나 출력하는 함수
void printMiddleDot();
void printEmpty();
void printMiddle(int a, int b, parking *plist, int count);
void printParkinglot(parking *a, int count);
int readFile(parking *plist);
void saveFile(parking *p, int count);

