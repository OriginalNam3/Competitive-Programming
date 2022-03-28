// Problem: D. Two Divisors
// Contest: Codeforces - Educational Codeforces Round 89 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1366/D
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

#define MAXN 10000003

int d[MAXN], pf[MAXN];
bool mf[MAXN];

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    fr(i, 0, MAXN) {
    	d[i] = 0;
    }
    fr(i, 2, MAXN) {
    	if (d[i] != 0) continue;
    	d[i] = i;
    	for (int j = i; j < MAXN; j+= i) {
    		d[j] = i;
    	}
    }
    fr(i, 2, MAXN) {
    	int j = i;
		int y = 1;
		while (j % d[i] == 0) {
			j /= d[i];
			y *= d[i];
		}
		if (j > 1) mf[i] = 1;
		else mf[i] = 0;
		pf[i] = y;
    }
    int n;
    cin >> n;
    vi a(n);
    fr(i, 0, n) {
    	cin >> a[i];
    }
    vi d1(n);
    vi d2(n);
    fr(i, 0, n) {
    	if (mf[a[i]] == 0) {
    		d1[i] = -1; d2[i] = -1;
    		continue;
    	}
    	d1[i] = pf[a[i]]; d2[i] = a[i]/ pf[a[i]];
    }
    fr(i, 0, n) cout << d1[i] << " ";
    cout << "\n";
    fr(i, 0, n) cout << d2[i] << " ";
}
