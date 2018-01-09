#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

typedef long long ll;


int main()
{
    int i, j, k, l, n;
    cin >> n;
    vector< vector< int > > tree (n + 1);

    for(i = 2; i < n + 1; i++){
        cin >> j;
        tree[j].push_back(i);
    }

    for(i = 1; i < n + 1; i++){
        k = 0;
        for(j = 0; j < tree[i].size(); j++){
            l = tree[i][j];
            if(tree[l].size() == 0) k++;
            if(k == 3) j = 1002;
        }

        if(j != 0 && j != 1003) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes";
    return 0;
}