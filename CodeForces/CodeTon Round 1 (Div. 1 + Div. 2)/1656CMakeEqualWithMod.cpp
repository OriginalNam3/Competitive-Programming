// Problem: C. Make Equal With Mod
// Contest: Codeforces - CodeTON Round 1 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1656/problem/C
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
    	vi a(n);
    	bool one = false;
    	fr(i, 0, n) {
    		cin >> a[i];
    		if (a[i] == 1) one = true;
    	}
    	if (!one) cout << "YES" << "\n";
    	else {
    		bool ok = true;
    		sor(a);
    		rf(i, 1, n) {
    			if (a[i] == a[i - 1] + 1) ok = false;
    		}
    		cout << (ok ? "YES": "NO") << "\n";
    	}
    }
}
