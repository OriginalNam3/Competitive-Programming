// Problem: B. The Two Routes
// Contest: Codeforces - 27-03-2022 TCP (Graphs)
// URL: https://codeforces.com/problemset/problem/601/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-04-27 18:39:58
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
    vector<vb> g(n, vb(n));
    rep(m){
    	int u, v;
    	cin >> u >> v;
    	u--;
    	v--;
    	g[u][v] = 1;
    	g[v][u] = 1;
    }
    queue<int> q;
    q.push(0);
    vi d(n, INT_MAX);
    d[0] = 0;
    while (!q.empty()){
    	int u = q.front();
    	q.pop();
    	forn(v, 0, n){
    		if (g[u][v] && d[u] + 1 < d[v]){
    			d[v] = d[u] + 1;
    			q.push(v);
    		}
    	}
    }
    int ans = d[n-1];
    q.push(0);
    d.assign(n, INT_MAX);
    d[0] = 0;
    while (!q.empty()){
    	int u = q.front();
    	q.pop();
    	forn(v, 0, n){
    		if (!g[u][v] && d[u] + 1 < d[v]){
    			d[v] = d[u] + 1;
    			q.push(v);
    		}
    	}
    }
    if (d[n-1] == INT_MAX || ans == INT_MAX){
    	cout << "-1";
    	return 0;
    }
	if (d[n-1] == ans){
		cout << ans + 1;
	}
	else{
		cout << max(ans, d[n-1]);
	}
}
