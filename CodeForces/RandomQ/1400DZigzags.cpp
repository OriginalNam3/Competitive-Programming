// Problem: D. Zigzags
// Contest: Codeforces - Educational Codeforces Round 94 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1400/D
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
    	vi a(n);
    	each(x, a){
    		cin >> x;
    	}
    	ll ans = 0;
    	vector<vi> r(n+1, vi(n+1));
    	rf(j, 0, n-2){
    		fr(l, j + 2, n){
    			r[a[j+1]][a[l]]++;
    		}
    		fr(i, 0, j){
    			// cout << i << " " << j << " " << r[a[i]][a[j]] << "\n";
    			ans += r[a[i]][a[j]];
    		}
    	}
    	
    	cout << ans << "\n";
    }
}
