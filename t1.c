#include <stdio.h>

int main(){
	while (1)
	{
		int i, j, k, n;

		printf("ют╥б : ");
		scanf("%d", &n);

		for (i = 1; i <= n; i++){
			for (j = i; j < n; j++){
				printf(" ");
			}
			for (k = 0; k < 2 * i - 1; k++){
				printf("*");
			}

			printf("\n");
		}
	}
	return 0;
}

