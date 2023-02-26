#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<string, int> mp;
    mp["goru"] = 1;
    mp["chagol"] = 2;
    mp["murgi"] = 4;
    mp["ghora"] = 3;
    for (auto i : mp)
    {
        cout << "key : " << i.first << " , Value : " << i.second << endl;
    }
    return 0;
}