// Problem: F. Vitaly and Advanced Useless Algorithms
// Contest: Codeforces - Codeforces Round #776 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1650/F
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

#define fr(i,a,b) for (int i = (a); i < (b); ++i)
#define rf(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define each(x, a) for (auto& x: a)

// qq mt(int a, int b, int c) {
	// qq tuple;
	// tuple[0] = a;
	// tuple[1] = b;
	// tuple[2] = c;
	// return tuple;
// }

const int INF = INT_MAX >> 1;

struct option{
	int t, p, id;
};

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--){
    	int n, m;
    	cin >> n >> m;
    	vi a(n);
    	vector<vector<option> > b(n);
    	fr(i, 0, n){
    		cin >> a[i];
    	}
    	fr(i, 1, m + 1){
    		int e, t, p;
    		cin >> e >> t >> p;
    		option inp;
    		inp.t = t;
    		inp.p = p;
    		inp.id = i;
    		b[e-1].pb(inp);
    	}
    	
    	vi ans;
    	ll ct = 0;
    	bool ok = true;
    	fr(i, 0, n){
    		int s = b[i].size();
    		vector<vi> dp(101, vi(s+1, INF)); // dp for min completion time
    		dp[0][0] = 0;
    		fr(j, 0, s){
    			auto[t, p, id] = b[i][j];
    			dp[0][j + 1] = dp[0][j];
    			rf(k, 1, 101){
    				int f = max(0, k - p); // last progress
    				dp[k][j+1] = dp[k][j];
    				if (dp[f][j] + t < dp[k][j+1]) {
    					dp[k][j+1] = dp[f][j] + t;
    					// cout << next << " " << j + 1 << " " << k << " " << j << " " << dp[k][j] + t << "\n";
    				}
    			}
    		}
    		
    		int t = dp[100][s];
    		// cout << t << "\n";
    		if (t == INF){
    			// cout << "NO SOL\n";
    			ok = false;
    		}
    		ct += t;
    		if (ct > a[i]){
    			ok = false;
    		}
    		// if (i+1 < n) a[i+1] += a[i] - 2 * t;
			int k = 100;
    		rf(j, 0, s){
    			// cout << j << "\n";
    			if (dp[k][j+1] == dp[k][j]) continue;
    			ans.pb(b[i][j].id);
    			// cout << dp[k][j+1] << " " <<  b[i][j].id << " ";
    			k = max(0, k - b[i][j].p);
    			// cout << k << "\n";
    		}
    	}
    	// cout << "\nDONE\n";
    	if (!ok) {
    		cout << "-1\n";
    		continue;
    	}
    	
    	int o = ans.size();
    	cout << o << "\n";
    	fr(i, 0, o){
    		cout << ans[i] << " ";
    	}
    	cout << "\n";
    }
}
