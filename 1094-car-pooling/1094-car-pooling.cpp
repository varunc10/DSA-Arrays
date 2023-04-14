class Solution {
public:
    #define pi pair<int, int>
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        sort(trips.begin(), trips.end(), [](vector<int> a, vector<int> b){
            if(a[1] == b[1]){
                return a[2] < b[2];
            }
            return a[1] < b[1];
        });
        int currCap = capacity;
        for(int i = 0; i < trips.size(); i++){
            while(!pq.empty() && pq.top().first <= trips[i][1]){
                currCap += pq.top().second;
                pq.pop();
            }
            if(trips[i][0] > currCap){
                return false;
            }
            else if(trips[i][0] <= currCap){
                currCap -= trips[i][0];
                pq.push({trips[i][2], trips[i][0]});
            }
        }
        return true;
    }
};