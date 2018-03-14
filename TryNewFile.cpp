#include <stdio.h>

int main(void)
{
	FILE * fp = fopen("some_data.txt", "w");
	char c;

	if (fp == NULL)
	{
		printf(" Error!! ");
		return 0;
	}

	fputs("There is some data in this FILE !!!!", fp);

	return 0;

}