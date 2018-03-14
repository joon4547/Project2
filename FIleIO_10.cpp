#include <stdio.h>

/*파일의 마지막 문자를 보기*/
int main(void)
{
	FILE *fp = fopen("some_data.txt", "r");
	char data[10];
	char c;

	if (fp == NULL)
	{
		printf("file open error!\n");
		return 0;
	}
	
	//제일 끝에는 EOF이 들어있음으로 그 옆에있는 ! 를 출력하기위해 -1 을 해주엇다.
	fseek(fp, -1, SEEK_END);
	c = fgetc(fp);
	printf("파일 마지막 문자 : %c\n", c);

	fclose(fp);
}