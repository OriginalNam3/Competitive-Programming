// Problem: B. Maximum Value
// Contest: Codeforces - Codeforces Round #276 (Div. 1)
// URL: https://codeforces.com/problemset/problem/484/B
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
#define fors(i,a,b,s) for (int i = (a); i < (b); i += s)
#define rofn(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define rep(n) for (int _ = 0; _ < n; _++)
#define each(x, a) for (auto& x: a)

const int N = 1000005;

int main (){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vi a, b(2 * N);
    vb c(N);
    int mx = 0;
    forn(i, 0, n) {
    	int x;
    	cin >> x;
    	if (c[x]) continue;
    	c[x] = 1;
    	a.pb(x);
    	mx = max(mx, x);
    }
    sor(a);
    
    n = a.size();
    forn(i, 0, n-1){
    	forn(j, a[i]+1, a[i+1]+1){
    		b[j] = a[i];
    	}
    }
    forn(i, a[n-1]+1, 2 * N){
    	b[i] = a[n-1];
    }
    
    int ans = 0;
    forn(i, 0, n){
    	fors(j, a[i] * 2, 2 * mx + 1, a[i]){
    		// cout << j << " " << b[j] << "\n";
    		ans = max(ans, b[j] % a[i]);
    	}
    }
    cout << ans;
}
