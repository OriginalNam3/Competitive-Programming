// Problem: D. Not Adding
// Contest: Codeforces - Codeforces Round #766 (Div. 2)
// URL: https://codeforces.com/contest/1627/problem/D
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

#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define pb push_back

#define fr(i,a,b) for (int i = (a); i < (b); ++i)
#define rf(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define each(x, a) for (auto& x: a)

#define MAXN 1e6+1

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n, m = 0;
    cin >> n;
    vb a(MAXN);
    fr(i, 0, n) {
    	int x;
    	cin >> x;
    	a[x] = 1;
    	if (x > m) m = x;
    }
    
    int cnt = 0;
    fr(i, 1, m + 1) {
    	if (a[i]) {
    		cnt += 1;
    		continue;
    	}
    	int c = 0;
    	for (int j = i; j <= m; j += i) {
    		if (a[j]) {
    			if (c == 0) c = j;
    			c = gcd(c, j);
    		}
    	}
    	if (c == i) cnt += 1;
    }
    cout << cnt - n << "\n";
}
