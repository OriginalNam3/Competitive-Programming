// Problem: Concert Tickets
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1091
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Date & Time: 2022-05-03 00:05:56
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

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> h(n);
    for (int &x: h) cin >> x;
    vector<int> t(m);
    for (int &x: t) cin >> x;
    
    set<int> a;
    map<int, int> cnt;
    for (int x: h){
    	a.insert(x);
    	cnt[x]++;
    }
    for (int x: t){
    	auto it = a.upper_bound(x);
    	if (it == a.begin()){
    		cout << "-1\n";
    	}
    	else{
    		it--;
    		cout << *it << "\n";
    		if (--cnt[*it] == 0) a.erase(it);
    	}
    }
}