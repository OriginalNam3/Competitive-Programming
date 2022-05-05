// Problem: G. Fall Down
// Contest: Codeforces - Codeforces Round #784 (Div. 4)
// URL: https://codeforces.com/contest/1669/problem/G
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-05-03 22:50:44
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
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

const int mod = 1e9+7;
const int INF = INT_MAX >> 1;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

void solve(){
	int n, m;
	cin >> n >> m;
	vector<vi> g(n, vi(m));
	forn(i, 0, n){
		str row;
		cin >> row;
		forn(j, 0, m){
			if (row[j] == '*') g[i][j] = 1;
			if (row[j] == 'o') g[i][j] = 2;
		}
	}
	vector<vi> res(n, vi(m));
	forn(i, 0, m){
		int cur = n - 1;
		rofn(j, 0, n){
			if (g[j][i] == 1){
				res[cur--][i] = 1;
			}
			if (g[j][i] == 2){
				res[j][i] = 2;
				cur = j - 1;
			}
		}
	}
	forn(i, 0, n){
		forn(j, 0, m){
			if (res[i][j] == 0) cout << '.';
			if (res[i][j] == 1) cout << '*';
			if (res[i][j] == 2) cout << 'o';
		}
		cout << "\n";
	}
	cout << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
