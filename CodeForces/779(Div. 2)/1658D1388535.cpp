// Problem: D1. 388535 (Easy Version)
// Contest: Codeforces - Codeforces Round #779 (Div. 2)
// URL: https://codeforces.com/contest/1658/problem/D1
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

#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define pb push_back

#define fr(i,a,b) for (int i = (a); i < (b); ++i)
#define rf(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define each(x, a) for (auto& x: a)

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
    	int l, r;
    	cin >> l >> r;
    	vi a(17);
    	vi b(17);
    	fr(i, l, r + 1) {
    		int k = i;
    		fr(j, 0, 17) {
    			if (k & 1) a[j]++;
    			k >>= 1;
    		}
    		int y;
    		cin >> y;
    		fr(j, 0, 17) {
    			if (y & 1) b[j]++;
    			y >>= 1;
    		}
    	}
    	long long ans = 0;
    	rf(i, 0, 17) {
    		if (a[i] != b[i]) ans +=1;
    		ans <<= 1;
    	}
    	ans >>= 1;
    	cout << ans << "\n";
    }
}
