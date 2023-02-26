#include <bits/stdc++.h>
using namespace std;
int main()
{
    multiset<int> a;
    a.insert(5);
    a.insert(6);
    a.insert(60);
    a.insert(661);
    a.insert(326);
    a.insert(326);
    a.insert(16);
    a.insert(62);
    a.insert(162);
    a.insert(64);
    a.insert(64);
    a.insert(64);
    a.insert(64);
    a.insert(64);
    a.insert(64);

    for (auto i : a)
    {
        cout << i << " ";
    }
    cout << endl;
    a.erase(64);
    for (auto i : a)
    {
        cout << i << " ";
    }
    a.erase(a.find(326));
    cout << endl;
    for (auto i : a)
    {
        cout << i << " ";
    }
    if (a.find(999) != a.end())
    {
        a.erase(a.find(999));
    }
    for (auto i : a)
    {
        cout << i << " ";
    }
    return 0;
}