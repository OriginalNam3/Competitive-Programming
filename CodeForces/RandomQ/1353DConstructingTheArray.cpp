// Problem: D. Constructing the Array
// Contest: Codeforces - Codeforces Round #642 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1353/D
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
    	int n, cnt = 1;
    	cin >> n;
    	vi a(n);
    	priority_queue<pi> q;
    	q.push(mp(n, 0));
    	while (!q.empty()) {
    		int l = q.top().f, i = -(q.top().s);
    		q.pop();
    		if (l == 1) {
    			a[i] = cnt;
    			cnt++;
    			continue;
    		}
    		if (l == 2) {
    			a[i] = cnt;
    			cnt++;
    			q.push(mp(1, -(i+1)));
    			continue;
    		}
    		a[i + (l-1)/2] = cnt;
    		cnt++;
    		q.push(mp((l-1)/2, -i));
    		q.push(mp(l/2, -(i + 1 + (l-1)/2)));
    	}
    	fr(i, 0, n) {
    		cout << a[i] << " ";
    	}
    	cout << "\n";
    }
}
