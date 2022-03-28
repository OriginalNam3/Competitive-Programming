// Problem: C. Divisibility by Eight
// Contest: Codeforces - Codeforces Round #306 (Div. 2)
// URL: https://codeforces.com/problemset/problem/550/C
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
    str n;
    cin >> n;
    vi a(n.size());
    fr(i, 0, n.size()){
    	a[i] = n[i] - '0';
    }
    
    fr(i, 0, n.size()){
    	if (a[i] % 8 == 0) {
    		cout << "YES\n" << a[i];
    		return 0;
    	}
    	fr(j, i+1, n.size()){
    		int c = 10 * a[i] + a[j];
    		if (c % 8 == 0){
    			cout << "YES\n" << c;
    			return 0;
    		}
    		fr(k, j + 1, n.size()){
    			int d = c * 10 + a[k];
    			if (d % 8 == 0) {
    				cout << "YES\n" << d;
    				return 0;
    			}
    		}
    	}
    }
    cout <<"NO";
}
