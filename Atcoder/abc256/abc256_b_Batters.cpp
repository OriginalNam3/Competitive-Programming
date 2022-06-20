// Problem: B - Batters
// Contest: AtCoder - Tokio Marine & Nichido Fire Insurance Programming Contest 2022（AtCoder Beginner Contest 256)
// URL: https://atcoder.jp/contests/abc256/tasks/abc256_b
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Date & Time: 2022-06-18 13:02:03
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
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x: a) cin >> x;
	vector<int> b(4);
	int ans = 0;
	for (int i = 0; i < n; i++){
		b[0]++;
		for (int j = 3; j >= 0; j--){
			if (j + a[i] >= 4) {
				ans += b[j];
			}
			else{
				b[j + a[i]] = b[j];
			}
			b[j] = 0;
		}
		dbg(b);
	}
	
	cout << ans;
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
}
