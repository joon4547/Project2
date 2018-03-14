#include <stdio.h>

int main(void)
{
	FILE * fp = fopen("a.txt", "r");
	fgetc(fp);
	fgetc(fp);
	fgetc(fp);
	fgetc(fp);

	//fseek 함수는 fp를 세번째 인자로부터 두번째 인자 만큼 떨어진 곳으로 파일 위치 지정자를 돌린다.
	fseek(fp, 0, SEEK_SET);
	printf("다시 파일 처음에서 입력 받는다면 : %c\n", fgetc(fp));
	fclose(fp);

	return 0;
}