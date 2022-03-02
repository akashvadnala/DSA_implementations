class Solution {
public:
    bool check(string& s, int& i) {
        if(s[i]=='t'){
            ++i;
            return true;
        }
        if(s[i]=='f'){
            ++i;
            return false;
        }
        char op=s[i++];
        bool res = (op=='&');
        if(op == '!') {
            ++i;
            res = check(s, i);
            ++i;
            return !res;
        }
        while(s[i] != ')'){
            ++i;
            if (op == '&') res &= check(s, i);
            else res |= check(s, i);
        }
        ++i;
        return res;
    }

    bool parseBoolExpr(string s) {
        int i = 0;
        return check(s, i);
    }
};