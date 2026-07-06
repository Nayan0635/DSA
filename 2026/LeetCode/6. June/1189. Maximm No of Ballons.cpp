#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int maxNumberofBaloons(string str){
        int cnt[26] = {0};
        for (auto& ch : str){
            cnt[ch - 'a']++;
        }
        return min({cnt['b'-'a'], cnt['a'-'a'], cnt['l'-'a'], cnt['o'-'a'], cnt['n'-'a']});
    }
};
int main(){
    string str = "loonbalxballpoon";
    
    Solution s;
    cout<<s.maxNumberofBaloons(str);
    return 0;
}