// Problem: Make them Equal
// Contest: CodeChef - START43
// URL: https://www.codechef.com/submit-v2/MAKEQUAL
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-06-15 21:31:35
// 
// Powered by CP Editor (https://cpeditor.org)

// https://codeforces.com/profile/Intellegent husbando <3

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
#define pb emplace_back

#ifdef ORIGINAL_LOCAL
#include <bits/debug.h>
#else
#define dbg(...) 42
#endif

const int mod = 1e9+7;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

void solve(){
	ll a, b, c;
	cin >> a >> b >> c;
	for (int i = 0; i < 40; i++){
		if (a == b && b == c){
			cout << "YES\n";
			return;
		}
		int cnt = ((a >> i) & 1) + ((b >> i) & 1) + ((c >> i) & 1);
		
		if (cnt == 1){
			if ((a >> i) & 1) a += (1LL << i);
			else if ((b >> i) & 1) b += (1LL << i);
			else if ((c >> i) & 1) c += (1LL << i);
		}
		else if (cnt == 2){
			if (!((a >> i) & 1)) a += (1LL << i);
			else if (!((b >> i) & 1)) b += (1LL << i);
			else if (!((c >> i) & 1)) c += (1LL << i);
		}
		else{
			break;
		}
	}
	cout << "NO\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; 
    cin >> t;
    while (t--)
    solve();
}
