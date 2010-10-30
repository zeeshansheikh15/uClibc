#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#define check_d1(func, param, expected) \
do { \
	int err; hex_union ur; hex_union up; \
	up.f = param; ur.f = result = func(param); \
	errors += (err = (result != expected)); \
	err \
	? printf("FAIL: %s(%g/"HEXFMT")=%g/"HEXFMT" (expected %g)\n", \
		#func, (param), (long long)up.hex, result, (long long)ur.hex, expected) \
	: printf("PASS: %s(%g)=%g\n", #func, (param), result); \
} while (0)

#define HEXFMT "%08llx"
typedef union {
	double f;
	uint64_t hex;
} hex_union;
double result;

int errors = 0;

int main(void)
{
	check_d1(rint, 0.6, 1.0);

        printf("Errors: %d\n", errors);
        return errors;
}
