#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[]) {
	int n;
	sscanf(argv[1], "%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n - 1; j++) {
			if (i >= abs(n - 1 - j))
				printf("%c", '*');
			else
				printf("%c", ' ');
		}
		printf("%c", '\n');
	}
	return 0;
}