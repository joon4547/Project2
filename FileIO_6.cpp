#include <stdio.h>


int main(void)
{
	FILE * fp = fopen("a.txt", "w");
	fputs("Psi is an excllent C programmer", fp);
	fseek(fp, 0, SEEK_SET);
	fputs("is Psi", fp);
	fclose(fp);

	return 0;
}