// Problem: C. Connect the Points
// Contest: Codeforces - 2021-2022 ICPC, NERC, Northern Eurasia Onsite (Unrated, Online Mirror, ICPC Rules, Teams Preferred)
// URL: https://codeforces.com/problemset/problem/1666/C
// Memory Limit: 512 MB
// Time Limit: 3000 ms
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
#define rsor(x) sort(x.rbegin(), x.rend())
#define pb push_back

#define forn(i,a,b) for (int i = (a); i < (b); ++i)
#define fors(i,a,b,s) for (int i = (a); i < (b); i+=s)
#define rofn(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define rep(n) for (int _ = 0; _ < n; _++)
#define each(x, a) for (auto& x: a)
#define debug(x) cout << #x << " = " << x << "\n";

const int mod = 1e9+7;
const int INF = INT_MAX >> 1;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

void solve(){

}

bool ycmp(pi a, pi b){return a.s < b.s;}
bool xcmp(pi a, pi b){return a.f < b.f;}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    vpi a(3);
    vpi b(3);
    forn(i, 0, 3) {
    	cin >> a[i].f >> a[i].s;
    	b[i].f = a[i].f; b[i].s = a[i].s;
    }
    cout << "3\n";
    sort(all(a), xcmp);
    sort(all(b), ycmp);
    cout << a[0].f << " " << b[1].s << " " << a[2].f << " " << b[1].s << "\n";
    cout << b[0].f << " " << b[0].s << " " << b[0].f << " " << b[1].s << "\n";
    cout << b[2].f << " " << b[2].s << " " << b[2].f << " " << b[1].s << "\n";
}
