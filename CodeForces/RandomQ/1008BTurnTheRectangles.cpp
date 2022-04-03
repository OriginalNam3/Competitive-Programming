// Problem: B. Turn the Rectangles
// Contest: Codeforces - Codeforces Round #497 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1008/B
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

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vpi a(n);
    vi b(n);
    bool ok = true;
    forn(i, 0, n){
    	cin >> a[i].f >> a[i].s;
    }
    b[0] = max(a[0].f, a[0].s);
    forn(i, 1, n){
    	if (min(a[i].f, a[i].s) > b[i-1]){
    		ok = false;
    		break;
    	}
    	if (max(a[i].f, a[i].s) <= b[i-1]){
    		b[i] = max(a[i].f, a[i].s);
    	}
    	else b[i] = min(a[i].f, a[i].s);
    }
    cout << (ok ? "YES": "NO");
}
