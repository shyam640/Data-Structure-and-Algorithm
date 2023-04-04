#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> edge;
int enemy, person;
set<int> st;
vector<bool> visited;
vector<bool> dirty;
void dfs (int node, int par) {
    visited[node] = true;
    for (int child: edge[node]) {
        if (!visited[child]) {
            dfs(child, node);
        }
    }
    if (par != -1) {
        dirty[par] = dirty[par] or dirty[node];
    }
        
    
}
int main() {
    int n; cin >> n;
    int sz = 0;
    for (int i = 0; i < n; ++i) {
        int node;
        cin >> node;
        sz = max(sz, node + 1);
    }
    edge.resize(sz);
    visited.resize(sz, false);
    dirty.resize(sz);
    int edges; cin >> edges;
    while (edges--) {
        int u, v;
        cin >> u >> v;
        edge[v].push_back(u);
    }
    cin >> enemy >> person;
    dirty[enemy] = true;
    dfs(person, -1);
    for (int child: edge[person]) {
        if (dirty[child]) {
            cout << child << " ";
        }
    }

}