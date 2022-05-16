// Problem: E. Special Elements
// Contest: Codeforces - Codeforces Round #640 (Div. 4)
// URL: https://codeforces.com/problemset/problem/1352/E
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Date & Time: 2022-05-13 22:53:15
// 
// Powered by CP Editor (https://cpeditor.org)

// You either sink in the coom, or coom in the sink.

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
#define pb push_back

#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

const int mod = 1e9+7;
const int INF = INT_MAX >> 1;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x: a) cin >> x;
	
	vector<int> pre(n);
	vector<bool> cnt(n+1), ok(n+1);
	for (int x: a) cnt[x] = 1;
	
	pre[0] = a[0];
	for (int i = 1; i < n; i++){
		pre[i] += a[i];
		pre[i] += pre[i-1];
		if (pre[i] <= n) ok[pre[i]] = 1;
		for (int j = i-2; j >= 0; j--){
			if (pre[i] - pre[j] > n) break;
			if (cnt[pre[i] - pre[j]]) ok[pre[i]-pre[j]] = 1;
		}
	}
	// vdebug(cnt)
	// vdebug(ok)
	int ans = 0;
	for (int x: a){
		if (ok[x]) ans++;
	}
	
	cout << ans << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
