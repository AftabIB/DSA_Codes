class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> st;
        int cnt=0;
        for(auto a:s)
        {
            if(a=='(')
                st.push(a);
            else if(a==')')
            {
                if(!st.empty())
                    st.pop();
                else
                    cnt++;
            }
        }
        return cnt+st.size();
    }
    //     //odd condition
    //     if(s.length()%2 == 1)
    //     {
    //         return 1;
    //     }

    //     //even condition
    //     stack<char> st;
    //     for(int i=0;i<s.length();i++)
    //     {
    //         char ch = s[i];
    //         // for opening brackets
    //         if(ch == '(')
    //         {
    //             st.push(ch);
    //         }
    //         // for closing brackets
    //         else
    //         {
    //             if(!st.empty() && st.top() == '(')
    //             {
    //                 st.pop();
    //             }
    //             else
    //             {
    //                 st.push(ch);
    //             }
    //         }
    //     }

    //     //invalid expressions
    //     int a = 0, b = 0;
    //     while(!st.empty())
    //     {
    //         if(st.top() == '(')
    //         {
    //             b++;
    //         }
    //         else
    //         {
    //             a++;
    //         }
    //         st.pop();
    //     }

    //     int ans = (a+1)/2 + (b+1)/2;
    //     return ans;
    // }
};