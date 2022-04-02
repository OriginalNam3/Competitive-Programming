// Problem: B. Stoned Game
// Contest: Codeforces - Codeforces Round #666 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1396/B
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

void solve(){
	int n;
    cin >> n;
    int m = 0, sum = 0;
    forn(i, 0, n){
    	int x;
    	cin >> x;
    	m = max(m, x);
    	sum += x;
    }
    if (m > sum - m){
    	cout << "T\n";
    	return;
    }
    cout << (sum%2 ? "T\n": "HL\n");
    return;
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--){
    	solve();
    }
}
