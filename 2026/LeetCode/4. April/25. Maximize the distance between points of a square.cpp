/*
maximum possible minimum manhattan diantace between k points of a square
points lying on perimeter
*/
#include<bits/stdc++.h>
using namespace std;

class Solution{
    typedef long long ll;
    public:
    int get_position(int x, int y, int side){//from (0, 0) lying on boundary
        if(y == 0) return x;
        else if(x == side) return side + y;
        else if(y == side) return 2ll * side + (side-x);
        else return 3ll * side + (side-y);//out of bound
    }

    bool check(vector<ll>& doubled, int n, int k, int side, int min_dist){
        ll perimeter = 4*side;

        for (int i = 0; i < n; i++){          //O(n)
            int cnt = 1; //picked first point
            int idx = i;

            ll lastPos = doubled[idx]; // picked point

            // need other points
            for(int j = 2; j < k; j++){  //O(k * log(n))
                ll next_point = lastPos + min_dist; //next desired point

                auto it = lower_bound(begin(doubled) + idx + 1, begin(doubled) + i + n, next_point);

                if(it == begin(doubled) + i + n) break; //reached till end didn't find come out

                idx = it - begin(doubled); // index - initial_point = distance
                lastPos = doubled[idx];
                cnt++; //found another point
            }

            if(cnt == k && (doubled[i] + perimeter - lastPos) >= min_dist) return true;
        }
        
        return false;
    }

    int maxDistance(int side, vector<vector<int>>& points, int k){
        int n = points.size();// points
        ll perimeter = 4*side;
        vector<int> positions(n);//flatten points

        for (int i = 0; i < n; i++){
            positions[i] = get_position(points[i][0], points[i][1], side);//in straight line
        }

        sort(positions.begin(), positions.end());//sorted now

        vector<ll> doubled_(2*n); //for circular movement
        for (int i = 0; i < n; i++){
            doubled_[i] = positions[i];
            doubled_[i + n] = positions[i] + perimeter;
        }
         
        int l = 0, r = 2*side;

        int result = 0;

        //log(side) * n * klog(n)
        while(l <= r){
            int mid = l + (r-l)/2;
            vector<int> choosen;
            if(check(doubled_, n, k, side, mid)){
                result = mid;
                l = mid + 1;
            }else {
                r = mid - 1;
            }
        }
        return result;
    }


    //Brute Force
    // int get_position(vector<int> p1, vector<int> p2){
    //     return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    // }

    // bool check(vector<vector<int>>& points, int k, int dist, int i, vector<int>& chosen){
    //     if(chosen.size() == k){
    //         return true;
    //     }
    //     int s = points.size();
    //     for(int p = i; p < s; p++){

    //         bool valid = true;

    //         for (int ind : chosen){
    //             // check with already selected points
    //             if(get_position(points[p], points[ind]) < dist){  //maximize the dist
    //                 valid = false;
    //                 break;
    //             }
    //         }
    //         if(!valid) continue; //go out pick different point

    //         chosen.push_back(p);
    //         if(check(points, k , dist, p+1, chosen)){// pick
    //             return true;
    //         }
    //         chosen.pop_back();
    //     }
    //     return false;
    // }

    // int maxDistance(int side, vector<vector<int>>& points, int k){
    //     int l = 0;
    //     int r = 2*side;

    //     int result = 0;

    //     while(l <= r){
    //         int mid = l + (r-l)/2;
    //         vector<int> chosen;

    //         if(check(points, k, mid, 0, chosen)){
    //             result = mid;
    //             l = mid + 1;
    //         }else {
    //             r = mid - 1;
    //         }
    //     }

    //     return result;
    // }
};

int main(){
    vector<vector<int>> points = {{0, 0}, {0, 2}, {2, 0}, {2, 2}};
    int k = 4, side = 2;
    Solution s;
    cout<<s.maxDistance(side, points, k);
    return 0;
}