#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int rearrangeCharacters(string s, string target){
        int s_cnt[26] = {-1};
        int t_cnt[26] = {-1};
        
        for (auto& ch : target){
            t_cnt[ch - 'a']++; //now make it 0
        }
        
        for (auto& ch : s){
            s_cnt[ch - 'a']++; //now make it 0
        }

        int ans = INT_MAX;

        for (auto& ch : target){
            int idx = ch - 'a';
            ans = min(ans, s_cnt[idx]);
        }
        
        return ans;
    }
};
int main(){
    string str = "ilovecodingonleetcode";
    string target = "code";

    Solution s;
    cout<<s.rearrangeCharacters(str, target)<<endl;
    return 0;
}