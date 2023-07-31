#include<bits/stdc++.h>
using namespace std;

void setIO(string name="usaco") {
	cin.tie(0)->sync_with_stdio(0);
	if ((int)name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main() {
	setIO("censor");
   string s, t;
   cin>>s>>t;
   string ans = "";
   int i=0;
   while(i<s.length()){
      ans += s[i];
      if (ans.size() > t.size() and ans.substr(ans.size() - t.size()) == t) {
			ans.resize(ans.size() - t.size());
		}
      i++;
   }
   cout<<ans<<endl;
	
   return 0;
}