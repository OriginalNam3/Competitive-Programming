// Problem: D. Carousel
// Contest: Codeforces - Codeforces Round #629 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1328/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double db;
typedef string str;
typedef pair<int,int> pi;
#define mp make_pair
#define f first
#define s second

typedef queue<int> qi; typedef queue<long long> qll;
typedef vector<int> vi; typedef vector<long long> vll; typedef vector<bool> vb; 

#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define pb push_back

#define fr(i,a,b) for (int i = (a); i < (b); ++i)
#define rf(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define each(x, a) for (auto& x: a)

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    while (q--) {
    	int n, di;
    	cin >> n;
    	vi t(n);
    	bool ok = false, diff = false;
    	fr(i, 0, n) {
    		cin >> t[i];
    		if (i > 0) {
    			if (t[i] == t[i-1]) {
	    			ok = true;
	    			di = i;
    			}
    			if (t[i] != t[i-1]) {
    				diff = true;
    			}
    		}
    	}
    	if (!diff) {
    		cout << "1\n";
    		fr(i, 0, n) cout << "1 ";
    		cout << "\n";
    		continue;
    	}
    	if (n%2 == 0 || t[0] == t[n-1]) {
    		cout << "2\n";
    		fr(i, 0, n) {
    			cout << i % 2 + 1 << " ";
    		}
    		cout << "\n";
    		continue;
    	}
    	if (ok) {
    		cout << "2\n";
    		fr(i, 0, n-1) {
    			if (i == di) {
    				i--;
    				di = -1;
    			}
    			cout << i % 2 + 1 << " ";
    		}
    		if (di == n - 1) {
    			cout << n % 2 + 1;
    		}
    		cout <<"\n";
    		continue;
    	}
    	
    	cout << "3\n";
    	fr(i, 0, n-1){
    		cout << i % 2 + 1 << " ";
    	}
    	cout << "3\n";
    }
}
