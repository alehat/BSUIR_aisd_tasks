#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

int main() {
	long num;
	cin >> num;
	vector<char> number;
	while (num > 0) {
		number.push_back(num % 10);
		num /= 10;
	}
	reverse(number.begin(), number.end());
	if (next_permutation(number.begin(), number.end())) {
		for (long i = 0; i < number.size(); ++i) 
			cout << (int)number[i];
		cout << endl;
	} else {
		cout << "-1" << endl;
	}
	return 0;
}