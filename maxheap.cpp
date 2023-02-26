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
};
vector<int> heap_sort(vector<int> a)
{
    MaxHeap h;
    h.build_from_array(a);
    vector<int> ans;
    for (int i = 0; i < a.size(); i++)
    {
        ans.push_back(h.extract_max());
    }
    reverse(ans.begin(), ans.end());
    return ans;
};
int main()
{
    MaxHeap h;
    vector<int> a = {1, 2, 3, 4, 10, 9, 8, 7};
    vector<int> sorted = heap_sort(a);
    for (int i = 0; i < sorted.size(); i++)
    {
        cout << sorted[i] << " ";
    }

    return 0;
}