#include <stdio.h>
#include <windows.h>

void textcolor(int color_number) //�ܼ�â ��»����� ��Ÿ���� �Լ�
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}

int main() {

    int helper;

    system("mode con cols=37 lines=24");
    //cols = ĭ/�� (����)  lines = ��/�� (����)
    //���ڸ� �ٲپ��ָ� ���ϴ� ũ��� ������ �� �ֽ��ϴ�.

    system("cls");   // �� ��â ��ü ���� �����

    SetConsoleTitle((LPCWSTR)L"���ڿ��׽�Ʈ"); // �ܼ�â Ÿ��Ʋ ����

    for (helper = 0; helper <= 15; helper++) {
        textcolor(helper);
        printf("%2d�� ���� ���\n", helper);
    }
    //15������ for���� ���� ��� ������ ����ϰ� �ֽ��ϴ� 
}
