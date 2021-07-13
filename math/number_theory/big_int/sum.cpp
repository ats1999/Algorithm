//============================================================================
// Name        : Add big integers
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : https://www.tutorialspoint.com/sum-of-two-large-numbers-in-cplusplus
// T.C         : O(N)
// A.S         : O(N)
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

/**
 * Convert string a and b into integer array and store them into a_int and b_int respectively.
 * @param {String} a
 * @param {String} b
 * @param {vector} a_int
 * @param {vector} b_int
 */
void preProcess(string &a, string &b, vector<int> &a_int, vector<int> &b_int)
{
    // convert both string of numbers into array of integers
    // '7'-'0' = 7
    for (char c : a)
        a_int.push_back(c - '0');
    for (char c : b)
        b_int.push_back(c - '0');

    // reverse both integer arrays
    // addition will become easy when we reverse them
    reverse(a_int.begin(), a_int.end());
    reverse(b_int.begin(), b_int.end());
}

/**
 * Add numbers of string a and b and store them into integer array ans.
 * @param {String} a
 * @param {String} b
 * @param {vector} ans
 */
void sumBigInts(string a, string b, vector<int> &ans)
{
    vector<int> a_int, b_int;
    preProcess(a, b, a_int, b_int);

    // add
    int carry = 0, idx;
    for (idx = 0; idx < min(a_int.size(), b_int.size()); idx++)
    {
        long long sum = a_int[idx] + b_int[idx] + carry;
        ans.push_back(sum % 10);
        carry = sum / 10;
    }

    // if a_int has more numbers
    for (; idx < a_int.size(); idx++)
    {
        int sum = a_int[idx] + carry;
        ans.push_back(sum % 10);
        carry = sum / 10;
    }

    // if a_int has more numbers
    for (; idx < b_int.size(); idx++)
    {
        int sum = b_int[idx] + carry;
        ans.push_back(sum % 10);
        carry = sum / 10;
    }

    if (carry > 0)
        ans.push_back(carry);

    // reverse the ans back
    reverse(ans.begin(), ans.end());
}

// use num+'0' to convert number to character
// use num-'0' to convert character to number

// TODO: Optimization-1 (AS)
//      answer can be stored into an string with the help of function
//      this way we can save an array

// TODO: Optimization-2 (AS)
//      we do not need to create a_int and b_int
//      we can directly manipulate the input string and store the result into bigger string

int main()
{
    IOS;
    file_io();

    // a and b are two input numbers
    string a, b;
    cin >> a >> b;
    vector<int> ans;
    sumBigInts(a, b, ans);
    for (int i : ans)
        cout << i;
    return 0;
}
