#include <iostream>
#include <cstdio>
using namespace std;

struct node {
	int pos;
	int init;
	int level;
	node(int pos, int init, int level) {
		this->pos = pos;
		this->init = init;
		this->level = level;
	}
	node() {}
}

struct block {
	node blocks[25];
	int top[25];
} block;

void mOnto(int a, int b);
void mOver(int a, int b);
void pOnto(int a, int b);
void pOver(int a, int b);

void initilize(int n) {
	for (int i = 0; i < n; ++i) {
		block.blocks[i] = node(i, i, 0);
		block.top[i] = 0;
	}
}

int main(void) {
	int n;
	scanf("%d", &n);
	initilize(n);
	char cmd[15];
	while (true) {
		scanf("%d", &cmd);
		if (cmd[0] == 'm' && cmd[8] == 'n') mOnto(cmd[5] - '0', cmd[12] - '0');
		else if (cmd[0] == 'm' && cmd[8] == 'v') mOver(cmd[5] - '0', cmd[12] - '0');
		else if (cmd[0] == 'p' && cmd[8] == 'n') pOnto(cmd[5] - '0', cmd[12] - '0');
		else if (cmd[0] == 'p' && cmd[8] == 'v') pOver(cmd[5] - '0', cmd[12] - '0');
		else if (cmd[0] == 'q') break;
	}
}

void mOnto(int a, int b) {
	node& tmpa[25];
	node& tmpb[25];
	int Tai = 0, Tbi = 0;
	int pA, pB;
	for (int i = 0; i < n; ++i) {
		if (block.blocks[i].pos == a) {
			if (block.blocks[i].init == a) {
				pA = Tai;
			}
			tmp[Tai++] = block.blocks[i];
		}
	}
	for (int i = 0; i < n; ++i) {
		if (block.blocks[i].pos == b) {
			if (block.blocks[i].init == b) {
				pB = Tbi;
			}
			tmp[Tbi++] = block.blocks[i];
		}
	}
	for (int i = pA + 1; i < Tai; ++i) {
		tmp[i].pos = tmp[i].init;
	}
	for (int i = pB + 1; i < Tbi; ++i) {
		tmp[i].pos = tmp[i].init;
	}
	tmp[pA].pos = block.blocks[b].pos;
}

void mOver(int a, int b) {
	node& tmpa[25];
	int pA;
	for (int i = 0; i < n; ++i) {
		if (block.blocks[i].pos == a) {
			if (block.blocks[i].init == a) {
				pA = Tai;
			}
			tmp[Tai++] = block.blocks[i];
		}
	}
	for (int i = pA + 1; i < Tai; ++i) {
		tmp[i].pos = tmp[i].init;
	}
	tmp[pA].pos = block.blocks[b].pos;
}

void pOnto(int a, int b) {
	
}