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

int printMenu();                                // 메뉴를 출력하는 함수
int addData(parking *s, parking *a, int count); // 데이터를 출력하는 함수
int fixData(parking *s, parking *a, int count); // 데이터를 수정하는 함수
void vacant(int count, parking *plist);
void payment(parking *plist,int count);
void findMyCar(parking *p, int count);
void payNchange(parking *p, int count);
int selectData(parking *a, int count); // 리스트를 출력하고 + 사용자에게 데이터를 입력받고 수정하는 함수
void listData(parking *a, int count);  // 리스트를 출력하는 함수
void readData(parking a);              // 데이터를 읽어서 하나 출력하는 함수
void printMiddleDot();
void printEmpty();
void printMiddle(int a, int b, parking *plist, int count);
void printParkinglot(parking *a, int count);

int main()
{
    parking plist[20]; // 구조체 배열 20개 선언
    int count = 0;     // 총 몇개가 있는지 index번호
    int index = 0;     // 배열의 인덱스 번호가 몇번인지
    while (1)
    {
        int menu = printMenu();
        if (menu == 1) // 데이터 추가하기
        {
            count += addData(&plist[index++], plist, count);
        }
        if (menu == 2) // 데이터 수정하기
        {
            int no = selectData(plist, count);
            fixData(&plist[no - 1], plist, count);
        }
        if (menu == 3) // 리스트를 출력하는 함수
        {
            listData(plist, count);
        }
        if (menu == 4)
        { // 데이터 삭제하기
        }
        if (menu == 5) // 요금 정산하기
        {
            payment(plist,count);
        }

        if (menu == 6) // 남은 자리 함수 구하기
        {
            vacant(count, plist);
        }

        if (menu == 7) // 내 자동차 어딨는지 구하는 함수
        {
            printParkinglot(plist, count);
            findMyCar(plist, count);
        }

        if (menu == 8) // 지불 금액, 거스름돈 구하는 함수
        {
            payNchange(plist, count);
        }

        if (menu == 0) // 종료
            break;
    }
    return 0;
}

int addData(parking *p, parking *a, int count)
{ // *p는 저장할 위치, *a는 리스트의 처음 위치, count는 현재 몇개가 저장되어있는이 위치
   // int T = 0;
    printf("차량번호를 입력하세요\n");
    scanf("%s", p->carName);
    printf("들어온 시간을 입력하세요. ex) 0900\n");
    scanf("%d", &(p->enterTime));
    p->enterTimeH = (p->enterTime) / 100; // 앞의 두자리 시간 = (s->enterTime)%100;
    p->enterTimeM = (p->enterTime) % 100; // 뒤의 두자리 분= (s->enterTime)/10;
    p->pay = 0;
    while (1)
    {
        int T = 0; // while문 break 판단 변수
        // 주차 자리 번호 입력------------------------
        printf("주차하실 자리 번호를 선택하세요 ex) 1~20 \n");
        scanf("%d", &(p->place));
        for (int i = 0; i < count; i++)
        {
            if (p->place == a[i].place)
            {
                printf("다른 차가 주차되어 있습니다. 다른 자리를 입력해 주세요\n");
                T = 1;
                break;
            }
        }
        if (T == 0)
            break;
    }
    printf("자리 배정이 완료 되었습니다.\n");
    p->clomm = (p->place - 1) % 5; // 열위치
    p->row = (p->place - 1) / 5;   // 행위치

    return 1;
}

int fixData(parking *p, parking *a, int count)
{ // *p는 저장할 위치, *a는 리스트의 처음 위치, count는 현재 몇개가 저장되어있는이 위치
    int T = 0;
    printf("차량번호를 입력하세요\n");
    scanf("%s", p->carName);
    printf("들어온 시간을 입력하세요. ex) 0900\n");
    scanf("%d", &(p->enterTime));
    p->enterTimeH = (p->enterTime) / 100; // 앞의 두자리 시간 = (s->enterTime)%100;
    p->enterTimeM = (p->enterTime) % 100; // 뒤의 두자리 분= (s->enterTime)/10;
    p->pay = 0;
    while (1)
    {
        int T = 0; // while문 break 판단 변수
        // 주차 자리 번호 입력------------------------
        printf("주차하실 자리 번호를 선택하세요 ex) 1~20 \n");
        scanf("%d", &(p->place));
        for (int i = 0; i < count; i++)
        {
            if (p->place == a[i].place)
            {
                printf("다른 차가 주차되어 있습니다. 다른 자리를 입력해 주세요\n");
                T = 1;
                break;
            }
        }
        if (T == 0)
            break;
    }
    printf("자리 배정이 완료 되었습니다.\n");
    p->clomm = (p->place - 1) % 5; // 열위치
    p->row = (p->place - 1) / 5;   // 행위치

    return 1;
}

int printMenu()
{
    int result;
    printf("--------------주차 관리 시스템---------------\n");
    printf("|                                           |\n");
    printf("--------------메뉴를 선택하세요--------------\n");
    printf("|   1. 데이터 추가                          |\n");
    printf("|   2. 데이터 변경                          |\n");
    printf("|   3. 데이터 출력                          |\n"); // list형식
    printf("|   4. 데이터 삭제                          |\n");
    printf("|   5. 요금 정산하기                        |\n");
    printf("|   6. 남은 자리 확인하기                   |\n");
    printf("|   7. 내 자동차 찾기                       |\n");
    printf("|   8. 지불할 금액 & 거스름돈               |\n");
    printf("|   0. 종료                                 |\n");
    printf("---------------------------------------------\n");

    scanf("%d", &result);

    return result;
}

int printCharge(parking *p)
{
    printf("지불해야 할 금액: %d\n", p->total_pay);
    return 0;
}

