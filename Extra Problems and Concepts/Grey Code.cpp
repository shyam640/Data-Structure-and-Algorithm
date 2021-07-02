#include <bits/stdc++.h>
using namespace std;

// What are Grey Codes?
// Grey codes are binary codes which differ by 1 bit from its adjacent code.

// Basic Ides Behind these Method :
// Generate a list say l1 of (n-1) bit binary code and another list say l2 i.e. reverse of l1 .
// Then prefix l1 with "0" and l2 with "1" making them different from 1 bit
// Concatenate both l1 and l2 list and return the final list obtained after Concatenating.


// Approach 1 :- Basic Loop.
void simpleGreyCodeGenerate(int n){
    if(n<=0)
        return;
    vector<string> ans;     
    // Initialise 1 bit to ans array
    ans.push_back("0");
    ans.push_back("1");
    for(int i=2;i<(1<<n);i = i<<1){
        for(int j=i-1;j>=0;j--)
            ans.push_back(ans[j]);
        for(int j=0;j<i;j++)                        // Adding prefix "0" to first list l1
            ans[j] = "0"+ans[j];
        for(int j=i;j<2*i;j++)                      // Adding prefix "1" to second list l2
            ans[j] = "1"+ans[j];
    }
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}

// Approach 2 :- Recursive Method
vector<string> generateCodes(int n){
    if(n==0)
        return {"0"};
    if(n==1)
        return {"0","1"};
    vector<string> recAns = generateCodes(n-1);     // Recursive call
    vector<string> ans;
    for(int i=0;i<recAns.size();i++)                // Adding prefix "0" to first list l1
        ans.push_back("0"+recAns[i]);
    for(int i=recAns.size()-1;i>=0;i--)             // Adding prefix "1" to second list l2
        ans.push_back("1"+recAns[i]);
    return ans;
}
void recursivelyGreyCodeGenerate(int n){
    vector<string> ans = generateCodes(n);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}

// Approach 3 :- using inbuilt bitset
void bitsetGreyCodeGenerate(int n){
    vector<string> ans;
    for(int i=0;i<(1<<n);i++){
        int val = i^(i>>1);
        bitset<32> bt(val);
        string temp = bt.to_string();
        ans.push_back(temp.substr(32-n));
    }
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
}

// Approach 4 :- Backtracking Method
void generateBacktrackCodes(vector<int>& ans,int n,int& num){
    if(n==0){
        ans.push_back(num);
        return;
    }
    generateBacktrackCodes(ans,n-1,num);
    num = num^(1<<(n-1));
    generateBacktrackCodes(ans,n-1,num);
}
void backtrackingGreyCodeGenerate(int n){
    vector<int> ans;
    int num=0;
    generateBacktrackCodes(ans,n,num);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
}

int main() {
    int n =3;
    
	cout<<"Simple Loop Method to Generate Grey codes"<<endl;
	simpleGreyCodeGenerate(n);
	cout<<endl<<endl;
	
	cout<<"Recursive Method to Generate Grey codes"<<endl;
	recursivelyGreyCodeGenerate(n);
	cout<<endl<<endl;
	
	cout<<"Bitset function Method to Generate Grey codes"<<endl;
	bitsetGreyCodeGenerate(n);
	cout<<endl<<endl;
	
	cout<<"Backtracking Method to Generate Grey codes"<<endl;
	backtrackingGreyCodeGenerate(n);
	cout<<endl<<endl;
	
	return 0;
}
