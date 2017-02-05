#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	string s;
	getline(cin, s);
	long z = 0;
	while (s[s.length() - z - 1] == '\n' || s[s.length() - z - 1] == '\r')
		z++;
	s = s.substr(0, s.length() - z);
	vector<long> d1(s.length(), 0), d2(s.length(), 0);
	
	/*Ladies and gentlemans, Manaker's algorithm*/
	long maxlen = -1;

	long k, l = 0, r = -1, n = s.length();
	for (long i = 0; i < n; ++i) {
		if (i > r) 
			k = 1;
		else 
			k = min(d1[l + r - i], r - i);

		while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) 
			k++;
		d1[i] = k;

		if (i - k >= 0 && i + k < n) {
			long maxstep = min(i - k, n - 1 - i - k);
			long newk = k + maxstep;
			if (2 * newk + 1 > maxlen)
				maxlen = 2 * newk + 1;
		}
		
		if (i + k - 1 > r)
			r = i + k - 1, l = i - k + 1;
	}

	l = 0, r = -1;
	for (long i = 0; i < n; i++) {
		if (i > r) 
			k = 0;
		else 
			k = min(d2[l + r - i + 1], r - i + 1);

		while (i + k < n && i - k - 1 >= 0 && s[i + k] == s[i - k - 1]) 
			k++;
		d2[i] = k;

		if (i - k - 1 >= 0 && i + k < n) {
			long maxstep = min(i - k - 1, n - 1 - i - k);
			long newk = k + 1 + maxstep;
			if (2 * newk > maxlen)
				maxlen = 2 * newk;
		}

		if (i + k - 1 > r)
			l = i - k, r = i + k - 1;
	}

	cout << maxlen << endl;
	return 0;
}