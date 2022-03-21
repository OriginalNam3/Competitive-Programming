// Problem: B. Absent Remainder
// Contest: Codeforces - Educational Codeforces Round 118 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1613/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = long double; // or double if tight TL

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

#define f(i,a,b) for (int i = (a); i < (b); ++i)
#define r(i,a,b) for (int i = (b)-1; i >= (a); --i)

int main () {
    int t; 
    cin >> t;
    while (t--) {
    	int n;
    	cin >> n;
    	vi a(n);
    	int maxn = 0;
    	f(i, 0, n) {
    		cin >> a[i];
    	}
    	sor(a);
    	
    	f(i, 1, n/2 + 1){
    		cout << a[i] << " " << a[0] << "\n";
    	}
    }
}
