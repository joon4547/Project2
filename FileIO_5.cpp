#include <stdio.h>

int main(void)
{
	FILE * fp = fopen("a.txt", "r");
	fgetc(fp);
	fgetc(fp);
	fgetc(fp);
	fgetc(fp);

	//fseek �Լ��� fp�� ����° ���ڷκ��� �ι�° ���� ��ŭ ������ ������ ���� ��ġ �����ڸ� ������.
	fseek(fp, 0, SEEK_SET);
	printf("�ٽ� ���� ó������ �Է� �޴´ٸ� : %c\n", fgetc(fp));
	fclose(fp);

	return 0;
}