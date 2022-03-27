// Problem: C. Bracket Sequence Deletion
// Contest: Codeforces - Educational Codeforces Round 125 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1657/C
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
    	int n;
    	cin >> n;
    	int cnt = 0, b = 0, li = 0, i = 0;
    	str s;
    	cin >> s;
    	while (i < s.size() - 1) {
    		if (s[i] == ')'){
    			i++;
    			while (i < s.size()) {
    				if (s[i] == ')') {
    					i++;
    					li = i;
    					cnt++;
    					break;
    				}
    				i++;
    			}
    		}
    		else {
    			i += 2;
    			li = i;
    			cnt++;
    		}
    	}
    	cout << cnt << " " << s.size() - li << "\n";
    }
}
