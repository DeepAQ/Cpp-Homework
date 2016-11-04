/*
 * main.cpp
 *
 *  Created on: 2016年10月26日
 *      Author: adn55
 */

#include <iostream>
#include <vector>

using namespace std;

struct Matrix {
    int depth;
    vector<int> sizes;
    vector<int> raw_data;
    Matrix(int depth) : depth(depth) {};
    Matrix() {};
};

void print(const Matrix *a) {
    for (int t : a->raw_data)
        cout << t << " ";
    cout << endl;
}

Matrix* add(const Matrix *a, const Matrix *b) {
//    if (a->raw_data.size() != b->raw_data.size())
//        return;
    Matrix *t = new Matrix(a->depth);
    t->sizes = a->sizes;
    for (unsigned i=0; i<a->raw_data.size(); i++)
        t->raw_data.push_back(a->raw_data[i] + b->raw_data[i]);
    return t;
}

vector<int> raw_multiply(const Matrix *a, const Matrix *b) {
//    if (a->sizes[1] != b->sizes[0])
//        return;
    vector<int> v;
    for (int i=0; i<a->sizes[0]; i++) {
        for (int j=0; j<a->sizes[0]; j++) {
            int sum = 0;
            for (int k=0; k<a->sizes[1]; k++)
                sum += a->raw_data[i*a->sizes[1] + k] * b->raw_data[k*b->sizes[1] + j];
            v.push_back(sum);
        }
    }
    return v;
}

vector<int> multiply(const Matrix *a, const Matrix *b, int depth) {
//    if (a->depth == 0 || b->depth == 0)
//        return;
//    if (a->sizes[1] != b->sizes[0])
//        return;
    if (depth == 1)
        return raw_multiply(a, b);
    vector<int> v;
    if (depth == 0) {
    	v.push_back(a->raw_data[0] * b->raw_data[0]);
    	return v;
	}
    for (int i=0; i<a->sizes[0]; i++) {
        for (int j=0; j<a->sizes[0]; j++) {
            vector<int> tv;
            for (int k=0; k<a->sizes[1]; k++) {
                Matrix *tmpa = new Matrix(depth-1);
                Matrix *tmpb = new Matrix(depth-1);
                // a[i][k] + b[k][j]
                int as=1, bs=1;
                for (unsigned x=2; x<a->sizes.size(); x++) {
                    tmpa->sizes.push_back(a->sizes[x]);
                    as *= a->sizes[x];
                }
                for (unsigned x=2; x<b->sizes.size(); x++) {
                    tmpb->sizes.push_back(b->sizes[x]);
                    bs *= b->sizes[x];
                }
                for (int x=(i*a->sizes[1] + k)*as; x<(i*a->sizes[1] + k+1)*as; x++)
                    tmpa->raw_data.push_back(a->raw_data[x]);
                for (int x=(k*b->sizes[1] + j)*bs; x<(k*b->sizes[1] + j+1)*bs; x++)
                    tmpb->raw_data.push_back(b->raw_data[x]);
                vector<int> result = multiply(tmpa, tmpb, depth-1);
                if (k == 0)
                    tv = result;
                else {
                    for (unsigned y=0; y<tv.size(); y++)
                        tv[y] += result[y];
                }
            }
            v.insert(v.end(), tv.begin(), tv.end());
        }
    }
    return v;
}

int main() {
    int n, depth, row, col, t;
    vector<Matrix*> ms;

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> depth;
        Matrix *tmp = new Matrix;
        if (depth == 0) {
            tmp->depth = -1;
            ms.push_back(tmp);
            continue;
        }
        int total = 1, real_depth = 0;
        for (int j=0; j<depth; j++) {
            cin >> row >> col;
            if (row == 1 && col == 1)
                continue;
            real_depth++;
            total *= row * col;
            tmp->sizes.push_back(row);
            tmp->sizes.push_back(col);
        }
        tmp->depth = real_depth;
        for (int j=0; j<total; j++) {
            cin >> t;
            tmp->raw_data.push_back(t);
        }
        ms.push_back(tmp);
    }

    int op, x, y, z;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> op;
        switch (op) {
            case 0:
                cin >> x;
                print(ms[x]);
                break;
            case 2:
                cin >> x >> y >> z;
                while (z >= ms.size())
                    ms.push_back(NULL);
                ms[z] = add(ms[x], ms[y]);
                break;
            case 3:
                cin >> x >> y >> z;
                while (z >= ms.size())
                    ms.push_back(NULL);
                vector<int> result = multiply(ms[x], ms[y], ms[x]->depth);
                Matrix *t = new Matrix();
                int depth = ms[x]->depth;
                for (int j=0; j<ms[x]->depth; j++) {
                    int a = ms[x]->sizes[j*2];
                    int b = ms[y]->sizes[j*2+1];
                    if (a==1 && b==1) {
                        depth--;
                        continue;
                    }
                    t->sizes.push_back(a);
                    t->sizes.push_back(b);
                }
                t->depth = depth;
                t->raw_data = result;
                ms[z] = t;
                break;
        }
    }
    return 0;
}
