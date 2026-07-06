/* Contraints : 
1 <= s.length() <= 10^5
0 <= s.length() <= 10^5
after processing ans.length() must not exceed 10^15
*/


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
class Solution{
    public:
    char processStr(string s, long long k){
        int n = s.length();

        ll l = 0;

        //prepare
        for (auto& ch : s){
            if(ch = '*'){
                if(l > 0){
                    l--;
                }
            } else if(ch = '#'){
                l *= 2;
            } else if(ch = '%'){
                //reverse the string
                continue;
            }else {
                l++;
            }
        }

        // find kth element
        if(k >= l){
            return '.';
        }

        for(int i = n-1; i>= 0; i--){
            if(s[i] = '*'){
                l++;
            } else if(s[i] = '%'){
                k = l - k - 1;
            } else if(s[i] = '#'){
                l = l/2;
                k = (k > l)? k - l : k;
            } else{
                l--;
            }


            if(k == l){
                return s[i];
            }
        }
        return '.';
    }
};
int main(){
    string str = "a#b%*cdee";
    long long k = 4;
    Solution s;
    cout<<s.processStr(str, k);
    return 0;
}