/*

// Nearest Meeting Cell

#include<bits/stdc++.h>
using namespace std;

vector<int> shortPath(vector<int> adj[], int c1, int n){
   vector<int> dist(n, INT_MAX);
   queue<int> q;
   q.push(c1);
   dist[c1] = 0;

   while(!q.empty()){
      int u = q.front();
      q.pop();
      
      for(auto &v: adj[u]){
         if(dist[v] > dist[u] + 1){
               dist[v] = dist[u] + 1;
               q.push(v);
         }
      }
   }
   return dist;
}
int main(){
   int n;
   cin>>n;

   vector<int> edges(n);
   for(int i=0 ; i<n ; i++)
      cin >> edges[i];

   int c1, c2;
   cin>>c1>>c2;

   vector<int> adj[n];
   for(int i=0 ; i<n ; i++){
      if(edges[i] == -1) continue;
      adj[i].push_back(edges[i]);
   }
   vector<int> v1 = shortPath(adj, c1, n);
   vector<int> v2 = shortPath(adj, c2, n);

   int mn = INT_MAX, node = -1;
   for(int i=0 ; i<n ; i++){
      if(v1[i] == INT_MAX || v2[i] == INT_MAX)
         continue;
      if(v1[i] + v2[i] < mn){
         mn = v1[i] + v2[i];
         node = i;
      }
   }
   cout << node << endl;
   return 0;
}



*/



/*

// Largest Sum Cycle

#include<bits/stdc++.h>
using namespace std;

class Solution
{
  public:
  long long ans = -1;
  void dfs(vector<int> adj[], int node, vector<bool> &visited, vector<long long> &d, long long sum){
      visited[node] = true;
      d[node] = sum;
      sum += node;
      for(auto it : adj[node]){
          if(!visited[it]){
              dfs(adj, it, visited, d, sum);
          }else if(d[it]){
              ans = max(ans, sum-d[it]);
          }
      }
      d[node] = 0;
  }
  long long largestSumCycle(int N, vector<int> Edge){
    vector<int> adj[N];
    for(int i=0;i<Edge.size();i++){
        if(Edge[i]==-1) continue;
        adj[i].push_back(Edge[i]);
        // adj[Edge[i]].push_back(i);
    }
    
    vector<long long> d(N, 0);
    vector<bool> visited(N, false);
    for(int i=0;i<N;i++){
        if(!visited[i]){
            dfs(adj, i, visited, d, 1);
        }
    }
    return ans;
  }
};

signed main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      long long ans=obj.largestSumCycle(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}



*/






/*


// Maximum Weight Node


int solution(vector<int>arr){
    int ans=INT_MIN;
    int result=-1;
    vector<int>weight(arr.size(),0);
    for(int i=0;i<arr.size();i++){
        if(arr[i]!=-1){
            weight[arr[i]]+=i;
            if(ans<=weight[arr[i]]){
                ans=max(ans,weight[arr[i]]);
                result=arr[i];
            }
        }
    }
    if(ans!=INT_MIN)
        return result;
    return -1;
}






*/


#include <bits/stdc++.h>
using namespace std;

struct Node{
	string v;
	vector<Node*> links;
	Node* parent;
	int anc_locked, dec_locked, uid;
	bool isLocked;
	
	Node(string x, Node *p){
		v = x;
		parent = p;
		anc_locked = 0;
		dec_locked = 0;
		uid = 0;
		isLocked = false;
	}

	void addLinks(vector<string> l, Node *p){
		for(auto &i : l)
			links.push_back(new Node(i,p));
	}
};

void printTree(Node *r){
	cout << "Parent: " << r->v << "\n";
	cout << "Child: \n";
	for(auto k : r->links){
		cout << k->v << " anc_locked: " << k->anc_locked 
			<< " dec_locked:" << k->dec_locked << " isLocked:" 
			<< k->isLocked << " uid:" << k->uid << "\n";
	}
	cout << "\n";
	for(auto k : r->links){
		printTree(k);
	}
}

