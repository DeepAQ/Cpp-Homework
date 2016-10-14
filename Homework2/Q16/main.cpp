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
	vector<int> v;
	int n, a;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		if (v.size()<2 || a!=*(v.end()-1) || a!=*(v.end()-2))
			v.insert(v.end(), a);
	}

	cout << v.size() << endl;
	if (v.size() > 0)
	{
		cout << v[0];
		for (unsigned int i = 1; i < v.size(); i++)
			cout << " " << v[i];
	}
	return 0;
}
