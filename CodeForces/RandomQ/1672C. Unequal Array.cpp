// Problem: C. Unequal Array
// Contest: Codeforces - Codeforces Global Round 20
// URL: https://codeforces.com/problemset/problem/1672/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-05-04 11:16:51
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
	vi a(n);
	each(x, a) cin >> x;
	int i = 0;
	bool first = 1;
	while(i < n-1){
		if (a[i] == a[i+1]) break;
		i++;
	}
	int j = n-1;
	while (j > 0){
		if (a[j] == a[j-1]) break;
		j--;
	}
	if (i == j - 2){
		cout << 1 << "\n"; return;
	}
	if (i >= j - 1) cout << "0\n";
	else cout << j - i - 2 << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
