// Problem: B. Stone Age Problem
// Contest: Codeforces - Codeforces Round #791 (Div. 2)
// URL: https://codeforces.com/contest/1679/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-05-14 10:35:13
// 
// Powered by CP Editor (https://cpeditor.org)

// You either sink in the coom, or coom in the sink.

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double db;
typedef string str;

#define mp make_pair
#define f first
#define s second

#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rsor(x) sort(x.rbegin(), x.rend())
#define pb push_back

#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

const int mod = 1e9+7;
const int INF = INT_MAX >> 1;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

void solve(){
	
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> upd(n, -1), a(n);
    ll ans = 0;
    for (int &x: a) {
    	cin >> x;
    	ans += x;
    }
    
    int cur = 0, last = -1;
    for (int rep = 0; rep < q; rep++){
    	int t;
    	cin >> t;
    	if (t == 1){
    		int i, x;
    		cin >> i >> x;
    		i--;
    		if (last > upd[i]) {
    			ans += x - cur;
    		}
    		else{
    			ans += x - a[i];
    		}
    		a[i] = x;
    		upd[i] = rep;
    	}
    	if (t == 2){
    		last = rep;
    		cin >> cur;
    		ans = 1LL * cur * n;
    	}
    	cout << ans << "\n";
    }
}
