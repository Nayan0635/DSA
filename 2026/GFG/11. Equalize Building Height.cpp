/*return the minimum cost such
that all buildings willhave equal height
*/
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    typedef long long ll;
    ll calCost(vector<int>& h, vector<int>& c, int m){
        ll cost = 0;
        int n = h.size();
        for(int i = 0; i < n; i++){
            cost += 1LL * c[i] * abs(h[i] - m);
        }
        return cost;
    }

    int minCost(vector<int>& heights, vector<int>& cost){
        int low = *min_element(heights.begin(), heights.end());
        int high = *max_element(heights.begin(), heights.end());

        while(high - low > 2){
            int m1 = low + (high = low)/3;
            int m2 = high - (high = low)/3;

            ll c1 = calCost(heights, cost, m1);
            ll c2 = calCost(heights, cost, m2);

            if(c1 > c2){
                high = m2 - 1;
            }else{
                low = m1 + 1;
            }
        }

        ll minCost = LLONG_MAX;
        for(int i = low; i <= high; i++){
            minCost = min(minCost, calCost(heights, cost, i));
        }

        return minCost;
    }
    // int minCost(vector<int>& heights, vector<int>& cost) {
    //     int maxH = *max_element(heights.begin(), heights.end());
    //     int minCost = INT_MAX;
    //     for (int h = 1; h <= maxH; h++) {
    //         minCost = min(minCost, calCost(heights, cost, h));
    //     }
    //     return minCost;
    // }
};

int main(){
    vector<int> heights = {1, 2, 3};
    vector<int> cost = {10, 100, 1000};
    Solution s;
    cout<<s.minCost(heights, cost);
    return 0;
}
    // int minCost(vector<int>& heights, vector<int>& cost) { //doesn't work not binary searh thing
    //     int low = *min_element(heights.begin(), heights.end());
    //     int high = *max_element(heights.begin(), heights.end());
    //     int minCost = INT_MAX;
    //     while(low <= high){
    //         int mid = low + (high-low)/2;

    //         int reqcost = calCost(heights, cost, mid);
    //         if(reqcost <= minCost){
    //             high = mid - 1;
    //             minCost = min(minCost, reqcost);
    //         }else{
    //             low = mid + 1;
    //         }
    //     }
    //     return minCost;