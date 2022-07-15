#include<stdarg.h>
#include<stdio.h>
#include<math.h>

#define _0601



#ifdef _0601
double sqr(double x) {
	return x * x;
}
int main(void) {
	double x = 0;

	printf("実数値を入力せよ : ");
	scanf_s("%lf", &x);

	printf("その数の2乗は%.3fです。\n", sqr(x));

	return 0;
}
#endif

//実行不可
#ifdef _0602
int main(void) {
	double x = 0;

	printf("実数値を入力せよ : ");
	scanf_s("%lf", &x);

	printf("その数の2乗は%.3fです。\n", sqr(x));

	return 0;
}
double sqr(double x) {
	return x * x;
}
#endif

#ifdef _0603
int main(void) {
	double x = 0;

	printf("実数値を入力せよ : ");
	scanf_s("%lf", &x);

	printf("その数の3乗は%.3fです。\n", pow(x, 3.0));

	return 0;
}
#endif

#ifdef _0604
int func(int a, int b) {
	struct {
		int x;
		int y;
	}z;
	z.x = a;
	z.y = b;

	printf("z.x = %d\n", z.x);
	printf("z.y = %d\n", z.y);

	return z.x + z.y;
}
int main(void) {
	int a = 1; 
	int b = 2;

	printf("func(a, b) = %d\n", func(a, b));

	return 0;
}
#endif

#ifdef _0605
extern double pow();

int main(void) {
	double x = 0;

	printf("実数値を入力せよ : ");
	scanf_s("%lf", &x);

	printf("その数の3乗は%.3fです。\n", pow(x, 3.0));

	return 0;
}
#endif

#ifdef _0606
extern double pow();

int main(void) {
	double x = 0;

	printf("実数値を入力せよ : ");
	scanf_s("%lf", &x);

	printf("その数の3乗は%.3fです。\n", pow(x, 3));

	return 0;
}
#endif

#ifdef _0607
double pow(double, double);

int main(void) {
	double x = 0;

	printf("実数値を入力せよ : ");
	scanf_s("%lf", &x);

	printf("その数の3乗は%.3fです。\n", pow(x, 3));

	return 0;
}
#endif

//0608 … 0603と(ほぼ)同じ

#ifdef _0609
int add(int x, int y) {
	return x + y;
}
int main(void) {
	int x = 0, y = 0;

	printf("整数値を入力せよ : "); scanf_s("%d", &x);
	printf("整数値を入力せよ : "); scanf_s("%d", &y);

	printf("それらの和は%dです。\n", add(x, y));

	return 0;
}
#endif

#ifdef _0610
void iprint(int x), lprint(long x), fprint(float x), dprint(double x);

int main(void) {
	int a = 10000;
	long b = 40000;
	float c = 50000;
	double d = 60000;

	puts("-- a(int) --");
	iprint(a);
	lprint(a);

	puts("\n-- b(long) --");
	iprint(b);
	lprint(b);
	
	puts("\n-- c(float) --");
	iprint(c);
	lprint(c);
	
	puts("\n-- d(double) --");
	iprint(d);
	lprint(d);
}

void iprint(int x) {
	printf("iprint -> %d\n", x);
}
void lprint(long x) {
	printf("lprint -> %ld\n", x);
}
void fprint(float x) {
	printf("fprint -> %.1f\n", x);
}
void dprint(double x) {
	printf("dprint -> %.1f\n", x);
}
#endif


#ifdef _0613
#include"sum.h"
#define max 10

int main(void) {
	int n = 0; 

	do {
		printf("1～%dの整数値 : ", max);
		scanf_s("%d", &n);
	} while (n < 1 || n > max);

	printf("1～%dの和は%dです。\n", n, sum(n));

	return 0;
}
#endif

#ifdef _0614
double vsum(int sw, ...) {
	double sum = 0.0;
	va_list ap = nullptr;

	va_start(ap, sw);

	switch (sw) {
	case 0:
		sum += va_arg(ap, int);
		sum += va_arg(ap, int);
		break;
	case 1:
		sum += va_arg(ap, int);
		sum += va_arg(ap, long);
		break;
	case 2:
		sum += va_arg(ap, int);
		sum += va_arg(ap, long);
		sum += va_arg(ap, double);	
		break;
	}
	va_end(ap);

	return sum;
}
int main(void) {
	printf("10 + 2         = %.2f\n", vsum(0, 10, 2));
	printf("57 + 300000L   = %.2f\n", vsum(1, 57, 300000L));
	printf("98 + 2L + 3.14 = %.2f\n", vsum(2, 98, 2L, 3.14));

	return 0;
}
#endif

#ifdef _0615
int aprintf(const char* format, ...) {
	int count = 0;
	va_list ap = nullptr;

	putchar('\a');
	va_start(ap, format);
	count = vprintf(format, ap);
	va_end(ap);
	return count;
}
int main(void) {
	aprintf("Hello!\n");
	aprintf("%d %ld %.2f\n", 2, 3L, 3.14);

	return 0;
}
#endif