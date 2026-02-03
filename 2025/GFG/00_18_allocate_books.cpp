/*allocate books to students such that maximum pages 
allocated to any particular student is minimum;*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

class Solution{
    public:
    bool countStudents(vector<int> &arr, int pages, int k){
        int student = 1;
        long long studentPages = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++){
            if(studentPages + arr[i] <= pages)
                studentPages+= arr[i];
            else{
                student++;
                studentPages = arr[i];
            }
            if (student > k) return false;
        }
        return true;
    }
    int findPages(vector<int> &arr, int k){
        int low = *max_element(arr.begin(),arr.end());
        int high = accumulate(arr.begin(),arr.end(),0);
        if (arr.size() < k) return -1;
        while (low <= high){
            int mid = low + (high - low)/2;
            if (countStudents(arr, mid, k))
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};
int main(){
    vector<int> vec = {25, 46, 28, 49, 24};
    Solution s;
    cout<<s.findPages(vec, 4);
    return 0;
}//18/12