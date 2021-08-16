// Question Link --> https://leetcode.com/problems/decode-string/



class Solution {
public:
    string decodeStringHelper(string &s , int &start){
        string word="",number="";
        for(;start<=s.length();start++){
            if(isdigit(s[start]))
                number+=s[start];
            else if(isalpha(s[start])){
                word+=s[start];
            }else if(s[start]=='['){
                string substring = decodeStringHelper(s,++start);
                if(number!=""){
                     int addChar = stoi(number);
                    while(addChar--){
                        word+=substring;
                    }
                    number="";
                }
            }else if(s[start]==']')
                return word;
        }
        return word;
    }
    string decodeString(string s) {
        int start = 0;
        return decodeStringHelper(s,start);
    }
};