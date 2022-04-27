// Problem: D. Weights Assignment For Tree Edges
// Contest: Codeforces - Brogrammer Contest #1
// URL: https://codeforces.com/gym/379420/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-04-24 19:33:13
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
	vi b(n), p(n);
	vector<vi> g(n);
	int root = 0;
	forn(i, 0, n){
		cin >> b[i];
		b[i]--;
		g[b[i]].pb(i);
		if (b[i] == i){
			root = i;
		}
	}
	each(x, p) {
		cin >> x;
		x--;
	}
	
	if (p[0] != root){
		cout << "-1\n"; return;
	}
	vi ans(n), d(n);
	set<int> q;
	each(x, g[root]){
		q.insert(x);
	}
	int i = 1;
	while (!q.empty() && i < n){
		auto it = q.find(p[i]);
		if (it == q.end()){
			cout << "-1\n";
			return;
		}
		ans[p[i]] = d[p[i-1]] + 1 - d[b[p[i]]];
		d[p[i]] = d[b[p[i]]] + ans[p[i]];

		int u = *it;
		q.erase(p[i]);
		each(v, g[u]){
			q.insert(v);
		}
		i++;
	}
	if (i != n){
		cout << "-1\n"; return;
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
    while (t--){
    	solve();
    }
}
