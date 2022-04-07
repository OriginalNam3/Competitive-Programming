// Problem: A. And Matching
// Contest: Codeforces - Codeforces Round #768 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1630/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

void solve(){
	int n, k;
	cin >> n >> k;
	if (k == 3 && n == 4){
		cout << "-1\n";
		return;
	}
	
	int mlg = __lg(n)-1, b = n-1;

	if (k == 0){
		forn(i, 0, n/2){
			int j = i^b;
			cout << i << " " << j << "\n";
		}
		return;
	}
	
	if (k == b){
		cout << 0 << " " << 2 << "\n";
		cout << 1 << " " << n-3 << "\n";
		cout << n-1 << " " << n-2 << "\n";
		forn(i, 3, n/2){
			int j = i ^ b;
			cout << i << " " << j << "\n";
		}
		return;
	}
	
	int c = k ^ b;
	cout << b << " " << k << "\n";
	cout << 0 << " " << c << "\n";
	forn(i, 1, n/2){
		if (i == k || i == c) continue;
		int j = i ^ b;
		cout << i << " " << j << "\n";
	}
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--){
    	solve();
    }
}
