#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int n = atoi(argv[1]), m = atoi(argv[2]), l = (n + m - 1) / m;
    cout << n << " " << m << endl;
    while (m--){
    	cout << rnd.next(l, n) << " ";
    }
}