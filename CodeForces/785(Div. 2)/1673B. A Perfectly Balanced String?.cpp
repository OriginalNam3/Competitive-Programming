// Problem: B. A Perfectly Balanced String?
// Contest: Codeforces - Codeforces Round #785 (Div. 2)
// URL: https://codeforces.com/contest/1673/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-04-30 15:35:08
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

#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rsor(x) sort(x.rbegin(), x.rend())
#define pb push_back

#define forn(i,a,b) for (int i = (a); i < (b); ++i)
#define fors(i,a,b,s) for (int i = (a); i < (b); i+=s)
#define rofn(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define rep(n) for (int _ = 0; _ < n; _++)
#define each(x, a) for (auto& x: a)
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

const int mod = 1e9+7;
const int INF = INT_MAX >> 1;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

void solve(){
	str s;
	cin >> s;
	int n = s.size();
	vector<vi> cnt(n+1, vi(26));
	
	map<int, int> last;
	set<int> chars;
	
	forn(i, 0, n){
		chars.insert(s[i]-'a');
	}
	
	int total = chars.size();
	
	forn(i, 0, n){
		// debug(s[i]);
		cnt[i+1][s[i]-'a']++;
		forn(j, 0, 26){
			cnt[i+1][j] += cnt[i][j];
		}
		forn (j, 0, 26) if (cnt[i+1][j] - cnt[last[s[i]-'a']][j] >= 2){
			int ok = 0;
			forn(k, 0, 26){
				if (cnt[i+1][k] - cnt[last[s[i]-'a']][k] >= 1){
					ok++;
					// debug(k);
				}
			}
			// debug(total);
			// debug(ok);
			if (ok < total) {cout << "NO\n";
			return;}
		}
		
		last[s[i]-'a'] = i;
	}
	cout << "YES\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
