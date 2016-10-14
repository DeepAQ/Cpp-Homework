/*
 * main.cpp
 *
 *  Created on: 2016年10月14日
 *      Author: adn55
 */

#include <iostream>

using namespace std;

int main()
{
	int n, a;
	cin >> n;
	string str[10] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	string str2[10] = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
	string str3[10] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
	// hundred
	a = n / 100;
	cout << str[a];
	if (a > 0)
	{
		cout << " hundred";
		n -= a*100;
		if (n > 0) cout << " and ";
	}
	// ten
	if (n < 10) cout << str[n];
	else if (n>=10 && n<20) cout << str3[n-10];
	else {
		a = n / 10;
		cout << str2[a];
		n -= a*10;
		if (n > 0) cout << " " << str[n];
	}
	return 0;
}
