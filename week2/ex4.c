#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int *a, int *b) {
	int c = *b;
	*b = *a;
	*a = c;
	return;
}

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	swap(&a, &b);
	printf("%d %d", a, b);
	return 0;
}