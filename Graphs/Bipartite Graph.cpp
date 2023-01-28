// Bipartite Graph -> Graph that can be coloured using only two colors is knows as bipartite graph.


#include<bits/stdc++.h>
using namespace std;

bool BipartiteGraphUsingBFS(int src, vector<int> &color, vector<int> &adj[]){
   queue<int> q;
   q.push(src);
   color[src] = 1; // You can start with 0 too.
   while(!q.empty()){
      int node = q.front();
      q.pop();

      for(auto it : adj[node]){
         if(color[it] == -1){
            color[it] = 1 - color[node];
            q.push(it);
         }else if(color[it] == color[node])
            return false;
      }
   }
   return true;
}


bool BipartiteGraphUsingDFS(int node, vector<int> &color, vector<int> &adj[]){
   if(color[node] == -1) color[node] = 1;
   for(auto it : adj[node]){
      if(color[it]==-1){
         if(!BipartiteGraphUsingDFS(it,color,adj))
            return false;
      }else if(color[it] == color[node])
         return false;
   }
   return true;
}


bool detectBipartite(int v, vector<int> adj[]){
   vector<int> color(v,-1);
   /**************** BIPARTITE GRAPH DETECTION USING BFS ****************************/
   // for(int i=1;i<=v;i++){
   //    if(color[i]==-1){
   //       if(!BipartiteGraphUsingBFS(i,color,adj))
   //          return false;
   //    }
   // }
   // return true;


   /********************** BIPARTITE GRAPH DETECTION USING DFS *****************************/
   // for(int i=1;i<=v;i++){
   //    if(color[i]==-1){
   //       if(!BipartiteGraphUsingDFS(i,color,adj))
   //          return false;
   //    }
   // }
   // return true;
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
   cout<<detectBipartite(n,adj)<<endl;
}