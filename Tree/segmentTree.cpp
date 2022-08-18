#include <bits/stdc++.h>
using namespace std;

int arr[1000], seg[4 * 1000 + 10];

void build(int idx, int l, int h)
{
    if (l == h)
    {
        seg[idx] = arr[l];
        return;
    }
    int mid = (l + h) / 2;
    build(2 * idx + 1, l, mid);
    build(2 * idx + 2, mid + 1, h);
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    seg[idx] = max(seg[left], seg[right]);
}

int query(int idx, int left, int right, int l, int r)
{

    // completely
    if (left >= l && right <= r)
    {
        return seg[idx];
    }
    if (left > r || right < l)
        return INT_MIN;
    int mid = (left + right) / 2;
    int leftVal = query(2 * idx + 1, left, mid, l, r);
    int rightVal = query(2 * idx + 2, mid + 1, right, l, r);
    return max(leftVal, rightVal);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    build(0, 0, n - 1);
    int l, r;
    cin >> l >> r;
    cout << query(0, 0, n - 1, l, r) << endl;
}