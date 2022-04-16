// Problem: L. Labyrinth
// Contest: Codeforces - 2021-2022 ICPC, NERC, Northern Eurasia Onsite (Unrated, Online Mirror, ICPC Rules, Teams Preferred)
// URL: https://codeforces.com/problemset/problem/1666/L
// Memory Limit: 512 MB
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
    int n, m, s;
    cin >> n >> m >> s;
    s--;
    vector<vi> g(n, vi());
    rep(m){
    	int u, v;
    	cin >> u >> v;
    	u--; v--;
    	g[u].pb(v);
    }
    if (g[s].size() == 1){
    	cout << "Impossible\n";
    	return 0;
    }
    vi p(n, -1), o(n, -1);
    queue<int> q;
    each(v, g[s]){
    	o[v] = v;
    	p[v] = s;
    	q.push(v);
    }
    while (!q.empty()){
    	int u = q.front();
    	q.pop();
    	each(v, g[u]){
    		if (o[v] != -1 && o[v] != o[u] && v != s){
    			vi ans1, ans2;
    			int i = v;
    			while (i != s){
    				ans1.pb(i+1);
    				i = p[i];
    			}
    			ans1.pb(s+1);
    			ans2.pb(v+1);
    			while (u != s){
    				ans2.pb(u+1);
    				u = p[u];
    			}
    			ans2.pb(s+1);
    			if (ans1[1] == ans2[1]) continue;
    			cout << "Possible\n" << ans1.size() << "\n";
    			rofn(i, 0, ans1.size()){
    				cout << ans1[i] << " ";
    			}
    			cout << "\n" << ans2.size() << "\n";
    			rofn(i, 0, ans2.size()){
    				cout << ans2[i] << " ";
    			}
    			cout << "\n";
    			return 0;
    		}
			if (o[v] == -1){
				p[v] = u;
				o[v] = o[u];
				q.push(v);
			}
    	}
    }
    cout << "Impossible\n";
}
