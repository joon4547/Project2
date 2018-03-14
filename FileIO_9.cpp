#include <stdio.h>

int main(void)
{
	FILE * fp = fopen("some_data.txt", "r");
	char data[10];
	char c;

	if (fp == NULL)
	{
		printf("file open error ! \n");
		return 0;
	}

	//fp로부터 입력을 받는다. 이 때, 문자열 형태로 입력을 받는다.
	//왜 1을 뺀만큼 받냐면 data에문자열을 구성하기 위해 맨 뒤에는 언제나 NULL문자를 윟나 자리를 만들어줘야 해서 .
	fgets(data, 5, fp);
	printf("입력 받은 데이터 : %s\n", data);

	//그리고 e가 찍힌다음 포인터가 다음으로 이동.
	c = fgetc(fp);
	printf("그 다음에 입력 받은 문자 : %c\n ", c);


	//SEEK_CUR : 현재 파일 위치 지정자의 위치를 나타냄
	//두번째 인자로 -1을 전달했으니까 왼쪽으로 1만큼 이동. 
	fseek(fp, -1, SEEK_CUR);

	c = fgetc(fp);
	printf("그렇다면 무슨 문자가? : %c \n", c);

	fclose(fp);
}