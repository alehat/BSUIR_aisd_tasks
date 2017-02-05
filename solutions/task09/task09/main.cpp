#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	stack<long> s;
	long N;
	cin >> N;
	long long result = 0;
	for (long i = 0; i < N; ++i) {
		long t;
		cin >> t;
		if (s.empty() || s.top() > t) {
			s.push(t);
		} else {
			if (t == s.top())
				continue;
			long q = s.top();
			s.pop();
			while (!s.empty() && s.top() <= t) {
				result += (long long)(s.top() - q);
				q = s.top();
				s.pop();
			}
			result += (long long)(t - q);
			s.push(t);
		}
	}
	if (!s.empty()) {
		long q = s.top();
		s.pop();
		while (!s.empty()) {
			result += (long long)(s.top() - q);
			q = s.top();
			s.pop();
		}
	}
	cout << result << endl;
	return 0;
}