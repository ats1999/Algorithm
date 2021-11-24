//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 17
// Copyright   : Everyone can freely use and distribute it.
// Description : https://www.codechef.com/NOV21B/problems/MAXBRIDGE
// T.C         : O()
// A.S         : O()
//============================================================================

#include <bits/stdc++.h>
using namespace std;

#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr)

void file_io() {
#ifndef ONLINE_JUDGE
    freopen("/home/rahul/Desktop/Algorithm/input.txt", "r", stdin);
    freopen("/home/rahul/Desktop/Algorithm/output.txt", "w", stdout);
#endif
}

int main() {
    IOS;
    file_io();
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        if (n - 1 == m) {
            // all edges are bridge
            for (int i = 1; i < n; i++) {
                cout << i << " " << (i + 1) << endl;
            }
        } else if (n * (n - 1) / 2 == m) {
            // there is no bridge in the graph
            for (int i = 1; i < n; i++) {
                for (int j = i + 1; j <= n; j++) {
                    cout << i << " " << j << endl;
                }
            }
        } else {
            // general case
            vector<unordered_set<int>> G(n + 1);
            for (int i = 1; i < n; i++) {
                G[i].insert(i + 1);
            }

            m -= (n - 1);

            for (int i = 3; i <= n; i++) {
                for (int j = 1; j < i; j++) {
                    if (m == 0) break;

                    if(G[j].find(i) == G[j].end()){
                        G[j].insert(i);
                        m--;
                    }
                }
                if (m == 0) break;
            }

            for(int i=1; i<=n; i++){
                for(int node:G[i]){
                    cout<<i<<" "<<node<<endl;
                }
            }
        }
    }
    return 0;
}