#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void mstrcpy(char* from, char* to) {
	int idx = 0;

	while (to[idx] = from[idx]) idx++;
}

int mstrcmp(char* str1, char* str2) {

	int idx = 0;

	while (str1[idx] != 0 && str1[idx] == str2[idx]) idx++;

	return str1[idx] - str2[idx];
}

char category[2][100] = { "The INSTALL_PERMISSION permission must not be held by", "Whitelisted packages are here :" };
char commingSentense[200];

int currentIndex;

int main() {

	while (1) {
		scanf("%[^\n]", commingSentense);
		printf("%s", commingSentense);

		printf("currentIndex : %d\n", currentIndex);

		if (currentIndex == 2) {
			puts("파일 생성되었으니 확인해보세요.");
			break;
		}
		// if both sentense are same, keep going
		if (!mstrcmp(category[currentIndex], commingSentense)) currentIndex++;
		
	}

	return 0;
}