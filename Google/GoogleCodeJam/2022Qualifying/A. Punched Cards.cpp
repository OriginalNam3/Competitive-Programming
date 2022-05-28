// Problem: Punched Cards
// Contest: Google Coding Competitions - Qualification Round 2022 - Code Jam 2022
// URL: https://codingcompetitions.withgoogle.com/codejam/round/0000000000876ff1/0000000000a4621b
// Memory Limit: 1024 MB
// Time Limit: 5000 ms
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
    int n;
    cin >> n;
    forn(t, 1, n+1){
    	int r, c;
    	cin >> r >> c;
    	cout << "Case #" << t << ":\n";
    	cout << "..";
    	forn(i, 1, c){
    		cout << "+-";
    	}
    	cout << "+\n";
    	cout << "..";
    	forn(i, 1, c){
    		cout << "|.";
    	}
    	cout << "|\n";
    	forn(i, 1, r){
    		forn(j, 0, c){
    			cout << "+-";
    		}
    		cout << "+\n";
    		forn(j, 0, c){
    			cout << "|.";
    		}
    		cout << "|\n";
    	}
    	forn(j, 0, c){
    		cout << "+-";
    	}
    	cout << "+\n";
    }
}
