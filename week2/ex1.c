#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
	int i = INT_MAX;
	float f = FLT_MAX;
	double d = DBL_MAX;
	printf("max value for integer is %d\nsize of integer is %lu bytes\nmax value for float is %f\nsize of float is %lu bytes\nmax value for double is %lf\nsize of double is %lu bytes\n",
		 i, sizeof(int), f, sizeof(float), d, sizeof(double));
	return 0;
}
