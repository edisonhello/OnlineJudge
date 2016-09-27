#include "lib1168.h"
#include <queue>
#include <vector>
using namespace std;

struct Node {
  int n;
  int pos;
  bool operator < (const Node& node) const {
    return n < node.n;
  }
  bool operator > (const Node& node) const {
    return n > node.n;
  }
  Node(int n, int pos): n(n), pos(pos) {}
  Node() {}
};

priority_queue<Node, vector<Node>, less<Node> > pq1;
priority_queue<Node, vector<Node>, greater<Node> > pq2;
vector<bool> v(1000010, 0);
int p = 0;

void pop_big() {
  while (v[pq1.top().pos]) {
    pq1.pop();
  }
  v[pq1.top().pos] = true;
  pq1.pop();
}

void pop_small() {
  while (v[pq2.top().pos]) {
    pq2.pop();
  }
  v[pq2.top().pos] = true;
  pq2.pop();
}

void push(int s) {
  pq1.push(Node(s, p));
  pq2.push(Node(s, p++));
}

int big() {
  while (v[pq1.top().pos]) {
    pq1.pop();
  }
  return pq1.top().n;
}

int small() {
  while (v[pq2.top().pos]) {
    pq2.pop();
  }
  return pq2.top().n;
}
