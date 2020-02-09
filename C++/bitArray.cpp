/*
https://www.hackerrank.com/challenges/bitset-1/problem
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

bitset<2147483648> a;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int N,S,P,Q;
    cin>>N>>S>>P>>Q;
    //a.reset();
    unsigned int prev = S;
    a.set(S,1);
    for(int i=1;i<N;i++){
        int b = ((prev*P)+Q) % 0x80000000;
        a.set(b,1);
        prev = b;
    }
    cout<<a.count()<<endl;
    return 0;
}
