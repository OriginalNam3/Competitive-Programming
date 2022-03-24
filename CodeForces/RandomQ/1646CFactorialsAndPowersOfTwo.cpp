// Problem: C. Factorials and Powers of Two
// Contest: Codeforces - Codeforces Round #774 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1646/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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

long long fact[14];
vector<pair<long long, int> > sums(16384);

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    fact[0] = 1;
    fr(i, 1, 14) fact[i] = fact[i-1] * (i+1);
    
    fr(i, 0, 16384) {
    	long long x = 0;
    	int y = i, c = 0;
    	fr(j, 0, 14) {
    		if (y & 1) {
    			x += fact[j]; 
    			c++;
    		}
    		y >>= 1;
    	}
    	sums[i] = mp(x, c);
    }
    
    int t;
    cin >> t;
    while (t--) {
    	long long n;
    	cin >> n;
    	int k = INT_MAX;
    	fr(i, 0, 16384) {
    		long long x = n - sums[i].f;
    		if (x < 0) continue;
    		int c = sums[i].s;
    		fr (j, 0, 64){
    			if (x & 1) c++;
    			x >>= 1;
    		}
    		if (c < k) {
    			k = c;
    		}
    	}
    	cout << k << "\n";
    }
}
