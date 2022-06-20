// Problem: C - Filling 3x3 array
// Contest: AtCoder - Tokio Marine & Nichido Fire Insurance Programming Contest 2022（AtCoder Beginner Contest 256)
// URL: https://atcoder.jp/contests/abc256/tasks/abc256_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Date & Time: 2022-06-18 13:07:52
// 
// Powered by CP Editor (https://cpeditor.org)

// https://codeforces.com/profile/Intellegent husbando <3

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double db;
typedef string str;

#define mp make_pair
#define f first
#define s second

#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rsor(x) sort(x.rbegin(), x.rend())
#define pb emplace_back

#ifdef ORIGINAL_LOCAL
#include <bits/debug.h>
#else
#define dbg(...) 42
#endif

const int mod = 1e9+7;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

void solve(){
	vector<int> w(6);
	for (int &x: w) cin >> x;
	ll ans = 0;
	for (int a = 1; a < 30; a++){
		for (int b = 1; b < 30; b++){
			for (int c = 1; c < 30; c++){
				for (int d = 1; d < 30; d++){
					int e = w[0] - a - b, f = w[2] - c - d, g = w[3] - a - c, h = w[5] - b - d;
					if (e > 0 && f > 0 && g > 0 && h > 0 && w[4] - e - f == w[1] - g - h && w[4] - e - f > 0){
						ans++;
					}
				}
			}
		}
	}
	cout << ans;
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
}
