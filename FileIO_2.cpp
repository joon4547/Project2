#include <stdio.h>

/*fgets로 a.txt에서 내용을 입력 받는다.*/
int main(void)
{

	//"r" 읽기형식.
	FILE * fp = fopen("a.txt", "r");
	char buf[20]; 

	//파일을 열때는 더 중요함.
	if (fp == NULL)
	{
		printf("Read Error!!\n");
		return 0;
	}

	//fgets(어디에 입력 받을 지, 입력받을 바이트 수, 어떤 스트림);
	fgets(buf, 20, fp);
	
	printf("입력 받을 내용 : %s \n", buf);

	fclose(fp);
	return 0;
}