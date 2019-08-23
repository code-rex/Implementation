/*
Knight movement on a chess board

Given any source point and destination point on a chess board, we need to find whether Knight can move to the destination or not.

Knight's movements on a chess board

The above figure details the movements for a knight ( 8 possibilities ). Note that a knight cannot go out of the board.

If yes, then what would be the minimum number of steps for the knight to move to the said point.
If knight can not move from the source point to the destination point, then return -1

Input:

N, M, x1, y1, x2, y2
where N and M are size of chess board
x1, y1  coordinates of source point
x2, y2  coordinates of destination point
Output:

return Minimum moves or -1
Example

Input : 8 8 1 1 8 8
Output :  6
*/

int bfsmove(int **board,int N,int M,int starti,int startj,int endi,int endj){

queue<pair<int,int> > q;

//Use this directional additives to help you chose the directions
//This will help you in avoiding writing 8 if-else conditions
vector <vector <int> > dir={{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2}};

//Level vector to store the shortest distance traveled so far
vector <vector<int> > lev(N,vector<int>(M,0));

q.push(make_pair(starti,startj));
board[starti][startj]=1;

while(!q.empty()){
    
    pair<int,int> p=q.front();
    q.pop();
    
    for(int i=0;i<8;i++){
        int newr=p.first+dir[i][0];
        int newc=p.second+dir[i][1];
        
        if(newr>=0 && newr<N && newc>=0 && newc<M && !board[newr][newc]){
            lev[newr][newc]=lev[p.first][p.second]+1;
            board[newr][newc]=1;
            q.push(make_pair(newr,newc));
            
            if(newr==endi && newc==endj)
                return lev[endi][endj];
        }
    }
}
return -1; //Return -1 if endi and endj are never encountered
}

int Solution::knight(int A, int B, int C, int D, int E, int F) {

if(C==E && D==F)
    return 0;

int **board=new int*[A];

for(int i=0;i<A;i++){
    board[i]=new int[B];
    for(int j=0;j<B;j++){
        board[i][j]=0;
    }
}
//BFS is used here as we need to reach the shortest path as soon as possible
int ans=bfsmove(board,A,B,C-1,D-1,E-1,F-1);//C,D,E and F are orignally 1 based converting to them 0 based

return ans;
}
