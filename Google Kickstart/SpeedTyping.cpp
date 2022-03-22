#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    int c=1;
    while(t--){
        string s,p;
        cin>>s>>p;
        unordered_map<char,int> mp;
        for(int i=0;i<p.length();i++)
            mp[p[i]]++;
        int ans=0;
        bool flag=0;
        if(s.length()<=p.length()){
            for(int i=0;i<s.length();i++){
                  if(mp.find(s[i])!=mp.end()){
                     if(mp[s[i]]>0)
                        mp[s[i]]--;
                     else{
                        flag=1;
                        break;
                     }
                  }else{
                     flag=1;
                     break;
                  }
            }
            if(flag)
                  cout<<"Case #"<<c<<": "<<"IMPOSSIBLE"<<endl;
            else{
                  for(auto &it : mp){
                     if(it.second>0)
                        ans+=it.second;
                  }
                  cout<<"Case #"<<c<<": "<<ans<<endl;
            }
        }else{
            cout<<"Case #"<<c<<": "<<"IMPOSSIBLE"<<endl;
        }



      // Mukul Method 

      // queue<char> store;
      // if(s.length()<=p.length()){
      //    for(int i=0;i<p.length();i++)
      //       store.push(p[i]);
      //    for(int i=0;i<s.length();i++){
      //       while(store.front()!=s[i]){
      //          if(store.empty())
      //             break;
      //          store.pop();
      //       }
      //       if(store.empty())
      //          break;
      //       else{
      //          ans += s[i];
      //          store.pop();
      //       }
      //    }
      //    if(s == ans)
      //       cout<<"Case #"<<c<<": " <<p.length()-s.length()<<endl;
      //    else
      //       cout<<"Case #"<<c<<": IMPOSSIBLE"<<endl;
      // }else{
      //    cout<<"Case #"<<c<<": IMPOSSIBLE"<<endl;
      // }


      c++;
    }
}