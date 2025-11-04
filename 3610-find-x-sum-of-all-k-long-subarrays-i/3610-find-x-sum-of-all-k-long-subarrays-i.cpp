class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> answer;
        
        for (int i = 0; i <= n - k; i++) {
            unordered_map<int, int> freq;
            for (int j = i; j < i + k; j++) {
                freq[nums[j]]++;
            }
            
            vector<pair<int, int>> freqVec;
            for (auto& p : freq) {
                freqVec.push_back({p.second, p.first});
            }
            
            sort(freqVec.begin(), freqVec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
                if (a.first != b.first) return a.first > b.first;
                return a.second > b.second;
            });
            
            int sum = 0;
            int count = min(x, (int)freqVec.size());
            for (int j = 0; j < count; j++) {
                sum += freqVec[j].first * freqVec[j].second;
            }
            
            answer.push_back(sum);
        }
        
        return answer;
    }
};