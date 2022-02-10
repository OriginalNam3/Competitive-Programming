#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct person {
    bool searched = false;
    vector<int> sus;
    vector<int> homies;
};



int count(int grid){
    
}

int main() {
    int t;
    cin >> t;
    while (t--){
        int a, b, c;
        cin >> a >> b >> c;
        c = c == 'imposters';
        if (c){
            bakas[a].sus.push_back(b);
            bakas[b].sus.push_back(a);
        }
        else {
            bakas[a].homies.push_back(b);
            bakas[b].homies.push_back(a);
        }

    }
    return 0;
}