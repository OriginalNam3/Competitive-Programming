// Problem: E. Expand the Path
// Contest: Codeforces - Educational Codeforces Round 123 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1644/E
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
#define each(x, a) for (auto& x: a)


int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
    	long long n;
    	cin >> n;
    	str s;
    	cin >> s;

    	int ex = 1, ey = 1, fri = -1, fdi = -1, lri = -1, ldi = -1;
    	fr(i, 0, s.size()) {
    		if (s[i] == 'D') {
    			if (fdi == -1) fdi = i;
    			ex++;
    			ldi = i;
    		}
    		else {
    			if (fri == -1) fri = i;
    			ey++;
    			lri = i;
    		}
    	}
    	
    	if (lri == -1 || ldi == -1) {
    		cout << n << "\n";
    		continue;
    	}
    	
    	int x = 1, y = 1;
    	long long cnt = 0;
    	fr(i, 0, s.size()) {
    		if (i == fri) {
    			y = n - ey + 1;
    		}
    		if (i == ldi && ldi != fdi) {
    			cnt += (n - y) * (ex - x - 1);
    		}
    		if (s[i] == 'R') {
    			y++;
    		}
    		else {
    			x++;
    			cnt += n - y;
    		}
    		// cout << x << " " << y << " " << cnt << "\n";
    	}
    	x = 1; y = 1;
   		// cout << "\n";
    	fr(i, 0, s.size()) {
    		if (i == fdi) {
    			x = n - ex + 1;
    		}
    		if (i == lri && lri != fri) {
    			cnt += (n - x) * (ey - y - 1);
    			y = n - 1;
    		}
    		if (s[i] == 'D') {
    			x++;
    		}
    		if (s[i] == 'R') {
    			y++;
    			cnt += n - x;
    		}
    		// cout << x << " " << y << " " << cnt << "\n";
    	}

    	long long ans = n * n;
    	ans -= cnt;
    	cout << ans << "\n";
    }
}
