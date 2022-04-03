// Problem: C. Longest Regular Bracket Sequence
// Contest: Codeforces - Codeforces Beta Round #5
// URL: https://codeforces.com/problemset/problem/5/C
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
typedef array<int, 3> qq;

#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define pb push_back

#define forn(i,a,b) for (int i = (a); i < (b); ++i)
#define rofn(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define rep(n) for (int _ = 0; _ < n; _++)
#define each(x, a) for (auto& x: a)

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    str s;
    cin >> s;
    int n = s.size();
    stack<int> seq;
    int a[n], b[n];
    forn(i, 0, n){
    	a[i] = -1; b[i] = -1;
    	if (s[i] == ')'){
    		if (!seq.empty()){
    			int l = seq.top();
    			a[i] = l;
    			seq.pop();
    			if (l > 0) if (b[l-1] != -1) l = b[l-1];
    			b[i] = l;
    		}
    	}
    	else{
    		// cout << i << " pushed\n";
    		seq.push(i);
    	}
    }
    int mx = 0, cnt = 0;
    forn(i, 0, n){
    	// cout << b[i] << " ";
    	if (b[i] == -1) continue;
    	if (i - b[i] + 1 > mx){
    		mx = i - b[i] + 1;
    		cnt = 1;
    		continue;
    	}
    	if (i - b[i] + 1 == mx){
    		cnt++;
    	}
    }
    // cout << "\n";
    if (mx == 0){
    	cout << "0 1";
    	return 0;
    }
    cout << mx << " " << cnt;
}
