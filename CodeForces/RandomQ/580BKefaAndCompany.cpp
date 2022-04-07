// Problem: B. Kefa and Company
// Contest: Codeforces - Codeforces Round #321 (Div. 2)
// URL: https://codeforces.com/problemset/problem/580/B
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
const int INF = INT_MAX >> 1;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

bool cmp (pi x, pi y){return x.f < y.f;}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, d;
    cin >> n >> d;
    vpi a(n);
    forn(i, 0, n){
    	cin >> a[i].f >> a[i].s;
    }
    sort(all(a), cmp);
    
    ll ans = 0, sum = 0;
    int j = 0;
    forn(i, 0, n){
    	while (j < n && a[j].f < a[i].f + d){
    		sum += a[j].s;
    		j++;
    	}
    	// cout << sum << "\n";
    	ans = max(ans, sum);
    	sum -= a[i].s;
    }
    cout << ans;
}
