/*
 * main.cpp
 *
 *  Created on: 2016年10月26日
 *      Author: adn55
 */

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

void convert(vector<int> &v, int left, int right) {
    if (left == right) {
        cout << v[left] << " ";
        return;
    }
    if (left > right) {
        return;
    }
    int mid = (left + right + 1) / 2;
    convert(v, left, mid-1);
    convert(v, mid+1, right);
}

int main() {
    vector<int> v;
    string s;
    getline(cin, s);
    istringstream iss(s);
    int a = 0;
    while (iss >> a)
        v.push_back(a);
    convert(v, 0, v.size()-1);
    return 0;
}
