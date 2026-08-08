// Last updated: 8/8/2026, 10:34:55 AM
1class Solution {
2public:
3    vector<int> nums;
4    vector<int> multi;
5    unordered_map<string,int> mpp;
6   int  func(int i ,int j , int k){
7
8        if(k== multi.size()) return 0;
9
10       string hash = to_string(i) + " " + to_string(j) + " " + to_string(k);
11       if(mpp.find(hash)!=mpp.end()) return mpp[hash];
12        long long x =  multi[k]*nums[i] +func(i+1,j,k+1);
13
14        long long y =  multi[k]*nums[j] +func(i,j-1,k+1);
15
16        return  mpp[hash] =max(x,y);
17    }
18    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
19        this->nums = nums;
20        this->multi = multipliers;
21        return func(0,nums.size()-1,0);
22    }
23};