// Problem: E. Tetrahedron
// Contest: Codeforces - Codeforces Round #113 (Div. 2)
// URL: https://codeforces.com/problemset/problem/166/E
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

const int mod = 1e9+7;
const int INF = INT_MAX >> 1;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

#define REP(i, n) for(int i = 0; i < (n); i++)
int n = 4; // matrix size
struct Matrix{
	vector<vector<int> > a = vector<vector<int> >(n, vector<int>(n));
	Matrix operator *(const Matrix& other){
		Matrix product; 
		vector<vector<int> > tmp(n, vector<int>(n));
		REP(i, n) REP(j, n) REP(k, n){
			product.a[i][k] = add(product.a[i][k], mul(a[i][j], other.a[j][k]));
		}
		return product;
	}
};

void solve(){
	
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int len;
    cin >> len;
    Matrix res, p;
    REP(i, n) REP(j, n){
    	if (i == j) {
    		p.a[i][j] = 0;
    		res.a[i][j] = 1;
    	}
    	else p.a[i][j] = 1;
    }
    while (len > 0){
    	if (len&1){
    		res = res * p;
    	}
    	p = p * p;
    	len >>= 1;
    }
    cout << res.a[0][0];
}
