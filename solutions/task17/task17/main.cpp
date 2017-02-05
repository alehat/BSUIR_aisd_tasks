#include <iostream>

using namespace std;

int main() {
	long n, m, x1, x2, y1, y2;
	cin >> n >> m >> x1 >> y1 >> x2 >> y2;
	long strip_x = min(x1, x2);
	long strip_y = min(y1, y2);
	x1 -= strip_x - 1; x2 -= strip_x - 1;
	y1 -= strip_y - 1; y2 -= strip_y - 1;
	n = max(x1, x2);
	m = max(y2, y2);
	if (x1 == x2 || y1 == y2 || x1 - y1 == x2 - y2 || x1 + y1 == x2 + y2) {
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
	}
	return 0;
}