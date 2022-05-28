// Problem: D. Required Length
// Contest: Codeforces - Educational Codeforces Round 129 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1681/problem/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// Date & Time: 2022-05-23 16:08:40
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
#define pb push_back

#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

const int mod = 1e9+7;
const int INF = INT_MAX >> 1;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

ll qpow(ll a, int b){  // returns a^b % c
	ll res = 1;
	while (b > 0){
		if (b & 1) res *= a;
		b >>= 1;
		a *= a;
	}
	return res;
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll n, x;
    cin >> n >> x;
    ll t = qpow(10, n - 1);
    
    vector<ll> q;
    q.pb(x);
    vector<bool> cnt(10);

    for (int rep = 0; rep < 100; rep++){
    	int siz = q.size();
    	for (int j = 0; j < siz; j++){
    		ll cur = q[j];
    		// debug(cur)
    		str s = to_string(cur);
    		if (cur / t > 0){
    			if (cur / t < 10){
    				cout << rep;
    				return 0;
    			}
    			continue;
    		}
	    	cnt.assign(10, 0);
	    	for (int i = 0; i < s.size(); i++){
	    		cnt[s[i] - '0'] = 1;
	    	}
	    	for (int i = 2; i < 10; i++){
	    		if (cnt[i]) {
	    			ll ncur = cur * i;
	    			q.pb(ncur);
	    		}
	    	}
    	}
    	sort(q.rbegin(), q.rend());
    	if (q.size() > 1000) q.resize(1000);
    }
    cout << -1;
}
