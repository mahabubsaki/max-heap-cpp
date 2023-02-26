#include <bits/stdc++.h>
using namespace std;
int main()
{
    set<int> x;
    x.insert(3);
    x.insert(6);
    x.insert(5);
    x.insert(8);
    x.insert(40);
    x.insert(42);
    x.insert(4);
    x.insert(31);

    for (auto i = x.begin(); i != x.end(); i++)
    {
        cout << *i << " ";
    }
    x.erase(8);
    for (auto i : x)
    {
        cout << i << " ";
    }
    if (x.find(3) != x.end())
    {
        cout << "found";
    }
    else
    {
        cout << "not found";
    }
    return 0;
}