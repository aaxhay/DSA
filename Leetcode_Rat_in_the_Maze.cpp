#include <bits//stdc++.h>
using namespace std;

// solving this problem using recursion and backtracking
class Solution{
    private:
    
    bool isSafe(vector<vector<int>> &m,int n,vector<vector<int>> visited,int x,int y){
        if((x>=0 && x<n && y>=0 && y<n) && visited[x][y]==0 && m[x][y]==1){
            return true;
        }
        else{
            return false;
        }
    }
    
    void solve(vector<vector<int>> &m, int n,vector<string>& ans,vector<vector<int>> visited,
               int srcx ,int srcy,string path){
        
        
        //base case
        if(srcx==n-1 && srcy == n-1){
            ans.push_back(path);
            return;
        }
        
        visited[srcx][srcy] = 1;
        
        //down movement
        int newx = srcx+1;
        int newy = srcy;
        if(isSafe(m,n,visited,newx,newy)){
            path.push_back('D');
            solve(m,n,ans,visited,newx,newy,path);
            path.pop_back();
        }                
        
        //up movement
         newx = srcx-1;
         newy = srcy;
        if(isSafe(m,n,visited,newx,newy)){
            path.push_back('U');
            solve(m,n,ans,visited,newx,newy,path);
            path.pop_back();
        }
        
        //left movement
         newx = srcx;
         newy = srcy-1;
        if(isSafe(m,n,visited,newx,newy)){
            path.push_back('L');
            solve(m,n,ans,visited,newx,newy,path);
            path.pop_back();
        }
        
        //down movement
         newx = srcx;
         newy = srcy+1;
        if(isSafe(m,n,visited,newx,newy)){
            path.push_back('R');
            solve(m,n,ans,visited,newx,newy,path);
            path.pop_back();
        }
        
        
       visited[srcx][srcy] = 0; 
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
         vector<string> ans;
         int srcx = 0;
         int srcy = 0;
         
         if(m[srcx][srcy] == 0){
             return ans;
         }
         
         vector<vector<int>> visited = m;
         
         for(int i = 0 ; i<n ; i++){
             for(int j = 0; j<n ; j++){
                 visited[i][j] = 0;
             }
         }
         
         string path = "";
         
         solve(m,n,ans,visited,srcx,srcy,path);
         sort(ans.begin(),ans.end());
         return ans;
    }
};

int main(void)
{
    return 0;
}