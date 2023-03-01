#include <stdio.h>
#include <math.h>

void eq() {
	printf("There are two functions:\n\t1) f(x) = cos(t / x) - 2 * sin(1 / x) + 1 / x\n\t2) f(x) = sin(log(x)) - cos(log(x)) + t * log(x)\n");	
	printf("Please choose which one of them you want to calculate\n");
	printf("\nEnter 1 to calculate the first function or enter 2 to culculate the second function: ");
}

void method() {
	printf("\nYou can use on of two methods given to calculate your function:\n\t1) The halving method\n\t2) The Nelson method\n\n");
	printf("If you want to calculate using halving method enter 1\n");
	printf("If you want to calculate using the Newton method enter 2\n\n");
	printf("\nPlease enter 1 or 2: ");
}

float eps(float* e) {
	return *e = 1 / pow(10, *e);
}

float f1(float x, float t) {
	return (cos(t / x) - 2 * sin(1 / x) + 1 / x);
}

float f2(float x, float t) {
	return (sin(log(x)) - cos(log(x)) + t * log(x));
}

float half_method(float a, float b, float t, float eps, float(*f)(float, float)) {
	float x = (a + b) / 2;
	while (fabs(b - a) > eps) {
		x = (a + b) / 2;
		(f(a, t) * f(x, t) > 0) ? (a = x) : (b = x);
	}
	return x;
}

float get_def(float x, float t, float eps, float(*f)(float, float)) {
	return ((f(x + eps, t) - f(x, t)) / eps);
}

float Newton_method(float a, float b, float t, float eps, float(*f)(float, float)) {
	float x = 0;
	(x == 0) ? (x = a) : (x = b);
	float delta = f(x, t) / get_def(x, t, eps, f);
	x -= delta;
	while (fabs(delta) > eps) {
	delta = f(x, t) / get_def(x, t, eps, f);
	x -= delta;
	}
	return x;
}

void printAnswer(float answer, float a, float b, float eps) {
	(answer >= (a + eps) && answer <= (b - eps)) ? printf("\nx = %f\n", answer) : printf("\nCan't find the solution\n");
}

int main() {

	float a, b, t, e, answer;
	int choice1, choice2;

	eq();
	scanf("%d", &choice1);
	printf("\nEnter the start point of the interval: ");
	scanf("%f", &a);
	printf("\nEnter the end point of the interval: ");
	scanf("%f", &b);
	printf("\nEnter t: ");
	scanf("%f", &t);
	printf("\nEnter epsilon: ");
	scanf("%f", &e);	
	method();
	scanf("%d", &choice2);
	(eps >= 1) ? eps(&e) : e;

	if (choice1 == 1) {
		if (choice2 = 1) {
			answer = half_method(a, b, t, e, f1);
			printAnswer(answer, a, b, e);
		}
		else if (choice2 == 2) {
			answer = Newton_method(a, b, t, e, f1);
			printAnswer(answer, a, b, e);
		}
		else {
			printf("\nYou can choose only 1 or 2\n");
			return 1;
		}
	}
	else if (choice1 == 2) {
		if (choice2 == 1) {
			answer = half_method(a, b, t, e, f2);
			printAnswer(answer, a, b, e);
		}
		else if (choice2 == 2) {
			answer = Newton_method(a, b, t, e, f2);
			printAnswer(answer, a, b, e);
		}
		else {
			printf("\nYou can choose only 1 or 2\n");
			return 1;
		}
	}
	else {
		printf("\nYou can choose only 1 or 2\n");
		return 1;
	}	
	return 0;
}
