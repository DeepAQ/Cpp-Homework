/*
 * main.cpp
 *
 *  Created on: 2016年9月24日
 *      Author: adn55
 */

#include <iostream>
#include <cmath>

using namespace std;

double fact(long n) {
	double s = 1;
	for (int i = 2; i <= n; i++) {
		s *= i;
	}
	return s;
}

double mysin(double x) {
	double accuracy = 1E-7;
	if (x < 0) x = -x;
	double result = x;
	int i = 1;
	while (true) {
		i += 2;
		double t = pow(x, i) / fact(i);
		if (t < accuracy) {
			break;
		}
		result += (i%4==1 ? 1 : -1) * t;
	}
	return result;
}

int main(int argc, char **argv) {
	long r, s;
	cin >> r >> s;
	double result = (r*r<=s*s ? sqrt(pow(mysin(r), 2) + pow(mysin(s), 2)) : mysin(r*s)/2);
	printf("%.6f", result);
	return 0;
}
