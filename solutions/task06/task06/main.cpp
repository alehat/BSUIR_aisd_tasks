#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Edge{
	long from;
	long to;
	long weight;
	Edge(long a, long b, long c):from(a),to(b),weight(c) { }
};

int main() {
	//freopen("input.txt", "r", stdin);
	long N, M;
	const long MAXN = 100000;
	const long long LINF = 21000000000000;
	cin >> N >> M;
	vector<vector<Edge *>> g;
	g.resize(N);
	vector<long long> dis(N, LINF);
	for (long i = 0; i < M; ++i) {
		long a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		g[a].push_back(new Edge(a, b, c));
		g[b].push_back(new Edge(b, a, c));
	}
	long A, B;
	cin >> A >> B;
	A--; B--;
	dis[A] = 0;
	queue<Edge *> edges;
	for (long i = 0; i < g[A].size(); ++i) {
		edges.push(g[A][i]);
	}
	while (!edges.empty()) {
		Edge * e = edges.front();
		if (dis[e->to] > dis[e->from] + e->weight) {
			dis[e->to] = dis[e->from] + e->weight;
			for (long i = 0; i < g[e->to].size(); ++i)
				edges.push(g[e->to][i]);
		}
		edges.pop();
	}
	cout << dis[B] << endl; 
	return 0;
}