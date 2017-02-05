#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	long y;
	cin >> y;
	if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}