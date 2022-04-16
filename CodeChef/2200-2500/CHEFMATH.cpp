// Problem: Chef and math
// Contest: CodeChef - Practice
// URL: https://www.codechef.com/problems/CHEFMATH
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
vi a(2);
int n;

int search(int x, int k, int i){
	if (k == 0 && x == 0) return 1;
	if (i < 0 || x < 0 || (k == 0 && x > 0) || (k > 0 && x == 0) || (1LL * k * a[i] < 1LL * x)) return 0;
	return add(search(x - a[i], k - 1, i), search(x, k, i-1));
}

void solve(){
	int x, k;
	cin >> x >> k;
	auto it = upper_bound(all(a), x) - a.begin();
	it--;
	// debug(it);
	cout << search(x, k, it) << "\n";
}

int main () {
	int i = 2;
	a[0] = 1; a[1] = 2;
	while (true){
		ll b = a[i-1] + a[i-2];
		if (b > mod){
			break;
		}
		a.pb(b);
		i++;
	}
	// each(x, a) debug(x);
	n = a.size();
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int q;
    cin >> q;
    rep(q){
    	solve();
    }
}
