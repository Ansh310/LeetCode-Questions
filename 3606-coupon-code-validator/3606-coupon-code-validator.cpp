class Solution {
public:
    bool checkC(string& s) {
        int n = s.size();
        for(int i = 0; i < n; i++) {
            
            if(!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9') || s[i] == '_')) {
                return false;
            }
        }
        return true;
    }

    bool checkB(string& s) {
        
        if(s == "restaurant" || s == "grocery" || s == "pharmacy" || s == "electronics") {
            return true;
        }
        return false;
    }

    int convert(string& s) {
        if(s == "electronics") return 0;
        if(s == "grocery") return 1;
        if(s == "pharmacy") return 2;
        if(s == "restaurant") return 3;

        return -1;
    }

    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {

        vector<vector<string>> bs_to_code(4); int n = code.size();

        for(int i = 0; i < n; i++) {
            if(!code[i].empty() && isActive[i] && checkC(code[i]) && checkB(businessLine[i])) {
                int idx = convert(businessLine[i]);
                bs_to_code[idx].push_back(code[i]);
            }
        }
        
        sort(bs_to_code[0].begin(), bs_to_code[0].end());
        sort(bs_to_code[1].begin(), bs_to_code[1].end());
        sort(bs_to_code[2].begin(), bs_to_code[2].end());
        sort(bs_to_code[3].begin(), bs_to_code[3].end());

        vector<string> ans;
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < bs_to_code[i].size(); j++) {
                ans.push_back(bs_to_code[i][j]);
            }
        }

        return ans;
        
    }
};