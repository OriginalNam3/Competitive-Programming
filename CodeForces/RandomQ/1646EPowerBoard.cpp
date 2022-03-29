// Problem: E. Power Board
// Contest: Codeforces - Codeforces Round #774 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1646/E
// Memory Limit: 256 MB
// Time Limit: 1500 ms
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

#define fr(i,a,b) for (int i = (a); i < (b); ++i)
#define rf(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define each(x, a) for (auto& x: a)

#define MLG 20
#define MAXN 1000001

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m, cnt = 0;
    cin >> n >> m;
    vb product(MLG * MAXN + 1);
    vi c(MLG + 1);
    fr(i, 1, MLG + 1){
    	fr(j, 1, m + 1) {
    		if (!product[i * j]){
    			product[i * j] = 1;
    			cnt++;
    		}
    	}
    	c[i] = cnt;
    }
    vb good(n + 5, 1);
    vi rows(n + 5, 1);
    for (int i = 2; i * i <= n; i++){
    	if (good[i] == 0) continue;
    	// cout << i << " is good\n";
    	for (int j = i; i * j <= n; j *= i){
    		good[i * j] = 0;
    		rows[i]++;
    	}
    }
    ll ans = 1;
    fr(i, 2, n+1){
    	if (!good[i]) continue;
    	ans += c[rows[i]];
    }
    cout << ans;
}
