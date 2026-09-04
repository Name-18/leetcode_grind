// Last updated: 9/4/2026, 3:38:38 PM
1class Solution {
2public:
3    void nextPermutation(vector<int>& nums) {
4        int n = nums.size();
5        int pivotIndex = -1;
6
7        // -------- Step 1: Find the pivot (break point) --------
8        // Scan from right to left. The pivot is the first index (from right)
9        // where the sequence stops being non-increasing, i.e. nums[i] < nums[i+1].
10        // Everything to the right of pivot is in descending order.
11        for (int i = n - 2; i >= 0; i--) {
12            if (nums[i] < nums[i + 1]) {
13                pivotIndex = i;
14                break;
15            }
16        }
17
18        
19        if (pivotIndex == -1) {
20            reverseArray(nums, 0);
21            return;
22        }
23
24      
25        int successorIndex = -1;
26        for (int i = n - 1; i > pivotIndex; i--) {
27            if (nums[i] > nums[pivotIndex]) {
28                    swap(nums[pivotIndex], nums[i]);
29                break;
30            }
31        }
32
33    
34
35 
36        reverse(nums.begin()+ pivotIndex + 1 , nums.end());
37    }
38
39private:
40    // Reverses nums[start ... end] in place.
41    void reverseArray(vector<int>& nums, int start) {
42        int left = start;
43        int right = nums.size() - 1;
44        while (left < right) {
45            swap(nums[left], nums[right]);
46            left++;
47            right--;
48        }
49    }
50};