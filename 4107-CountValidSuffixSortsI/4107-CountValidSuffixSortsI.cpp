// Last updated: 11/14/2026, 12:43:20 AM
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
32        for(int i = inx ; i<n;i++){
33            if(i > 0){
34            mi[i]  = min(mi[i-1],nums[i]);
35            }else{
36             mi[i]  = min(mi[i],nums[i]);
37            }
38        }
39        for(int i = n-1 ; i>=inx;i--){
40           if(i != n-1){
41            mx[i]  = max(mx[i+1],nums[i]);
42            }else{
43             mx[i]  = max(mx[i],nums[i]);
44            }
45        }
46        if(mask - inx < -1) return 0;
47 int ans = 1;
48            for(int i = inx+1;i<n;i++){
49                if(nums[i-1] >= mx[i]){
50                    ans +=1;
51                }else{
52                    break;
53                }      
54            }
55            return ans;
56
57        
58    }
59};