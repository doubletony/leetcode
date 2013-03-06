class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        int left = '/' == path.at(0)? 0: -1;
        int right = 0;
        while(left < path.size())
        {
            right = left;
            while(++right < path.size() && '/' != path.at(right));
            string part = path.substr(left+1, right-left-1);
            left = right;
            if("." == part || "" == part)
                continue;
            else if(".." == part)
            {
                if(st.size() > 0)	st.pop_back();
            }
            else
                st.push_back(part);
        }
        if(st.size() > 0)
        {
            stringstream oss;
            for(int i = 0; i < st.size(); ++i)
                oss << "/" << st[i];
            return oss.str();
        }
        else
            return "/";
    }
};