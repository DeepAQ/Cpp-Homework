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
	bool first = true, desc = false;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		if (v.size()>=1 && a<*(v.end()-1))
			desc = true;
		v.insert(v.end(), a);
	}

	cin >> n;
	vector<int>::iterator t = v.begin();
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		while (t!=v.end() && ((!desc && *t<=a) || (desc && *t>=a)))
		{
			if (!first) cout << " ";
			first = false;
			cout << *t;
			t++;
		}
		if (!first) cout << " ";
		first = false;
		cout << a;
	}
	while (t!=v.end())
	{
		if (!first) cout << " ";
		first = false;
		cout << *t;
		t++;
	}

	return 0;
}
