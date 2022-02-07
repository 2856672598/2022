// #include<iostream>
// #include<vector>
// using namespace std;

// class Solution {
// public:
//     int numSubarrayProductLessThanK(vector<int>& nums, int k) {
//         int count =0;
//         int left = 0,right  = 0;
//         int sum = 1;
//         while(right<nums.size())
//         {
//             sum*=nums[right];
//             while(left <= right&& sum >=k)
//             {
//                 sum/=nums[left++];
//             }
//             count += right >= left ? right - left + 1 : 0;
//             right++;
//         }
//         return count;
//     }
// };
// int main()
// {
//     vector<int>nums{10,5,2,6};
//     int k=100;
//     cout<<Solution().numSubarrayProductLessThanK(nums,k)<<endl;
//     return 0;
// }


// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;

// class Solution
// {
// public:
//     static bool comp(int x, int y)
//     {
//         return x > y;
//     }
//     vector<int> sortEvenOdd(vector<int> &nums)
//     {
//         vector<int> even, odd;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             if (i % 2 == 0)
//                 even.push_back(nums[i]);
//             else
//                 odd.push_back(nums[i]);
//         }
//         sort(even.begin(), even.end());
//         sort(odd.begin(), odd.end(), comp);
//         vector<int> ret;
//         int begin = 0 ,end= even.size();
//         while(begin<end)
//         {
//             ret.push_back(even[begin]);
//             if(begin< odd.size())
//                 ret.push_back(odd[begin]);
//             begin++; 
//         }
//         return ret;
//     }
// };

// int main()
// {
//     vector<int>nums{4,1,2,3};
//     vector<int>ret = Solution().sortEvenOdd(nums);
//     for(auto e:ret)
//         cout<<e<<" ";
//     return 0;
// }

// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;

// class Solution
// {
// public:
//     long long smallestNumber(long long num)
//     {
//         int flag = 1;
//         if (num == 0)
//             return 0;
//         if (num < 0)
//             flag = -1;
//         vector<int> arr;
//         while (num)
//         {
//             arr.push_back(num % 10);
//             num /= 10;
//         }
//         sort(arr.begin(), arr.end());
//         if (arr[0] == 0)
//         {
//             for (int i = 0; i < arr.size(); i++)
//             {
//                 if (arr[i] != 0)
//                 {
//                     swap(arr[i], arr[0]);
//                     break;
//                 }
//             }
//         }

//         long long ret = 0;
//         for (int i = 0; i < arr.size(); i++)
//         {
//             ret = ret * 10 + arr[i];
//         }
//         return ret;
//     }
// };

// int main()
// {
//     int num =-7650;
//     cout<<Solution().smallestNumber(num);
//     return 0;
// }

// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;

// class Solution {
// public:
//     int minimumSum(int num) {
//         vector<int>arr;
//         while(num)
//         {
//             arr.push_back(num%10);
//             num/=10;
//         }
//         sort(arr.begin(),arr.end());
//         int new1=0,new2=0;
//         new1 =arr[0]*10+arr[3];
//         new2 =arr[1]*10+arr[2];
//         return new1+new2;
//     }
// };

// int main()
// {
//     return 0;
// }

// #include <iostream>
// #include <vector>
// using namespace std;
// class Solution
// {
// public:
//     vector<int> pivotArray(vector<int> &nums, int pivot)
//     {
//         vector<int> ret;
//         vector<int> arr;
//         int flag = 0;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             if (nums[i] < pivot)
//                 ret.push_back(nums[i]);
//             else if (nums[i] == pivot)
//                 flag++;
//             else if (nums[i] > pivot)
//                 arr.push_back(nums[i]);
//         }
//         while (flag)
//         {
//             ret.push_back(pivot);
//             flag--;
//         }
//         ret.insert(ret.end(), arr.begin(), arr.end());
//         return ret;
//     }
// };
// int main()
// {
//     vector<int>nums{9,12,5,10,14,3,10};
//     int pivot = 2;
//     Solution().pivotArray(nums,pivot);
//     return 0;
// }

// #include<iostream>
// #include<algorithm>
// #include<vector>
// #include<string>
// #include<unordered_map>
// using namespace std;

// class Solution
// {
// public:
//     vector<vector<int>> threeSum(vector<int> &nums)
//     {
//         sort(nums.begin(), nums.end());
//         unordered_map<string, vector<int>> m;
//         for (int i = 0; i < (int)nums.size() - 2; i++)
//         {
//             for (int j = i + 1; j < (int)nums.size() - 1; j++)
//             {
//                 for (int z = j + 1; z < nums.size(); z++)
//                 {
//                     if (nums[i] + nums[j] + nums[z] == 0)
//                     {
//                         string key;
//                         key += nums[i];
//                         key += nums[j];
//                         key += nums[z];
//                         if (m.find(key) == m.end())
//                         {
//                             m.insert(pair<string,vector<int>>(key,{}));
//                             m[key].push_back(nums[i]);
//                             m[key].push_back(nums[j]);
//                             m[key].push_back(nums[z]);
//                         }
//                     }
//                 }
//             }
//         }
//         vector<vector<int>> ret;
//         for (auto e : m)
//         {
//             vector<int> tmp(e.second);
//             ret.push_back(tmp);
//         }
//         return ret;
//     }
// };

