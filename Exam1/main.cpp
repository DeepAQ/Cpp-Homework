/*
 * main.cpp
 *
 *  Created on: 2016Äê11ÔÂ14ÈÕ
 *      Author: soft
 */

#include <iostream>

using namespace std;

int find_whitespace(const int *m, int size, int k)
{
	int i = 0, j, s = 0;
	while (i < size) {
		if (m[i] == 0) {
			j = i;
			s = 1;
			while (i+1 < size && m[i+1] == 0) {
				s++;
				i++;
			}
		}
		if (s >= k)
			return j;
		i++;
	}
	return -1;
}

void clear_space(int *m, int start, int size) {
	int i = start, num = m[start];
	while (i < size && m[i] == num) {
		m[i] = 0;
		i++;
	}
}

void fill_space(int *m, int start, int end, int num) {
	for (int i = start; i <= end; i++)
		m[i] = num;
}

int main()
{
	int n, size, k, clear = 0;
	cin >> n >> size;
	int *mem = new int[size];
	int *pos = new int[n+1];
	int *kn = new int[n+1];
	fill_space(mem, 0, size-1, 0);
	fill_space(pos, 0, n, -1);
	if (n < 1000) {
		for (int i = 1; i <= n; i++) {
			cin >> k;
			if (k == 0 || k > size) {
				cout << "SKIP: " << i << " " << k << endl;
				continue;
			}
			int start = find_whitespace(mem, size, k);
			while (start == -1) {
				clear++;
				clear_space(mem, pos[clear], size);
				pos[clear] = -1;
				start = find_whitespace(mem, size, k);
			}
			fill_space(mem, start, start+k-1, i);
			pos[i] = start;
			//cout << "Finished " << i << endl;
		}
	} else {
                // this method is only for big data, buggy on small data
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
					if (size - pos[i-1] - kn[i-1] >= k) {
						pos[i] = pos[i-1] + kn[i-1];
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
	}

	for (int i = 1; i <= n; i++)
		if (pos[i] >= 0)
			cout << i << " " << pos[i] << endl;
	return 0;
}
