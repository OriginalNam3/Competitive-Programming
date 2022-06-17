// Problem: A. Creep
// Contest: Codeforces - Goodbye Exams (TK L)
// URL: https://codeforces.com/contest/1693/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-06-17 19:25:08
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
	int a, b;
	cin >> a >> b;
	if (a < b){
		for (int i = 0; i < a; i ++){
		cout << "01";
		}
		for (int i = a; i < b; i++){
			cout << "1";
		}
	}
	else{
		for (int i = 0; i < b; i ++){
		cout << "01";
		}
		for (int i = b; i < a; i++){ 
			cout << "0";
		}
	}
	cout << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; 
    cin >> t;
    while (t--)
    solve();
}
