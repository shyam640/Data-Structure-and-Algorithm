#include<bits/stdc++.h>
using namespace std;

struct NAryTreeNode{
   string countryName;
   vector<NAryTreeNode*> joints;
   NAryTreeNode* parent;
   int countLockedAncestors, countLockedDescendant, UID;
   bool isNodeLocked;

   // Contructor
   NAryTreeNode(string c_name, NAryTreeNode *p){
      countryName = c_name;
      parent = p;
      countLockedAncestors = 0;
      countLockedDescendant = 0;
      UID = 0;
      isNodeLocked = false;
   }

   void addJoints(vector<string> countries, NAryTreeNode *parent){
      for(auto &country : countries)
         joints.push_back(new NAryTreeNode(country, parent));
   }


   // void printNAryTree(){

   // }
};


struct NAryTreeNode* buildTree(NAryTreeNode *root, int &m, vector<string> &countries){
   queue<NAryTreeNode*> q;
   q.push(root);

   int counter = 1;
   while(!q.empty()){
      NAryTreeNode *tempRoot = q.front();
      q.pop();

      if(counter >= countries.size())  continue;

      vector<string> childs;
      for(int i=counter;i<counter+m;i++)
         childs.push_back(countries[i]);
      
      tempRoot->addJoints(childs, tempRoot);
      counter += m;

      for(auto node : tempRoot->joints)
         q.push(node);
   }

   return root;
}

void showTree(NAryTreeNode *root){
   cout<<"Parent : "<<root->countryName<<endl;
   cout<<"Childs : ";
   for(auto node : root->joints)
      cout<<node->countryName<<" ";
   cout<<endl<<endl;
   for(auto node : root->joints)
      showTree(node);
}


class NAryTree{
   private:
      NAryTreeNode *root;
      unordered_map<string, NAryTreeNode*> mappedCountry;
   public:
      
      NAryTree(NAryTreeNode *r_n){
         root = r_n;
      }

      NAryTreeNode* getRootNode() {return root;}

      void mapCountiesWithParent(NAryTreeNode *root){
         if(!root)   return;
         mappedCountry[root->countryName] = root;
         for(auto node : root->joints)
            mapCountiesWithParent(node);
      }

      void informDecendantsAboutState(NAryTreeNode *root, int val){
         for(auto node : root->joints){
            node->countLockedAncestors += val;
            informDecendantsAboutState(node, val);
         }
      }

      bool verifyDecendantsForLockedState(NAryTreeNode *root, int unique_id, vector<NAryTreeNode*> &tempArr){
         if(root->isNodeLocked){
            if(root->UID != unique_id)  return false;
            tempArr.push_back(root);
         }
         if(root->countLockedDescendant == 0)   return true;

         bool ans = true;
         for(auto node : root->joints){
            ans = (ans & verifyDecendantsForLockedState(node, unique_id, tempArr));
            if(!ans) return false;
         }
         return ans;
      }


      bool LOCK(string country_name, int unique_id){
         NAryTreeNode *node = mappedCountry[country_name];

         if(node->isNodeLocked)   return false;

         if(node->countLockedAncestors > 0)  return false;
         if(node->countLockedDescendant > 0) return false;

         NAryTreeNode *curr = node->parent;
         // cout<<node->parent->countryName<<endl;

         while(curr){
            // cout<<curr->countryName<<endl;
            curr->countLockedDescendant++;
            curr = curr->parent;
         }
         
         informDecendantsAboutState(node, 1);
         node->isNodeLocked = true;
         node->UID = unique_id;
         return true;
      }

      bool UNLOCK(string country_name, int unique_id){
         NAryTreeNode *node = mappedCountry[country_name];

         if(!node->isNodeLocked) return false;
         if(node->isNodeLocked and node->UID != unique_id)  return false;

         NAryTreeNode *curr = node->parent;
         while(curr){
            curr->countLockedDescendant -= 1;
            curr = curr->parent;
         }

         informDecendantsAboutState(node, -1);
         node->isNodeLocked = false;
         return true;
      }

      bool UPGRADE(string country_name, int unique_id){
         NAryTreeNode *node = mappedCountry[country_name];

         if(node->countLockedAncestors != 0)  return false;
         if(node->countLockedDescendant == 0)   return false;

         vector<NAryTreeNode*> tempArr;
         if(verifyDecendantsForLockedState(node, unique_id, tempArr)){
            for(auto node : tempArr){
               UNLOCK(node->countryName, unique_id);
            }
         }else{
            return false;
         }
         LOCK(country_name, unique_id);
         return true;
      }
};


int main(){
   /*
      n -> Country Names
      m -> Childs per Node (N-ary NAryTree)
      q -> Queries Input

   */

   /*
      Constraints

   */

   int n, m, q;
   cin>>n>>m>>q;

   vector<string> countries(n);
   
   for(auto &country : countries)   cin>>country;

   // Create Root Node with name 'World'
   NAryTreeNode *root = new NAryTreeNode(countries[0], NULL);

   // Creating Complete NAryTree
   root = buildTree(root, m, countries);

   // showTree(root);

   // Check if tree is created correctly
   NAryTree NAT(root);
   NAT.mapCountiesWithParent(NAT.getRootNode());

   // for(auto it : NAT.mappedCountry)
   //    cout<<it.first<<" "<<it.second<<endl;


   int type, unique_id;
   string country_name;
   while(q--){
      cin>>type>>country_name>>unique_id;
      if(type==1){
         // cout<<country_name<<" "<<unique_id<<endl;
         if(NAT.LOCK(country_name, unique_id))
            cout<<"True"<<endl;
         else
            cout<<"False"<<endl;
      }else if(type==2){
         if(NAT.UNLOCK(country_name, unique_id))
            cout<<"True"<<endl;
         else
            cout<<"False"<<endl;
      }else if(type==3){
         if(NAT.UPGRADE(country_name, unique_id))
            cout<<"True"<<endl;
         else
            cout<<"False"<<endl;
      }else{
         cout<<"Wrong Input !!"<<endl;
      }
   }

   return 0;

}