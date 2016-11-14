/*
 * main.cpp
 *
 *  Created on: 2016Äê11ÔÂ14ÈÕ
 *      Author: soft
 */

#include <iostream>

using namespace std;

void fill_space(int *m, int start, int end, int num) {
    for (int i = start; i <= end; i++)
        m[i] = num;
}

int main()
{
    int n, size, k, clear = 0;
    cin >> n >> size;
    int *pos = new int[n+1];
    int *kn = new int[n+1];
    fill_space(pos, 0, n, -1);

    for (int i = 1; i <= n; i++) {
        cin >> k;
        kn[i] = k;
        if (k == 0 || k > size) {
            cout << "SKIP: " << i << " " << k << endl;
            continue;
        }
        while (pos[i] < 0) {
            int start = 0, min = size, j = 0;
            for (int x = clear+1; x < i; x++) {
                if (pos[x] >= 0 && pos[x] < min) {
                    min = pos[x];
                    j = x;
                }
            }
            if (min >= k) {
                pos[i] = 0;
            } else {
                for (int x = j+1; x < i; x++) {
                    if (pos[x]-pos[x-1]-kn[x-1] >= k) {
                        pos[i] = pos[x-1] + kn[x-1];
                    }
                }
            }
            if (pos[i] < 0) {
                j = i-1;
                while (pos[j] < 0)
                    j--;
                if (size - pos[j] - kn[j] >= k) {
                    pos[i] = pos[j] + kn[j];
                    for (int x = clear+1; x < i; x++) {
                        if (pos[x] >= pos[i] && pos[x] < pos[i] + kn[i]) {
                            pos[x] = -1;
                            clear = x;
                        }
                    }
                } else {
                    clear++;
                    pos[clear] = -1;
                }
            }
        }
        //cout << "Finished " << i << " " << k << endl;
    }

    for (int i = 1; i <= n; i++)
        if (pos[i] >= 0)
            cout << i << " " << pos[i] << endl;
    return 0;
}
