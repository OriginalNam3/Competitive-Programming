// Problem: E. Rescheduling the Exam
// Contest: Codeforces - Codeforces Round #776 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1650/E
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
    while (t--){
        int n, d;
        cin >> n >> d;
        vi a(n + 1);
        fr (i, 1, n + 1) cin >> a[i];
        int minr = INT_MAX, mini = 0;
        fr(i, 1, n + 1){
            int r = a[i] - a[i-1] - 1;
            if (r <= minr) {
                minr = r;
                mini = i;
            }
        }
        

        
        int ans = minr;
        
        vi b;
        b.pb(0);
        fr(i, 1, n + 1) {
        	if (i == mini) continue;
        	b.pb(a[i]);
        }
        
        int maxr = d - b[n - 1] - 1;
        minr = INT_MAX;
        fr(i, 1, n) {
        	int r = b[i] - b[i-1] - 1;
        	if (r > maxr) maxr = r;
        	if (r < minr) minr = r; 
        }
        
        ans = max(ans, min(minr, max((maxr - 1) / 2, d - b[n - 1] - 1)));
        
        if (mini > 1) {
        	b.clear();
        	b.pb(0);
        	fr(i, 1, n + 1) {
        		if (i == mini - 1) continue;
        		b.pb(a[i]);
        	}
        	maxr = d - b[n - 1] - 1;
	        minr = INT_MAX;
	        fr(i, 1, n) {
	        	int r = b[i] - b[i-1] - 1;
	        	if (r > maxr) maxr = r;
	        	if (r < minr) minr = r;
	        }

	        ans = max(ans, min(minr, max((maxr - 1) / 2, d - b[n - 1] - 1)));
        }
        cout << ans << "\n";
    }
}
