#include<bits/stdc++.h>
using namespace std;

void doBFS(int numberOfVertices, vector<int> &adj[]){
   vector<int> bfs;

   /********
   // What if its given as vector<pair<int,int>> adj;
   // then do
   vector<int> adj_vl[vertex+1];
   for(int i=0;i<vertex;i++){
      adj_vl[adj[i].first].push_back(adj[i].second);
      adj_vl[adj[i].second].push_back(adj[i].first);
   }
   for(int i=0;i<vertex;i++)
      sort(adj_vl[i].begin(),adj_vl[i].end());

   *******/


   vector<bool> visited(numberOfVertices+1,false);
   for(int i=1;i<=numberOfVertices;i++){
      if(!visited[i]){
         queue<int> q;
         q.push(i);
         visited[i] = true;
         while(!q.empty()){
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            
            for(auto it : adj[node]){
               if(!visited[it]){
                  q.push(it);
                  visited[it] = true;
               }
            }
         }
      }
   }

   for(auto &node : bfs)
      cout<<node<<" ";
   cout<<endl;
}


void recurseDFS(int node, vector<int> &visited,vector<int> &dfs,vector<int> &adj[]){
   dfs.push_back(node);
   for(auto &it : adj[node]){
      if(!visited[it])
         recurseDFS(it,visited,dfs,adj);
   }
}

void doDFS(int vertex,vector<int> &adj[]){
   vector<int> dfs;
   vector<bool> visited(vertex+1,false);
   for(int i=1;i<=vertex;i++){
      if(!visited[i]){
         recurseDFS(i,visited,dfs,adj);
      }
   }

   for(auto &node : dfs)
      cout<<node<<" ";
   cout<<endl;
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
   doBFS(n,adj);
}