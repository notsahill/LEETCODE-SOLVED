class Solution {
private:
    unordered_map<string,string> en;
    int c=0;
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) 
    {
        string s=to_string(c);
        c++;
        en[s]=longUrl;
        return s;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return en[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));