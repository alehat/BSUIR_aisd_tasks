#include <iostream>
#include <vector>
#include <algorithm>

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

int main() {
	//freopen("input.txt", "r", stdin);
	long N;
	long M;
	cin >> N >> M;
	set_count = N - 1;
	snm.resize(N);
	snm_rank.resize(N);
	for (long i = 0; i < N; ++i) {
		snm[i] = i;
		snm_rank[i] = 0;
	}

	for (long i = 0; i < M; ++i) {
		long u, v;
		cin >> u >> v;
		u--; v--;
		union_set(u, v);
	}

	if (set_count > 0)
		cout << -1 << endl;
	else
		cout << (M - N + 1) << endl;
	return 0;
}