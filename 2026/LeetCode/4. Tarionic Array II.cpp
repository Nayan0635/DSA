#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    typedef long long ll;
    int n;
    vector<vector<ll>> memo;

    ll solve(int i, int trend, vector<int>& nums){
        //Base case
        if(i == n){
            if(trend == 3){
                return 0;//no more elements
            }else{
                return LLONG_MIN/2;
            }
        }

        if(memo[i][trend] != LLONG_MIN){
            return memo[i][trend];
        }

        ll take = LLONG_MIN/2;
        ll skip = LLONG_MIN/2;

        //skip
        if(trend == 0){//haven't started yet
            skip = solve(i+1, 0, nums);
        }
        // I'm at trend = 3 nd now i can end at nums[i]
        if(trend == 3){
            take = nums[i];
        }

        if(i < n){
            int curr = nums[i];
            if(i+1 < n){
                int next = nums[i+1];

                if(trend == 0 && next > curr){//1st increasing trend
                    take = max(take, curr + solve(i+1, 1, nums));
                }

                else if(trend == 1){
                    if(next > curr){//continue current trend
                        take = max(take, curr + solve(i+1, 1, nums));
                    }else if(next < curr){//start decreasing trend
                        take = max(take, curr + solve(i+1, 2, nums));
                    }
                }


                else if(trend == 2){
                    if(next < curr){//continue current trend
                        take = max(take, curr + solve(i+1, 2, nums));
                    }else if(next > curr){//start 2nd increasing trend
                        take = max(take, curr + solve(i+1, 3, nums));
                    }
                }

                else if(trend == 3 && next > curr){//continue current trend (to get maximum)
                    take = max(take, curr + solve(i+1, 3, nums));
                }
            }

        }
        return memo[i][trend] = max(take, skip);
    }

    ll maxSumTrionic(vector<int>& nums) {
        n = nums.size();

        memo.assign(n+1, vector<ll>(4, LLONG_MIN));

        return solve(0, 0, nums);//solve(i, trend, nums)
    }
};

int main(){
    vector<int> arr = {0, -2, -1, -3, 0, 2, 1};
    Solution s;
    cout<<s.maxSumTrionic(arr);
    return 0;
}