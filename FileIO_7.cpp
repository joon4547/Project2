#include <stdio.h>

/*파일에 문자를 하나씩 입력받는다*/
int main(void)
{
	FILE * fp = fopen("some_data.txt", "r");
	char c;

	if (fp == NULL)
	{
		printf("file open error ! \n");
		return 0;
	}

	while ((c = fgetc(fp)) != EOF)
	{
		printf("%c", c);
	}
}