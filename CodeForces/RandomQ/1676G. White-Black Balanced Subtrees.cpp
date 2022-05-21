// Problem: G. White-Black Balanced Subtrees
// Contest: Codeforces - Codeforces Round #790 (Div. 4)
// URL: https://codeforces.com/problemset/problem/1676/G
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-05-17 08:59:49
// 
// Powered by CP Editor (https://cpeditor.org)

// History - deleted
// Holy water - needed
// Meat - beated
// Phone - yeeted
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

vector<vector<int> > cnt, g;
int ans;

void dfs(int u){
	for (int v: g[u]){
		dfs(v);
		cnt[u][0] += cnt[v][0]; 
		cnt[u][1] += cnt[v][1];
	}
	if (cnt[u][0] == cnt[u][1]) ans++;
}

void solve(){
	int n;
	cin >> n;
	g.assign(n, vector<int> ());
	cnt.assign(n, vector<int> (2));
	
	for (int v = 1; v < n; v++){
		int u; cin >> u; u--;
		g[u].pb(v);
	}
	
	str s;
	cin >> s;
	for (int i = 0; i < n; i++){
		if (s[i] == 'W') cnt[i][0]++;
		else cnt[i][1]++;
	}
	
	ans = 0;
	dfs(0);
	cout << ans << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
