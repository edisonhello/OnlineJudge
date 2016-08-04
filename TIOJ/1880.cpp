#include <iostream>
#include <cstdio>
using namespace std;

struct node {
	int number;
	node* frd;
	int color; //0->black; 1->red;
	int visit = 0;
}

node people[100001];

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; ++i) {
		int p, q;
		scanf("%d %d", &p, &q);
			if (!people[p] && !people[q]) {
				people[p].number = p;
				people[q].number = q;
				people[p].frd = &people[q];
				people[q].frd = &people[p];
				people[p].color = 0;
				people[q].color = 1;
			}
			else if (!people[p] && people[q]) {
				people[p].number = p;
				people[p].frd = &people[q];
				people[p].color = people[q].color == 0 ? 1 : 0;
			}
			else if (people[p] && !people[q]) {
				people[q].number = q;
				people[q].frd = &people[p];
				people[q].color = people[p].color == 0 ? 1 : 0;
			}
	}
	int group = 0;
	int idx = 0;
	while (true) {
		if (people[idx].color == people[idx].frd->color) {
			group = 0;
			break;
		}
		else if (people[idx].frd->visit == 1) {
			group++;
			idx = 
		}
	}

}