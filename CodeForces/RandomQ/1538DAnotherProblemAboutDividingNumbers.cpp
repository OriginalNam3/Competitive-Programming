// Problem: D. Another Problem About Dividing Numbers
// Contest: Codeforces - Codeforces Round #725 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1538/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
using vb = vector<bool>;
using vpi = vector<pi>;

#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define pb push_back

#define fr(i,a,b) for (int i = (a); i < (b); ++i)
#define rf(i,a,b) for (int i = (b)-1; i >= (a); --i)

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
    	int a, b, k;
    	cin >> a >> b >> k;
    	if (k == 1) {
    		cout << ((max(a, b) % min(a, b) || (a == b)) ? "NO": "YES") << "\n";
    		continue;
    	}
    	int p = 2;
    	int ca = 0, cb = 0;
    	while (a > 1 && p * p <= a) {
    		while (a % p == 0) {
    			a /= p;
    			ca++;
    		}
    		p++;
    	}
    	p = 2;
    	while (b > 1 && p * p <= b) {
    		while (b % p == 0) {
    			b /= p;
    			cb++;
    		}
    		p++;
    	}
    	if (a > 1) ca++;
    	if (b > 1) cb++;
    	cout << ((ca + cb >= k) ? "YES": "NO") << "\n";
    }
}
