// Last updated: 9/20/2026, 10:12:21 AM
1class Solution {
2public:
3    int intr( vector<int>& a , vector<int> &b){
4      
5        if( a[1] >=  b[0]) return true;
6
7        return false;
8    }
9    int countIntersectingIntervals(vector<vector<int>>& intervals) {
10int n = intervals.size();
11        int cnt = 0;
12sort(intervals.begin(),intervals.end());
13        for(int i=0;i<n;i++){
14            for(int j=i+1;j<n;j++){
15
16                if( intr( intervals[i] , intervals[j] )  ) {
17
18                cnt +=1;
19                }
20            }
21        }
22        return cnt ;
23    }
24};