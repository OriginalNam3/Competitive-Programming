// Problem: A. Greg and Array
// Contest: Codeforces - Codeforces Round #179 (Div. 1)
// URL: https://codeforces.com/problemset/problem/295/A
// Memory Limit: 256 MB
// Time Limit: 1500 ms
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
const int INF = INT_MAX >> 1;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vi a(n);
    forn(i, 0, n) cin >> a[i];
    vector<qq> op(m);
    forn(i, 0, m){
    	cin >> op[i][0] >> op[i][1] >> op[i][2];
    	op[i][0]--;
    }
    
    vll c(m+1);
    forn(i, 0, k){
    	int l, r;
    	cin >> l >> r;
    	l--;
    	c[l]++; c[r]--;
    }
    forn(i, 1, m){
    	c[i] += c[i-1];
    }
    
    vll b(n+1);
    forn(i, 0, m){
    	b[op[i][0]] += op[i][2] * c[i];
    	b[op[i][1]] -= op[i][2] * c[i];
    }
    
    cout << a[0] + b[0] << " ";
    forn(i, 1, n){
    	b[i] += b[i-1];
    	cout << a[i] + b[i] << " ";
    }
    // cout << "\n";
    // forn(i, 0, n){
    	// cout << b[i] << " ";
    // }
}
