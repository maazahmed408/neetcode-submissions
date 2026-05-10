class Solution {
public:

string encode(vector<string>& strs) {
    string out;
    for (const string& w : strs) {
        out += to_string(w.size());
        out += '#';
        out += w;
    }
    return out;
}

vector<string> decode(string s) {
    vector<string> out;
    int i = 0;

    while (i < (int)s.size()) {
        int len = 0;

        // read the number (could be multiple digits)
        while (i < (int)s.size() && s[i] != '#') {
            len = len * 10 + (s[i] - '0');
            i++;
        }

        i++; // skip '#'

        // read the next len characters as the word
        out.push_back(s.substr(i, len));
        i += len;
    }

    return out;
}

};
