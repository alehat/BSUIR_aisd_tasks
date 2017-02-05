#include <iostream>
#include <string>
#include <string.h>
#include <map>

#pragma comment(linker, "/STACK:200000000")

using namespace std;

struct automaton_state {
	long len;
	long link;
	long * next;
};

const long MAXLEN = 100000;
long alphabetian[MAXLEN * 52] = {0};
automaton_state states[MAXLEN * 2];
long size, last;
long long dyn[MAXLEN * 2] = {0};

void sa_init() {
	size = last = 0;
	states[0].len = 0;
	states[0].link = -1;
	++size;
	states[0].next = alphabetian;
	for (long i = 1; i < MAXLEN * 2; ++i) {
		states[i].next = states[i - 1].next + 26;
	}
}

void sa_extend(char c) {
	long cur = size++;
	states[cur].len = states[last].len + 1;
	long p;
	for (p=last; p!=-1 && states[p].next[c] == 0; p=states[p].link)
		states[p].next[c] = cur;
	if (p == -1)
		states[cur].link = 0;
	else {
		long q = states[p].next[c];
		if (states[p].len + 1 == states[q].len)
			states[cur].link = q;
		else {
			long clone = size++;
			states[clone].len = states[p].len + 1;
			for (long j = 0; j < 26; ++j) 
				states[clone].next[j] = states[q].next[j];
			states[clone].link = states[q].link;
			for (; p != -1 && states[p].next[c] == q; p = states[p].link)
				states[p].next[c] = clone;
			states[q].link = states[cur].link = clone;
		}
	}
	last = cur;
}

void dfs(long w) {
	dyn[w] = 1;
	for (long i = 0; i < 26; ++i) {
		if (states[w].next[i] > 0) {
			if (dyn[states[w].next[i]] == 0)
				dfs(states[w].next[i]);
			dyn[w] += dyn[states[w].next[i]];
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	char s[MAXLEN + 2];
	scanf("%s", s);
	long len = strlen(s);
	sa_init();
	for (long i = 0; i < len; ++i) {
		sa_extend(s[i] - 'a');
	}
	dfs(0);
	cout << dyn[0] - 1 << endl;
	return 0;
}