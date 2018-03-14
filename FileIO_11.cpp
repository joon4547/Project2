#include <stdio.h>

int main(void)
{
	//"읽기 및 쓰기형식으로 열겠다"라는 뜻인데, 파일이존재하니 않는다면 열지 않겟다는 의미
	//만일 파일이 존재하면 파일의 내용을 지우지 않는다.
	//"w+" 도 읽기 및 쓰기형식으로 열겟다. 
	//이 경우 파일이 존재하지 않는다면 파일을 새로 만들고 파일이 존재하면 파일의 내용을 다 지웁니다.
	FILE * fp = fopen("some_data.txt", "r+");
	char data[100];

	//최대 100바이트 까지 읽어들엿다.
	//파일 위치 지정자도 맨 끝을 가리키고 있다.
	fgets(data, 100, fp);
	printf("현재 파일에 있는 내용 : %s\n", data);

	//앞에서 5칸 떨어진 곳으로 이동. 
	fseek(fp, 5, SEEK_SET);

	//이전의 내용은 무시하고 is nohthing on this file이 차지하는 만큼 덮어 씌우기가 된다.
	fputs("is nothing on this file", fp);

	fclose(fp);
}