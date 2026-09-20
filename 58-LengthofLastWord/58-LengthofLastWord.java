// Last updated: 9/20/2026, 5:31:38 PM
1class Solution {
2    public int lengthOfLastWord(String s) {
3         s =s.trim();
4         String ans = "";
5         System.out.println(s);
6         int last = -1;
7        for(int i = 0 ;i< s.length();i++){
8
9            if(s.charAt(i) == ' '){
10                   ans = "";
11                   last = ans.length();
12            }else{
13                ans += s.charAt(i);
14            }
15        }
16        if(last != -1 &&  s.charAt(s.length()-1)==' ') return last; 
17return ans.length();
18    }
19}