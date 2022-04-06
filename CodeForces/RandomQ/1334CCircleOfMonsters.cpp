// Problem: C. Circle of Monsters
// Contest: Codeforces - Educational Codeforces Round 85 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1334/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
const int INF = INT_MAX >> 1;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

void solve(){
	int n;
	cin >> n;
	vll a(n), b(n);
	set<pair<ll, int> > q;
	forn(i, 0, n){
		cin >> a[i] >> b[i];
	}
	int s = -1;
	ll mn = LLONG_MAX;
	forn(i, 0, n){
		if (a[(i+1)%n]-max(1LL*0, a[(i+1)%n] - b[i]) < mn){
			mn = a[(i+1)%n]-max(1LL*0, a[(i+1)%n] - b[i]);
			s = (i+1)%n;
		}
	}
	// cout << s << "\n";
	ll ans = a[s];
	forn(i, s, s + n-1){
		ans += max(1LL * 0, a[(i+1)%n] - b[i%n]);
	}
	cout << ans << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while(T--){
    	solve();
    }
}
