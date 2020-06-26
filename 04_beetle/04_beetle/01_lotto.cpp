#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>   
#include <time.h>

int flag[46] = { 0 };

int main() {
	srand(time(NULL));

	for (int i = 0; i < 6; ) {		/// 증감식이 여기 없는 이유 설명하시오
									/*
									    아래 조건문의 continue가 처리되면
									    블럭의 끝으로 가고 for 문의 증감식을
										수행하므로 중복인 경우에도 i가
										증가하여 6개의 숫자가 모두 출력되지
										않을 수 있다.
									*/
		int random = rand() % 44 + 1;
		if (flag[random])
			continue;
		printf("%d \n", rand() % 44 + 1);
		flag[random] = 1;
		i++;						/// 증감식이 여기 있는 이유 설명하시오
									/*
										위의 조건문이 실행되지 않았을 경우
										증감식을 실행하여 6개의 숫자가 출력될
										때까지 반복해야 하므로 증감식을
										그 아래에 넣어 처리한다.
									*/
	}
}