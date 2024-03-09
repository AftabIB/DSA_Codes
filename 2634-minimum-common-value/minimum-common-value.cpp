class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int p1 = 0,p2 = 0;
        while(p1<n1 && p2<n2)
        {
            int x = nums1[p1];
            int y = nums2[p2];

            if(x == y)
                return x;
            else if(x>y)
                p2++;
            else
                p1++;
        }
        return -1;
    }
};