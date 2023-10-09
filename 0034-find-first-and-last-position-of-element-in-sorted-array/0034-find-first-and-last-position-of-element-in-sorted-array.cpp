class Solution {
private:
int search(vector<int>& nums, int target,bool findLeft)
{
    int index = -1;
    int start = 0;
    int end = nums.size() - 1;

    while(start <= end)
    {
        int mid = start + (end - start)/2;
        if(nums[mid] == target)
        {
            index = mid;
            if(findLeft)
           {
                end = mid - 1;
           }
           else
           {
               start = mid + 1;
           }
        }
        else if(nums[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return index;
}

// int rightBound(vector<int>& nums, int target)
// {
//     int index = -1;
//     int start = 0;
//     int end = nums.size() - 1;

//     while(end > start)
//     {
//         int mid = start + (end - start)/2;
//         if(nums[mid] == target)
//         {
//             index = mid;
//             start = mid + 1;
//         }
//         if(target > nums[mid])
//         {
//             start = mid + 1;
//         }
//         else
//         {
//             end = mid - 1;
//         }
//     }
//     return index;
// }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = search(nums,target,true);
        int right = search(nums,target,false);

        if (left <= right) {
            return {left, right};
        } else {
            return {-1, -1};
        }
    }
};