// Problem: F2. Promising String (hard version)
// Contest: Codeforces - Codeforces Round #780 (Div. 3)
// URL: https://codeforces.com/contest/1660/problem/F2
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double db;
typedef string str;

#define mp make_pair
#define f first
#define s second

typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<bool> vb;
typedef vector<pi> vpi;
typedef array<int, 3> qq;

#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define pb push_back

#define forn(i,a,b) for (int i = (a); i < (b); ++i)
#define rofn(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define rep(n) for (int _ = 0; _ < n; _++)
#define each(x, a) for (auto& x: a)

void solve(){
	int n;
	cin >> n;
	str s;
	cin >> s;
	vi cnt(2 * n + 1), freq(3);
	int cur = n;
	ll ans = 0;
	cnt[cur]++;
	freq[cur%3]++;
	forn(i, 0, n){
		if (s[i] == '+'){
			freq[cur%3] -= cnt[cur];
			cur++;
		}
		else{
			cur--;
			freq[cur%3] += cnt[cur];
		}
		ans += freq[cur%3];
		cnt[cur]++;
		freq[cur%3]++;
		// cout << "cur: " << cur << "\n";
	}
	cout << ans << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--){
    	solve();
    }
}
