// Intuition
// Step1:  Find the max depth node with index.
// Step2: Find  the max depth by taking that index as a root.

#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
vector<int> G[N];

int depth[N];

void dfs(int vertex, int par = -1)
{
    for (auto child : G[vertex])
    {
        if (child == par)
            continue;
        depth[child] = depth[vertex] + 1;
        dfs(child, vertex);
    }
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        G[v1].push_back(v2);
        G[v2].push_back(v1);
    }
    dfs(1);

    int max_depth = 0;
    int max_node;

    for (int i = 1; i <= n; i++)
    {
        if (max_depth < depth[i])
        {
            max_depth = depth[i];
            max_node = i;
        }
        depth[i] = 0;
    }

    dfs(max_node);
    max_depth = -1;
    for (int i = 1; i <= n; i++)
    {
        if (max_depth < depth[i])
        {
            max_depth = depth[i];
            max_node = i;
        }
    }

    cout << "Max Diameter is " << max_depth;
}

// input:
// 13
// 1 2
// 1 3
// 1 13
// 2 5
// 3 4
// 4 9
// 4 10
// 5 6
// 5 7
// 5 8
// 8 12
// 10 11