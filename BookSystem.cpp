#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 

struct BOOK
{
	char book_name[30];
	char auth_name[30];
	char publ_name[30];
	int borrowed;
};

typedef struct BOOK BOOK;
int register_book(BOOK *book_list, int *nth);
int search_book(BOOK *book_list, int total_num_book);
int borrow_book(BOOK *book_list);
int return_book(BOOK *book_list);
int print_book_list(BOOK *book_list, int total_num_book);
int retrieve_book_info(BOOK **book_list, int *total_num_book);
char compare(char *str1, char *str2);

int main()
{
	int user_choice; /* ������ ������ �޴� */
	int num_total_book = 0; /* ���� å�� �� */

	BOOK *book_list;
	int i;

	printf("�������� �ִ� ���� �弭 ���� �������ּ��� : ");
	scanf("%d", &user_choice);

	book_list = (BOOK *)malloc(sizeof(BOOK)*user_choice);

	while (1)
	{
		printf("���� ���� ���α׷� \n");
		printf("�޴��� �����ϼ��� \n");
		printf("1. å�� ���� �߰��ϱ� \n");
		printf("2. å�� �˻��ϱ� \n");
		printf("3. å�� ������ \n");
		printf("4. å�� �ݳ��ϱ� \n");
		printf("5. ���α׷� ���� \n");
		printf("6. å���� ������ book_list.txt �� ��� \n");
		printf("7. å���� ������ book_list.txt ���� �ҷ��� \n");
		printf("8. å���� ����� ��� \n");

		printf("����� ������ : ");
		scanf("%d", &user_choice);

		if (user_choice == 1)
			/* å�� ���� �߰��ϴ� �Լ� ȣ�� */
			register_book(book_list, &num_total_book);
		else if (user_choice == 2)
			/* å�� �˻��ϴ� �Լ� ȣ�� */
			search_book(book_list, num_total_book);
		else if (user_choice == 3)
			/* å�� ������ �Լ� ȣ�� */
			borrow_book(book_list);
		else if (user_choice == 4)
			/* å�� �ݳ��ϴ� �Լ� ȣ�� */
			return_book(book_list);
		else if (user_choice == 5)
			/* ���α׷��� �����Ѵ�. */
			break;
		else if (user_choice == 6)
			/* book_list.txt �� å���� ����� ����Ѵ�*/
			print_book_list(book_list, num_total_book);
		else if (user_choice == 7)
			/* book_list.txt ���� å���� ����� �����´�*/
			retrieve_book_info(&book_list, &num_total_book);
		else if (user_choice == 8)
		{
			/* å���� ����� ȭ�鿡 ����Ѵ�. */
			for (i = 0; i < num_total_book; i++)
				printf("%s // %s // %s // ", book_list[i].book_name, book_list[i].auth_name, book_list[i].publ_name);
				if (book_list[i].borrowed == 0)
					printf("NO\n");
				else
					printf("YES\n");
		}
	}

	free(book_list);
	return 0;
}
int print_book_list(BOOK *book_list, int total_num_book)
{
	FILE *fp = fopen("book_list.txt", "w");
	int i;

	if (fp == NULL)
		printf("��� ���� ! \n");
		return -1;

	fprintf(fp, "%d\n", total_num_book);

	for (i = 0; i < total_num_book; i++)
	{
		fprintf(fp, "%s\n%s\n%s\n", book_list[i].book_name, book_list[i].auth_name, book_list[i].publ_name);
		if (book_list[i].borrowed == 0)
			fprintf(fp, "NO\n");
		else
			fprintf(fp, "YES\n");
	}

	printf("��� �Ϸ�! \n");
	fclose(fp);

	return 0;
}
char compare(char *str1, char *str2)
{
	while (*str1)
	{
		if (*str1 != *str2)
		{
			return 0;
		}

		str1++;
		str2++;
	}

	if (*str2 == '\0')
		return 1;

	return 0;
}

