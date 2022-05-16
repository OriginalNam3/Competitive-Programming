// Problem: Maximum Subarray Sum
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1643
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Date & Time: 2022-05-14 15:47:08
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    
    ll bst = INT_MIN, cur = 0;
    for (int i = 0; i < n; i++){
    	cur = max(cur + a[i], 1LL * a[i]);
    	bst = max(bst, cur);
    }
    
    cout << bst;
}
