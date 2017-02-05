#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MODULUS = 1000000007;

long long mul(long long a, long long b) {
    long long res = a * b;
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    long N;
    long K;
    cin >> N >> K;
    vector<long> a(N);
    for (long i = 0; i < N; ++i) {
        long t;
        cin >> t;
        a[i] = t;
    }
    sort(a.begin(), a.end());
    long from_top = 0;
    long from_bottom = 0;
    long got = 0;
    long long result = 1;
    while (got + 2 <= K) {
        long long mul_top = mul(a[from_top * 2], a[from_top * 2 + 1]);
        long long mul_bottom = mul(a[N - 1 - from_bottom * 2], a[N - 2 - from_bottom * 2]);
        if (mul_top > mul_bottom) {
            result = mul(result % MODULUS, mul_top % MODULUS) % MODULUS;
            from_top++;
        } else {
            result = mul(result % MODULUS, mul_bottom % MODULUS) % MODULUS;
            from_bottom++;
        }
        got += 2;
    }
    if (got < K) {
        long j = from_top * 2;
        while (a[j] == 0 && j + 1 < N - 2 - ((from_bottom>0?from_bottom:1) - 1) * 2)
            ++j;
        result = mul(result % MODULUS, a[j] % MODULUS) % MODULUS;
    }
    cout << (result + MODULUS) % MODULUS << endl;
    return 0;
}