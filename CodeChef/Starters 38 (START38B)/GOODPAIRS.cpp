// Problem: Good Pairs
// Contest: CodeChef - CodeChef Starters 38 Division 2 (Rated)
// URL: https://www.codechef.com/START38B/problems/GOODPAIRS
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-05-11 15:31:59
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

#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

const int mod = 1e9+7;
const int INF = INT_MAX >> 1;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x: a) cin >> x;
	vector<int> b(n);
	for (int &x: b) cin >> x;
	map<pair<int, int>, int> cnt;
	
	ll ans = 0;
	for (int i = 0; i < n; i++){
		ans += cnt[mp(b[i], a[i])];
		cnt[mp(a[i], b[i])]++;
	}
	cout << ans << "\n";
} 

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
