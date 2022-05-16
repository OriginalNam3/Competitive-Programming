// Problem: B. Array Walk
// Contest: Codeforces - Educational Codeforces Round 92 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1389/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-05-13 10:27:16
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
	int n, k, z;
	cin >> n >> k >> z;
	vector<int> a(n);
	for (int &x: a) cin >> x;

	if (z == 0){
		int ans = a[0];
		for (int i = 1; i <= k; i++){
			ans += a[i];
		}
		cout << ans << "\n";
		return;
	}
	
	vector<int> pre(n);
	pre[0] = a[0];
	for (int i = 1; i <= k; i++){
		pre[i] = pre[i-1] + a[i];
	}
	
	int ans = 0;
	for (int i = 0; i <= k; i++){
		int cur = (a[i] + a[i+1]) * min(z, (k - i) / 2) + pre[k - min(z, (k - i) / 2) * 2];
		ans = max(ans, cur);
	}
	cout << ans << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
