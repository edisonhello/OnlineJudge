#include <iostream>
#include <string>
using namespace std;

struct queue {
	int data[100];
	int f = -1;
	int r = -1;
	void push(int n) {
		data[++r] = n;
	}
	int pop() {
		return data[++f];
	}
	int front() {
		return data[f + 1];
	}
	bool empty() {
		return f == r;
	}
};

queue qn;

int maxI(int n) {
	int idx;
	int max = 0;
	for (int i = 0; i < n; ++i) {
		if (qn.data[i] > max) {
			max = qn.data[i];
			idx = i;
		}
	}
	return idx;
}

int main() {
	int t;
	int n, m;
	int time;
	int job;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		cin >> n >> m;
		memset(qn.data, -1, sizeof(qn.data));
		for (int i = 0; i < n; ++i) {
			cin >> qn.data[i];
		}
		time = 0;
		job = qn.data[m];
		while (true) {
			int max = maxI(n);
			if (qn.data[max] == qn.front()) {
				if (qn.front() == job) {
					qn.pop();
					time++;
					break;
				} else {
					qn.pop();
					time++;
				}
			} else {
				qn.data[max] = -1;
				qn.push(qn.pop());
			}
		}
		cout << time << endl;
	}
	return 0;
}