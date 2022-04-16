// Problem: Bear and House Queries
// Contest: CodeChef - Practice
// URL: https://www.codechef.com/problems/QHOUSE
// Memory Limit: 256 MB
// Time Limit: 500 ms
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

const int mod = 1e9+7;
const int INF = INT_MAX >> 1;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

bool q(int x, int y){
	cout << "? " << x << " " << y << "\n";
	cout.flush();
	str inp;
	cin >> inp;
	return inp == "YES";
}

void solve(){
	
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll sidelen, base, height;
    int l = 1, r = 1000;
    while (l < r){
    	int m = (l + r)/2;
    	if (l == r-1) m++;
    	if (q(m, 0)) l = m;
    	else r = m-1;
    }
    sidelen = l * 2;
    l = 1, r = 1000;
    while (l < r){
    	int m = (l + r)/2;
    	if (l == r-1) m++;
    	if (q(m, sidelen)) l = m;
    	else r = m-1;
    }
    base = l;
    l = 1, r = 1000 - sidelen;
    while (l < r){
    	int m = (l + r)/2;
    	if (l == r-1) m++;
    	if (q(0, sidelen + m)) l = m;
    	else r = m-1;
    }
    height = l;
    cout << "! " << sidelen * sidelen + base * height;
}
