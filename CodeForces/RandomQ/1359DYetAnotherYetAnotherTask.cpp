// Problem: D. Yet Another Yet Another Task
// Contest: Codeforces - Educational Codeforces Round 88 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1359/D
// Memory Limit: 512 MB
// Time Limit: 1500 ms
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
const int INF = -(1<<20);
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vi a(n);
    forn(i, 0, n){
    	cin >> a[i];
    }
    int ans = 0;
    forn(mx, -30, 31){
    	vi b(n);
    	int sum = a[0], nans = INF;
    	if (a[0] > mx) sum = INF;
    	bool ok = a[0] == mx;
    	forn(i, 1, n){
    		if (a[i] == mx) ok = true;
    		
    		if (a[i] > mx){
    			b[i] = INF;
    		}
    		else{
    			b[i] = a[i];
    		}
    		sum = max(sum + b[i], b[i]);
    		nans = max(nans, sum);
    	}
    	if (ok) {
    		// cout << ans << " " << nans << "\n";
    		ans = max(ans, nans - mx);
    	}
    }
    cout << ans;
}
