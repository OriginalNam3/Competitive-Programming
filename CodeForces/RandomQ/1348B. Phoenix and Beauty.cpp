// Problem: B. Phoenix and Beauty
// Contest: Codeforces - Codeforces Round #638 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1348/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-05-21 22:27:55
// 
// Powered by CP Editor (https://cpeditor.org)

// https://codeforces.com/profile/Intellegent <3

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
	int n, k;
	cin >> n >> k;
	vector<bool> a(n + 1);
	int cnt = 0;
	for (int i = 0; i < n; i++){
		int x; cin >> x;
		if (!a[x]) cnt++;
		a[x] = 1;
	}
	if (cnt > k){
		cout << "-1\n";
		return;
	}
	vector<int> ans;
	for (int i = 1; i <= n; i++){
		if (a[i]) ans.pb(i);
	}
	for (int i = cnt; i < k; i++){
		ans.pb(ans[cnt-1]);
	}
	cout << k * n << "\n";
	for (int i = 0; i < n; i++){
		for (int x: ans){
			cout << x << " ";
		}
	}
	cout << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
