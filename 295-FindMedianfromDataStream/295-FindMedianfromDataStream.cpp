// Last updated: 7/26/2026, 1:02:17 AM
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
18       else if(!pq1.empty() and pq1.top()  <= num){
19             pq1.push(num);
20        }
21
22        if(abs((int)pq1.size() - (int)pq2.size()) > 1 ) {
23
24            if(pq1.size() > pq2.size()){
25                pq2.push(pq1.top());
26                pq1.pop();
27            }
28            else{
29                pq1.push(pq2.top());
30                pq2.pop();
31            }
32        }
33       
34    }
35    
36    double findMedian() {
37        if(pq2.size()==pq1.size()){
38              
39              int t =  pq2.top();
40              int t2 = pq1.top();
41              double x = (t+t2);
42              x/=2;
43              return x;
44        }
45        if(pq1.size()> pq2.size()) return pq1.top();
46
47        return pq2.top();
48        
49    }
50};
51
52/**
53 * Your MedianFinder object will be instantiated and called as such:
54 * MedianFinder* obj = new MedianFinder();
55 * obj->addNum(num);
56 * double param_2 = obj->findMedian();
57 */