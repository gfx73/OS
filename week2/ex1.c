#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
	int i = INT_MAX;
	float f = FLT_MAX;
	double d = DBL_MAX;

	printf("%d %d\n%f %d\n%lf %d", i, sizeof(i), f, sizeof(f), d, sizeof(d));

	return 0;
}