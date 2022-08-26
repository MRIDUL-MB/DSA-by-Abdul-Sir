// INTUITION
//  1) find the path of both the given node
//  2) return last common node

#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
vector<int> G[N];

int Sum[N];

void dfs(int vertex, int parent)
{
    Sum[vertex] += vertex;
    for (auto child : G[vertex])
    {
        if (child == parent)
            continue;
        dfs(child, vertex);
        Sum[vertex] += Sum[child];
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

    dfs(1, 0);
    int ans = 0;
    int i = 2;
    for (i = 2; i <= n; i++)
    {
        int part1 = Sum[i];
        int part2 = Sum[1] - Sum[i];
        ans = max(ans, part1 * part2);
    }
    cout << "Ans: " << ans << endl;
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