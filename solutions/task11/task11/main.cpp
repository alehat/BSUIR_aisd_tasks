#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

const int MODULUS = 1000000007;
vector<long> a;

long long mul(long long a, long long b) {
	long long res = a * b;
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	long N;
	long K;
	cin >> N >> K;
	a.resize(N);
	for (long i = 0; i < N; ++i) {
		long t;
		cin >> t;
		a[i] = t;
	}
	sort(a.begin(), a.end());
	deque<long> d;
	for (long i = 0; i < N; ++i) {
		d.push_front(a[i]);
	}
	long got = 0;
	long long result = 1;
	bool inverse = false;
	if (K % 2 == 1) {
		long num = d.front();
		result = mul(result % MODULUS, num % MODULUS) % MODULUS;
		if (num < 0) {
			inverse = true;
		}
		d.pop_front();
		got++;
	}
	while (got + 2 <= K) {
		long t_t1 = d.front();
		d.pop_front();
		long t_t2 = d.front();
		d.pop_front();
		long long mul_top = mul(t_t1, t_t2);
		if (d.size() > 1) {
			long b_t1 = d.back();
			d.pop_back();
			long b_t2 = d.back();
			d.pop_back();
			long long mul_bottom = mul(b_t1, b_t2);
			if ((mul_top > mul_bottom) ^ inverse) {
				result = mul(result % MODULUS, mul_top % MODULUS) % MODULUS;
				d.push_back(b_t2);
				d.push_back(b_t1);
			} else {
				result = mul(result % MODULUS, mul_bottom % MODULUS) % MODULUS;
				d.push_front(t_t2);
				d.push_front(t_t1);
			}
		} else {
			if (d.size() == 1) {
				long b_t1 = d.back();
				d.pop_back();
				long long mul_bottom = mul(b_t1, t_t2);
				if ((mul_top > mul_bottom) ^ inverse) {
					result = mul(result % MODULUS, mul_top % MODULUS) % MODULUS;
					d.push_back(b_t1);
				} else {
					result = mul(result % MODULUS, mul_bottom % MODULUS) % MODULUS;
					d.push_front(t_t1);
				}
			} else {
				result = mul(result % MODULUS, mul_top % MODULUS) % MODULUS;
			}
		}
		got += 2;
	}
	cout << (result + MODULUS) % MODULUS << endl;
	return 0;
}