// Last updated: 7/12/2026, 1:12:26 PM
1class Solution {
2public:
3    bool judgeCircle(string moves) {
4        if (moves.length() & 1) return false;
5        int x = 0, y = 0;
6
7        for (char c : moves) {
8            y += (c == 'U') - (c == 'D');
9            x += (c == 'R') - (c == 'L');
10        }
11
12        return !x && !y;
13    }
14};
15
16