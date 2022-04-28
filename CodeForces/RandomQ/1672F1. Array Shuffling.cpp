// Problem: F1. Array Shuffling
// Contest: Codeforces - Codeforces Global Round 20
// URL: https://codeforces.com/problemset/problem/1672/F1
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-04-27 14:37:43
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
	int n;
	cin >> n;
	vi a(n);
	each(x, a) cin >> x;
	
	map<int, int> cnt;
	set<int> b;
	each(x, a) {
		cnt[x]++;
		b.insert(x);
		// debug(x);
		// debug(cnt[x]);
	}
	
	vpi c;
	while (!b.empty()){
		// debug(*b.begin());
		// debug(cnt[*b.begin()]);
		c.pb(mp(cnt[*b.begin()], *b.begin()));
		b.erase(b.begin());
	}
	sor(c);
	vi d;
	forn(i, 0, c.size()){
		rep(c[i].f) d.pb(c[i].s);
	}
	
	
	int mx = c[c.size()-1].f;
	map<int, vi> mapping;
	forn(i, 0, n){
		mapping[d[i]].pb(d[(i + mx) % n]);
	}
	
	vi ans(n);
	forn(i, 0, n){
		// debug(a[i]); debug(mapping[a[i]]);
		if (mapping[a[i]].size() > 0){
			ans[i] = mapping[a[i]][mapping[a[i]].size()-1];
			mapping[a[i]].pop_back();
		}
		else{
			ans[i] = a[i];
		}
	}
	each(x, ans){
		cout << x << " ";
	}
	cout << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
