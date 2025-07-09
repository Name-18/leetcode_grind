#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        
 // if alpha then best shot is bucket sort
 // hashing 
 if(s.size()!=t.size()) return false;

 sort(s.begin(),s.end());
 sort(t.begin(),t.end());

 return s==t;

    }
};
