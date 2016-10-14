/*
 * main.cpp
 *
 *  Created on: 2016年10月13日
 *      Author: adn55
 */

#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<int, bool> map;
	int n, a;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		if (map.find(a) != map.end())
		{
			cout << "true";
			return 0;
		}
		else
		{
			map[a] = true;
		}
	}
	cout << "false";
	return 0;
}
