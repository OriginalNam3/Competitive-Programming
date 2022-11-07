// Problem: E. Iahub and Permutations
// Contest: Codeforces - Codeforces Round #198 (Div. 2)
// URL: https://codeforces.com/problemset/problem/340/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-06-20 22:53:41
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

int dp[2005][2005];

int ans(int any, int fixed){
	dbg(any, fixed);
	if (dp[any][fixed] > 0){
		return dp[any][fixed];
	}
	dp[any][fixed] = add(dp[any][fixed], mul(fixed - 1, ans(any + 1, fixed - 2)));
	dp[any][fixed] = add(dp[any][fixed], mul(any, ans(any, fixed - 1)));
	return dp[any][fixed];
}

void solve(){
	int n;
	cin >> n;
	
	vector<int> a(n), in(n);
	for (int &x: a) {
		cin >> x;
		if (x != -1) in[x-1] = 1;
	}
	dbg(a);
	int cnt = 0, ok = 0;
	for (int i = 0; i < n; i++){
		if (in[i] == 0){
			dbg(i, a[i]);
			if (a[i] == -1){
				cnt++;
			}
			else{
				ok++;
			}
		}
	}
	
	memset(dp, 0, sizeof dp);
	dp[0][0] = dp[0][1] = 1;
	for (int i = 1; i <= n; i++){
		dp[i][0] = mul(dp[i-1][0], i);
		dp[i][1] = mul(dp[i][0], i);
	}
	
	cout << ans(ok, cnt);
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
}
