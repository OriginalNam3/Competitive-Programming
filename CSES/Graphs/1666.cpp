// Problem: Building Roads
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1666
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Date & Time: 2022-05-20 20:22:21
// 
// Powered by CP Editor (https://cpeditor.org)

// https://codeforces.com/profile/Intellegent <3

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double db;
typedef string str;

#define mp make_pair
#define f first
#define s second

#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rsor(x) sort(x.rbegin(), x.rend())
#define pb push_back

#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

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
    vector<vector<int> > g(n, vector<int>());
    
    for (int i = 0; i < m; i++){
    	int a, b;
    	cin >> a >> b;
    	a--; b--;
    	g[a].pb(b);
    	g[b].pb(a);
    }
    
    vector<int> ans;
    vector<bool> searched(n, 0);
    queue<int> q;
    for (int i = 0; i < n; i++){
    	if (!searched[i]){
    		ans.pb(i + 1);
    		searched[i] = 1;
    		q.push(i);
    		while (!q.empty()){
    			int u = q.front();
    			q.pop();
    			for (int v: g[u]){
    				if (searched[v] == 1) continue;
    				q.push(v);
    				searched[v] = 1;
    			}
    		}
    	}
    }
    cout << ans.size() - 1 << "\n";
    for (int i = 1; i < ans.size(); i++){
    	cout << ans[0] << " " << ans[i] << "\n";
    }
}
