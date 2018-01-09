#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

typedef long long ll;

int expthis(int base, int ex) //include a conditions beforehand anytime you call this function
{
    int i, ans;
    ans = 1;
    for(i = 0; i < ex; i++) ans *= base;
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    if(n > 30) cout << m << endl;
    else cout << (m % expthis(2, n)) << endl;
    return 0;
}