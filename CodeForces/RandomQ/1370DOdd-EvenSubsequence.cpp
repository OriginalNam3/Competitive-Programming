// Problem: D. Odd-Even Subsequence
// Contest: Codeforces - Codeforces Round #651 (Div. 2)
// URL: https://codeforces.com/contest/1370/problem/D
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

#define fr(i,a,b) for (int i = (a); i < (b); ++i)
#define rf(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define each(x, a) for (auto& x: a)

// const int INF = INT_MAX>>1;
// const int MOD = 998244353;

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    vll a(n);
    fr(i, 0, n){
    	cin >> a[i];
    }
    ll l = 1, r = 1e9;
    while (l < r){
    	ll t = (1LL * l + r)/2;
    	bool ok = false;
    	int cnt = 0, i = 0, c = 0;
    	fr(i, 0, n){
    		if (c){
    			cnt++;
    			c ^= 1;
    		}
    		else{
    			if (a[i] <= t){
    				cnt++;
    				c ^= 1;
    			}
    		}
    	}
    	if (cnt >= k) ok = true;
    	else {
    		cnt = 1; c = 0;
    		fr(i, 1, n){
    			if (c){
    				cnt++;
    				c^=1;
    			}
    			else{
	    			if (a[i] <= t){
	    				cnt++;
	    				c ^= 1;
	    			}
    			}
    		}
    		if (cnt >= k) ok = true;
	    }
    	if (ok) r = t;
    	else l = t+1;
    }
    cout << l;
}
