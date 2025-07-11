class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
          unordered_map<string, int> freq;

    // Count frequency
    for (const string& word : words) {
        freq[word]++;
    }

    // Move map to a vector for sorting
    vector<pair<string, int>> items(freq.begin(), freq.end());

    // Sort by: descending frequency, then lexicographically ascending
    sort(items.begin(), items.end(), [](const auto& a, const auto& b) {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second > b.second;
    });

    // Collect top k
    vector<string> result;
    for (int i = 0; i < k && i < items.size(); i++) {
        result.push_back(items[i].first);
    }

    return result;
    }
};