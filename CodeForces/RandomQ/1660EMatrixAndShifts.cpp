// Problem: E. Matrix and Shifts
// Contest: Codeforces - Codeforces Round #780 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1660/E
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
typedef array<int, 3> qq;

#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define pb push_back

#define forn(i,a,b) for (int i = (a); i < (b); ++i)
#define rofn(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define rep(n) for (int _ = 0; _ < n; _++)
#define each(x, a) for (auto& x: a)

const int mod = 1e9+7;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

void solve(){
	int n;
	cin >> n;
	vector<vb> a(n, vb(n));
	int cnt = 0;
	forn(i, 0, n){
		str row;
		cin >> row;
		forn(j, 0, n){
			a[i][j] = row[j] == '1';
			if (a[i][j]) cnt++;
		}
	}
	int mx = 0;
	forn(i, 0, n){
		int c = 0;
		forn(j, 0, n){
			if (a[(i + j)%n][j]) c++;
		}
		mx = max(mx, c);
	}
	cout << cnt - mx + n - mx << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--){
    	solve();
    }
}
