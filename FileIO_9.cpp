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

	//fp�κ��� �Է��� �޴´�. �� ��, ���ڿ� ���·� �Է��� �޴´�.
	//�� 1�� ����ŭ �޳ĸ� data�����ڿ��� �����ϱ� ���� �� �ڿ��� ������ NULL���ڸ� ���� �ڸ��� �������� �ؼ� .
	fgets(data, 5, fp);
	printf("�Է� ���� ������ : %s\n", data);

	//�׸��� e�� �������� �����Ͱ� �������� �̵�.
	c = fgetc(fp);
	printf("�� ������ �Է� ���� ���� : %c\n ", c);


	//SEEK_CUR : ���� ���� ��ġ �������� ��ġ�� ��Ÿ��
	//�ι�° ���ڷ� -1�� ���������ϱ� �������� 1��ŭ �̵�. 
	fseek(fp, -1, SEEK_CUR);

	c = fgetc(fp);
	printf("�׷��ٸ� ���� ���ڰ�? : %c \n", c);

	fclose(fp);
}