#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
vector<int> G[N];

int Sum_Subtree[N];
int Even_Subtree[N];

void dfs(int vertex, int parent = 0)
{
    if (vertex % 2 == 0)
        Even_Subtree[vertex] += 1;
    Sum_Subtree[vertex] += vertex;
    for (auto child : G[vertex])
    {
        if (child == parent)
            continue;
        dfs(child, vertex);
        Sum_Subtree[vertex] += Sum_Subtree[child];
        Even_Subtree[vertex] += Even_Subtree[child];
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
    cout << endl;
    cout << "Sum"
         << "  "
         << "Even" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << Sum_Subtree[i] << "  " << Even_Subtree[i] << endl;
    }
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