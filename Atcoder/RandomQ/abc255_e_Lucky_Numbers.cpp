// Problem: E - Lucky Numbers
// Contest: AtCoder - Aising Programming Contest 2022（AtCoder Beginner Contest 255）
// URL: https://atcoder.jp/contests/abc255/tasks/abc255_e
// Memory Limit: 1024 MB
// Time Limit: 4000 ms
// Date & Time: 2022-06-11 14:52:49
// 
// Powered by CP Editor (https://cpeditor.org)

// https://codeforces.com/profile/Intellegent husbando <3

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double db;
typedef string str;

#define mp make_pair
#define f first
#define s second

#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rsor(x) sort(x.rbegin(), x.rend())
#define pb emplace_back

#ifdef ORIGINAL_LOCAL
#include <bits/debug.h>
#else
#define dbg(...) 42
#endif

const int mod = 1e9+7;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

void solve(){
	int n, m;
    cin >> n >> m;
    vector<int> b(n-1), c(m);
    for (int &x: b) cin >> x;
    for (int &x: c) cin >> x;
    
    map<ll, int> ocnt, ecnt;
    vector<ll> a(n);
    ecnt[0]++;
    for (int i = 1; i < n; i++){
    	a[i] = b[i-1] - a[i-1];
    	if (i % 2) ocnt[a[i]]++;
    	else ecnt[a[i]]++;
    }
    
    int ans = 0, cur;
    ll e;
    for (int i = 0; i < n; i++){
    	for (int j = 0; j < m; j++){
    		if (i % 2 == 0) e = c[j] - a[i];
    		else e = a[i] - c[j];
    		dbg(e, i);
    		cur = 0;
    		for (int k = 0; k < m; k++){
    			auto it = ocnt.find(c[k] + e);
    			if (it != ocnt.end()) cur += it->s;
    			it = ecnt.find(c[k] - e);
    			if (it != ecnt.end()) cur += it->s;
    		}
    		ans = max(ans, cur);
    	}
    }
    
    cout << ans;
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
}
