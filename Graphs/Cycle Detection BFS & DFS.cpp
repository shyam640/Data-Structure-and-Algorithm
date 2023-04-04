#include<bits/stdc++.h>
using namespace std;

bool cyclePresentUsingBFS(int node, vector<int> &visited, vector<int> adj[], int v){
   queue<pair<int,int>> q;    // {node, prev_node}
   visited[node] = true;
   q.push({node,-1});
   while(!q.empty()){
      int curr_node = q.front().first;
      int prev_node = q.front().second;
      q.pop();

      for(auto it : adj[curr_node]){
         if(!visited[it]){
            visited[it] = true;
            q.push({it,curr_node});
         }else if(prev_node != it)
            return true;
      }

   }
   return false;
}


bool cyclePresentUsingDFS(int node, int parent, vector<int> &visited, vector<int> &adj[]){
   visited[node] = true;
   for(auto it : adj[node]){
      if(!visited[it]){
         if(cyclePresentUsingDFS(it,node,visited,adj))
            return true;
      }else if(it != parent)
         return true;
   }
   return false;
}




bool detectCycle(int v, vector<int> adj[]){
   vector<int> visited(v+1,false);
   /**************** CYCLE DETECTION USING BFS ****************************/
   // for(int i=1;i<=v;i++){
   //    if(!visited[i]){
   //       if(cyclePresentUsingBFS(i,visited,adj,v))
   //          return true;
   //    }
   // }
   // return false;


   /********************** CYCLE DETECTION USING DFS *****************************/
   // for(int i=1;i<=v;i++){
   //    if(!visited[i]){
   //       if(cyclePresentUsingDFS(i,-1,visited,adj))
   //          return true;
   //    }
   // }
   // return false;
}

int main(){
   int n,m;
   cin>>n>>m;
   int u,v;
   vector<int> adj[n];
   for(int i=0;i<n;i++){
      cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
   }
   cout<<detectCycle(n,adj)<<endl;
}