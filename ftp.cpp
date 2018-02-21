#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/types.h>

#define MAXBUF 1000

int login(int ssock);
void command(char *s);
void getIpAddr(char *ipp);
void getClientInfo(char *clientInfo);
void *dataLink();
void getDNS(char *name, char *serverIpAddress);
void *getData();
void *putData();

char  msg[MAXBUF], buf[MAXBUF];
int ssock, hsock;
int h_Port = 7000;;
char fileName[30];







int main(int argc, char *argv[]){


	int clen, serverMassage;
	struct sockaddr_in server_addr;
	char serverIpAddress[16] = "";

	if ((ssock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
		perror("socket error : ");
		exit(1);
	}

	clen = sizeof(server_addr);


	getDNS(argv[1], serverIpAddress);


	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr(serverIpAddress);
	server_addr.sin_port = htons(21);

	if (connect(ssock, (struct sockaddr *)&server_addr, clen) < 0) {
		perror("connect error :");
		exit(1);
	}


	printf("connecting %s\n", argv[1]);
	read(ssock, buf, MAXBUF);
	puts(buf);

	if (atoi(buf) == 220){

		if (login(ssock) == 230){  //로그인이 성공했을시
			while (1){
				printf("ftp>");
				memset(buf, 0, MAXBUF);
				memset(msg, 0, MAXBUF);
				fgets(msg, sizeof(msg), stdin);

				if (strcmp(msg, "quit\n") == 0 || strcmp(msg, "bye\n") == 0){    //입력 받은 커맨드가 quit나 bye 인지 확인
					write(ssock, "QUIT\r\n", 7);
					read(ssock, buf, MAXBUF);
					puts(buf);
					memset(buf, 0, MAXBUF);
					read(ssock, buf, MAXBUF);
					puts(buf);
					memset(buf, 0, MAXBUF);
					break;
				}
				else{

					command(msg);

				}
			}
		}
	}
	else{
		printf("connecting error!");
	}

	close(ssock);

}






//****************입력받은 Command를 처리하는 함수******************** 


void command(char *s){


	//pthread_t thread;
	char file1[50], file2[50];
	char *cmd, *userCMD, *file_Name;
	char userMessage[50];
	char *s1 = s;
	FILE *f;
	pthread_t thread1, thread2, thread3;





	/* strtok, strstr 합수 사용

	strtok(s1,s2);
	s1의 문자열을 s2문자를 구분으로 토큰(덩어리)로 나눔.

	strstr(s1, s2);
	s1의 문자열에 s2가 있으면 포인터형으로 반환, 없으면 NULL반환

	*/

	if (strstr(s1, " ") == NULL){      /*입력받은 커맨드가 하나라면*/
		cmd = s;
		userCMD = "";
	}
	else{							/*입력받은 커멘드가 2개 이상이라면.*/
		cmd = strtok(s1, " "); 	//명령어 추출
		userCMD = strtok(NULL, "\n,\r\n,\0");	//사용자 메시지 추출

	}

	if (strcmp(cmd, "ls\n") == 0 || strcmp(cmd, "ls") == 0){
		pthread_create(&thread1, NULL, dataLink, NULL);
		memset(buf, 0, MAXBUF);
		read(ssock, buf, MAXBUF);		//"200 Port command successful."	
		puts(buf);

		if (strcmp(userCMD, "") == 0){	//아규먼트가 없다면
			if (atoi(buf) == 200){		//IP와 포트정보가 서버에 잘 전송되었는지 검사
				write(ssock, "NLST\r\n", 6);		//명령어 보냄
				memset(buf, 0, MAXBUF);
				read(ssock, buf, MAXBUF);			//"150 Opening ASCII mode data connection for file list"	or	"550 *: No such file or directory."
				puts(buf);
				if (atoi(buf) == 150){
					memset(buf, 0, MAXBUF);
					read(hsock, buf, MAXBUF);		//새로 생성된 소켓으로 데이터를 받음	
					close(hsock);
					puts(buf);
					memset(buf, 0, MAXBUF);
					read(ssock, buf, MAXBUF);		//226 Transfer complete.
					puts(buf);
				}
			}
			else{
				puts("[ls] command error ! ");	//200 메시지를 못받은경우
			}
		}
		else {	//아규먼트가 있다면
			if (atoi(buf) == 200){		//IP와 포트정보가 서버에 잘 전송되었는지 검사
				sprintf(userMessage, "NLST %s\r\n", userCMD);
				write(ssock, userMessage, strlen(userMessage));		//명령어 보냄 (-al 과  -all 이 있지만 방식은 동일하므로 하나로 축약)
				memset(buf, 0, MAXBUF);
				read(ssock, buf, MAXBUF);			//"150 Opening ASCII mode data connection for file list"	or	"550 *: No such file or directory."
				puts(buf);
				if (atoi(buf) == 150){
					memset(buf, 0, MAXBUF);
					read(hsock, buf, MAXBUF);		//새로 생성된 소켓으로 데이터를 받음	
					close(hsock);
					puts(buf);
					memset(buf, 0, MAXBUF);
					read(ssock, buf, MAXBUF);		//226 Transfer complete.
					puts(buf);
				}
			}
			else{
				puts("[ls] command error ! ");	//200 메시지를 못받은경우
			}
		}
		close(hsock);
	}
	else if (strcmp(cmd, "dir\n") == 0 || strcmp(cmd, "dir") == 0){
		pthread_create(&thread1, NULL, dataLink, NULL);
		memset(buf, 0, MAXBUF);
		read(ssock, buf, MAXBUF);		//"200 Port command successful."	
		puts(buf);

		if (strcmp(userCMD, "") == 0){	//아규먼트가 없다면
			if (atoi(buf) == 200){		//IP와 포트정보가 서버에 잘 전송되었는지 검사
				write(ssock, "LIST\r\n", 6);		//명령어 보냄
				memset(buf, 0, MAXBUF);
				read(ssock, buf, MAXBUF);			//"150 Opening ASCII mode data connection for file list"	or	"550 *: No such file or directory."
				puts(buf);
				if (atoi(buf) == 150){
					memset(buf, 0, MAXBUF);
					read(hsock, buf, MAXBUF);		//새로 생성된 소켓으로 데이터를 받음	
					close(hsock);
					puts(buf);
					memset(buf, 0, MAXBUF);
					read(ssock, buf, MAXBUF);		//226 Transfer complete.
					puts(buf);
				}
			}
			else{
				puts("[dir] command error ! ");	//200 메시지를 못받은경우
			}
		}
		else{	//아규먼트가 있다면
			if (atoi(buf) == 200){		//IP와 포트정보가 서버에 잘 전송되었는지 검사
				sprintf(userMessage, "LIST %s\r\n", userCMD);
				write(ssock, userMessage, strlen(userMessage));		//명령어 보냄 (-al 과  -all 이 있지만 방식은 동일하므로 하나로 축약)
				memset(buf, 0, MAXBUF);
				read(ssock, buf, MAXBUF);			//"150 Opening ASCII mode data connection for file list"	or	"550 *: No such file or directory."
				puts(buf);
				if (atoi(buf) == 150){
					memset(buf, 0, MAXBUF);
					read(hsock, buf, MAXBUF);		//새로 생성된 소켓으로 데이터를 받음	
					close(hsock);
					puts(buf);
					memset(buf, 0, MAXBUF);
					read(ssock, buf, MAXBUF);		//226 Transfer complete.
					puts(buf);
				}
			}
			else{
				puts("[dir] command error ! ");	//200 메시지를 못받은경우
			}

		}
		close(hsock);
	}
	else if (strcmp(cmd, "get\n") == 0 || strcmp(cmd, "get") == 0){
		if (userCMD != ""){
			pthread_create(&thread1, NULL, dataLink, NULL);
			memset(buf, 0, MAXBUF);
			read(ssock, buf, MAXBUF);  //200 Port command successful.
			puts(buf);

			if (atoi(buf) == 200){		//IP와 포트정보가 서버에 잘 전송되었는지 검사
				sprintf(userMessage, "RETR %s\r\n", userCMD);
				write(ssock, userMessage, strlen(userMessage));
				read(ssock, buf, MAXBUF);			//"150 Opening ASCII mode data connection for file list"	or	"550 *: No such file or directory."
				puts(buf);
				if (atoi(buf) == 150){
					strcpy(fileName, userCMD);
					pthread_create(&thread2, NULL, getData, NULL);
					read(ssock, buf, MAXBUF);		//226 Transfer complete.
					puts(buf);
				}
			}
			else{
				puts("[get] command error !");		//200 메시지를 못받은경우
			}

		}
		else{										//get만 쳤을경우 
			printf("Remote file ");
			fgets(file1, sizeof(file1), stdin);		//file1에 받을파일명 저장
			printf("Local file ");
			fgets(file2, sizeof(file2), stdin);		//file2에 받아서 저장할 파일명 저장

			file_Name = strtok(file2, "\r\n,\n,\0");			//파일명에서 쓸대없는 NULL 값을 제거

			pthread_create(&thread1, NULL, dataLink, NULL);
			memset(buf, 0, MAXBUF);
			read(ssock, buf, MAXBUF);  //200 Port command successful.
			puts(buf);


			if (atoi(buf) == 200){		//IP와 포트정보가 서버에 잘 전송되었는지 검사
				sprintf(userMessage, "RETR %s", file1);			//Remote file 에서 받은 파일명을 보냄
				write(ssock, userMessage, strlen(userMessage));
				read(ssock, buf, MAXBUF);			//"150 Opening ASCII mode data connection for file list"	or	"550 *: No such file or directory."
				puts(buf);
				if (atoi(buf) == 150){
					strcpy(fileName, file_Name);				//Local file 에서 받은 파일명을 저장
					pthread_create(&thread2, NULL, getData, NULL);
					read(ssock, buf, MAXBUF);		//226 Transfer complete.
					puts(buf);
				}
			}
			else{
				puts("[get] command error !");		//200 메시지를 못받은경우
			}



		}
	}
	else if (strcmp(cmd, "put\n") == 0 || strcmp(cmd, "put") == 0){
		if (userCMD != ""){
			if ((f = fopen(userCMD, "r")) != NULL){			//파일이 있는지 없는지 검사.
				fclose(f);							//검사할때 열었던 파일을 다시 닫음.

				pthread_create(&thread1, NULL, dataLink, NULL);		//소켓 생성을 위한 쓰레드 작동	
				memset(buf, 0, MAXBUF);
				read(ssock, buf, MAXBUF);  //200 Port command successful.
				puts(buf);

				if (atoi(buf) == 200){		//IP와 포트정보가 서버에 잘 전송되었는지 검사
					sprintf(userMessage, "STOR %s\r\n", userCMD);
					write(ssock, userMessage, strlen(userMessage));
					read(ssock, buf, MAXBUF);		//"150 Opening ASCII mode data connection for file list"	or	"550 *: No such file or directory."
					puts(buf);
					if (atoi(buf) == 150){
						strcpy(fileName, userCMD);
						pthread_create(&thread3, NULL, putData, NULL);
						memset(buf, 0, MAXBUF);
						read(ssock, buf, MAXBUF);		//226 Transfer complete.
						puts(buf);
					}
				}
				else{
					puts("[put] command eroor !");		//200 메시지를 못받았을경우
				}
			}
			else{
				printf("%s : File not found\n", userCMD);	//파일이 없는경우
			}
		}
		else{				//파일명을 쓰지 않은 경우
			printf("Local file ");
			fgets(file1, sizeof(file1), stdin);		//file1에 올릴 저장
			printf("Remote file ");
			fgets(file2, sizeof(file2), stdin);		//file2에 올려서 저장할 파일명 저장

			file_Name = strtok(file1, "\r\n,\n,\0");			//파일명에서 쓸대없는 NULL 값을 제거

			if ((f = fopen(file_Name, "r")) != NULL){			//파일이 있는지 없는지 검사.
				fclose(f);							//검사할때 열었던 파일을 다시 닫음.

				pthread_create(&thread1, NULL, dataLink, NULL);
				memset(buf, 0, MAXBUF);
				read(ssock, buf, MAXBUF);  //200 Port command successful.
				puts(buf);

				if (atoi(buf) == 200){		//IP와 포트정보가 서버에 잘 전송되었는지 검사
					sprintf(userMessage, "STOR %s", file2);
					write(ssock, userMessage, strlen(userMessage));
					read(ssock, buf, MAXBUF);		//"150 Opening ASCII mode data connection for file list"	or	"550 *: No such file or directory."
					puts(buf);
					if (atoi(buf) == 150){
						strcpy(fileName, file_Name);
						pthread_create(&thread3, NULL, putData, NULL);
						memset(buf, 0, MAXBUF);
						read(ssock, buf, MAXBUF);		//226 Transfer complete.
						puts(buf);
					}
				}
				else{
					puts("[put] command eroor !");		//200 메시지를 못받았을경우
				}
			}
			else{
				printf("%s : File not found\n", file_Name);	//파일이 없는경우
			}

		}
	}
	else if (strcmp(cmd, "cd") == 0 || strcmp(cmd, "cd\n") == 0){
		if (userCMD != ""){
			sprintf(userMessage, "CWD %s\r\n", userCMD);
			write(ssock, userMessage, strlen(userMessage));
			read(ssock, buf, MAXBUF);
			puts(buf);
		}
		else{
			write(ssock, "CWD\r\n", 5);
			read(ssock, buf, MAXBUF);
			puts(buf);
		}

	}
	else if (strcmp(cmd, "pwd\n") == 0){
		write(ssock, "XPWD\r\n", 6);
		read(ssock, buf, MAXBUF);
		puts(buf);
	}
	else if (strcmp(cmd, "del\n") == 0 || strcmp(cmd, "del") == 0){
		if (strcmp(userCMD, "") != 0){
			sprintf(userMessage, "DELE %s\r\n", userCMD);
			write(ssock, userMessage, strlen(userMessage));
			read(ssock, buf, MAXBUF);
			puts(buf);
		}
		else{
			printf("Remote file ");
			fgets(file1, sizeof(file1), stdin);
			sprintf(userMessage, "DELE %s", file1);
			write(ssock, userMessage, strlen(userMessage));
			read(ssock, buf, MAXBUF);
			puts(buf);



		}
	}
	else if (strcmp(cmd, "mkdir\n") == 0 || strcmp(cmd, "mkdir") == 0){
		if (strcmp(userCMD, "") != 0){
			sprintf(userMessage, "XMKD %s\r\n", userCMD);
			write(ssock, userMessage, strlen(userMessage));
			read(ssock, buf, MAXBUF);
			puts(buf);
		}
		else{
			printf("Directory name ");
			fgets(file1, sizeof(file1), stdin);
			sprintf(userMessage, "XMKD %s", file1);
			write(ssock, userMessage, strlen(userMessage));
			read(ssock, buf, MAXBUF);
			puts(buf);



		}
	}
	else if (strcmp(cmd, "rmdir\n") == 0 || strcmp(cmd, "mkdir") == 0){
		if (strcmp(userCMD, "") != 0){
			sprintf(userMessage, "XRMD %s\r\n", userCMD);
			write(ssock, userMessage, strlen(userMessage));
			read(ssock, buf, MAXBUF);
			puts(buf);
		}
		else{
			printf("Directory name ");
			fgets(file1, sizeof(file1), stdin);
			sprintf(userMessage, "XRMD %s", file1);
			write(ssock, userMessage, strlen(userMessage));
			read(ssock, buf, MAXBUF);
			puts(buf);



		}
	}
	else if (strcmp(cmd, "\n") == 0){							//엔터만 쳤을때
		printf("");
	}
	else{
		puts("Invalid command!");
	}

	memset(buf, 0, MAXBUF);
	memset(file1, 0, sizeof(file1));
	memset(file2, 0, sizeof(file2));


}



//**************** Data-Link 함수(쓰레드 함수)************************
void *dataLink(){


	struct sockaddr_in client_addr, server_addr;
	int csock, clen;
	char clientInfo[27];
	pthread_t thread2;

	if ((csock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0){
		perror("socket error : ");
	}

	clen = sizeof(client_addr);


	while (1){

		memset(&server_addr, 0, sizeof(server_addr));
		server_addr.sin_family = AF_INET;
		server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
		server_addr.sin_port = htons(h_Port);

		if (bind(csock, (struct sockaddr *) &server_addr, sizeof(server_addr)) <0){
			h_Port++;
		}
		else break;
	}


	if (listen(csock, 8) < 0){
		perror("listen error : ");
	}

	getClientInfo(clientInfo);
	write(ssock, clientInfo, strlen(clientInfo));		//클라이언트의 정보를 서버로 보냄

	hsock = accept(csock, (struct sockaddr *)&client_addr, &clen);



	close(csock);



}

void *getData(){

	int dfd;
	int n;

	dfd = open(fileName, O_WRONLY | O_CREAT | O_EXCL, 0644);

	while ((n = read(hsock, buf, MAXBUF)) > 0)
		write(dfd, buf, n);

	memset(buf, 0, MAXBUF);
	close(hsock);
	close(dfd);

}

void *putData(){

	int sfd;
	int n;

	sfd = open(fileName, O_RDONLY);

	while ((n = read(sfd, buf, MAXBUF)) > 0){
		write(hsock, buf, n);
	}
	memset(buf, 0, MAXBUF);
	close(hsock);
	close(sfd);

}


//****************자신의 IP Address 얻어 오는 함수******************** 

void getIpAddr(char *ipp){


	int i;
	socklen_t len = sizeof(struct sockaddr_in);
	int s = socket(PF_INET, SOCK_DGRAM, 0);
	struct sockaddr_in sin;
	struct sockaddr_in sout;

	memset((char *)&sin, 0, sizeof(struct sockaddr_in));

	sin.sin_family = AF_INET;
	sin.sin_port = htons(1);
	sin.sin_addr.s_addr = inet_addr("1.1.1.1");

	connect(s, (struct sockaddr *)&sin, sizeof(struct sockaddr_in));

	getsockname(s, (struct sockaddr *)&sout, &len);
	strcpy(ipp, inet_ntoa(sout.sin_addr));

	close(s);

}




//****************IP Address와 Port를 연결 변환 시켜주는 함수******************** 			

void getClientInfo(char *clientInfo){

	int i, n;
	int port1, port2;
	unsigned char *h_IP1 = "";
	unsigned char *h_IP2 = "";
	unsigned char *h_IP3 = "";
	unsigned char *h_IP4 = "";
	char ipp[20];

	port1 = h_Port / 256;
	port2 = h_Port % 256;



	//strtok() 합수를 사용하여 "." 를 구분자로 h_IP에 아이피를 저장

	getIpAddr(ipp);
	h_IP1 = strtok(ipp, ".");
	h_IP2 = strtok(NULL, ".");
	h_IP3 = strtok(NULL, ".");
	h_IP4 = strtok(NULL, ".");

	//clientInfo변수에 아이피 주소와 포트 번호를 붙임
	sprintf(clientInfo, "PORT %s,%s,%s,%s,%d,%d\r\n", h_IP1, h_IP2, h_IP3, h_IP4, port1, port2);

	h_Port = h_Port + 5;  //다음번 커넥트를 위해서 포트를 미리 증가시켜놓음

}




/*
=================================처음 로그인 관련 함수===========================================
*/


//*******************DNS에서 IP받아오는 함수***************

void getDNS(char *name, char *serverIpAddress){

	char serverName[15];
	struct hostent *serverIP;

	/* DNS서버에서 IP주소 얻어오기 */

	serverIP = gethostbyname(name);

	unsigned char a = serverIP->h_addr[0];
	unsigned char b = serverIP->h_addr[1];
	unsigned char c = serverIP->h_addr[2];
	unsigned char d = serverIP->h_addr[3];

	sprintf(serverName, "%d.%d.%d.%d", a, b, c, d);
	/* IP주소 얻어오기 끝 */
	strcpy(serverIpAddress, serverName);

}

//****************로그인 함수******************** 


int login(int ssock){
	int i;
	char userID[100], userPASS[100];
	printf("User ID : ");
	fgets(msg, sizeof(msg), stdin);    //ID를 입력 받으면
	sprintf(userID, "USER %s", msg);	//sprintf를 이용하여 userID에 "USER ID"를 붙인다
	write(ssock, userID, strlen(userID));
	read(ssock, buf, MAXBUF);
	printf("%s\n", buf);
	memset(buf, 0, MAXBUF);
	printf("\nPassword : ");		//ID보내는 형식과 동일
	fgets(msg, sizeof(msg), stdin);
	sprintf(userPASS, "PASS %s", msg);
	write(ssock, userPASS, strlen(userPASS));
	read(ssock, buf, MAXBUF);
	printf("%s\n", buf);

	i = atoi(buf); //서버에서 받은 message를 atoi를 이용하여 숫자만 추출
	//	 atoi(s) :: 변수 s(숫자+문자열로 구성)에서 숫자만 추출함(원래는 문자열을 숫자로 바꿔주는 함수)  

	return i;
}
