#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

struct segment {
	long l;
	long r;
	long n;
};

bool compare(segment a, segment b) {
	if (a.l < b.l)
		return true;
	if (a.l == b.l)
		return (a.r < b.r);
	return false;
}

int main() {
	long N, M;
	cin >> N >> M;
	vector<segment> segs(M);
	for (long i = 0; i < M; ++i) {
		cin >> segs[i].l >> segs[i].r >> segs[i].n;
	}
	sort(segs.begin(), segs.end(), compare);
	for (long i = 0; i < M - 1; ++i) {
		segs[i].r = min(segs[i].r, segs[i + 1].l - 1);
	}
	cout <<sort<<endl;
	return 0;
}
