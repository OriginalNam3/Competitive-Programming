// Problem: B. Fun with Even Subarrays
// Contest: Codeforces - Codeforces Round #768 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1631/B
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
#define rofn(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define rep(n) for (int _ = 0; _ < n; _++)
#define each(x, a) for (auto& x: a)

const int mod = 1e9+7;
const int INF = INT_MAX >> 1;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

void solve(){
	int n;
	cin >> n;
	vi a(n);
	forn(i, 0, n){
		cin >> a[i];
	}
	int cnt = 0, i = 0;
	while (a[n-i-1] == a[n-1] && i < n){
		i++;
	}
	while (i < n){
		while(i < n && a[n-i-1] == a[n-1]){
			i++;
		}
		if (i == n) break;
		cnt++;
		i <<= 1;
	}
	cout << cnt << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--){
    	solve();
    }
}
