/*
 * main.cpp
 *
 *  Created on: 2016年10月26日
 *      Author: adn55
 */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, a;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> a;
        v.insert(v.end(), a);
    }
    bool first = true;
    for (unsigned i = 0; i < v.size()-2; i++) {
        if (i>0 && v[i]==v[i-1])
            continue;
        for (unsigned j = i+1; j < v.size()-1; j++) {
            if (j>i+1 && v[j]==v[j-1])
                continue;
            for (unsigned k = j+1; k < v.size(); k++) {
                if (k>j+1 && v[k]==v[k-1])
                    continue;
                if (!(v[i] + v[j] + v[k])) {
                    if (!first)
                        cout << endl;
                    first = false;
                    cout << v[i] << " " << v[j] << " " << v[k];
                }
            }
        }
    }
    return 0;
}
