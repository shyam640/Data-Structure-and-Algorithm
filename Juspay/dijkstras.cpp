#include <bits/stdc++.h>

vector<int> dijkstra(vector<vector<int>> &edge, int vertices, int edges, int source) {
	vector<pair<int,int>> adj[vertices];
	for(int i=0;i<edge.size();i++){
		adj[edge[i][0]].push_back({edge[i][1], edge[i][2]});
		adj[edge[i][1]].push_back({edge[i][0], edge[i][2]});
	}

	// for(auto it : adj){
	// 	cout<<it.first<<" "<<it.second.first<<" "<<it.second.second<<endl;
	// }

	// vector<int> dist(vertices, INT_MAX);
	// dist[source] = 0;
	// priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;	// {dist, node}
	// pq.push({0,source});
	
	// while(!pq.empty()){
	// 	int dis = pq.top().first;
	// 	int node = pq.top().second;
	// 	pq.pop();

	// 	for(auto it  : adj[node]){
	// 		int adjNode = it.first;
	// 		int adjDist = it.second;

	// 		if(dis + adjDist < dist[adjNode]){
	// 			dist[adjNode] = dis + adjDist;
	// 			pq.push({dist[adjNode], adjNode});
	// 		}
	// 	}
	// }
	// return dist;


	set< pair<int, int> > setds;
	vector<int> dist(V, 1e18);
	setds.insert(make_pair(0, src));
	dist[src] = 0;
	while (!setds.empty()){
		pair<int, int> tmp = *(setds.begin());
		setds.erase(setds.begin());
		int u = tmp.second;
		list< pair<int, int> >::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i){
			int v = (*i).first;
			int weight = (*i).second;

			if (dist[v] > dist[u] + weight){
				if (dist[v] != 1e18)
					setds.erase(setds.find(make_pair(dist[v], v)));
				dist[v] = dist[u] + weight;
				setds.insert(make_pair(dist[v], v));
			}
		}
	}

}


int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> edges = {{}};

	for(lli i=0;i<edges.size();i++){

	}
}