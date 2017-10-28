#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
    int dest[100007], cycles[100007];
    int i, j, k, t, n, ncycles = 0;
    ll ans = 0;
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> dest[i];
        dest[i]--;
    }

    for(i = 0; i < n; i++)
    {
        if(dest[i] != -1)
        {
            j = i;
            k = 0;
            while(dest[j] != -1)
            {
                t = dest[j];
                dest[j] = -1;
                k++;
                j = t;   
            }
            cycles[ncycles] = k;
            ncycles++;
        }
    }      
    sort(cycles, cycles + ncycles);
    for(i = 0; i < ncycles - 2; i++)
    {
        ans += ((ll) cycles[i]) * ((ll)cycles[i]);
    }
    if(ncycles > 1) 
    { ans +=
        ((ll)(cycles[ncycles - 1] + cycles[ncycles - 2])) * 
        ((ll) (cycles[ncycles - 1] + cycles[ncycles - 2]));
    }
    else ans += ((ll)cycles[0]) * ((ll) cycles[0]);

    cout << ans;

    return 0;
}