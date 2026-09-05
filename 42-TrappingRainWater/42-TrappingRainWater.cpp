// Last updated: 9/5/2026, 10:28:05 PM
1class Solution {
2public:
3    int trap(vector<int>& height) {
4        int n = height.size();
5        int left = 0;
6        int right = height.size()-1;
7        int left_max = 0;
8        int right_max = 0;
9        int ans= 0;
10        while(left<=right){
11         
12            if( left_max> right_max){
13                 int wt = min(left_max,right_max);
14                 wt-= height[right];
15
16                 ans += max(0,wt);
17                 right_max = max(right_max ,height[right] );
18
19               right--;
20            }else{
21                 int wt = min(left_max,right_max);
22                 wt-= height[left];
23
24                 ans += max(0,wt);
25                 left_max = max(left_max,height[left] );
26
27               left++;
28            }
29        }
30        return ans;
31    }
32};