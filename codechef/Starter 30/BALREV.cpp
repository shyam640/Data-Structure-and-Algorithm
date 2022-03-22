#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    string s;
	    cin>>s;
	   //  if(n==1)
	   //      cout<<s<<endl;
      //   else{
      //       // string zero="",one="";
      //       // for(int i=0;i<n;i++){
      //       //     if(s[i]=='0')
      //       //         zero += s[i];
      //       //     else
      //       //         one += s[i];
      //       // }
      //       // cout<<zero+one<<endl;
      //       sort(s.begin(),s.end());
      //       cout<<s<<endl;
      //   }
      sort(s.begin(),s.end());
      cout<<s<<endl;
	}
	return 0;
}