// Problem: D. For Gamers. By Gamers.
// Contest: Codeforces - Educational Codeforces Round 125 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1657/D
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = long double; // or double if tight TL
using str = string;

using pi = pair<int,int>;
#define mp make_pair
#define f first
#define s second

using pqi = priority_queue<int>;
using pqll = priority_queue<long long>;
using qi = queue<int>;
using qll = queue<long long>;
using vi = vector<int>;
using vll = vector<long long>;
using vb = vector<bool>;
using vpi = vector<pi>;

#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define pb push_back

#define fr(i,a,b) for (int i = (a); i < (b); ++i)
#define rf(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define each(x, a) for (auto& x: a)

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, co;
    cin >> n >> co;
    vll a(co + 1);
    fr (i, 0, n) {
    	int c, d, h;
    	cin >> c >> d >> h;
    	a[c] = max(a[c], d * 1LL * h);
    }
    
    fr (i, 1, co + 1) {
    	for (int j = 1; i * j <= co; j++) {
    		a[i * j] = max(a[i * j], a[i] * j);
    	}
    }
    fr (i, 0, co) {
    	a[i+1] = max(a[i], a[i+1]);
    }
    int m;
    cin >> m;
    fr (i, 0, m) {
    	ll d, h;
    	cin >> d >> h;
    	ll p = d * h;
    	if (p >= a[co]) {
    		cout << "-1\n";
    		continue;
    	}
    	int ans = upper_bound(all(a), p) - a.begin();
    	cout << ans << " ";
    }
    cout << "\n";
}
