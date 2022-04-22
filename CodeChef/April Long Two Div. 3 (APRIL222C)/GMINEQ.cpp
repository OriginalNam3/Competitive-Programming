// Problem: Geometric Mean Inequality
// Contest: CodeChef - April Long Two 2022 Division 3 (Rated)
// URL: https://www.codechef.com/APRIL222C/problems/GMINEQ
// Memory Limit: 256 MB
// Time Limit: 500 ms
// Date & Time: 2022-04-22 12:13:17
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
	int n;
	cin >> n;
	int cnt1 = 0, cnt2 = 0;
	forn(i, 0, n){
		int x;
		cin >> x;
		if (x == 1) cnt2++;
		else cnt1++;
	}
	int seq1 = n/2, seq2 = n/2 + n%2, a[2][2] = {{seq1/2, seq1/2 + seq1%2}, {seq2/2, seq2/2 + seq2%2}};
	forn(i, 0, 2) forn(j, 0, 2){
		if (a[0][i] + a[1][j] == cnt1 && a[0][!i] + a[1][!j] == cnt2){
			cout << "Yes\n";
			return;
		}
	}
	cout << "No\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