// int main()
// {
//     vector<int>nums{ };
//     Solution().threeSum(nums);
//     return 0;
// }

// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;

// class Solution
// {
// public:
//     vector<vector<int>> threeSum(vector<int> &nums)
//     {
//         vector<vector<int>> ret;
//         sort(nums.begin(), nums.end());
//         for (int i = 0; i < (int)nums.size() - 2; i++)
//         {
//             int tmp = 0 - nums[i];
//             int left = i + 1, right = nums.size() - 1;
//             if (i > 0 && nums[i] == nums[i - 1])
//                 continue;
//             while (left < right)
//             {
//                 if (nums[left] + nums[right] > tmp)
//                     right--;
//                 else if (nums[left] + nums[right] < tmp)
//                     left++;
//                 else
//                 {
//                     ret.push_back({nums[i], nums[left], nums[right]});
//                     left++;
//                     right--;
//                     while(left>0&&nums[left] == nums[left-1])
//                     {
//                         left++;
//                     }
//                 }
//             }
//         }
//         return ret;
//     }
// };

// int main()
// {
//     vector<int> nums{0,0,0,0};
//     Solution().threeSum(nums);
//     return 0;
// }


// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;

// class Solution
// {
// public:
//     int minSubArrayLen(int target, vector<int> &nums)
//     {
//         int left = 0, right = 0;
//         int sum = 0;
//         int ret = INT_MAX;
//         while (right < nums.size())
//         {
//             sum += nums[right];
//             if (sum >= target)
//             {
//                 while (left <= right && sum >= target)
//                 {
//                     ret = min(ret, right - left + 1);
//                     sum -= nums[left++];
//                 }
//             }
//             right++;
//         }
//         ret = ret != INT_MAX ? ret : 0;
//         return ret;
//     }
// };

// int main()
// {
//     vector<int>nums{1,2,3,4,5};
//     int target =11;
//     cout<<Solution().minSubArrayLen(target,nums);
//     return 0;
// }

// #include<iostream>
// #include<vector>
// using namespace std;

// class Solution
// {
// public:
//     int subarraySum(vector<int> &nums, int k)
//     {
//         int ret = 0, sum = 0;
//         int left = 0, right = 0;
//         while (right < nums.size())
//         {
//             sum += nums[right];
//             while (sum > k && left <= right)
//             {
//                 sum -= nums[left++];
//             }
//             if (sum == k && left <= right)
//             {
//                 ret++;
//             }
//             right++;
//         }
//         return ret;
//     }
// };
// int main()
// {
//     vector<int>nums{1};
//     int k =0;
//     Solution().subarraySum(nums,k);
//     return 0;
// }


// #include<iostream>
// #include<vector>
// #include<algorithm>
// #include<unordered_map>
// using namespace std;

// class Solution
// {
// public:
//     int findMaxLength(vector<int> &nums)
//     {
//         int cnt = 0;
//         int ret = 0;
//         unordered_map<int, int> m;
//         m[0] = -1;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             if (nums[i] == 0)
//                 cnt -= 1;
//             else
//                 cnt += 1;
//             if (m.count(cnt))
//             {
//                 ret = max(ret, i - m[cnt]);
//             }
//             else
//                 m[cnt] = i;
//         }
//         return ret;
//     }
// };

// int main()
// {
//     vector<int>nums{0,0,1,0,0,0,1,1};
//     Solution().findMaxLength(nums);
//     return 0;
// }

// #include<iostream>
// #include<vector>
// using namespace std;

// class Solution
// {
// public:
//     int sumOfUnique(vector<int> &nums)
//     {
//         int arr[101] = {0};
//         for (auto e : nums)
//             arr[e]++;
//         int sum = 0;
//         for (int i = 1; i <= 100; i++)
//         {
//             if (arr[i] == 1)
//                 sum += i;
//         }
//         return sum;
//     }
// };

// int main()
// {
//     return 0;
// }

#include<iostream>
#include<vector>
using namespace std;

class NumMatrix {
private:
    vector<vector<int>>sum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if(matrix.size()== 0)
            return;
        sum.resize(matrix.size()+1,vector<int>(matrix[0].size()+1,0));
        for (int i = 1; i <= matrix.size(); i++)
        {
            for (int j = 1; j <= matrix[0].size(); j++)
            {
                sum[i][j] = sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+matrix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++,row2++;
        col1++,col2++;
        return sum[row2][col2]-sum[row1-1][col2]-sum[row2][col1-1]+sum[row1-1][col1-1];
    }
};