void payment(parking *plist,int c)
{
    int num;
    printf("주차된 위치를 알려주세요: ");
    scanf("%d", &num);
    int ob;

    for(int i=0;i<c;i++)
    {
        if(plist[i].place == num)
        {
            printf("찾았습니다!\n");
            ob=i;
        }
        else{
            printf("차량이 없습니다\n");
        }
    }
    int et=0;
    int em=0;
    int hour = 0; // 머무른 시간
    int min = 0;  // 분
    printf("시간당 2000원, 30분 단위로 1500원\n");
    // 1시간 23분 머물렀으면 3500원
    printf("나가는 시간을 입력하세요(ex0900): ");
    scanf(" %d", &et);
    em=et;

    plist[ob].exitTimeH = et/100;
    plist[ob].exitTimeM = em%100;

    hour = plist[ob].exitTimeH - plist[ob].enterTimeH;
    min = plist[ob].exitTimeM - plist[ob].enterTimeM;

    if (min <= 30)
        min = 1;
    else if (min > 30)
        min = 2;

    plist[ob].total_pay = hour * 2000 + min * 1500;
    printf("지불해야 할 금액: %d\n", plist[ob].total_pay);
}

void vacant(int count, parking *plist)
{
    int left = 20 - count;
    printf("남은 자리 갯수: %d\n", count);
    printf("사용할 수 없는 자리들:");
    for (int i = 0; i < count; i++)
    {
        printf(" %d", plist[i].place);
    }
    printf("\n");
}

void findMyCar(parking *p, int count)
{
    char targetCar[20];

    printf("차량번호를 입력하세요:\n");
    scanf("%s", targetCar);

    for (int i = 0; i < count; i++)
    {
        if (strcmp(targetCar, p[i].carName) == 0) // 입력한 차번호가 동일하면
        {
            printf("차가 %d에 주차되어 있습니다!\n", p[i].place);
        }
        else // 차번호가 동일하지 않으면
        {
            printf("등록된 차가 없습니다!!\n");
        }
    }
}

void payNchange(parking *p, int count)
{
    char targetCar[20];

    printf("차량번호를 입력하세요:\n");
    scanf("%s", targetCar);

    for (int i = 0; i < count; i++)
    {
        if (strcmp(targetCar, p[i].carName) == 0)
        {
            printCharge(&p[i]);
            // 거스름돈 계산 등의 추가 로직을 구현할 수 있습니다.

            printf("얼마를 지불하겠습니까? \n");
            scanf("%d", &p[i].pay);

            p[i].change = p[i].pay - p[i].total_pay;

            printf("거스름돈은 %d입니다.\n", p[i].change);
            break;
        }
    }
}
void listData(parking *a, int count)
{
    printf("등록되어 있는 데이터의 리스트\n\n");
    printf("  차량번호   주차한 시간  주차된 위치   \n");
    printf("------------------------------------------------\n");
    for (int i = 0; i < count; i++)
    {
        if (a[i].place == -1)
            continue;
        printf("%2d", i + 1);
        readData(a[i]);
    }
    printf("\n");
}
void readData(parking a)
{
    // 읽어오는 함수 구현해야한다
    printf("%9s      %02d : %02d    %d\n", a.carName, a.enterTimeH, a.enterTimeM, a.place);
}

int selectData(parking *a, int count) // list를 출력하고 사용자에게 입력 받는 + 함수
{
    int no;
    listData(a, count);
    printf("원하는 번호를 입력해 주세요!");
    scanf("%d", &no);
    return no;
}

void printParkinglot(parking *a, int count)
{
    // 윗 천장
    printf("-------------------------------------< 매   장   입   구  >-------------------------------------------\n");
    // 위 2칸 입구 그리기
    printf("|                                                                                         <--      입\n");
    printf("|                                                                                         <--      구\n");
    // 중간 테두리
    int i = 0;
    int j = 0;
    int number = 1;
    for (i = 0; i < 2; i++)
    {
        printEmpty();
        for (j = 0; j < 2; j++)
        {
            printMiddleDot();
            printMiddle(number, number + 4, a, count);
            number += 5;
        }
        printMiddleDot();
    }

    // 아래 출구
    printf("|                                                                                         -->      출\n");
    printf("|                                                                                         -->      구\n");
    printf("----------------------------------------------------------------------------------------------------\n");
}
void printMiddleDot()
{
    for (int i = 0; i < 1; i++)
    {
        printf("|");
        // 처음 공백 10칸
        for (int j = 0; j < 10; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < 80; j++)
        {
            printf("-");
        }
        for (int j = 0; j < 8; j++)
        {
            printf(" ");
        }
        printf("|\n");
    }
}

void printEmpty()
{
    for (int i = 0; i < 1; i++)
    {
        printf("|");
        for (int j = 0; j < 98; j++)
        {
            printf(" ");
        }
        printf("|\n");
    }
}

void printMiddle(int a, int b, parking *plist, int count)
{
    for (int i = 0; i < 1; i++)
    {
        printf("|");
        // 처음 공백 10칸
        for (int j = 0; j < 10; j++)
        {
            printf(" ");
        }

        for (int j = a; j <= b; j++)
        {
            int term = 0;
            printf("|%-2d번 ", j); // 숫자와 내용 출력하는 부분 중요 !!

            for (int k = 0; k < count; k++)
            {
                if (plist[k].place == -1)
                    continue;
                if (plist[k].place == j)
                {
                    term = 1;
                }
            }
            if (term == 1)
            {
                printf("%10s", "자리 없음");
            }
            else if (term == 0)
            {
                printf("%10s", "주차 가능");
            }
        }
        printf("|");
        for (int j = 0; j < 7; j++)
        {
            printf(" ");
        }
        printf("|\n");
    }
}
