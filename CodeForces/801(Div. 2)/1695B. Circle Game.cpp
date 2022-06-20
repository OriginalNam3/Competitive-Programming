// Problem: B. Circle Game
// Contest: Codeforces - Codeforces Round #801 (Div. 2) and EPIC Institute of Technology Round
// URL: https://codeforces.com/contest/1695/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-06-18 15:44:50
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
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x: a) cin >> x;
	
	if (n % 2){
		cout << "Mike\n";
		return;
	}
	int sum1 = INT_MAX, sum2 = INT_MAX;
	
	for (int i = 0 ; i < n; i += 2){
		sum1 = min(sum1, a[i]);
	}
	for (int i = 1; i < n; i += 2){
		sum2 = min(sum2, a[i]);
	}
	if (sum1 > sum2){
		cout << "Mike\n";
		return;
	}
	if (sum2 > sum1){
		cout << "Joe\n";
		return;
	}
	int i = 0;
	for (; i < n; i += 2){
		if (a[i] == sum1){
			break;
		}
	}
	int j = 1;
	for (; j < n; j += 2){
		if (a[j] == sum2){
			break;
		}
	}
	if (i < j){
		cout << "Joe\n";
	}
	else{
		cout << "Mike\n";
	}
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; 
    cin >> t;
    while (t--)
    solve();
}
