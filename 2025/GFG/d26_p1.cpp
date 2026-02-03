// count number of possible triangles
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    int countTriangles(vector<int> &arr){
        sort(arr.begin(), arr.end());
        int count = 0;
        for (int k = arr.size()-1; k >= 2; k--){
            int i = 0, j = k-1;
            while (i < j){
                if(arr[i] + arr[j] > arr[k]){
                    count += j - i;
                    j--;
                }else{
                   i++;
                }
            }
        }
        return count;
    }
};
int main()
{
    vector<int> vec = {9,22,15,33,34,47,7,42,10};
    Solution s;
    cout << s.countTriangles(vec);
    return 0;
}//08/01/25
/*int Brute(vector<int> &arr){//O(N^3)
    int n = arr.size();
    int cnt = 0;
    for (int i = 0; i < n-2; i++){
        for (int j = i+1; j < n-1; j++){
            for (int k = j+1; k < n; k++){
                int a = arr[i];
                int b = arr[j];
                int c = arr[k];
                if (a+b>c && b+c>a && c+a>b)
                    cnt++;
            }
        }
    }
    return cnt;
}*/