// Last updated: 6/25/2026, 12:16:39 AM
1class Solution {
2    const int MOD = 1e9 + 7;
3    using Matrix = vector<vector<long long>>;
4
5    Matrix multiply(const Matrix& A, const Matrix& B) {
6        int sz = A.size();
7        Matrix C(sz, vector<long long>(sz, 0));
8
9        for (int i = 0; i < sz; i++) {
10            for (int k = 0; k < sz; k++) {
11                if (!A[i][k]) continue;
12                for (int j = 0; j < sz; j++) {
13                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
14                }
15            }
16        }
17
18        return C;
19    }
20
21public:
22    int zigZagArrays(int n, int l, int r) {
23        if (n == 1) return r - l + 1;
24
25        int k = r - l + 1;
26        int sz = 2 * k;
27
28        Matrix M(sz, vector<long long>(sz, 0));
29
30        for (int i = 0; i < k; i++) {
31            for (int j = 0; j < i; j++) {
32                M[i][k + j] = 1;
33            }
34
35            for (int j = i + 1; j < k; j++) {
36                M[k + i][j] = 1;
37            }
38        }
39
40        Matrix res(sz, vector<long long>(sz, 0));
41
42        for (int i = 0; i < sz; i++) {
43            res[i][i] = 1;
44        }
45
46        long long p = n - 1;
47
48        while (p > 0) {
49            if (p % 2 == 1) {
50                res = multiply(res, M);
51            }
52
53            M = multiply(M, M);
54            p /= 2;
55        }
56
57        long long ans = 0;
58
59        for (int i = 0; i < sz; i++) {
60            for (int j = 0; j < sz; j++) {
61                ans = (ans + res[i][j]) % MOD;
62            }
63        }
64
65        return (int)ans;
66    }
67};