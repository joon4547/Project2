#include <stdio.h>

/*���Ͽ� ���ڸ� �ϳ��� �Է¹޴´�*/
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