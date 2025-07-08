class Solution {
    /* helper uses indices so it never allocates a new string */
    static bool check(const string& s, int l, int r) {
        while (l < r && !isalnum(s[l]))  ++l;
        while (l < r && !isalnum(s[r]))  --r;

        if (l >= r) return true;                       // cleaned‑up range empty
        if (tolower(s[l]) != tolower(s[r])) return false;

        return check(s, l + 1, r - 1);                 // tail call, cheap
    }

public:
    /* LeetCode still sees ONE parameter only */
    bool isPalindrome(string s) {
        return check(s, 0, static_cast<int>(s.size()) - 1);
    }
};
