#include <stdio.h>

/*������ ������ ���ڸ� ����*/
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
	
	//���� ������ EOF�� ����������� �� �����ִ� ! �� ����ϱ����� -1 �� ���־���.
	fseek(fp, -1, SEEK_END);
	c = fgetc(fp);
	printf("���� ������ ���� : %c\n", c);

	fclose(fp);
}