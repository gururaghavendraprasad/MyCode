class Solution {
public:
    string reverseWords(string s) {
        stack<string> osStack;
        string oTmp;
        int iSize = s.length();
        for(int i =0; i < iSize;i++)
        {
            if (s[i] != ' ' || (i-1 == iSize))
            {
                oTmp.push_back(s[i]);
                continue;
            }
            osStack.push(oTmp);
            oTmp.clear();
        }
        while (!osStack.empty())
        {
            oTmp = oTmp + " " + (osStack.top());
            osStack.pop();
        }
        return oTmp;
    }
};
