// Problem: D. Buying Shovels
// Contest: Codeforces - Codeforces Round #644 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1360/D
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
    	int n, k;
		cin >> n >> k;
		int d = n;
		for (int x = 1; x * x <= n; x++){
			if (n % x == 0){
				if (x <= k) d = min(d, n/x);
				if (n/x <= k) d = min(d, x);
			}
		}
		cout << d << "\n";
    }
}
