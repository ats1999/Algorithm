//============================================================================
// Name        :
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use, contribute and distribute it.
// Description :
// T.C         : O()
// A.S         : O()
//============================================================================

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

int MOD = 1e9 + 9;
int P = 31;

void p_powCompute(int ar[], int len)
{
    ar[0] = 1;
    for (int i = 1; i < len; i++)
    {
        ar[i] = (ar[i - 1] * P) % MOD;
    }
}

long long hashStr(string str, int p_pow[])
{
    long long hash = 0;
    for (int i = 0; i < str.length(); i++)
    {
        hash += (str[i] - 'a' + 1) * p_pow[i] % MOD;
    }
    return hash;
}

int solve(const string A, const string B)
{
    int p_pow[A.length()];
    int count = 0;
    p_powCompute(p_pow, A.length());

    long long hashB = hashStr(B, p_pow);
    long long hashA = 0;
    for (int i = 0; i < B.length(); i++)
        hashA += (A[i] - 'a' + 1) * p_pow[i] % MOD;

    // cout << "hash: " << hashA << ", " << hashB << endl;
    if (hashA == hashB)
        count++;

    for (int i = 1; i < A.length() - B.length() + 1; i++)
    {
        hashA -= (A[i] - 'a' + 1) * p_pow[0] % MOD;
        hashA /= P;
        hashA += (A[i + B.length() - 1] - 'a' + 1) * p_pow[B.length() - 1] % MOD;

        // cout << i << " -> hash: " << hashA << ", " << hashB << endl;
        if (hashA == hashB)
            count++;
    }
    return count;
}
int main()
{
    IOS;
    file_io();
    int t;
    cin >> t;

    string a, b;
    cin >> a >> b;
    cout << solve(a, b);
    return 0;
}
