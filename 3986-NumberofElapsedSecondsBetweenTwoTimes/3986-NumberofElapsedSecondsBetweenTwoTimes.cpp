// Last updated: 7/12/2026, 5:32:42 PM
1class Solution {
2public:
3  int func(string &s){
4    int cnt = 0;
5
6    int hr = 0;
7    hr += s[0] - '0';
8    hr *=10;
9    hr +=s[1] - '0';
10    int min = 0;
11    min += s[3] - '0';
12    min *=10;
13    min +=s[4] - '0';
14
15    int sec  = 0;
16        sec += s[6] - '0';
17    sec*=10;
18    sec +=s[7] - '0';
19
20    return hr * 3600 + min* 60 + sec;
21  }
22    int secondsBetweenTimes(string startTime, string endTime) {
23         return  func( endTime) - func(startTime);
24
25    }
26};