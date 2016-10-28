/*
 * main.cpp
 *
 *  Created on: 2016年10月27日
 *      Author: adn55
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, a;
    cin >> n;
    vector<int> v;
    for (int i=0; i<n; i++) {
        cin >> a;
        v.insert(v.end(), a);
    }
    int min = 1, max = n-1;
    while (min < max) {
        int mid = (min + max)/2;
        int s = 0;
        for (int a : v)
            if (a <= mid) s++;
        if (s > mid)
            max = mid;
        else
            min = mid + 1;
    }
    cout << min;
    return 0;
}
