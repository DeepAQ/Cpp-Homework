/*
 * main.cpp
 *
 *  Created on: 2016年10月14日
 *      Author: adn55
 */

#include <iostream>
#include <vector>

using namespace std;

bool check(vector<int>& v, int left, int right)
{
	while (left < right)
	{
		if (v[left] != v[right])
			return false;
		left++;
		right--;
	}
	return true;
}

int main()
{
	int n, a;
	cin >> n >> a;

	vector<int> v;
	if (a == 0) v[0] = 0;
	while (a > 0)
	{
		v.insert(v.begin(), a % 10);
		a /= 10;
	}

	int max = 1;
	for (int i = 0; i < n; i++)
		for (int j = i+1; j < n; j++)
			if (check(v, i, j) && j-i+1>max)
				max = j-i+1;
	cout << max;
	return 0;
}
