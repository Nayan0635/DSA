#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string processStr(string s){
        int n = s.length();
        string ans = "";
        for (char i = 0; i < n; i++){
            if(s[i] == '#')
            ans+= ans;
            else if(s[i] == '%')
            reverse(ans.begin(), ans.end());
            else if(s[i] == '*'){
                if(!ans.empty())
                ans.pop_back();
            } else{
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};
int main(){
    string str = "a#b%*";
    string result;
    Solution s;
    result = s.processStr(str);

    cout<<result<<endl;
    return 0;
}