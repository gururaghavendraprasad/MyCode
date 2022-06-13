#define VECTOR  // performance of vector is faster than stack. The below code take 4ms and 15ms with vector and stack. 

#if VECTOR
class Solution {
public:
    string reverseWords(string s) {
        vector<string> osStack;
        string oTmp = "";
        for(string::iterator it = s.begin(); it != s.end(); it++)
        {
            if (*it != ' ')
            {
                oTmp.push_back(*it);
                continue;
            }
            if (oTmp.size() != 0)
            {
                osStack.push_back(oTmp);
                oTmp.clear();
            }
        }
        if (oTmp.size() != 0) // This check is to confirm last word is not space
        {
            osStack.push_back(oTmp);
            oTmp.clear();
        }
        vector<string>::reverse_iterator it = osStack.rbegin();
        oTmp = *it;
        it++;
        while (it != osStack.rend())
        {
            oTmp += " " + *it;
            it++;
        }
        return oTmp;
    }
};
#else
class Solution {
public:
    string reverseWords(string s) {
        stack<string> osStack;
        string oTmp = "";
        for(string::iterator it = s.begin(); it != s.end(); it++)
        {
            if (*it != ' ')
            {
                oTmp.push_back(*it);
                continue;
            }
            if (oTmp.size() != 0)
            {
                osStack.push(oTmp);
                oTmp.clear();
            }
        }
        if (oTmp.size() == 0) // This check is to confirm last word is not space
        {
            oTmp = osStack.top();
            osStack.pop();
        }
        while (!osStack.empty())
        {
            oTmp += " " + (osStack.top());
            osStack.pop();
        }
        return oTmp;
    }
};
#endif
