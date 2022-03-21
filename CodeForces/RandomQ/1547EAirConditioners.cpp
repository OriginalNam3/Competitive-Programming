// Problem: E. Air Conditioners
// Contest: Codeforces - Codeforces Round #731 (Div. 3)
// URL: https://codeforces.com/contest/1547/problem/E
// Memory Limit: 512 MB
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
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    while (q--){
    	int n, k;
    	cin >> n >> k;
    	vi a(k);
    	f(i, 0, k) cin >> a[i];

    	vi t(n);
    	f(i, 0, k) cin >> t[a[i]-1];
    	
    	vi rt(n);
    	if (t[0]) rt[0] = t[0];
    	f(i, 1, n) {
    		if (t[i]) {
    			if (rt[i-1] > 0){
    				rt[i] = min(rt[i-1] + 1, t[i]);
    			}
    			else rt[i] = t[i];
    		}
    		else if (rt[i-1]){
    			rt[i] = rt[i-1] + 1;
    		}
    	}
    	
    	vi lt(n);
    	if (t[n-1]) lt[n-1] = t[n-1];
    	r(i, 0, n-1){
    		if (t[i]) {
    			if (lt[i+1] > 0) {
    				lt[i] = min(lt[i+1] + 1, t[i]);
    			}
    			else lt[i] = t[i];
    		}
    		else if (lt[i+1]){
    			lt[i] = lt[i+1] + 1;
    		}
    	}
    	
    	f(i, 0, n) {
    		if (lt[i] == 0 || rt[i] == 0) cout << max(lt[i], rt[i]) << " ";
    		else cout << min(lt[i], rt[i]) << " ";
    	}
    	cout << "\n";
    }
}
