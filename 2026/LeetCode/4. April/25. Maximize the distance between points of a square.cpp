//maximum possible minimum manhattan diantace between k points 

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int manhattan_distance(vector<int> p1, vector<int> p2){
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }

    bool check(vector<vector<int>>& points, int k, int dist, int i, vector<int>& chosen){
        if(chosen.size() == k){
            return true;
        }
        int s = points.size();
        for(int p = i; p < s; p++){

            bool valid = true;

            for (int ind : chosen){
                // check with already selected points
                if(manhattan_distance(points[p], points[ind]) < dist){  //maximize the dist
                    valid = false;
                    break;
                }
            }

            if(!valid) continue; //go out pick different point

            chosen.push_back(p);
            if(check(points, k , dist, p+1, chosen)){// pick
                return true;
            }
            chosen.pop_back();
        }
        return false;
    }

    int maxDistance(int side, vector<vector<int>>& points, int k){
        int l = 0;
        int r = 2*side;

        int result = 0;

        while(l <= r){
            int mid = l + (r-l)/2;

            vector<int> chosen;

            if(check(points, k, mid, 0, chosen)){
                result = mid;
                l = mid + 1;
            }else {
                r = mid - 1;
            }
        }

        return result;
    }
};
int main(){
    vector<vector<int>> points = {{0, 0}, {0, 2}, {2, 0}, {2, 2}};
    int k = 4, side = 2;
    Solution s;
    cout<<s.maxDistance(side, points, k);
    return 0;
}