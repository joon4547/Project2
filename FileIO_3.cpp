#include <stdio.h>


/*�� ���ھ� �Է¹ޱ�*/
int main(void)
{
	FILE * fp = fopen("a.txt", "r");
	char c;

	//fgetc�� fp���� ���� �ϳ��� ���´�.
	//��, �� ���ھ� �о���̴� ��.
	//������ ���������� EOF��� End Of File�� ��Ÿ���� ���� -1�� ����ִ�.
	while ((c = fgetc(fp)) != EOF)
	{
		printf("%c", c);
	}

	fclose(fp);
	return 0;
}