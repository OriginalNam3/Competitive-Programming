// Problem: A. Good Pairs
// Contest: Codeforces - CodeTON Round 1 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1656/problem/A
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
    	int n;
    	cin >> n;
    	vi a(n);
    	vi b(n);
    	fr(i, 0, n) {
    		cin >> a[i];
    		b[i] = a[i];
    	}
    	
    	if (n == 1) {
    		cout << "1 1" << "\n";
    		continue;
    		}
    	sor(a);
    	int mine = a[0], maxe = a[n-1];
    	fr(i, 0, n) {
    		if (b[i] == mine){
    			cout << i + 1 << " ";
    			mine = -1;
    		}
    		else if (b[i] == maxe) {
    			cout << i + 1 << " ";
    			maxe = -1;
    		}
    	}
    	cout << endl;
    }
}
