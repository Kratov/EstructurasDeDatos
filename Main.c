#include <stdio.h>

int main(int argc, char* argv[]) {
	int *p = (int *)malloc(sizeof(int));
	*p = 821;
	printf("%d", *p);
	return 0;
}