// Problem: D. Three Integers
// Contest: Codeforces - Codeforces Round #624 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1311/D
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
#define fors(i,a,b,s) for (int i = (a); i < (b); i+=s)
#define rofn(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define rep(n) for (int _ = 0; _ < n; _++)
#define each(x, a) for (auto& x: a)

const int mod = 1e9+7;
const int INF = INT_MAX >> 1;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

vector<vb> a(1001, vb(1001));

void solve(){
	int a, b, c;
	cin >> a >> b >> c;
	int o = INF, na, nb, nc;
	forn(i, 1, 2 * a+1){
		fors(j, i, 2*b+1, i){
			if (abs(a-i) + abs(b - j) + min(c%j, j-c%j) < o){
				o = abs(a-i) + abs(b - j) + min(c%j, j-c%j);
				na = i, nb = j;
				if (c%j < j - c%j){
					nc = c - c%j;
				}
				else nc = c + j - c%j;
			}
		}
	}
	cout << o << "\n";
	cout << na << " " << nb << " " << nc << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    forn(i, 1, 1001){
    	a[1][i] = 1;
    }
    forn(i, 2, 1001){
    	fors(j, i, 1001, i){
    		a[i][j] = 1;
    	}
    }
    int t;
    cin >> t;
    while(t--){
    	solve();
    }
}
