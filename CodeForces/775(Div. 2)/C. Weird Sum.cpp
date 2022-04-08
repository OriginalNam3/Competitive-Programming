// Problem: A. Weird Sum
// Contest: Codeforces - Codeforces Round #775 (Div. 1, based on Moscow Open Olympiad in Informatics)
// URL: https://codeforces.com/problemset/problem/1648/A
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
#define rsor(x) sort(rbegin(x), rend(x))
#define pb push_back

#define forn(i,a,b) for (int i = (a); i < (b); ++i)
#define fors(i,a,b,s) for (int i = (a); i < (b); i+=s)
#define rofn(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define rep(n) for (int _ = 0; _ < n; _++)
#define each(x, a) for (auto& x: a)

const int mod = 1e9+7;
const int INF = INT_MAX >> 1;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

const int N = 100002;

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<vi> > c(N, vector<vi>(2, vi()));
    forn(i, 0, n){
    	forn(j, 0, m){
    		int colour;
    		cin >> colour;
    		c[colour][0].pb(i);
    		c[colour][1].pb(j);
    	}
    }
    ll ans = 0;
    forn(i, 1, N){
    	forn(p, 0, 2){
    		sor(c[i][p]);
    		int k = c[i][p].size();
    		forn(j, 0, k){
    			ans += (1LL * 2 * j + 1 - k) * 1LL * c[i][p][j];
    		}
    	}
    }
    cout << ans;
}
