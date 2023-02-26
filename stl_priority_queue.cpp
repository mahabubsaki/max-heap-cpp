#include <bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int> pq;
    pq.push(2);
    pq.push(6);
    pq.push(3);
    pq.push(1);
    pq.push(8);
    while (pq.size())
    {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}