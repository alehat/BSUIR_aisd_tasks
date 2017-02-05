#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<long> snm;
vector<long> snm_rank;
long set_count;

long get_set(long v) {
	if (v == snm[v])
		return v;
	snm[v] = get_set(snm[v]);
	return snm[v];
}

void union_set(long a, long b) {
	long set_a = get_set(a);
	long set_b = get_set(b);
	if (set_a != set_b) {
		set_count--;
		if (snm_rank[set_a] < snm_rank[set_b])
			swap(set_a, set_b);
		snm[set_b] = set_a;
		if (snm_rank[set_a] == snm_rank[set_b])
			++snm_rank[set_a];
	}
}

/*vector<vector<int>> g;
vector<bool> used;

void dfs(long v) {
	used[v] = true;
	for (long j = 0; j < g[v].size(); ++j) {
		if (!used[g[v][j]])
			dfs(g[v][j]);
	}
}*/

int main() {
	long N;
	long M;
	cin >> N >> M;
	set_count = N - 1;
	snm.resize(N);
	snm_rank.resize(N);
	/*g.resize(N);
	used.resize(N);*/
	for (long i = 0; i < N; ++i) {
		snm[i] = i;
		snm_rank[i] = 0;
		//used[i] = false;
	}

	for (long i = 0; i < M; ++i) {
		long u, v;
		cin >> u >> v;
		u--; v--;
		union_set(u, v);
		/*g[u].push_back(v);
		g[v].push_back(u);*/
	}

	/*long comp_count = 0;
	for (long i = 0; i < N; ++i) {
		if (!used[i]) {
			dfs(i);
			++comp_count;
		}
	}*/

	cout << set_count;
	
	/*if (set_count < 1)
		cout << 0; 
	else
		cout << set_count;*/
	
	return 0;
}