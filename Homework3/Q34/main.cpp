/*
 * main.cpp
 *
 *  Created on: 2016年10月26日
 *      Author: adn55
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    vector<int> v;

    cin >> n >> m;
    for (int i=0; i<n; i++) {
        v.push_back(i);
    }

    int x = m;
    for (int i=0; i<n-1; i++) {
		x += 2;
		x %= v.size();
		v.erase(v.begin() + x);
	}
    cout << v[0];
    return 0;
}
