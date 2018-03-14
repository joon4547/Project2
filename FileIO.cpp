#include <stdio.h>

int main()
{
	FILE *fp;
	//fopen 함수는 만든 스트림을 가리키는 포인터를 리턴한다.
	//fopen 에서 원래 'a.txt'가 존재하지 않았엇을 것 임으로 a.txt를 만든다.
	fp = fopen("a.txt", "w"); //"w"는 쓰기만 가능하다

	//fopen 할때는 가끔 실패하는데 실패할때 이런식으로 예외처리를 해줘야한다
	//fopen 이 실패하면 NULL을 리턴하게된다.
	if (fp == NULL)
	{
		printf("Write Error!!\n");
		return 0;
	}

	//fputs(파일에 기록할 문자열, 스트림);
	fputs("Hello World!! \n", fp);
	//stdout은 이미 이름이 정해진 표준 스트림.
	//두번째 인자로 stdout을 전다랗면 우리 콘솔 화면에 문자열이 뜬다.
	fputs("Hello World!! \n", stdout);
	
	//여녈된 스트림을 닫기. 
	//닫지 않는다면 스트림이 계속 살아있어서 파일은 계속 '쓰기 상태'로 남아있게 된다.
	fclose(fp);
	return 0;
}