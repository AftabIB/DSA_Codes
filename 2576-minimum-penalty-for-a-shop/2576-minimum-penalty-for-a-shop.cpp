class Solution {
public:
    int bestClosingTime(string cust) {
        
        int mx=INT_MIN;
        int mxl=0;
        int c=0,y=0,n=0;
        for(int i=0;i<cust.size();i++)
        {
            if(cust[i]=='Y')
            {
                y++;
                c++;
            }
            if(cust[i]=='N')
            {
                n++;
                c--;
            }
            if(mx< c && c>0)
            {
                mx=c;
                mxl=i;
            } 

        }

        if(y==0 || mx==INT_MIN) return 0;
        return mxl+1;
    }
};