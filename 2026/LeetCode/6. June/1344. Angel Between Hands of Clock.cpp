#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    double angleClock(int hour, int minutes){
        double minute_angle = 0;
        double hour_angle = 0;

        hour_angle = (30 * hour) + (minutes/2.0);
        minute_angle = (6 * minutes);

        double ans = abs(hour_angle - minute_angle);

        return (ans < 180) ? ans : (360 - ans);
    }
};

int main(){
    int hour, minutes;
    hour = 3, minutes = 45;
    Solution s;
    cout<<s.angleClock(hour, minutes);
    return 0;
}