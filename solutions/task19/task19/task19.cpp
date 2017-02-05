#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	long N;
	bool dp1     = false; //1021
	bool dp2     = false; //1031
	bool dp3     = false; //1033
	bool dp1p2   = false; //1021*1031
	bool dp1p3   = false; //1021*1033
	bool dp2p3   = false; //1031*1033
	bool dp1p2p3 = false; //1087388483
	cin >> N;
	for (int i = 0; i < N; ++i) {
		long num;
		cin >> num;
		if (num == 1021)
			dp1 = true;
		if (num == 1031)
			dp2 = true;
		if (num == 1033)
			dp3 = true;
		if (num == 1021*1031)
			dp1p2 = true;
		if (num == 1021*1033)
			dp1p3 = true;
		if (num == 1031*1033)
			dp2p3 = true;
		if (num == 1087388483)
			dp1p2p3 = true;
	}
	if (  (dp1 && dp2 && dp3) ||
	      (dp1p2 && dp3)      ||
		  (dp1p3 && dp2)      ||
		  (dp2p3 && dp1)      ||
		  (dp1p2p3)               )
		cout << "YES";
	else
		cout << "NO";
	return 0;
}