#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
      // Method 1 : Brute Force TLE
	   //  int n;
	   //  cin>>n;
	   //  vector<int> arr(n);
	   //  for(int i=0;i<n;i++)
	   //      cin>>arr[i];
      //   long long int sum=0;
        
        // vector<int> temp(n);
        // temp = arr;
        // bool flag=0;
        // // Time Complexity : O(n*n!)
        // while(true){
        //     for(int i=0;i<n-1;i++)
        //         sum+=(temp[i]*temp[i+1]);
        //     if(sum%2==1){
        //         flag=1;
        //         break;
        //     }
        //     next_permutation(temp.begin(),temp.end());  
        //     if(temp==arr)
        //         break;
        //     sum=0;
        // }
        // if(flag){
        //     for(int i=0;i<n;i++)
        //         cout<<temp[i]<<" ";
        //     cout<<endl;
        // }else{
        //     cout<<"-1"<<endl;
        // }
        
        

        // Method 2 : Optimized  O(N)
        int n;
         cin>>n;
         vector<int> odd,even;
         for(int i=0;i<n;i++){
            int a;
            cin>>a;
            if(a%2!=0)
               odd.push_back(a);
            else
               even.push_back(a);
         }
         // If all elements are odd and size of array is odd sum cannot be odd
         if(odd.size()==n and n%2!=0)
            cout<<"-1"<<endl;
         // If only one odd element then product is always even so sum is always even
         else if(odd.size()==1 and even.size()>0)
            cout<<"-1"<<endl;
         // If only one odd element and no even element then sum is odd i.e. only one odd element in array
         else if(odd.size()==1 and even.size()==0)
            cout<<odd[0]<<endl;
         // If size of odd array is greater then 2 i.e.. two or more element present
         else if(odd.size()>=2){
            // If odd array size is odd i.e. 3,5 then there is always one odd product therefore sum is odd
            if(odd.size()%2!=0){
               cout<<odd[0]<<" ";
               for(int i=0;i<even.size();i++)
                  cout<<even[i]<<" ";
               for(int i=1;i<odd.size();i++)
                  cout<<odd[i]<<" ";
               cout<<endl;
            }else{
               for(int i=0;i<even.size();i++)
                  cout<<even[i]<<" ";
               for(int i=0;i<odd.size();i++)
                  cout<<odd[i]<<" ";
               cout<<endl;
            }
         }else{
            cout<<"-1"<<endl;
         }
	}
	return 0;
}
