// Problem: G. Special Permutation
// Contest: Codeforces - Codeforces Round #640 (Div. 4)
// URL: https://codeforces.com/problemset/problem/1352/G
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

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--){
    	int n;
    	cin >> n;
    	if (n <= 3) {
    		cout << -1 << "\n";
    		continue;
    	}
    	if (n == 4) {
    		cout << "3 1 4 2\n";
    		continue;
    	}
    	int c = -(n % 2) + 2, d = 2;
    	fr(i, 0, n) {
    		cout << c << " ";
    		if (c == n) {
    			c -= 3;
    			d = -2;
    			continue;
    		}
    		if (c == n - 3) {
    			c += 2;
    			continue;
    		}
    		if (c == n - 1) {
    			c -= 4;
    			continue;
    		}
    		c += d;
    	}
    	cout << "\n";
    }
}
