// Problem: A. Great Sequence
// Contest: Codeforces - Codeforces Round #773 (Div. 1)
// URL: https://codeforces.com/contest/1641/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
    	int n, x;
    	cin >> n >> x;
    	vi a(n);
    	map<int, int> b;
    	fr(i, 0, n) {
    		cin >> a[i];
    		b[a[i]]++;
    		// cout << a[i] << "\n";
    		// cout << b[a[i]] << "\n";
    	}
    	int cnt = 0;
    	sor(a);
    	
    	fr(i, 0, n) {
    		if (b[a[i]] == 0) {
    			continue;
    		}
    		if (a[i] > INT_MAX/x) {
    			cnt++;
    		}
			else {
				if (!b[a[i] * x]) {
					cnt++;
				}
				else {
					b[a[i] * x]--;
				}
			}
			b[a[i]]--;
    	}
    	cout << cnt << "\n";
    }
}
