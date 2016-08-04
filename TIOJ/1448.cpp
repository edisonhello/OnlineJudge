//
// Created by Wayne Tu on 3/7/16.
//


#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#define NULL 0

using namespace std;
struct Node {
    set<int> group;
    Node* next;
    Node* prev;
    Node() {
        this -> next = NULL;
        this -> prev = NULL;
    }
};

void mergeSet (set<int>& before, set<int>& after) {
    after.insert (before.begin(), before.end());
}

void merge (Node* px, Node* py) {
    if (px -> next && px -> prev) {
        if (py -> next && py -> prev) {
            mergeSet (px -> group, py -> group);
        }

        else if (!py -> next && py -> prev) {
            mergeSet (px -> group, py -> group);
            py -> next -> prev = py;
        }

        else if (!py -> next && !py -> prev) {
            mergeSet (px -> group, py -> group);

        }
    }
}