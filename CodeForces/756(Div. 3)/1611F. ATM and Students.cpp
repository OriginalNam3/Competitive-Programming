// Problem: F. ATM and Students
// Contest: Codeforces - Codeforces Round #756 (Div. 3)
// URL: https://codeforces.com/contest/1611/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-04-24 22:06:20
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
	int n, s;
	cin >> n >> s;
	vi a(n);
	each(x, a){
		cin >> x;
	}
	int r = 1, x = -1, y = -1;
	ll cur = a[0];
	forn(l, 0, n){
		if (s + cur >= 0){
			while (r < n && s + cur + a[r] >= 0){
				cur += a[r];
				r++;
			}
			if (r - l >= y - x + 1){
				x = l, y = r-1;
			}
		}
		// debug(cur); debug(r); debug(l);
		cur -= a[l];
		
	}
	if (x == -1){
		cout << "-1\n"; return;
	}
	cout << x+1 << " " << y+1 << "\n";
}
 
int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
