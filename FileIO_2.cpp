#include <stdio.h>

/*fgets�� a.txt���� ������ �Է� �޴´�.*/
int main(void)
{

	//"r" �б�����.
	FILE * fp = fopen("a.txt", "r");
	char buf[20]; 

	//������ ������ �� �߿���.
	if (fp == NULL)
	{
		printf("Read Error!!\n");
		return 0;
	}

	//fgets(��� �Է� ���� ��, �Է¹��� ����Ʈ ��, � ��Ʈ��);
	fgets(buf, 20, fp);
	
	printf("�Է� ���� ���� : %s \n", buf);

	fclose(fp);
	return 0;
}