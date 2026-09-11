// Last updated: 9/11/2026, 7:19:25 PM
1class Solution {
2public:
3vector<int> digits;
4set<int> st;
5  void func(int num, int mask , int str ,int i){
6    if(i==3){
7     
8    
9    st.insert(num);
10    return ;
11    }
12int ans= 0;
13    for(int j=0;j<digits.size();j++){
14
15        if( (mask & (1<<j) ) !=0 ){
16             
17             if(i==2){
18
19                if(digits[j]%2==0){
20                    func(num*10+digits[j] , (mask ^ (1<<j)) , 1,i+1);
21                }
22             }
23
24            else if(digits[j] == 0){
25
26                if(str == 0){
27                       continue;
28                }else{
29                    
30                     func(num*10+digits[j] , (mask ^ (1<<j)) , 1,i+1);
31                }
32            }else{
33                  func(num*10+digits[j] , (mask ^ (1<<j)) , 1,i+1);
34            }
35        }
36    }
37    
38  }
39
40    int totalNumbers(vector<int>& digits) {
41        int mask = 1<<(digits.size());
42     this->digits = digits;
43     mask-=1;
44     
45         func( 0 ,mask ,0,0);
46
47         return st.size();
48    }
49};