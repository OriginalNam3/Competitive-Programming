// Problem: D. Cross Coloring
// Contest: Codeforces - Educational Codeforces Round 123 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1644/D
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

#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define pb push_back

#define fr(i,a,b) for (int i = (a); i < (b); ++i)
#define rf(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define each(x, a) for (auto& x: a)

#define MAXN 200005
const int mod = 998244353;

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
    	int n, m, k, q;
    	cin >> n >> m >> k >> q;
    	
    	vpi queries(q);
    	fr(i, 0, q){
    		cin >> queries[i].f >> queries[i].s;
    	}
    	
    	if (k == 1) {
    		cout << "1\n";
    		continue;
    	}
    	
    	vb x(n + 1);
    	vb y(m + 1);
    	long long ans = 1;
    	int xcnt = 0, ycnt = 0;
    	rf(i, 0, q){
    		if (xcnt == n || ycnt == m) break;
    		if (!x[queries[i].f] || !y[queries[i].s]){
    			ans *= k;
    			ans %= mod;
    			if (!x[queries[i].f]){
    				x[queries[i].f] = 1;
    				xcnt++;
    			}
    			if (!y[queries[i].s]) {
    				y[queries[i].s] = 1;
    				ycnt++;
    			}
    			continue;
    		}
    	}
    	cout << ans << "\n";
    }
}
