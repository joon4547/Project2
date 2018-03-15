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
