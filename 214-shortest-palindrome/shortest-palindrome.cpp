class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.length();
        int i = 0;
        for (int j = n - 1; j >= 0; j--) 
        {
            if (s[i] == s[j]) i++;
        }
        if (i == n) return s;
        string rem = s.substr(i,n);
        reverse(rem.begin(), rem.end());
        return rem + shortestPalindrome(s.substr(0, i)) + s.substr(i);
    }

};