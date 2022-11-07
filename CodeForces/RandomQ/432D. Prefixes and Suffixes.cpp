// Problem: D. Prefixes and Suffixes
// Contest: Codeforces - Codeforces Round #246 (Div. 2)
// URL: https://codeforces.com/problemset/problem/432/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-06-21 13:38:31
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
	str s;
	cin >> s;
	
	int n = s.length();
	vector<int> z(n);
	z[0] = n;
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    dbg(z);
    vector<ll> cnt(n + 1);
    for (int i = 0; i < n; i++){
    	cnt[z[i]]++;
    }
    dbg(cnt);
    for (int i = n - 1; i >= 0; i--){
    	cnt[i] += cnt[i + 1];
    }
    
    
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--){
    	if (z[i] == n - i){
    		ans.pb(z[i]);
    		dbg(i);
    	}
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++){
    	cout << ans[i] << " " << cnt[ans[i]] << "\n";
    }
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
}
