// Problem: D. Xenia and Bit Operations
// Contest: Codeforces - Codeforces Round #197 (Div. 2)
// URL: https://codeforces.com/problemset/problem/339/D
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
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    int lgn = n;
    n = (1 << n);
    vi a(n);
    forn(i, 0, n){
    	cin >> a[i];
    }
	vector<vi> t(lgn+1, vi(n));
	forn(i, 0, n){
		t[lgn][i] = a[i];
	}
	rofn(i, 0, lgn){
		bool x = (lgn-i+1)%2;
		forn(j, 0, (1 << i)){
			if (x){
				t[i][j] = t[i+1][j*2] ^ t[i+1][j*2+1];
			}
			else{
				t[i][j] = t[i+1][j*2] | t[i+1][j*2+1];
			}
		}
	}
	// forn(i, 0, lgn+1){
		// forn(j, 0, n){
			// cout << t[i][j] << " ";
		// }
		// cout << "\n";
	// }
	// cout << "\n";
	rep(m){
		int p, b;
		cin >> p >> b;
		p--;
		t[lgn][p] = b;
		rofn(i, 0, lgn){
			p/=2;
			if ((lgn - i + 1) % 2) t[i][p] = t[i+1][p * 2] ^ t[i+1][p * 2 + 1];
			else t[i][p] = t[i+1][p * 2] | t[i+1][p * 2 + 1];
		}
		cout << t[0][0] << "\n";
	}
}
