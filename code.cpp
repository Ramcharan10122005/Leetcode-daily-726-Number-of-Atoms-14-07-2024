class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.size(), i, j, k;
        stack<pair<string, int>> st; // element and digit

        vector<int> mulfact(n, 1);
        int mul = 1;
        stack<int> temp;
        for (i = n - 1; i >= 0; i--) {
            char ch = formula[i];
            if (ch == ')') {
                string sdigit = "";
                for (j = i + 1; j < n; j++) {
                    ch = formula[j];
                    if (!isdigit(ch)) // checks whether the char is digit or not
                        break;
                    sdigit += ch;
                }
                if (sdigit == "")
                    sdigit = "1";
                int digit = stoi(sdigit); // string to number conversion
                mul = mul * digit;
                temp.push(digit);
            } else if (ch == '(') {
                int digit = temp.top();
                temp.pop();
                mul = mul / digit;
            }
            mulfact[i] = mul;
        }
        map<string, int> mp;
        for (i = 0; i < n; i++) {
            char ch = formula[i];
            if (isupper(ch)) { // checks whether the char is uppercase or not
                int mul = mulfact[i];
                string element = "";
                element += ch;
                for (j = i + 1; j < n; j++) {
                    ch = formula[j];
                    if (!islower(
                            ch)) // checks whether the char is lowercase or not
                        break;
                    element += ch;
                }
                string sdigit = "";
                for (k = j; k < n; k++) {
                    ch = formula[k];
                    if (!isdigit(ch))
                        break;
                    sdigit += ch;
                }
                if (sdigit == "")
                    sdigit = "1";
                int digit = stoi(sdigit);
                mp[element] += mul * digit;
                i = k - 1;
            } else if (ch == '(') {
                continue;
            } else if (ch == ')') {
                continue;
            }
        }
        string ans = "";
        for (auto p : mp) {
            string element = p.first;
            string sdigit = to_string(p.second); // integer to string conversion
            if (sdigit == "1")
                sdigit = "";
            ans += element + sdigit;
        }
        return ans;
    }
};
