// Problem: B. Modulo Sum
// Contest: Codeforces - Codeforces Round #319 (Div. 2)
// URL: https://codeforces.com/problemset/problem/577/B
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

// const int INF = INT_MAX>>1;
// const int MOD = 998244353;

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vi a(n);
    vi mod(m);
    each(x, a) {
    	cin >> x;
    	x %= m;
    	mod[x]++;
    }
    fr(i, 0, m){
    	mod[i] = mod[i] % 1001;
    }
    if (mod[0] > 0){
    	cout << "YES";
    	return 0;
    }
    
    vector<vb> dp(m, vb(2));
    bool ok = false;
    fr(i, 1, m){
    	if (mod[i] == 0) continue;
    	fr(k, 0, mod[i]){
    		dp[0][0] = 1;
	    	fr(j, 0, m){
	    		if (dp[j][0]){
	    			dp[(i + j) % m][1] = 1;
	    			// cout << i << " " << j << "\n";
	    			if ((i+j) % m == 0) ok = true;
	    		}
	    	}
		    fr(j, 0, m){
		    	dp[j][0] = dp[j][1];
		    }
		}
    }
    // fr(i, 0, m){
    	// cout << dp[i][0] << " ";
    // }
    cout << (ok ? "YES": "NO");
}
