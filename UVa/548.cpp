#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <sstream>
using namespace std;

struct Node {
    int data;
    struct Node *lchild, *rchild;
};

int index(vector<int>, int);
void buildTree(Node*, vector<int>, vector<int>);
void test(Node*);
void dfs(Node*, int, int*, int*);

int main() {
    vector<int> inOrder, postOrder;
    string s1, s2;
    while (getline(cin, s1)) {
        inOrder.clear();
        postOrder.clear();
        getline(cin, s2);
        istringstream is1(s1);
        istringstream is2(s2);
        for (int n; is1 >> n;) {
            inOrder.push_back(n);
        }
        for (int n; is2 >> n;) {
            postOrder.push_back(n);
        }
        int min = 2000000000;
        int minLeaf;
        Node* root = new Node;
        buildTree(root, inOrder, postOrder);
        dfs(root, 0, &min, &minLeaf);
        // test(root);
        cout << minLeaf << endl;
        delete root;
    }
    return 0;
}

int index(vector<int> vec, int n) {
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] == n) return i;
    }
    return -1;
}

vector<int> slice(const vector<int>& v, int start=0, int end=-1) {
    int oldlen = v.size();
    int newlen;

    if (end == -1 or end >= oldlen){
        newlen = oldlen-start;
    } else {
        newlen = end-start;
    }

    vector<int> nv(newlen);

    for (int i=0; i<newlen; i++) {
        nv[i] = v[start+i];
    }
    return nv;
}

void buildTree(Node* root, vector<int> inOrder, vector<int> postOrder) {
    if (root) {
        int mid = index(inOrder, postOrder.back());
        root->data = postOrder.back();
        if (inOrder.size() == 1) {
            root->lchild = NULL;
            root->rchild = NULL;
        } else if (inOrder.size() == 2) {
            if (mid == 1) {
                root->lchild = new Node;
                root->rchild = NULL;
                buildTree(root->lchild, slice(inOrder, 0, 1), slice(postOrder, 1, 2));
            } else {
                root->rchild = new Node;
                root->lchild = NULL;
                buildTree(root->rchild, slice(inOrder, 1, 2), slice(postOrder, 0, 1));
            }
        } else {
            root->lchild = new Node;
            root->rchild = new Node;
            buildTree(root->rchild, slice(inOrder, mid + 1, inOrder.size()), slice(postOrder, mid, postOrder.size() - 1));
            buildTree(root->lchild, slice(inOrder, 0, mid), slice(postOrder, 0, mid));
        }
    }
}

void test(Node* root) {
    if (root) {
        cout << root->data << ' ';
        test(root->lchild);
        test(root->rchild);
    }
}

void dfs(Node* root, int sum, int* min, int* minLeaf) {
    sum += root->data;
    if (!root->lchild && !root->rchild) {
        if (sum < *min) {
            *min = sum;
            *minLeaf = root->data;
        }
    } else if (!root->rchild) {
        dfs(root->lchild, sum, min, minLeaf);
    } else if (!root->lchild) {
        dfs(root->rchild, sum, min, minLeaf);
    } else {
        dfs(root->lchild, sum, min, minLeaf);
        dfs(root->rchild, sum, min, minLeaf);
    }
}
