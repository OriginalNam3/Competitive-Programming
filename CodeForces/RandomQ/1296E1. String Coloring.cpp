// Problem: E1. String Coloring (easy version)
// Contest: Codeforces - Codeforces Round #617 (Div. 3)
// URL: https://codeforces.com/contest/1296/problem/E1
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
template<class T> using V = vector<T>;
typedef array<int, 3> qq;

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

const int mod = 1e9+7;
const int INF = INT_MAX >> 1;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

void solve(){
	
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    str a;
    cin >> a;
    vi ans(n, -1);
    forn(i, 0, n){
    	char cur = a[i];
    	bool curans = 0;
    	bool first = 1;
    	rofn(j, 0, i){
    		// each(x, ans) cout << x << " ";
    		// cout << "\n";
    		if (a[j] > cur){
    			if (first){
    				curans = !ans[j];
    				// debug(cur);
    				// debug(curans);
    				// debug(j);
    				first = 0;
    				continue;
    			}
    			if (!first && !(ans[j] ^ curans)){
    				cout << "NO\n";
    				return 0;
    			}
    		}
    	}
    	ans[i] = curans;
    }
    cout << "YES\n";
    each(x, ans) cout << x;
}
