// Problem: C. Shinju and the Lost Permutation
// Contest: Codeforces - Codeforces Round #779 (Div. 2)
// URL: https://codeforces.com/contest/1658/problem/C
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
    while (t--) {
    	int n, start = -1;
    	cin >> n;
    	vi a(n);
    	bool ok = true;
    	fr(i, 0, n) {
    		cin >> a[i];
    		if (a[i] == 1 && start == -1) start = i;
    		else if (a[i] == 1 && start != -1) ok = false;
    		if (i > 0) if (a[i] > a[i-1] + 1) ok = false;
    	}
    	if (n == 1) {
    		cout << "YES\n";
    		continue;
    	}
    	if (a[0] > a[n-1] + 1) ok = false;
    	if (start == -1 || !ok) {
    		cout << "NO\n";
    		continue;
    	}
    	cout << (ok ? "YES\n": "NO\n");
    }
}
