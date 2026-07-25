// Last updated: 7/26/2026, 1:01:48 AM
1class MedianFinder {
2public:
3   priority_queue<int,vector<int> , greater<int>> pq1;
4   priority_queue<int> pq2;
5    MedianFinder() {
6        
7    }
8    
9    void addNum(int num) {
10        if(pq1.empty() and pq2.empty()){
11            pq1.push(num);
12        }
13
14       else if( !pq1.empty() and pq1.top()  > num){
15            pq2.push(num);
16        }
17        
18        else if(!pq1.empty() and pq1.top()  <= num){
19             pq1.push(num);
20        }
21        
22
23        if(abs((int)pq1.size() - (int)pq2.size()) > 1 ) {
24
25            if(pq1.size() > pq2.size()){
26                pq2.push(pq1.top());
27                pq1.pop();
28            }
29            else{
30                pq1.push(pq2.top());
31                pq2.pop();
32            }
33        }
34       
35    }
36    
37    double findMedian() {
38            if (pq1.size() == pq2.size()) {
39            // Use double casting to prevent integer overflow during addition
40            return ((double)pq1.top() + (double)pq2.top()) / 2.0;
41        }
42        if(pq1.size()> pq2.size()) return pq1.top();
43
44        return pq2.top();
45        
46    }
47};
48
49/**
50 * Your MedianFinder object will be instantiated and called as such:
51 * MedianFinder* obj = new MedianFinder();
52 * obj->addNum(num);
53 * double param_2 = obj->findMedian();
54 */