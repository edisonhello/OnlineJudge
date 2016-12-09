#include <iostream>
using namespace std;

struct Node {
  int r;
  Node *ch[2];
  Node() {
    ch[0] = ch[1] = NULL;
  }
  Node(Node* node) {
    ch[0] = node->ch[0];
    ch[1] = node->ch[1];
    r = node->r;
  }
};

int main() {

}
