// Problem: A. Game of Life
// Contest: Codeforces - Deltix Round, Spring 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/problemset/problem/1523/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
    	int n, m;
    	cin >> n >> m;
    	str state;
    	cin >> state;
    	vb a(state.size() + 2, 0);
    	fr(i, 1, a.size() - 1) a[i] = state[i - 1] - '0';
    	fr(i, 0, min(n, m)){
    		vb fa(a.size(), 0);
    		fr(j, 1, a.size() - 1) {
    			if (a[j-1] ^ a[j+1]) {
    				fa[j] = 1;
    			}
    			if (a[j]) fa[j] = 1;
    		}
    		fr(j, 0, a.size()) a[j] = fa[j];
    	}
    	fr(i, 1, a.size() - 1) cout << a[i];
    	cout << endl;
    }
}
