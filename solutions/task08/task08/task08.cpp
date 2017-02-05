#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	long N;
	cin >> N;

	vector<long long> els(N);
	for (int i = 0; i < N; ++i) 
		cin >> els[i];
	
	sort(els.begin(), els.end());
	
	long long mul1 = els[0]     * els[1];
	long long mul2 = els[N - 2] * els[N - 1];
	if (mul1 > mul2)
		cout << mul1;
	else
		cout << mul2;

	return 0;
}