/* �������� book_list �� ���� �ٲ�� �ϹǷ� ���� ������ ���� */
int retrieve_book_info(BOOK **book_list, int *total_num_book)
{
	FILE *fp = fopen("book_list.txt", "r");
	int total_book;
	int i;
	char str[10];

	if (fp == NULL)
	{
		printf("������ ������ ã�� �� �����ϴ�! \n");
		return -1;
	}

	/* ã�Ҵٸ� ��ü å�� ������ �о�´�. */
	fscanf(fp, "%d", &total_book);
	(*total_num_book) = total_book;

	/* ������ book_list �����͸� ���� */
	free(*book_list);
	/* �׸��� �ٽ� malloc ���� ���Ҵ� �Ѵ�. */
	(*book_list) = (BOOK *)malloc(sizeof(BOOK)*total_book);

	if (*book_list == NULL)
	{
		printf("\n ERROR \n");
		return -1;
	}
	for (i = 0; i<total_book; i++)
	{
		/* book_list[i]->book_name �� �ƴԿ� ����!! */
		fscanf(fp, "%s", (*book_list)[i].book_name);
		fscanf(fp, "%s", (*book_list)[i].auth_name);
		fscanf(fp, "%s", (*book_list)[i].publ_name);
		fscanf(fp, "%s", str);

		if (compare(str, "YES"))
		{
			(*book_list)[i].borrowed = 1;
		}
		else if (compare(str, "NO"))
		{
			(*book_list)[i].borrowed = 0;
		}
	}

	fclose(fp);
	return 0;

}
/* å�� �߰��ϴ� �Լ�*/
int register_book(BOOK *book_list, int *nth)
{
	printf("å�� �̸� : ");
	scanf("%s", book_list[*nth].book_name);

	printf("å�� ���� : ");
	scanf("%s", book_list[*nth].auth_name);

	printf("å�� ���ǻ� : ");
	scanf("%s", book_list[*nth].publ_name);

	book_list[*nth].borrowed = 0;
	(*nth)++;

	return 0;
}
/* å�� �˻��ϴ� �Լ� */
int search_book(BOOK *book_list, int total_num_book)
{
	int user_input; /* ������� �Է��� �޴´�. */
	int i;
	char user_search[30];

	printf("��� ������ �˻� �� ���ΰ���? \n");
	printf("1. å ���� �˻� \n");
	printf("2. ������ �˻� \n");
	printf("3. ���ǻ� �˻� \n");
	scanf("%d", &user_input);

	printf("�˻��� �ܾ �Է����ּ��� : ");
	scanf("%s", user_search);

	printf("�˻� ��� \n");

	if (user_input == 1)
	{
		/*
		i �� 0 ���� num_total_book ���� ���鼭 ������ å ������
		����ڰ� �Է��� �˻���� ���ϰ� �ִ�.
		*/
		for (i = 0; i < total_num_book; i++)
		{
			if (compare(book_list[i].book_name, user_search))
			{
				printf("��ȣ : %d // å �̸� : %s // ������ : %s // ���ǻ� : %s \n",
					i, book_list[i].book_name, book_list[i].auth_name, book_list[i].publ_name);
			}
		}

	}
	else if (user_input == 2)
	{
		/*
		i �� 0 ���� num_total_book ���� ���鼭 ������ ������ �̸���
		����ڰ� �Է��� �˻���� ���ϰ� �ִ�.
		*/
		for (i = 0; i < total_num_book; i++)
		{
			if (compare(book_list[i].auth_name, user_search))
			{
				printf("��ȣ : %d // å �̸� : %s // ������ : %s // ���ǻ� : %s \n",
					i, book_list[i].book_name, book_list[i].auth_name, book_list[i].publ_name);
			}
		}

	}
	else if (user_input == 3)
	{
		/*

		i �� 0 ���� num_total_book ���� ���鼭 ������ ���ǻ縦
		����ڰ� �Է��� �˻���� ���ϰ� �ִ�.

		*/
		for (i = 0; i < total_num_book; i++)
		{
			if (compare(book_list[i].publ_name, user_search))
			{
				printf("��ȣ : %d // å �̸� : %s // ������ : %s // ���ǻ� : %s \n",
					i, book_list[i].book_name, book_list[i].auth_name, book_list[i].publ_name);
			}
		}
	}

	return 0;
}
int borrow_book(BOOK *book_list)
{
	/* ����ڷ� ���� å��ȣ�� ���� ����*/
	int book_num;

	printf("���� å�� ��ȣ�� �����ּ��� \n");
	printf("å ��ȣ : ");
	scanf("%d", &book_num);

	if (book_list[book_num].borrowed == 1)
	{
		printf("�̹� ����� å�Դϴ�! \n");
	}
	else
	{
		printf("å�� ���������� ����Ǿ����ϴ�. \n");
		book_list[book_num].borrowed = 1;
	}

	return 0;
}
int return_book(BOOK *book_list)
{
	/* �ݳ��� å�� ��ȣ */
	int num_book;

	printf("�ݳ��� å�� ��ȣ�� ���ּ��� \n");
	printf("å ��ȣ : ");
	scanf("%d", &num_book);

	if (book_list[num_book].borrowed == 0)
	{
		printf("�̹� �ݳ��Ǿ� �ִ� �����Դϴ�\n");
	}
	else
	{
		book_list[num_book].borrowed = 0;
		printf("���������� �ݳ��Ǿ����ϴ�\n");
	}

	return 0;
}

