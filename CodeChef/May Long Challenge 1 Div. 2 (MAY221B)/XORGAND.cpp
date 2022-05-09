// Problem: Mystical Numbers
// Contest: CodeChef - May Long One 2022 Division 2 (Unrated)
// URL: https://www.codechef.com/MAY221B/problems/XORGAND
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-05-06 19:22:11
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
	int n;
	cin >> n;
	int a[n+3][33];
	memset(a, 0, sizeof a);
	forn(i, 1, n+1){
		int x; cin >> x;
		a[i][__lg(x)+1]++;
		forn(j, 0, 32){
			a[i][j] += a[i-1][j];
		}
		// vdebug(a[i])
	}
	int q;
	cin >> q;
	rep(q){
		int l, r, x;
		cin >> l >> r >> x;
		l--;
		cout << r - l - a[r][__lg(x) + 1] + a[l][__lg(x) + 1] << "\n";
	}
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
