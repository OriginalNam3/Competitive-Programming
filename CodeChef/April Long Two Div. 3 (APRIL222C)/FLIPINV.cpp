// Problem: Flip to Invert
// Contest: CodeChef - April Long Two 2022 Division 3 (Rated)
// URL: https://www.codechef.com/APRIL222C/problems/FLIPINV
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-04-22 11:44:18
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
	int n, k;
	cin >> n >> k;
	str s;
	cin >> s;

	// calculating prefix counts of 0s and 1s
	vi ocnt(n), zcnt(n);
	if (s[0] == '1') ocnt[0]++;
	if (s[0] == '0') zcnt[0]++;
	forn(i, 1, n){ 
		ocnt[i] += ocnt[i-1];
		zcnt[i] += zcnt[i-1];
		if (s[i] == '1') ocnt[i]++;
		if (s[i] == '0') zcnt[i]++;
		// cout << ocnt[i] << " " << zcnt[i] << "\n";
	}
	
	
	ll inv = 0; // the number of inversions
	forn(i, 0, n){
		if (s[i] == '1') {
			inv += zcnt[n-1] - zcnt[i];
		}
	}
	

	int oi = 0, zi = n - 1; 
	// oi = position of pointer to leftmost 1
	// zi = position of pointer to current 0 (k from the right)
	
	rep(k){
		while (zi >= 0 && s[zi] == '1') {
			zi--;
		}
		if (zi <= 0) {
			cout << "0\n";
			return;
		}
		inv -= ocnt[zi];
		zi--;
	}
	zi++;
	
	ll ans = inv;
	// inv += ocnt[zi]; // removing the zero to make space for the first 1
	// zi++;
	
	
	// forn(i, 0, n) cout << ocnt[i] << " ";
	// cout << "\n";
	
	forn(i, 0, k){
		// updating two pointers
		while (oi < n && s[oi] == '0') {
			oi++;
		}
		while (zi < n && s[zi] == '1') {
			zi++;
		}
		// if ((ocnt[oi] + zcnt[n-1] - zcnt[min(n - 1, zi)]) > k || (oi >= n && zi >= n)) break;
		// check whether total selected 1s and 0s exceed k and out of bounds
		
		if (oi > zi) {
			ans = 0;
			break;
		}
		
		if (zi < n) inv += ocnt[zi] - ocnt[oi] - (zcnt[zi] - zcnt[oi] - 1);
		else inv -= zcnt[n-1] - zcnt[oi];
		// changing 1 to 0 and 0 to 1
		// changing 1 to 0
		// debug(inv); debug(ans);
		ans = min(ans, inv);
		oi++;
		zi++;
	}
	cout << ans << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
