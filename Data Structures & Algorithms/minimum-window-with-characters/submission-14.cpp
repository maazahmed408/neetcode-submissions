class Solution {
public:
    string minWindow(string s, string t) {
        if(t=="" || t.size() > s.size()){
            return "";
        }

        unordered_map<char,int> window;
        unordered_map<char,int> countT;
        int have = 0;
        
        int resLen = INT_MAX;
        pair<int, int> res = {-1,-1};

        for(char& c : t){
            countT[c]++;
        } 

        int need = countT.size();

        int l = 0;
        int r;
        for(r = 0; r < s.size(); ++r){
            char c = s[r];
            window[c]++;

            if(countT.find(c) != countT.end() && window[c] == countT[c] ){
                have++;
            }

            while(have == need){
                //update result
                if(resLen > r-l+1){
                    resLen = r-l+1;
                      res.first = l;
                res.second = r;
                }
              

                //pop the first element
                window[s[l]]--;
                if(countT.find(s[l]) != countT.end() && window[s[l]] < countT[s[l]]){
                    --have;
                }

                l++;

            }
        }

        
        string result = "";
        if(res.first > -1 && res.second > -1){
               for(int i = res.first ; i <= res.second; ++i){
           result += s[i]; 
        }

        }
     
        return result;




    }
};
