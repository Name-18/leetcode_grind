// Last updated: 11/14/2026, 12:43:47 AM
1class Solution {
2public:
3    bool func(vector<int> nums, vector<int> target){
4        sort(nums.begin(),nums.end());
5        sort(target.begin(),target.end());
6        return nums != target;
7    }
8    int countSuffix(vector<int>& nums, vector<int>& target) {
9        if(func(nums,target)){
10            return 0;
11        }
12        int mask =  -1;
13        int n =  nums.size();
14        for(int i=0;i<n;i++){
15            if(nums[i] == target[i]){
16                mask+=1;
17            }else{
18                break;
19            }
20        }
21        int inx = n-1;
22        for(int i = n-2;i>=0;i--){
23            if(target[i] >= target[i+1]){
24                inx--;
25            }else{
26                break;
27            }
28        }
29        vector<int> mi(n,INT_MAX);
30        vector<int> mx(n,INT_MIN);
31     
32        for(int i = n-1 ; i>=inx;i--){
33           if(i != n-1){
34            mx[i]  = max(mx[i+1],nums[i]);
35            }else{
36             mx[i]  = max(mx[i],nums[i]);
37            }
38        }
39        if(mask - inx < -1) return 0;
40 int ans = 1;
41            for(int i = inx+1;i<n;i++){
42                if(nums[i-1] >= mx[i]){
43                    ans +=1;
44                }else{
45                    break;
46                }      
47            }
48            return ans;
49
50        
51    }
52};