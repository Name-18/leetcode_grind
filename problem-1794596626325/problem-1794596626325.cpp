// Last updated: 11/14/2026, 12:33:46 AM
1class Solution {
2public:
3    bool func(vector<int> nums, vector<int> target){
4        sort(nums.begin(),nums.end());
5        sort(target.begin(),target.end());
6
7        return nums != target;
8    }
9    int countSuffix(vector<int>& nums, vector<int>& target) {
10
11        if(func(nums,target)){
12            return 0;
13        }
14        int mask =  -1;
15        int n =  nums.size();
16        for(int i=0;i<n;i++){
17
18            if(nums[i] == target[i]){
19                mask+=1;
20            }else{
21                break;
22            }
23        }
24
25        int inx = n-1;
26
27        for(int i = n-2;i>=0;i--){
28
29            if(target[i] >= target[i+1]){
30
31                inx--;
32                
33            }else{
34                break;
35            }
36            
37        }
38        vector<int> mi(n,INT_MAX);
39        vector<int> mx(n,INT_MIN);
40        
41        for(int i = inx ; i<n;i++){
42            if(i > 0){
43            mi[i]  = min(mi[i-1],nums[i]);
44            }else{
45             mi[i]  = min(mi[i],nums[i]);
46            }
47        }
48        for(int i = n-1 ; i>=inx;i--){
49           if(i != n-1){
50            mx[i]  = max(mx[i+1],nums[i]);
51            }else{
52             mx[i]  = max(mx[i],nums[i]);
53            }
54        }
55
56
57
58        cout<<mask<<" "<<inx;
59
60        if(mask - inx < -1) return 0;
61
62 int ans = 1;
63            for(int i = inx+1;i<n;i++){
64
65                if(mi[i-1] >= mx[i]){
66                    ans +=1;
67                 
68                }else{
69                    break;
70                }
71                
72            }
73
74            return ans;
75        
76        
77      
78        
79    }
80};