// Problem: D. Madoka and the Best School in Russia
// Contest: Codeforces - Codeforces Round #777 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1647/D
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


int prime(int a) {
	for (int i = 2; i * i <= a; i++) {
		if (a % i == 0) return i;
	}
	return -1;
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
    	int x, d, a=0;
    	cin >> x >> d;
    	while (x % d == 0) {
    		x /= d;
    		a++;
    	}
    	if (a == 1) {
    		cout << "NO\n";
    		continue;
    	}
    	int bp = prime(x), dp = prime(d);
    	if (bp != -1) {
    		cout << "YES\n";
    		continue;
    	}
		if (dp == -1 || a < 3) {
			cout << "NO\n";
			continue;
		}
		int e = d, c = 0;
		while (e % dp == 0) {
			e /= dp;
			c++;
		}
		if (e == 1 && c == 2 && x == dp && a == 3) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
    }
}
