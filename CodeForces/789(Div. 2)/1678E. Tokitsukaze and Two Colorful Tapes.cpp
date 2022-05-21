// Problem: C. Tokitsukaze and Two Colorful Tapes
// Contest: Codeforces - Codeforces Round #789 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1677/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-05-17 09:22:36
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

const int N = 1e5 + 5;

map<int, int> ind;
vector<bool> searched(N);
vector<int> a(N), b(N), cycles;

void dfs(int i, int d){
	if (searched[i]){
		cycles.pb(d);
		return;
	}
	searched[i] = 1;
	dfs(ind[b[i]], d + 1);
}

void solve(){
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	
	ind.clear();
	for (int i = 0; i < n; i++){
		searched[i] = 0;
		ind[a[i]] = i;
	}
	
	cycles.clear();
	for (int i = 0; i < n; i++){
		if (!searched[i]){
			dfs(i, 0);
		}
	}
	
	ll cnt = 0; 
	for (int i = 0; i < cycles.size(); i++){
		cnt += cycles[i] / 2;
	}
	
	ll ans = (cnt * (2 * n - cnt + 1) - cnt * (cnt + 1));
	cout << ans << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
