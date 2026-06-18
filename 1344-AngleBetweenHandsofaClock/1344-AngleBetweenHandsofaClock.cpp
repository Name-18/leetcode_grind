// Last updated: 6/18/2026, 3:24:02 PM
1class Solution {
2public:
3    double angleClock(int hour, int minutes) {
4        
5        map<int,int>mpp;
6
7        mpp[12]=0;
8        int str = 30;
9        for(int i=1;i<=11;i++){
10            mpp[i]=str;
11            str+=30;
12        }
13
14        double m = minutes*6;
15        cout<<m<<endl;
16        double mov = 360/m;
17        cout<<mov<<endl;
18        double hr = mpp[hour] + 30/mov;
19
20        return min(abs(hr-m),360-abs(hr-m));
21    }
22};