#include <stdio.h>
#include <windows.h>

void textcolor(int color_number) //콘솔창 출력색상을 나타내는 함수
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}

int main() {

    int helper;

    system("mode con cols=37 lines=24");
    //cols = 칸/행 (가로)  lines = 줄/열 (세로)
    //숫자만 바꾸어주면 원하는 크기로 조절할 수 있습니다.

    system("cls");   // 콘 솔창 전체 내용 지우기

    SetConsoleTitle((LPCWSTR)L"문자열테스트"); // 콘솔창 타이틀 변경

    for (helper = 0; helper <= 15; helper++) {
        textcolor(helper);
        printf("%2d번 색상 출력\n", helper);
    }
    //15번까지 for문을 돌려 모든 색상을 출력하고 있습니다 
}
