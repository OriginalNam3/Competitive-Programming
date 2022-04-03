// Problem: B. String Mood
// Contest: Codeforces - Matrix Exponentiation
// URL: https://codeforces.com/gym/102644/problem/B
// Memory Limit: 256 MB
// Time Limit: 250 ms
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

const int mod = 1e9 + 7;

int add (int &a, int b){
	a = (1LL * a + b) % mod;
	return a;
}

int mul (int a, int b){
	return (1LL * a * b) % mod;
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll n;
    cin >> n;
    int a[2][2] = {{19, 7}, {6, 20}};
    int res[2][2] = {{1, 0}, {0, 1}}; // identity matrix
    while (n > 0){
    	if (n & 1){
    		int product[2][2] = {{0, 0}, {0, 0}};
    		forn(i, 0, 2) forn(j, 0, 2) forn (k, 0, 2){
    			add(product[i][k], mul(res[i][j], a[j][k]));
    		}
    		forn(i, 0, 2) forn(j, 0, 2) res[i][j] = product[i][j];
    	}
    	int product[2][2] = {{0, 0}, {0, 0}};
    	forn(i, 0, 2) forn(j, 0, 2) forn (k, 0, 2){
    		add(product[i][k], mul(a[i][j], a[j][k]));
    	}
    	forn(i, 0, 2) forn(j, 0, 2) a[i][j] = product[i][j];
    	n >>= 1;
    }
    cout << res[0][0];
}
