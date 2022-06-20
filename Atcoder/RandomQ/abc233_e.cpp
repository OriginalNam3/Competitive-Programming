// Problem: E - Σ[k=0..10^100]floor(X／10^k)
// Contest: AtCoder - AtCoder Beginner Contest 233
// URL: https://atcoder.jp/contests/abc233/tasks/abc233_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Date & Time: 2022-06-20 22:30:16
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
	str a;
	cin >> a;
	
	int n = a.size();
	vector<int> x(n);
	for (int i = 0; i < n; i++){
		x[i] = a[i] - '0';
	}
	dbg(x);
	vector<int> ans(n);
	ans[0] = x[0];
	for (int i = 1; i < n; i++){
		ans[i] = ans[i-1] + x[i];
	}
	int carry = 0;
	for (int i = n - 1; i >= 0; i--){
		ans[i] += carry;
		carry = ans[i] / 10;
		ans[i] %= 10;
		dbg(ans);
	}
	if (carry > 0){
		cout << carry;
	}
	for (int e: ans) cout << e;
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
}
