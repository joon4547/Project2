#include <stdio.h> 
#include <stdlib.h> 

struct BOOK
{
	char book_name[30];
	char auth_name[30];
	char publ_name[30];
	int borrowed;
};

typedef struct BOOK BOOK;
char compare(char *str1, char *str2);
int register_book(BOOK *book_list, int *nth);
int search_book(BOOK *book_list, int total_num_book);
int borrow_book(BOOK *book_list);
int return_book(BOOK *book_list);
int print_book_list(BOOK *book_list, int total_num_book);

int main()
{
	int user_choice; /* 유저가 선택한 메뉴 */
	int num_total_book = 0; /* 현재 책의 수 */


	BOOK *book_list;

	printf("도서관의 최대 보관 장서 수를 설정해주세요 : ");
	scanf("%d", &user_choice);

	book_list = (BOOK *)malloc(sizeof(BOOK)*user_choice);
	while (1)
	{
		printf("도서 관리 프로그램 \n");
		printf("메뉴를 선택하세요 \n");
		printf("1. 책을 새로 추가하기 \n");
		printf("2. 책을 검색하기 \n");
		printf("3. 책을 빌리기 \n");
		printf("4. 책을 반납하기 \n");
		printf("5. 프로그램 종료 \n");

		printf("6. 책들의 내용을 book_list.txt에 출력 \n");

		printf("당신의 선택은 : ");
		scanf("%d", &user_choice);

		if (user_choice == 1)
			/* 책을 새로 추가하는 함수 호출 */
			register_book(book_list, &num_total_book);
		else if (user_choice == 2)
			/* 책을 검색하는 함수 호출 */
			search_book(book_list, num_total_book);
		else if (user_choice == 3)
			/* 책을 빌리는 함수 호출 */
			borrow_book(book_list);
		else if (user_choice == 4)
			/* 책을 반납하는 함수 호출 */
			return_book(book_list);
		else if (user_choice == 5)
			/* 프로그램을 종료한다. */
			break;
		else if (user_choice == 6)
			print_book_list(book_list, num_total_book);
	}

	free(book_list);
	return 0;
}

int print_book_list(BOOK *book_list, int total_num_book)
{
	FILE *fp = fopen("book_list.txt", "w");
	int i;

	if (fp == NULL)
	{
		printf("출력오류\n");
		return 0;
	}

	fprintf(fp, "책 이름/ 저자 이름/출판사/반납 유무\n");
	for (i = 0; i < total_num_book; i++)
	{
		fprintf(fp, "%s / %s / %s", book_list[i].book_name, book_list[i].auth_name, book_list[i].publ_name);
		if (book_list[i].borrowed == 0)
			fprintf(fp, " / NO \n");
		else
			fprintf(fp, " /YES \n");
	}
	fclose(fp);
}
/* 책을 추가하는 함수*/
int register_book(BOOK *book_list, int *nth)
{
	printf("책의 이름 : ");
	scanf("%s", book_list[*nth].book_name);

	printf("책의 저자 : ");
	scanf("%s", book_list[*nth].auth_name);

	printf("책의 출판사 : ");
	scanf("%s", book_list[*nth].publ_name);

	book_list[*nth].borrowed = 0;
	(*nth)++;

	return 0;
}
/* 책을 검색하는 함수 */
int search_book(BOOK *book_list, int total_num_book)
{
	int user_input; /* 사용자의 입력을 받는다. */
	int i;
	char user_search[30];

	printf("어느 것으로 검색 할 것인가요? \n");
	printf("1. 책 제목 검색 \n");
	printf("2. 지은이 검색 \n");
	printf("3. 출판사 검색 \n");
	scanf("%d", &user_input);

	printf("검색할 단어를 입력해주세요 : ");
	scanf("%s", user_search);

	printf("검색 결과 \n");

	if (user_input == 1)
	{
		/*
		i 가 0 부터 num_total_book 까지 가면서 각각의 책 제목을
		사용자가 입력한 검색어와 비교하고 있다.
		*/
		for (i = 0; i < total_num_book; i++)
		{
			if (compare(book_list[i].book_name, user_search))
			{
				printf("번호 : %d // 책 이름 : %s // 지은이 : %s // 출판사 : %s \n",
					i, book_list[i].book_name, book_list[i].auth_name, book_list[i].publ_name);
			}
		}

	}
	else if (user_input == 2)
	{
		/*
		i 가 0 부터 num_total_book 까지 가면서 각각의 지은이 이름을
		사용자가 입력한 검색어와 비교하고 있다.
		*/
		for (i = 0; i < total_num_book; i++)
		{
			if (compare(book_list[i].auth_name, user_search))
			{
				printf("번호 : %d // 책 이름 : %s // 지은이 : %s // 출판사 : %s \n",
					i, book_list[i].book_name, book_list[i].auth_name, book_list[i].publ_name);
			}
		}

	}
	else if (user_input == 3)
	{
		/*
		i 가 0 부터 num_total_book 까지 가면서 각각의 출판사를
		사용자가 입력한 검색어와 비교하고 있다.
		*/
		for (i = 0; i < total_num_book; i++)
		{
			if (compare(book_list[i].publ_name, user_search))
			{
				printf("번호 : %d // 책 이름 : %s // 지은이 : %s // 출판사 : %s \n",
					i, book_list[i].book_name, book_list[i].auth_name, book_list[i].publ_name);
			}
		}
	}

	return 0;
}
char compare(char *str1, char *str2)
{
	while (*str1)
	{
		if (*str1 != *str2)
			return 0;
		str1++;
		str2++;
	}
	if (*str2 == '\0')
		return 1;

	return 0;
}
int borrow_book(BOOK *book_list)
{
	/* 사용자로 부터 책번호를 받을 변수*/
	int book_num;

	printf("빌릴 책의 번호를 말해주세요 \n");
	printf("책 번호 : ");
	scanf("%d", &book_num);

	if (book_list[book_num].borrowed == 1)
		printf("이미 대출된 책입니다! \n");
	else
		printf("책이 성공적으로 대출되었습니다. \n");
		book_list[book_num].borrowed = 1;

	return 0;
}
int return_book(BOOK *book_list)
{
	/* 반납할 책의 번호 */
	int num_book;

	printf("반납할 책의 번호를 써주세요 \n");
	printf("책 번호 : ");
	scanf("%d", &num_book);

	if (book_list[num_book].borrowed == 0)
		printf("이미 반납되어 있는 상태입니다\n");
	else
		book_list[num_book].borrowed = 0;
		printf("성공적으로 반납되었습니다\n");

	return 0;
}