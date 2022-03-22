#include<bits/stdc++.h>
using namespace std;
int main(){
   int n;
   cin>>n;
   vector<vector<int>> pages(n,vector<int>(10,0));
   for(int i=0;i<n;i++){
      while(char key = getchar()) { 
	      if (key == '\n') 
		      break; 
         else
            pages[i].push_back(key-1);
      }
   }
   int st,end;
   cin>>st>>end;
   for(int i=0;i<pages.size();i++){
      for(int j=0;j<pages[i].size();j++)
         cout<<pages[i][j];
   }

}