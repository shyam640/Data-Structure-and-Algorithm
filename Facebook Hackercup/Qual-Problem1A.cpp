#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define ll long long int
#define ld long double
#define mod             1000000007
#define inf             1e18
#define endl "\n"
#define pb push_back
#define vi vector<ll>
#define vs vector<string>
#define pii pair<ll,ll>
#define ump unordered_map
#define mp make_pair
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define all(n) n.begin(),n.end()
#define ff first
#define ss second
#define mid(l,r) (l+(r-l)/2)
#define bitc(n) __builtin_popcount(n)
#define loop(i,a,b) for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) for(int i=(a);i>=(b);i--)
#define iter(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define log(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b) for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
template <typename T> T gcd(T a, T b){if(a%b) return gcd(b,a%b);return b;}
template <typename T> T lcm(T a, T b){return (a*(b/gcd(a,b)));}
vs tokenizer(string str,char ch) {std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;}


void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
cout << *it << " = " << a << endl;
err(++it, args...);
}
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;

void file_i_o()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
}

void getMaxFrequencyChar(int count[], const char* set, char* letter, int *number){
   *letter = '\0';
   *number = 0;
   for(int i=0; set[i]; ++i){
      *letter = (count[set[i]-'A'] > *number)? set[i]            : *letter;
      *number = (count[set[i]-'A'] > *number)? count[set[i]-'A'] : *number;
   }
}

int main(int argc, char const *argv[]) {
clock_t begin = clock();
file_i_o();
// Write your code here....
int t;
cin>>t;
int c=1;
while(t--){
   ll ans=0;
   string s;
   cin>>s;
   int vol=0,con=0;
   for(int i=0;i<s.length();i++){
      if(s[i]=='A' or s[i]=='E' or s[i]=='I' or s[i]=='O' or s[i]=='U')
         vol++;
      else
         con++;
   }
   const char vowels[] = "AEIOU";
   const char cnsts[] = "BCDFGHJKLMNPQRSTVWXYZ";
   int v_max,c_max;
   char v_letter,c_letter;
   int count[26] = {};
   for(int i=0; s[i]; ++i)
      count[s[i]-'A'] += !!isalpha(s[i]);
   
   getMaxFrequencyChar(count, vowels, &v_letter, &v_max);
   getMaxFrequencyChar(count, cnsts, &c_letter, &c_max);

   string temp=s;
   sort(temp.begin(),temp.end());
   temp.erase(unique(temp.begin(),temp.end()),temp.end());
   if(temp.length()==1)
      ans=0;
   else if(vol<=con){
      loop(i,0,s.length()-1){
         if((s[i]=='A' or s[i]=='E' or s[i]=='I' or s[i]=='O' or s[i]=='U') and s[i]!=v_letter)
            ans+=2;
         else if(s[i]!=v_letter)
            ans++;
      }
   }else{
      loop(i,0,s.length()-1){
         if(s[i]=='A' or s[i]=='E' or s[i]=='I' or s[i]=='O' or s[i]=='U')
            ans++;
         else if(s[i]!=c_letter)
            ans+=2;
      }
   }
   cout<<"Case #"<<c<<": "<<ans<<endl;
   c++;
}

// #ifndef ONLINE_JUDGE 
// clock_t end = clock();
// cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
// #endif 
return 0;
}



