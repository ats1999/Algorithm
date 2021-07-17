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

void combinationUtil(int arr[], int n, int r,
                     int index, int data[], int i, vector<vector<int>> &ans);

/* arr[] ---> Input Array
n ---> Size of input array
r ---> Size of a combination to be printed
index ---> Current index in data[]
data[] ---> Temporary array to store current combination
i ---> index of current element in arr[] */
void combinationUtil(int arr[], int n, int r,
                     int index, int data[], int i, vector<vector<int>> &ans)
{
    // Current combination is ready, print it
    if (index == r)
    {
        vector<int> cur;
        for (int j = 0; j < r; j++)
            cur.push_back(data[j]);
        ans.push_back(cur);
        return;
    }

    // When no more elements are there to put in data[]
    if (i >= n)
        return;

    // current is included, put next at next location
    data[index] = arr[i];
    combinationUtil(arr, n, r, index + 1, data, i + 1, ans);

    // current is excluded, replace it with next (Note that
    // i+1 is passed, but index is not changed)
    combinationUtil(arr, n, r, index, data, i + 1, ans);
}

// The main function that prints all
// combinations of size r in arr[]
// of size n. This function mainly
// uses combinationUtil()
void printCombination(int arr[], int n, int r, vector<vector<int>> &ans)
{
    // A temporary array to store
    // all combination one by one
    int data[r];

    // Print all combination using
    // temporary array 'data[]'
    combinationUtil(arr, n, r, 0, data, 0, ans);
}

int main()
{
    IOS;
    file_io();
    int arr[26];

    int start = 97;
    for (int i = 0; i < 26; i++)
    {
        arr[i] = start;
        start++;
    }

    int r = 5;
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<vector<int>> ans;
    printCombination(arr, n, r, ans);

    cout << "Total: " << ans.size() << endl;

    for (auto v : ans)
    {
        for (int i : v)
        {
            cout << (char)i;
        }
        cout << endl;
    }

    return 0;
}
