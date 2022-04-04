// Problem: C. k-Tree
// Contest: Codeforces - Codeforces Round #247 (Div. 2)
// URL: https://codeforces.com/problemset/problem/431/C
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
typedef array<int, 3> qq;

#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define pb push_back

#define forn(i,a,b) for (int i = (a); i < (b); ++i)
#define rofn(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define rep(n) for (int _ = 0; _ < n; _++)
#define each(x, a) for (auto& x: a)

const int mod = 1e9+7;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, k, d;
    cin >> n >> k >> d;
    vi a(n+1);
    a[0] = 1;
    forn(i, 1, n+1){
    	forn(j, 1, k+1){
    		if (i - j < 0) break;
    		a[i] = (1LL * a[i] + a[i-j]) % mod;
    	}
    }
    vi b(n+1);
    b[0] = 1;
    forn(i, 1, n+1){
    	forn(j, 1, k+1){
    		if (i - j < 0) break;
    		if (j == d) break;
    		b[i] = (1LL * b[i] + b[i-j]) % mod;
    	}
    }
    // forn(i, 0, n+1){
    	// cout << a[i] << " ";
    // }
    // cout << "\n";
    // forn(i, 0, n+1){
    	// cout << b[i] << " ";
    // }
    // cout << "\n";
    cout << (1LL * a[n] + mod - b[n]) % mod;
}
