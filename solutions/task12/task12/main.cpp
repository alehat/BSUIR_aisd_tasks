#include <iostream>

using namespace std;

int main() {
	long long N;
	cin >> N;
	if (N % 10 == 0) 
		cout << "NO" << endl;
	else
		cout << N % 10 << endl;
	return 0;
}