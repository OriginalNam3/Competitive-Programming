// Problem: C. LIS or Reverse LIS?
// Contest: Codeforces - Codeforces Round #793 (Div. 2)
// URL: https://codeforces.com/contest/1682/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-05-22 15:35:11
// 
// Powered by CP Editor (https://cpeditor.org)

// https://codeforces.com/profile/Intellegent <3

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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    
    map<int, int> cnt;
    int dup = 0, unique = 0;
    for (int i = 0; i < n; i++){
    	cnt[a[i]]++;
    	if (cnt[a[i]] == 2){
    		dup++;
    	}
    	if (cnt[a[i]] == 1){
    		unique++;
    	}
    }
    unique -= dup;
    
    cout << dup + unique / 2 + unique%2 << "\n";
    // debug(l) debug(r)
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
