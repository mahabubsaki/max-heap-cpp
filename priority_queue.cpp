#include <bits/stdc++.h>
using namespace std;
class MaxHeap
{
public:
    vector<int> nodes;
    MaxHeap()
    {
    }
    void up_heapify(int idx)
    {
        while (idx > 0 && nodes[idx] > nodes[(idx - 1) / 2])
        {
            swap(nodes[idx], nodes[(idx - 1) / 2]);
            idx = (idx - 1) / 2;
        }
    }
    void insert(int x)
    {
        nodes.push_back(x);
        up_heapify(nodes.size() - 1);
    }
    void printHeap()
    {
        for (int i = 0; i < nodes.size(); i++)
        {
            cout << nodes[i] << " ";
        }
    }
    void delete_index(int idx)
    {
        if (idx >= nodes.size())
            return;
        swap(nodes[idx], nodes[nodes.size() - 1]);
        nodes.pop_back();
        down_heapify(idx);
    }
    void down_heapify(int idx)
    {
        while (true)
        {
            int large = idx;
            int left = (2 * idx) + 1;
            int right = (2 * idx) + 2;
            if (left < nodes.size() && nodes[large] < nodes[left])
            {
                large = left;
            }
            if (right < nodes.size() && nodes[large] < nodes[right])
            {
                large = right;
            }
            if (large == idx)
            {
                break;
            }
            swap(nodes[idx], nodes[large]);
            idx = large;
        }
    }
    int getMax()
    {
        if (nodes.empty())
        {
            cout << "Heap is empty" << endl;
            return -1;
        }
        return nodes[0];
    }
    int extract_max()
    {
        if (nodes.empty())
        {
            cout << "Heap is empty" << endl;
            return -1;
        }
        int ret = nodes[0];
        delete_index(0);
        return ret;
    }
    void build_from_array(vector<int> &a)
    {
        nodes = a;
        int n = nodes.size();
        int last_non_leaf = (n / 2) - 1;
        for (int i = last_non_leaf; i >= 0; i--)
        {
            down_heapify(i);
        }
    }
    int getSize()
    {
        return nodes.size();
    }
};
class PriorityQueue
{
public:
    MaxHeap h;
    PriorityQueue()
    {
    }
    void push(int x)
    {
        h.insert(x);
    }
    void pop()
    {
        h.delete_index(0);
    }
    int top()
    {
        return h.getMax();
    }
    int size()
    {
        return h.getSize();
    }
};
int main()
{
    PriorityQueue p;
    p.push(3);
    p.push(20);
    p.push(90);
    p.push(21);
    p.push(18);
    p.push(121);
    while (p.size())
    {
        cout << p.top() << " ";
        p.pop();
    }

    return 0;
}