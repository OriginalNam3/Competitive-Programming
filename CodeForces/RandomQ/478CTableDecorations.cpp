// Problem: C. Table Decorations
// Contest: Codeforces - Codeforces Round #273 (Div. 2)
// URL: https://codeforces.com/problemset/problem/478/C
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
    ios::sync_with_stdio(false);
    cin.tie(0);
    vll a(3);
    cin >> a[0] >> a[1] >> a[2];
    sor(a);
    int cnt = 0;
    while (a[1] && a[2] && 1LL * a[0] + a[1] + a[2] >= 3) {
    	sor(a);
    	if (a[2] - a[0] <= 1) {
    		cnt += a[0];
    		break;
    	}
    	if (a[2] >= 2 * (a[0] + a[1])) {
    		cnt += a[0] + a[1];
    		break;
    	}
    	int t = min(a[1] - a[0], (a[2] - a[0])/2);
    	if (t == 0) {
    		t = ((4 * a[0]) - a[2])/3;
    		if (t == 0) {
    			t = 1;
    		}
    		t = a[1] - t;
    		if (t == 0) t = 1;
			if (a[2] >= 4 * t) {a[0] -= t;
			cnt += t;
			a[2] -= 2 * t;}
    	}
    	if (a[1] > a[0] + a[2] - a[1] + 3) {
    		t = (2 * a[1] - a[2] - a[0])/3;
    		a[1] -= 2 * t;
    		a[2] -= t;
    		cnt += t;
    	}
    	a[1] -= t;
    	a[2] -= 2 * t;
    	// cout << t << "\n";
    	// cout << a[0] << " " << a[1] << " " << a[2] << "\n";
    	cnt += t;
    }
	
	cout << cnt;
}
