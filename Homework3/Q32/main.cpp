/*
 * main.cpp
 *
 *  Created on: 2016年10月26日
 *      Author: adn55
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void print(ListNode *first) {
    ListNode *ptr = first;
    while (ptr != NULL) {
        cout << ptr->val << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

ListNode* ins(ListNode *first, int v, int k) {
    if (first == NULL) k = 0;
    ListNode *ptr;
    if (k == 0) {
        ptr = new ListNode(v);
        ptr->next = first;
        return ptr;
    }
    ptr = first;
    for (int i=1; i<k; i++) {
        if (ptr->next == NULL)
            break;
        ptr = ptr->next;
    }
    ListNode *tmp = ptr->next;
    ptr->next = new ListNode(v);
    ptr->next->next = tmp;
    return first;
}

ListNode* del(ListNode *first, int v) {
    if (first == NULL) return first;
    ListNode *ptr = first;
    ListNode *tmp = NULL;
    while (ptr != NULL) {
        if (ptr->val == v) {
            if (ptr->next != NULL) {
                ptr->val = ptr->next->val;
                ptr->next = ptr->next->next;
            } else {
                if (tmp != NULL)
                    tmp->next = NULL;
                else
                    first = ptr->next;
                break;
            }
        } else {
            tmp = ptr;
            ptr = ptr->next;
        }
    }
    return first;
}

ListNode* rotate(ListNode *first, int k) {
    if (first == NULL) return first;
    ListNode *ptr = first;
    ListNode *ptr2 = ptr;
    ListNode *ptr3 = NULL;
    while (ptr2->next != NULL)
        ptr2 = ptr2->next;
    for (int i=0; i<k; i++) {
        ptr3 = ptr;
        while (ptr3->next != ptr2)
            ptr3 = ptr3->next;
        ptr3->next = NULL;
        ptr2->next = ptr;
        ptr = ptr2;
        ptr2 = ptr3;
    }
    return ptr;
}

int main() {
    // init
    int a, b, c, op;
    ListNode *ptr = new ListNode(0);
    ListNode *list = ptr;
    cin >> a;
    while (a != -1) {
        ptr->next = new ListNode(a);
        ptr = ptr->next;
        cin >> a;
    }
    list = list->next;
    // read operations
    cin >> a;
    for (int i=0; i<a; i++) {
        cin >> op;
        switch (op) {
            case 0:
                print(list);
                break;
            case 1:
                cin >> b >> c;
                list = ins(list, b, c);
                break;
            case 2:
                cin >> b;
                list = del(list, b);
                break;
            case 3:
                cin >> b;
                list = rotate(list, b);
                break;
            default:
                break;
        }
    }
    return 0;
}
