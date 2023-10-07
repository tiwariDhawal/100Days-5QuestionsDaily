//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    
  public:
    
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int>adjList[V];
        //Step1:firstly we will make the adjacency list 
        for(int i = 0;i < V;i++){
            for(int j = 0;j < V;j++){
                if(i != j && adj[i][j] == 1){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        int count = 0;
        //Step2:Now traversing through all the neighbours of the nodes using any algorithm 
        //either bfs or dfs
        //a> Making a visited array to keep track which nodes are visited 
        vector<int>vis(V,0);
        //b> Now checking for the visited part of the neighbours 
        for(int i = 0;i< V;i++){
            if(!vis[i]){
                count++;
                bfs(adjList,i,vis);
            }
        }
        //Step3:Returning the number of count
        return count;
        
    }
    void bfs(vector<int>adj[],int node,vector<int>&vis){
        
        queue<int>q;
        q.push(node);
        vis[node] = 1;
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            for(auto it: adj[frontNode]){
                if(!vis[it]){
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends