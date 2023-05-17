#include <stdio.h>
void printMiddleDot();
void printEmpty();
void printMiddle(int a, int b);

void printParkinglot();

int main()
{
    printParkinglot();
    return 0;
}
void printParkinglot()
{
    // 윗 천장
    printf("-------------------------------------< 매   장   입   구  >-------------------------------------------\n");
    // 위 2칸 입구 그리기
    printf("|                                                                                         <--      입\n");
    printf("|                                                                                         <--      구\n");
    // 중간 테두리
    for (int i = 1; i <= 2; i++)
    {
        printEmpty();
        for (int j = 1; j <= 2; j++)
        {

            printMiddleDot();
            printMiddle(i, j);
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

void printMiddle(int a, int b)
{
    for (int i = 0; i < 1; i++)
    {
        printf("|");
        // 처음 공백 10칸
        for (int j = 0; j < 10; j++)
        {
            printf(" ");
        }

        for (int j = 0; j < 5; j++)
        {
            printf("|%13d번", 100); // 숫자와 내용 출력하는 부분 중요 !!
        }
        printf("|");
        for (int j = 0; j < 7; j++)
        {
            printf(" ");
        }
        printf("|\n");
    }
}
