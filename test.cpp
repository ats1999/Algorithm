#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE 
	    freopen("/home/rahul/Desktop/Algorithm/input.txt", "r", stdin);  
	    freopen("/home/rahul/Desktop/Algorithm/output.txt", "w", stdout); 
    #endif 


    int t;
    cin>>t;
    while(t--){
        vector<string>grid(3);
        cin>>grid[0]>>grid[1]>>grid[2];
        
        // number of times the player won
        int numWinX=0, numWinO=0,countX=0, countO=0;

        // check for each i
        for(int i=0; i<3; i++){
            int colCountX=0, colCountO=0;
            int rowCountX=0, rowCountO=0;
            for(int j=0; j<3; j++){
                // row wise
                if(grid[i][j] == 'X')
                    rowCountX++;
                else if(grid[i][j] == 'O')
                    rowCountO++;

                // col wise
                if(grid[j][i] == 'X')
                    colCountX++;
                else if(grid[j][i] == 'O')
                    colCountO++;
            }

            // increment the number of times X and O wins
            if(colCountX == 3)
                numWinX++;
            else if(colCountO == 3)
                numWinO++;

            if(rowCountX == 3)
                numWinX++;
            else if(rowCountO == 3)
                numWinO++;
        }

        // count diagonal
        int diagX=0, diagO=0;
        diagX = (grid[0][0] == 'X') + (grid[1][1] == 'X') + (grid[2][2] == 'X');
        diagO = (grid[0][0] == 'O') + (grid[1][1] == 'O') + (grid[2][2] == 'O');

        if(diagX == 3)
            numWinX++;
        else if(diagO == 3)
            numWinO++;

        // reset
        diagX=0, diagO=0;
        diagX = (grid[0][2] == 'X') + (grid[1][1] == 'X') + (grid[2][0] == 'X');
        diagO = (grid[0][2] == 'O') + (grid[1][1] == 'O') + (grid[2][0] == 'O');

        if(diagX == 3)
            numWinX++;
        else if(diagO == 3)
            numWinO++;

        // count total
        int totalX=0, totalO = 0;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(grid[i][j] == 'X')
                    totalX++;
                else if(grid[i][j] == 'O')
                    totalO++;
            }
        }
        
        if((numWinX+numWinO)>1 || abs(numWinX-numWinO)>1)
            cout<<3<<endl;
        else if(numWinX==1 || numWinO == 1 || (totalO + totalX)==9)
            cout<<1<<endl;
        else cout<<2<<endl;
    }
	return 0;
}
