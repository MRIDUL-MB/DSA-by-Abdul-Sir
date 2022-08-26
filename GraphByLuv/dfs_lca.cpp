// INTUITION
//  1) find the path of both the given node
//  2) return last common node

#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
vector<int> G[N];

int par[N];

void dfs(int vertex, int parent)
{
    par[vertex] = parent;
    for (auto child : G[vertex])
    {
        if (child == parent)
            continue;
        dfs(child, vertex);
    }
}

vector<int> findPath(int vertex)
{
    vector<int> ans;
    while (vertex)
    {
        ans.push_back(vertex);
        vertex = par[vertex];
    }
    reverse(ans.begin(), ans.end());
    return ans;
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

    dfs(1, 0);
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << par[i] << " " << endl;
    // }

    vector<int> path1 = findPath(6);
    vector<int> path2 = findPath(7);
    int min_len = min(path1.size(), path2.size());
    int lca = 0;
    for (int i = 0; i < min_len; i++)
    {
        if (path1[i] == path2[i])
            lca = path1[i];
        else
            break;
    }
    cout << lca;
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