// Problem: C. Game On Leaves
// Contest: Codeforces - Codeforces Round #646 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1363/C
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
	int n, x;
	cin >> n >> x;
	x--;
	vi a(n);
	forn(i, 0, n-1){
		int u, v;
		cin >> u >> v;
		u--; v--;
		a[u]++; a[v]++;
	}
	if (a[x] <= 1) {
		cout << "Ayush\n";
		return;
	}
	if (n % 2 == 0){
		cout << "Ayush\n";
		return;
	}
	else{
		cout << "Ashish\n";
		return;
	}
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--){
    	solve();
    }
}
