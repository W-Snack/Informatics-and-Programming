// Copyright 2021 Fomin Vladimir


#include <stdio.h> 
#include <stdlib.h>
#include <math.h>

int num = 1;
void print_menu() {
	printf("\n1.One-time calculation of the function at a given point\n2.Serial experiment\n0.Exit the program\nInput: ");
}

void func_menu() {
	printf("1.Sin\n");
	printf("2.Cos\n");
	printf("3.Exp\n");
	printf("4.Arsh\n");
	printf("Choose function: ");
}

void case1_input (double *x, double *acc, int *N) {
	printf("Input X: ");
	scanf_s("%p", &x);
	printf("Input calculation accuracy (from 0.000001 and more): ");
	scanf_s("%p", &acc);
	printf("Input the number of elements of the series to perform the calculation (N - from 1 to 1000): ");
	scanf_s("%p", &N);

}

double cos_t(double x, double e, int N, int choice) {
	double x2, c, n, f, z;
	x2 = x * x;
	f = 2;
	c = 1;
	n = 2;
	z = -1;
	if (choice == 1) {
		while (((x2 / f) >= e) && (num < N)) {
			c = c + z * x2 / f;
			n = n + 2;
			x2 = x2 * x * x;
			f = f * (n - 1) * n;
			z = z * (-1);
			num++;
		}
	}
	else {
		while (num < N) {
			c = c + z * x2 / f;
			n = n + 2;
			x2 = x2 * x * x;
			f = f * (n - 1) * n;
			z = z * (-1);
			num++;
		}
	}
	return c;
}

double sin_t(double x, double e, int N, int choice)
{
	double n = x;
	double sum = 0.0;
	int i = 1;

	if (choice == 1) {
		do
		{
			sum += n;
			n *= -1.0 * x * x / ((2 * i) * (2 * i + 1));
			i++;
			num++;
		} while ((fabs(n) > e) && (num < N));
	}
	else {
		do
		{
			sum += n;
			n *= -1.0 * x * x / ((2 * i) * (2 * i + 1));
			i++;
			num++;
		} while (num < N);
	}
	return sum;
}

double exp_t(double x, double e, int N, int choice)
{
	double a = 1, s = 1;
	if (choice == 1) {
		for (int n = 1; (a > e) && (num < N); n++)
		{
			a *= x / n;
			s += a;
			num++;
		}
	}
	else {
		for (int n = 1; num < N ; n++)
		{
			a *= x / n;
			s += a;
			num++;
		}
	}
	return s;
}

double asinh_t(double x, double e, int N, int choice)
{
	double sum = x;
	long n = 0;
	double fn = (-0.166667) *  x;
	if (choice == 1) {
		do
		{
			sum += fn;
			n += 1;
			fn *= -(n + 1);
			fn /= 4 * x * x * (n + 2);
			num++;
		} while ((fabs(fn) > e) && (num < N));
	}
	else {
		do
		{
			sum += fn;
			n += 1;
			fn *= -(n + 1);
			fn /= 4 * x * x * (n + 2);
			num++;
		} while (num < N);
	}
	return sum;
}
double asinh2_t(double x, double e, int N, int choice) {
	double ai = x;
	double sum = 0;
	if (choice == 1) {
		for (int i = 1; (fabs(ai) > e) && (num<N); i++)
		{
			sum += ai;
			ai *= -x * x * (2. * i + 1.) * (2. * i + 1.) / (2. * i + 2.) / (2. * i + 3.);
			num++;
		}
	}
	else {
		for (int i = 1; (num < N); i++)
		{
			sum += ai;
			ai *= -x * x * (2. * i + 1.) * (2. * i + 1.) / (2. * i + 2.) / (2. * i + 3.);
			num++;
		}
	}
	return sum;
}

void cos_1case() {
	double x; int func; double acc; int N;
	double standard; double value;

	printf("Input X: ");
	scanf_s("%lf", &x);
	printf("Input calculation accuracy (from 0.000001 and more): ");
	scanf_s("%lf", &acc);
	printf("Input the number of elements of the series to perform the calculation (N - from 1 to 1000): ");
	scanf_s("%d", &N);
	standard = cos(x);
	value = cos_t(x, acc, N, 1);
	printf("Standard = %lf\n", standard);
	printf("Value = %lf\n", value);
	printf("The difference between the estimate and the standard value  = %lf\n", (fabs(value - standard)));
	printf("Count of terms = %d \n", num);
	num = 1;

}

void sin_1case() {
	double x; int func; double acc; int N;
	double standard; double value;

	printf("Input X: ");
	scanf_s("%lf", &x);
	printf("Input calculation accuracy (from 0.000001 and more): ");
	scanf_s("%lf", &acc);
	printf("Input the number of elements of the series to perform the calculation (N - from 1 to 1000): ");
	scanf_s("%d", &N);
	standard = sin(x);
	value = sin_t(x, acc, N, 1);
	printf("Standard = %lf\n", standard);
	printf("Value = %lf\n", value);
	printf("The difference between the estimate and the standard value  = %lf\n", (fabs(standard - value)));
	printf("Count of terms = %d \n", num);
	num = 1;

}

