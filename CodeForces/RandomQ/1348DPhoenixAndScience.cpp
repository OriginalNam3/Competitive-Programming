// Problem: D. Phoenix and Science
// Contest: Codeforces - Codeforces Round #638 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1348/D
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
    int t;
    cin >> t;
    
    while (t--){
    	int n;
    	cin >> n;
    	vi ans;
    	int c = 1;
    	while (n > 0){
    		if (c > n) {
    			break;
    		}
    		n -= c;
    		ans.pb(c);
    		c <<= 1;
    	}
    	if (n > 0) {
    		ans.pb(n);
    	}
    	sor(ans);
    	int d = ans.size();
    	d--;
    	cout << d << "\n";
    	fr(i, 0, d){
    		cout << ans[i + 1] - ans[i] << " ";
    	}
    	cout << "\n";
    }
}
