// Problem: A. Powered Addition
// Contest: Codeforces - Codeforces Round #633 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1338/A
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
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--){
    	int n;
    	ll m = 0;
    	cin >> n;
    	vll a(n);
    	fr(i, 0, n){
    		cin >> a[i];
    	}
    	ll cm = a[0];
    	fr(i, 1, n){
    		m = max(m, cm - a[i]);
    		if (a[i] > cm) cm = a[i];
    	}
    	if (m == 0) {
    		cout << "0\n";
    		continue;
    	}
    	cout << __lg(m) + 1 << "\n";
    }
}