void exp_1case() {
	double x; int func; double acc; int N;
	double standard; double value;

	printf("Input X: ");
	scanf_s("%lf", &x);
	printf("Input calculation accuracy (from 0.000001 and more): ");
	scanf_s("%lf", &acc);
	printf("Input the number of elements of the series to perform the calculation (N - from 1 to 1000): ");
	scanf_s("%d", &N);
	standard = exp(x);
	value = exp(x, acc, N, 1);
	printf("Standard = %lf\n", standard);
	printf("Value = %lf\n", value);
	printf("The difference between the estimate and the standard value  = %lf\n", (fabs(standard - value)));
	printf("Count of terms = %d \n", num);
	num = 1;
}

void asinh_1case() {
	double x; int func; double acc; int N;
	double standard; double value; int x_right = 0;
	while (!x_right) {
		printf("Input X ( |x| < 1 ): ");
		scanf_s("%lf", &x);
		if (fabs(x) < 1) {
			x_right = 1;
		}
		else {
			printf("Wrong X. Please, repeat.\n");
		}
	}
	printf("Input calculation accuracy (from 0.000001 and more): ");
	scanf_s("%lf", &acc);
	printf("Input the number of elements of the series to perform the calculation (N - from 1 to 1000): ");
	scanf_s("%d", &N);
	standard = asinh(x);
	value = asinh2_t(x, acc, N,1);
	printf("Standard = %lf\n", standard);
	printf("Value = %lf\n", value);
	printf("The difference between the estimate and the standard value  = %lf\n", (fabs(standard - value)));
	printf("Count of terms = %d \n", num);
	num = 1;
}

void cos_2case() {
	double x; int func; double acc; int N;
	double standard; double value;

	printf("Input X: ");
	scanf_s("%lf", &x);
	printf("Input number of experiments (NMax - from 1 to 25): ");
	scanf_s("%d", &N);
	standard = cos(x);		
	printf("Standard = %lf\n", standard);
	for (int i = 1; i <= N; i++) {
		value = cos_t(x, 0.000001, i, 2);		
		printf("Count of terms = %d \t", num);		
		printf("Value = %lf \t", value);
		printf("The difference between the estimate and the standard value  = %lf\n", (fabs(value - standard)));	
		num = 1;
	}		
}

void sin_2case() {
	double x; int func; double acc; int N;
	double standard; double value;
	num = 0;
	printf("Input X: ");
	scanf_s("%lf", &x);
	printf("Input number of experiments (NMax - from 1 to 25): ");
	scanf_s("%d", &N);
	standard = sin(x);
	printf("Standard = %lf\n", standard);
	for (int i = 1; i <= N; i++) {
		value = sin_t(x, 0.000001, i, 2);
		printf("Count of terms = %d \t", num);
		printf("Value = %lf \t", value);
		printf("The difference between the estimate and the standard value  = %lf\n", (fabs(value - standard)));
		num = 1;
	}
}

void exp_2case() {
	double x; int func; double acc; int N;
	double standard; double value;

	printf("Input X: ");
	scanf_s("%lf", &x);
	printf("Input number of experiments (NMax - from 1 to 25): ");
	scanf_s("%d", &N);
	standard = exp(x);
	printf("Standard = %lf\n", standard);
	for (int i = 1; i <= N; i++) {
		value = exp_t(x, 0.000001, i, 2);
		printf("Count of terms = %d \t", num);
		printf("Value = %lf \t", value);
		printf("The difference between the estimate and the standard value  = %lf\n", (fabs(value - standard)));
		num = 1;
	}
}

void asinh_2case() {
	double x; int func; double acc; int N;
	double standard; double value; int x_right = 0;
	while (!x_right) {
		printf("Input X ( |x| < 1 ): ");
		scanf_s("%lf", &x);
		if (fabs(x) < 1) {
			x_right = 1;
		}
		else {
			printf("Wrong X. Please, repeat.\n");
		}
	}
	printf("Input number of experiments (NMax - from 1 to 25): ");
	scanf_s("%d", &N);
	standard = asinh(x);
	printf("Standard = %lf\n", standard);
	for (int i = 1; i <= N; i++) {
		num = 0;
		value = asinh2_t(x, 0.000001, i, 2);
		printf("Count of terms = %d \t", num);
		printf("Value = %lf \t", value);
		printf("The difference between the estimate and the standard value  = %lf\n", (fabs(value - standard)));
		
	}
}


int main() {
	int us_choice; double standard; double value;
	
	printf("Welcome!\n");
	print_menu();
	scanf_s("%d", &us_choice);

	do {
		double x; int func; double acc; int N;
		switch (us_choice) {
		case 1:
			func_menu();
			scanf_s("%d", &func);
			switch (func) {
			case 1:
				sin_1case();

				break;
			case 2:
				cos_1case();

				break;
			case 3:
				exp_1case();

				break;
			case 4:
				asinh_1case();

				break;
			}
			break;
		case 2:
			func_menu();
			scanf_s("%d", &func);
			switch (func) {
			case 1:
				sin_2case();

				break;
			case 2:
				cos_2case();

				break;
			case 3:
				exp_2case();

				break;
			case 4:
				asinh_2case();

				break;
			}

			break;
		}
		print_menu();
		scanf_s("%d", &us_choice);
	} while (us_choice != 0);


	return 0;
}
