// Problem: C. Count Triangles
// Contest: Codeforces - Codeforces Round #643 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1355/C
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

#define forn(i,a,b) for (int i = (a); i < (b); ++i)
#define rofn(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define rep(n) for (int _ = 0; _ < n; _++)
#define each(x, a) for (auto& x: a)

const int N = 1000002;

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    vll cnt(N);
    forn(i, A, B+1){
    	cnt[i+B]++;
    	cnt[i+C+1]--;
    }
    forn(i, 1, N){
    	cnt[i] += cnt[i-1];
    }
    forn(i, 1, N){
    	cnt[i] += cnt[i-1];
    }
    ll ans = 0;
    forn(i, C, D+1){
    	ans += cnt[N-1] - cnt[i];
    }
    cout << ans;
}
