// Problem: B. Robots
// Contest: Codeforces - Educational Codeforces Round 128 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1680/problem/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// Date & Time: 2022-05-13 15:45:26
// 
// Powered by CP Editor (https://cpeditor.org)

// You either sink in the coom, or coom in the sink.

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
	int n, m;
	cin >> n >> m;
	vector<vector<int> > g(n, vector<int> (m));
	
	int mncol = INT_MAX, mnrow = INT_MAX;
	for (int i = 0; i < n; i++){
		string row; cin >> row;
		for (int j = 0; j < m; j++){
			if (row[j] == 'R'){
				mnrow = min(mnrow, i);
				mncol = min(mncol, j);
				g[i][j] = 1;
			}
		}
	}
	if (g[mnrow][mncol]){
		cout << "YES\n";
	}
	else{
		cout << "NO\n";
	}
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
