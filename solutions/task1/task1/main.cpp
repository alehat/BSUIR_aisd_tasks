#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long N;
vector<vector<long> > tree;
vector<pair<long, long> > dyn;

void dfs(long idx, long from) {
	if (tree[idx].size() == 1 && from != -1) {
		dyn[idx] = make_pair(0, 0);
		return;
	}

	long S = 0;

	for (long i = 0; i < tree[idx].size(); ++i) {
		if (tree[idx][i] == from)
			continue;
		dfs(tree[idx][i], idx);
		S += dyn[tree[idx][i]].second;
	}

	long max_f1 = -1;
	for (long i = 0; i < tree[idx].size(); ++i) {
		if (tree[idx][i] == from)
			continue;
		long partial_f1 = S - dyn[tree[idx][i]].second + dyn[tree[idx][i]].first;
		if (partial_f1 > max_f1)
			max_f1 = partial_f1;
	}
	dyn[idx] = make_pair(S, max_f1 + 1);
	return;
}

int main() {
	//freopen("input.txt", "r", stdin);
	cin >> N;
	tree.resize(N);
	dyn.resize(N);
	for (long i = 0; i < N - 1; ++i) {
		long t1, t2;
		cin >> t1 >> t2;
		t1--; t2--;
		tree[t1].push_back(t2);
		tree[t2].push_back(t1);
	}
	dfs(0, -1);
	cout << max(dyn[0].first, dyn[0].second);
	return 0;
}
