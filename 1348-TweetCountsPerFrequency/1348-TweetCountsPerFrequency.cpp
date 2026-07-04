// Last updated: 7/4/2026, 4:38:08 PM
1class TweetCounts {
2public:
3    unordered_map<string, vector<int>> mpp;
4
5    TweetCounts() {}
6
7    void recordTweet(string tweetName, int time) {
8
9        mpp[tweetName].push_back(time);
10    }
11
12    vector<int> getTweetCountsPerFrequency(string freq, string tweetName,
13                                           int startTime, int endTime) {
14
15        int interval;
16
17        if (freq == "minute")
18            interval = 60;
19        else if (freq == "hour")
20            interval = 3600;
21        else
22            interval = 86400;
23
24        vector<int> ans;
25
26        vector<int>& times = mpp[tweetName];
27        sort(times.begin(), times.end());
28
29        for (int start = startTime; start <= endTime; start += interval) {
30
31            int end = min(start + interval - 1, endTime);
32
33            auto left = lower_bound(times.begin(), times.end(), start);
34            auto right = upper_bound(times.begin(), times.end(), end);
35
36            ans.push_back(right - left);
37        }
38
39        return ans;
40    }
41};
42
43/**
44 * Your TweetCounts object will be instantiated and called as such:
45 * TweetCounts* obj = new TweetCounts();
46 * obj->recordTweet(tweetName,time);
47 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq, tweetName,
48 * startTime, endTime);
49 */