#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;
vector<int> G[N];
bool isVisited[N];

bool dfs(int vertex, int parent)
{
    // Take action on vertex after entering
    bool isLoop = false;
    isVisited[vertex] = true;
    for (auto child : G[vertex])
    {
        // Take action on child before entering
        if (parent == child)
            continue;
        if (isVisited[child])
            return true;
        isLoop |= dfs(child, vertex);

        // Take action on child after exiting
    }
    // Take action on vertex before exiting
    return isLoop;
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
    bool isLoop = false;
    for (int i = 0; i < m; i++)
    {
        if (isVisited[i])
            continue;
        if (dfs(i, i))
        {
            isLoop = true;
            break;
        }
    }
    isLoop ? cout << "true" : cout << "false";
}

// input:
//  8 6
//  1 2
//  1 5
//  2 3
//  2 4
//  3 5
//  6 7