// Problem: A. Queries about less or equal elements
// Contest: Codeforces - 20-04-2022 TCP (Two Pointers)
// URL: https://codeforces.com/problemset/problem/600/B
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
    int n, m;
    cin >> n >> m;
    vi a(n);
    
    vpi b(m);
    each(x, a) cin >> x;
    forn(i, 0, m){
    	cin >> b[i].f;
    	b[i].s = i;
    }
    vi c(m);
    sor(a); sor(b);
    int j = 0;
    forn(i, 0, m){
    	while (j < n && a[j] <= b[i].f) j++;
    	c[b[i].s] = j;
    	// debug(b[i].f); debug(b[i].s); debug(j);
    }
    each(x, c) cout << x << " ";
}
