#include "menu.h"
#include "parking.h"

int main()
{
    parking plist[20]; // 구조체 배열 20개 선언
    int count = readFile(plist);     // 총 몇개가 있는지 index번호
    int index = count;     // 배열의 인덱스 번호가 몇번인지
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
            deleteData(plist,count);
        }
        if (menu == 5) // 요금 정산하기
        {
            payment(&plist[index]);
        }

        if (menu == 6) // 남은 자리 함수 구하기
        {
          printParkinglot(plist, count);

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
	if (menu == 9)
        {
            saveFile(plist, count);
        }
        if (menu == 0) // 종료
            break;
    }
    return 0;
}
