// Problem: D. Potion Brewing Class
// Contest: Codeforces - Codeforces Round #778 (Div. 1 + Div. 2, based on Technocup 2022 Final Round)
// URL: https://codeforces.com/problemset/problem/1654/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
typedef vector<vi> graph;

#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define pb push_back

#define fr(i,a,b) for (int i = (a); i < (b); ++i)
#define rf(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define each(x, a) for (auto& x: a)

#define MAXN 200001
const int mod = 998244353;

vector<vector<pair<int, pi> > > g;
int n;
vector<vi> factors(MAXN + 1, vi()); // factors[x] = prime factorization of x
vi f, p, d(MAXN + 1); // d[x] = smallest divisor of x
vll o;

void dfs(int u, int ou) {
	for (auto a: g[u]) {
		int v = a.f, x = a.s.f, y = a.s.s;
		if (v == ou) continue;
		each(prime, factors[x]) {
			f[prime]++;
		}
		each(prime, factors[y]) {
			f[prime]--;
		}
		fr(i, 2, n+1) {
			p[i] = max(p[i], f[i]);
		}
		// fr(i, 2, n + 1) {
    	// cout << i << ": " << f[i] << "  ";
    	// }
    	// cout << "\n";
		dfs(v, u);
		each(prime, factors[x]) f[prime]--;
		each(prime, factors[y]) f[prime]++;
	}
}

void construct (int u, int ou) {
	fr(i, 2, n + 1) {
		fr(j, 0, p[i]){
			o[u] *= i;
			o[u] %= mod; 
		}
	}
	for (auto a: g[u]) {
		int v = a.f, x = a.s.f, y = a.s.s;
		if (v == ou) continue;
		each(prime, factors[x]) p[prime]--;
		each(prime,factors[y]) p[prime]++;
		construct(v, u);
		each(prime, factors[x]) p[prime]++;
		each(prime, factors[y]) p[prime]--;
	}
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    rf(i, 2, MAXN + 1) {
    	for (int j = i; j < MAXN + 1; j += i) {
    		d[j] = i;
    	}
    }

    fr(i, 2, MAXN + 1) {
    	for(int j = i; j > 1; j /= d[j]){
    		factors[i].pb(d[j]);
    	}
    }
    int t;
    cin >> t;
    while (t--) {
    	cin >> n;
    	g.assign(n + 1, vector<pair<int, pi> > ());
    	p.assign(n + 1, 0);
    	f.assign(n + 1, 0);
    	o.assign(n + 1, 1);
    	fr(k, 0, n - 1) {
    		int i, j, x, y;
    		cin >> i >> j >> x >> y;
    		g[i].pb(mp(j, mp(x, y)));
    		g[j].pb(mp(i, mp(y, x)));
    	}
    	
    	dfs(1, 1);
    	
    	// fr(i, 2, n + 1) {
    		// cout << i << " " << p[i] << "\n";
    	// }
    	
    	construct(1, 1);
    	
    	long long sum = 0;
    	fr(i, 1, n + 1) {
    		sum += o[i];
    		sum %= mod;
    		// cout << o[i] << " ";
    	}
    	cout << sum << "\n";
    }
}
