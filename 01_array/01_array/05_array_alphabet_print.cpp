#include <stdio.h>

int main() {
	char ch[26] = { 'A','B','C','D','E','F','G','H','I',
	'J','K','L','M','N','O','P','Q','R',
	'S','T','U','V','W','X','Y','Z' };


	for (int j = 0; j < 26; j++) {
		for (int i = 0; i < 26; i++) {
			printf("%c", ch[(i + j) % 26]);
		}
		printf("\n");
	}
}