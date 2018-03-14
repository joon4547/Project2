#include <stdio.h>


/*한 글자씩 입력받기*/
int main(void)
{
	FILE * fp = fopen("a.txt", "r");
	char c;

	//fgetc는 fp에서 문자 하나를 얻어온다.
	//즉, 한 문자씩 읽어들이는 것.
	//파일의 마지막에는 EOF라는 End Of File을 나타내는 값인 -1이 들어있다.
	while ((c = fgetc(fp)) != EOF)
	{
		printf("%c", c);
	}

	fclose(fp);
	return 0;
}