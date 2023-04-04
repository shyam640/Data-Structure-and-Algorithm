// Given Xi and Yi co-ordinate of N distinct points in the 2-D Plane, 
// the task is to count the number of squares that can be formed from 
// these points that are parallel to both X and Y-axis.


#include<bits/stdc++.h>
using namespace std;

int countSquares(vector<int> xcord, vector<int> ycord){
   int ans = 0;
   set<pair<int,int>> points;
   map<int,vector<int>> pointsOnLine;
   for(int i=0;i<xcord.size();i++){
      points.insert({xcord[i],ycord[i]});
   }
   for(auto it : points){
      pointsOnLine[it.first].push_back(it.second);
   }
   for(auto line : pointsOnLine){
      int xC1 = line.first;
      vector<int> yCL = line.second;
      for(int i = 0;i<yCL.size();i++){
         int yC1 = yCL[i];
         for(int j=i+1;j<yCL.size();j++){
            int yC2 = yCL[j];
            int dist = abs(yC1-yC2);
            int xC2 = xC1 + dist;
            if(points.find({xC2, yC1})!=points.end() and points.find({xC2, yC2})!=points.end())
               ans++;
         }
      }
   }
   return ans;
}

int main(){
   vector<int> X = {0, 0, 2, 2, 1}, Y = {0,2,0,2,1};
   cout<<countSquares(X, Y)<<endl;
}