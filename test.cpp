#include <bits/stdc++.h>
using namespace std;
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr)
void file_io()
{
#ifndef ONLINE_JUDGE
    freopen("/home/rahul/Desktop/Algorithm/input.txt", "r", stdin);
    freopen("/home/rahul/Desktop/Algorithm/output.txt", "w", stdout);
#endif
}

int main()
{
    IOS;
    file_io();

    vector<int> a{1, 2, 3};
    int *b;
    b = &a;
    b[1]=789;
    for (int i : a)
        cout << i << " ";
    cout << endl;

    for (int i : b)
        cout << i << " ";
    cout << endl;

    return 0;
}
