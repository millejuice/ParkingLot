#include "menu.h"

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

