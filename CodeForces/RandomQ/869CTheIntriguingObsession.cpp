#include <bits/stdc++.h>
using namespace std;

#define maxn 5002
int mod = 998244353;
int fact[maxn];
int ncr[maxn][maxn];

int main() {
    for (int i = 0; i < maxn - 1; i++){
        ncr[i][0] = 1;
        for (int j = 1; j <= i; j++){
            ncr[i][j] = (ncr[i-1][j-1] + ncr[i-1][j]) % mod;
        }
    }
    fact[0] = 1;
    for (int i = 1; i < maxn - 1; i++){
        fact[i] = (1LL * fact[i-1] * i) % mod;
    }
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    long long ans = 1;
    for (int i = 0; i < 3; i++){
        int c1 = a[i], c2 = a[(i + 1) % 3];
        long long n = 1;
        for (int i = 1; i <= min(c1, c2); i++){
            int m = fact[i];
            m = (1LL * m * ncr[c1][i]) % mod;
            m = (1LL * m * ncr[c2][i]) % mod;
            n += m;
            n %= mod;
        }
        ans *= n;
        ans %= mod;
    }
    cout << ans;
}
