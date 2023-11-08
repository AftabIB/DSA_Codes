class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        //find xdiff and ydiff
        int xDiff = abs(sx - fx),yDiff = abs(sy - fy);

        //edge case
        if(xDiff == 0 && yDiff == 0 && t == 1)
        {
            return false;
        }

        return (min(xDiff,yDiff) + abs(xDiff-yDiff)) <= t;
    }
};