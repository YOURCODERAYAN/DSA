class Solution {
public:
    // QuickSort Partition
    int partition(string &s, int low, int high) {
        char pivot = s[low];
        int i = low;
        int j = high;

        while (i < j) {
            while (i <= high && s[i] >= pivot) i++;   // descending order
            while (j >= low && s[j] < pivot) j--;

            if (i < j) swap(s[i], s[j]);
        }

        swap(s[low], s[j]);
        return j;
    }

    // QuickSort Function
    void quickSort(string &s, int low, int high) {
        if (low < high) {
            int p = partition(s, low, high);
            quickSort(s, low, p - 1);
            quickSort(s, p + 1, high);
        }
    }

    // Frequency Sort Function (example logic)
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;

        vector<pair<char, int>> arr(freq.begin(), freq.end());

        // Sort characters by frequency (descending)
        sort(arr.begin(), arr.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });

        string result = "";
        for(int i=0;i<arr.size();i++){
            char ch=arr[i].first;
            int cnt=arr[i].second;
            for(int j=0;j<cnt;j++){
                result+=ch;
            }
        }

        return result;
    }
};
