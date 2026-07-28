class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> data;
        for (int i = 0; i < n; ++i) {
            data.push_back({position[i], speed[i]});
        }

        sort(data.begin(), data.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first < b.first;
        });

        vector<double> times(n);
        for (int i = 0; i < n; ++i) {
            times[i] = static_cast<double>(target - data[i].first) / data[i].second;
        }

        int fleets = 0;
        double cur = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (times[i] > cur) {
                fleets++;
                cur = times[i];
            }
        }

        return fleets;
    }
};
