#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;
vector<int> G[N];
bool isVisited[N];

void dfs(int vertex)
{
    // Take action on vertex after entering
    isVisited[vertex] = true;
    cout << "Parent: " << vertex << endl;
    for (auto child : G[vertex])
    {
        // Take action on child before entering

        cout << "Parent: " << vertex << ", "
             << "Child: " << child << endl;
        if (isVisited[child])
            continue;
        dfs(child);

        // Take action on child after exiting
    }
    // Take action on vertex before exiting
}

int main()
{
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        G[v1].push_back(v2);
        G[v2].push_back(v1);
    }
    dfs(1);
}

// input:
// 6 9
// 1 3
// 1 5
// 3 5
// 3 4
// 3 6
// 3 2
// 2 6
// 4 6
// 5 6