struct Node* buildTree(Node *root, int &m, vector<string> &s){
	queue<Node*> q;
	q.push(root);

	int st = 1;
	while(!q.empty()){
		Node *r = q.front();
		q.pop();

		if(st >= s.size()) continue;

		vector<string> temp;
		for(int i = st; i < st + m; i++)
			temp.push_back(s[i]);
		r->addLinks(temp,r);
		st += m;

		for(auto k: r->links)
			q.push(k);
	}

	return root;
}

class Tree{
	private:
		Node *root;
		unordered_map<string, Node*> vton;
	public:

		Tree(Node *r){ root = r;}

		Node* getRoot() { return root; }

		void fillVtoN(Node *r){
			if(!r) return;
			vton[r->v] = r;
			for(auto k : r->links)
				fillVtoN(k);
		}

		void informDecendants(Node *r, int val){
			for(auto k: r->links){
				k->anc_locked += val;
				informDecendants(k,val);
			}
		}

		bool verifyDecendants(Node *r, int &id, vector<Node*> &v){
			if(r->isLocked){
				if(r->uid != id) return false;
				v.push_back(r);
			}
			if(r->dec_locked == 0) return true;

			bool ans = true;
			for(auto k: r->links){
				ans &= verifyDecendants(k,id,v);
				if(ans == false) return false;
			}
			return ans;
		}

		bool lock(string v, int id){
			Node *t = vton[v];
			if(t->isLocked) return false;

			if(t->anc_locked != 0) return false;
			if(t->dec_locked != 0) return false;

			Node *cur = t->parent;
			while(cur){
				cur->dec_locked++;
				cur = cur->parent;
			}
			informDecendants(t,1);
			t->isLocked = true;
			t->uid = id;
			return true;
		}

		bool unlock(string v, int id){
			Node *t = vton[v];
			if(!t->isLocked) return false;
			if(t->isLocked && t->uid != id) return false;

			Node *cur = t->parent;
			while(cur){
				cur->dec_locked--;
				cur = cur->parent;
			}
			informDecendants(t,-1);
			t->isLocked = false;
			return true;
		}

		bool upgrade(string v, int id){
			Node *t = vton[v];
			if(t->isLocked) return false;

			if(t->anc_locked != 0) return false;
			if(t->dec_locked == 0) return false;

			vector<Node*> vec;
			if(verifyDecendants(t,id,vec)){
				for(auto k : vec){
					unlock(k->v,id);
				}
			}else return false;
			lock(v,id);
			return true;
		}
};

/*
Example Input:
7
2
4
World
Asia
Africa
India
China
SouthAfrica
Egypt
1 China 9
1 India 9
3 Asia 9
2 India 9
*/

int main() {

	/*
	 * INPUT
	 * n = total number of nodes
	 * m = number of child per node
	 * q = number of queries
	 *
	 * next 'n' lines = node name in string
	 * next 'q' lines = queries with (opcode, string, uid)
	 *
	 * opcode => 1 = Lock, 2 = Unlock, 3 = Upgrade
	*/


	int n,m,q;
	cin >> n;
	cin >> m;
	cin >> q;

	vector<string> s(n);
	for(int i = 0; i < n; i++)
		cin >> s[i];
	
	Node *r = new Node(s[0],NULL);
	r = buildTree(r,m,s);
	// printTree(r);
	
	Tree t(r);
	t.fillVtoN(t.getRoot());

	int op,uid;
	string sq;
	for(int i = 0; i < q; i++){
		cin >> op >> sq >> uid;
		switch(op){
			case 1:	if(t.lock(sq,uid)){
						cout << "true\n";
						//printTree(r);
					}else
						cout << "false\n";
					break;
			case 2:	if(t.unlock(sq,uid))
						cout << "true\n";
					else
						cout << "false\n";
					break;
			case 3:	if(t.upgrade(sq,uid)){
						cout << "true\n";
						//printTree(r);
					}else
						cout << "false\n";
					break;
		}
	}

	return 0;
}
