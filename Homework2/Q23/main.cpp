/*
 * main.cpp
 *
 *  Created on: 2016年10月14日
 *      Author: adn55
 */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	long long a, avg = 0;
	vector<long long> v;

	cin >> a;
	while (a >= 0)
	{
		v.insert(v.end(), a);
		avg += a;
		cin >> a;
	}

	avg /= v.size();
	cout << avg;
	bool first = true;
	for (unsigned int i = 0; i < v.size(); i++)
		if (v[i] < avg)
		{
			if (first) cout << endl;
			else cout << " ";
			first = false;
			cout << v[i];
		}
	return 0;
}
