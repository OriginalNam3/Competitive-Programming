// Problem: C2. Potions (Hard Version)
// Contest: Codeforces - Codeforces Round #723 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1526/C2
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
typedef array<int, 3> qq;

#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define pb push_back

#define fr(i,a,b) for (int i = (a); i < (b); ++i)
#define rf(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define each(x, a) for (auto& x: a)

// void solve(){
// 	
// }

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vi a(n);
    each(x, a) {
    	cin >> x;
    }
    priority_queue<int> q;
    ll h = 0, cnt = 0;
    fr(i, 0, n){
    	// cout << i << " " << a[i] << "\n";
    	if (h + a[i] >= 0){
    		// cout << "DRANK\n";
    		h += a[i];
    		q.push(-a[i]);
    		cnt++;
    	}
    	else{
    		if (!q.empty()){
    			if (-q.top() < a[i] && h + q.top() + a[i] >= 0){
					h += q.top() + a[i];
    				q.pop();
    				q.push(-a[i]);
    			}
    		}
    	}
    }
    cout << cnt;
}
