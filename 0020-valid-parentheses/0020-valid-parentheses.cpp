class Solution {
public:
    bool isValid(string s) {
        stack<int> stk;
        for(int i=0;i<s.length();i++)
        {
            char ch = s[i];

            //they are openig brackets
            if(ch == '(' || ch == '{' || ch == '[')
            {
                stk.push(ch);
            }
            // they are closing brackets
            else
            {
                if(!stk.empty())
                {
                    char top = stk.top();

                    if((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '[') )
                    {
                        stk.pop();
                    }
                    else
                    {
                        return false;
                    }
                } 
                else
                {
                    return false;
                }
            }
        }

        if(stk.empty())
            return true;
        else
            return false;
    }
};