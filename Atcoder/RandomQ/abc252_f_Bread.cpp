// Problem: F - Bread
// Contest: AtCoder - AtCoder Beginner Contest 252
// URL: https://atcoder.jp/contests/abc252/tasks/abc252_f
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Date & Time: 2022-06-12 01:02:27
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
	ll l;
	cin >> n >> l;
	vector<int> a(n);
	for (int &x: a) cin >> x;
	
	priority_queue<ll> q;
	for (int i = 0; i < n; i++){
		l -= a[i];
		q.push(-a[i]);
	}

	if (l > 0){
		n++;
		q.push(-l);
	}
	
	ll ans = 0;
	for (int i = 1; i < n; i++){
		ll a = -q.top();
		q.pop();
		a -= q.top();
		q.pop();
		ans += a;
		q.push(-a);
		dbg(a);
	}
	
	cout << ans;
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
}
