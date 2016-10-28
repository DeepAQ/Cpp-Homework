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
    string s;
    cin >> s;
    struct Node
    {
        int val = 0;
        Node *parent;
        Node *left;
        Node *right;
    } root;

    int a = 0;
    Node *ptr;
    ptr = &root;
    for (char c : s) {
        if (c >= '0' && c <= '9')
            a = a * 10 + (c-'0');
        else switch (c) {
            case '(':
                if (a>0) ptr->val = a;
                a = 0;
                ptr->left = new Node;
                ptr->left->parent = ptr;
                ptr = ptr->left;
                break;
            case ',':
                if (a>0) ptr->val = a;
                a = 0;
                ptr->parent->right = new Node;
                ptr->parent->right->parent = ptr->parent;
                ptr = ptr->parent->right;
                break;
            case ')':
                if (a>0) ptr->val = a;
                a = 0;
                ptr = ptr->parent;
        }
    }

    ptr = &root;
    vector<Node*> v;
    a = 0;
    while (true) {
        while (ptr->val) {
            v.push_back(ptr);
            ptr = ptr->left;
        }
        if (!v.size())
            break;
        ptr = *(v.end()-1);
        v.pop_back();
        if (a > ptr->val) {
            cout << 0;
            return 0;
        }
        a = ptr->val;
        ptr = ptr->right;
    }
    cout << 1;
    return 0;
}