// Input :
// 45
// EASAYUEOXQXEAKAFIUOEAALAUIIUUGPA
// HLVTMEAUMYEDMFIMUMEEBEUKEAITNWOIIOSGTIAUPBUINUQGYOAAAETCJGOEMWQEAOPUTTDAAQEESKISO
// CONSISTENCY
// QPQWJXRJJXBTKKGBKVXNSCQBHZTSFZRYCDZFYQJQWHWHYJVDRXSGWRLJNTHBXYBRBTVXBBPPCXRBFVXVNDQQTHHBKXZDPQZGSHWF
// ABC
// OOEUEUIUUOOAUEIOIEEUIAIUAUOOAUUIIEUUOAAIOAEAUEIAOAOOAOOAAIEOAEOEIOIAAEAAIOEEOIIIEEIOIUEIEEEAAEEEEOAA
// OIOUAUOAIEUOEUIUIIUAAAAUOEIEUAIEEOIAOEUEAOOEAIIEEAEIUIOAUIIOEEUEAOEOOAAIAUAO
// GLZIAUAIULAYREOPAALTETAGFHAAURKILIEAAZAOOLJNBZKKICUIZOQUOEUKKIDUBUTQOUVRAUWNYIQAPASQA
// AHKELEGPWUNIMUEIUAFOEMAJVFNAEGDOIPASOCLZGPBEAZECGJUUOKHFZSIICWUGRGEAAIZANQIEFVNANAITXIOVDVAEOE
// OOOYSRHWNQELBPPMEPOMAZUEZWZAUBAOHNEEYXACMAKUUHUEAULHHBILUHWIONXKNFEAIAZOEUXIZOKJBUONPQAXPEOIRCX
// FBHC
// FOXEN
// UUKWEQAESOAANZPGYMYEDHQEQZWUPZRZIHIIYEUEICKALGANOHKMIEXMXCUAXXYLODOZKEOUGDFKCNI
// OXEOURJOEUEJUUTUEIEQORXSBGLUIIARAVUBPUICEIJAIILEQDBIIQONE
// IPQALOOEQAWOTODUOFNIAZGQPUTHFFSAEZWOOGYEVQSHRIKCALEUSDAVBUFKIACUSIAKSBLU
// IOAOIAAOAEOIEIEAIIEAOUEIEIOOIEIEOIEIOEOUUOEUEOAOEIOOUUUIIOAEIAIEIOIEUOIUUEIEAEIAAIEOE
// PTCJRYMLRWZVMZZPBKPNSDMFTCFKLCZXLPQLNQCLDXQVQZMYHBXPLQMXMHJQFKLHNXTKCRZMRKBWDTBBPYFTMLBQZMVVRBTXBCM
// AAAAAAAAAAEEEEEEEEEEIIIIIIIIIIOOOOOOOOOOUUUUUUUUUUBBBBBBBBBBBCCCCDDDDFFFFGGGGHHHHJJJJKKKKLLLLMMMMNNN
// F
// AIIOEAAAUEUUOEOOUAIIIIOEEIEAAAAUAIAEUUOUEUOAUAOIUAOUAAIUIIIE
// SYMPHXFDDRQRPMZTJBVFYWMPLGBRBPRYMTTBDBNTMTJFYJ
// UFOVKZEOUTPUJSWEITEUAIYDRIBGUIUIOEII
// KTNIUDNSSOOFAMLGAXJGKXOEBHGEOGQQELSAAEZAGKEFEYYRLETFAEBOAHASLIZUUEAGCP
// MYNTULUYAUBJWTUHTUUOWEOUUIQPGPKFPEAUUAOOARIVSDIQEIMCUIQUQDAUAIIENPILCBGIOCVNUR
// AYOOZMUIADIDNXXHTMDEFFDDJIMPJANSTOAUHSAIGAFXJHTAABWUZBURBOVJEDZICDOBEAXIJADNLMSKHAOAFEJPHWIAHC
// OWAMBXIRMUNOIXEUJILQLAPGLHQSFXUNAJLIERKUQEGCIYNHHEEYFHOFIAMH
// AOWESABWHAIARBELWCPEMRJSIE
// OKMEOEQIUSFATUOTONBRYEEUUUDGEITUGRARKUIUGOJIAOEGUKJOPIAYZBGKOEFOFHOXIJTCEOOEMSSOFCEXIUYOF
// AOEEUOAOOUEUUUUEEOAOIOOAAEIEAIEUOIAOOAIOUAAUIUEUIOIUUEEOOAEOIEUIUOOOIEIUEIAEEIIEIEEEEAUIOEIIUE
// AAAAAEEEEEIIIIIOOOOOOUUUUUXYZ
// BANANA
// KDIYULAIEGHARWVOIKBAUTEINPMEBAPRETFOUL
// HAAACKEEERCUUUP
// OOKMHREFNKYAYIIGKZTIQBUUAEOIOUAKXFIYTGLBZAEEGIEBZEUVUW
// OEOUAEOUAUAEIEIIIAIOOUAUIAEEUUIAIAIOUIIAUUIIUAUUEAOAOAEEUEUOUAOAIOUUEEIEAUOAIOEEOUIOAUOEOIAEO
// LNJYCVQZUUIKAFAIJSVMZPT
// GJNZWNDWKKNPLRRBSSDNHXFZ
// IOIWOWIOIWOWIOIWOWIOIWOWIOIWOWIOIWOWIOIWOWIOIWOWIOIWOWIOIWOWIOIWOWIOIWOWIOIWOWIOIWOWIOIWOWIOIWOWIOI
// EMLEKLIXUPNUEAUEAXUCKHPUEJBUIAKJTKCYIGITCIAUPIQAZUO
// RGQQRTUSHOIUEJBEYZSHIIRDASATUUPUBKTHHUZNTPNLOILOOQYU
// UVZVEOMIJOOAWGLCIEIAUBSQPRM
// ZVOIAGIMOLAHOAIAJEIUBHLNDDFIHGZHCIUWRMGIHIUOPICDOURTUVAOO
// GMJAIDRIBTPAOJATREMCOOVXODUIHEUBSAGF
// EJZITADGAAAKTEIQVEWLLIIZXWLKSEAIUUUIERFKEUOXONORJRXGKGLIUIUBNXINNJHHAEAACBEQWXZ
// EDHHDGFGCFHBHCAFGHHCBDHHECAEGGAGAGDGEGGFDGBCDFDCBHFGBDBCGHEACCGFAGEFBFGECFGFCGGBEDGDBFCEHEDHEHHFGCEB


// Output :
// Case #1: 38
// Case #2: 99
// Case #3: 12
// Case #4: 100
// Case #5: 2
// Case #6: 100
// Case #7: 76
// Case #8: 117
// Case #9: 114
// Case #10: 117
// Case #11: 4
// Case #12: 5
// Case #13: 94
// Case #14: 75
// Case #15: 86
// Case #16: 85
// Case #17: 99
// Case #18: 130
// Case #19: 0
// Case #20: 60
// Case #21: 46
// Case #22: 47
// Case #23: 80
// Case #24: 88
// Case #25: 102
// Case #26: 70
// Case #27: 29
// Case #28: 123
// Case #29: 94
// Case #30: 30
// Case #31: 3
// Case #32: 47
// Case #33: 17
// Case #34: 67
// Case #35: 93
// Case #36: 25
// Case #37: 24
// Case #38: 67
// Case #39: 60
// Case #40: 57
// Case #41: 33
// Case #42: 66
// Case #43: 43
// Case #44: 95
// Case #45: 94
