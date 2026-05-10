class Solution {
public:
    bool checkInclusion(string s1, string s2) {
    
        unordered_map<char,int> first;
        unordered_map<char , int> second;

        int l = 0;
        int r = s1.size() -1;

        for(int i = 0; i < s1.size(); ++i){
            first[s1[i]]++;
            second[s2[i]]++;
        }


        for(auto c : first){
            // cout<<first[s1[i]]<<endl;
            cout<<c.first<<endl;
        }

        while(r < s2.size() ){
            if(first == second){
                return true;
            }else{
                if(second[s2[l]]-- == 1){
                second.erase(s2[l]);
                }
                ++l;
                ++r;
                second[s2[r]]++;
            } 
            
        }

        return false;

    }
};
