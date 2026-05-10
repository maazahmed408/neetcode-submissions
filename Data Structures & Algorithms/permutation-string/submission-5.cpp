class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> A(26,0);
        vector<int> B(26,0);
        int matches = 0;

        for(int i = 0; i<s1.size(); ++i){
            A[s1[i] - 'a']++;
            B[s2[i] - 'a']++;
        }

        for(int i = 0; i<26; ++i){
            if(A[i]==B[i]){
                matches++;
            }
        }

        if(matches == 26){
            return true;
        }

        int l = 0;

        for(int r=s1.size();r<s2.size();++r){
            int leftIdx = s2[l] - 'a';
            int rightIdx = s2[r] - 'a';
          // remove s2[l]
            if (A[leftIdx] == B[leftIdx]) matches--;
            B[leftIdx]--;
            if (A[leftIdx] == B[leftIdx]) matches++;

            l++;

            // add s2[r]
            if (A[rightIdx] == B[rightIdx]) matches--;
            B[rightIdx]++;
            if (A[rightIdx] == B[rightIdx]) matches++;

            if(matches == 26){
                return true;
            }
        }

        return false;
    }
};







