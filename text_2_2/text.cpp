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

// #include<iostream>
// #include<vector>
// using namespace std;

// class NumMatrix {
// private:
//     vector<vector<int>>sum;
// public:
//     NumMatrix(vector<vector<int>>& matrix) {
//         if(matrix.size()== 0)
//             return;
//         sum.resize(matrix.size()+1,vector<int>(matrix[0].size()+1,0));
//         for (int i = 1; i <= matrix.size(); i++)
//         {
//             for (int j = 1; j <= matrix[0].size(); j++)
//             {
//                 sum[i][j] = sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+matrix[i-1][j-1];
//             }
//         }
//     }
    
//     int sumRegion(int row1, int col1, int row2, int col2) {
//         row1++,row2++;
//         col1++,col2++;
//         return sum[row2][col2]-sum[row1-1][col2]-sum[row2][col1-1]+sum[row1-1][col1-1];
//     }
// };

// #include<iostream>
// #include<vector>
// #include<string>
// #include<cstring>
// using namespace std;
// // class Solution {
// // public:
// //     vector<string>nums;
// //     void Backtracking(const string& s,string tmp,vector<int>used)
// //     {
// //         if(tmp.size() == s.size())
// //         {
// //             nums.push_back(tmp);
// //             return ;
// //         }
// //         for(int i =0;i<s.size();i++)
// //         {
// //             if(used[i] != 0)
// //                 continue;
// //             used[i] = 1;
// //             tmp.push_back(s[i]);
// //             Backtracking(s,tmp,used);
// //             tmp.pop_back();
// //             used[i] = 0;
// //         }
// //     }

// //     bool checkInclusion(string s1, string s2) {
// //         vector<int>used(s1.size(),0);
// //         Backtracking(s1,{},used);
// //         for(auto e:nums)
// //         {
// //             if(strstr(s2.c_str(),e.c_str())!=NULL)
// //                 return true;
// //         }
// //         return false;
// //     }
// // };

// class Solution
// {
// public:
//     bool checkInclusion(string s1, string s2)
//     {
//         vector<int> nums1(26, 0), nums2(26, 0);
//         if (s1.size() > s2.size())
//             return false;
//         for (int i = 0; i < s1.size(); i++)
//         {
//             nums1[s1[i] - 'a']++;
//             nums2[s2[i] - 'a']++;
//         }
//         if (nums1 == nums2)
//             return true;
//         int n = s1.size();
//         for (int i = n; i < s2.size(); i++)
//         {
//             nums2[s2[i] - 'a']++;
//             nums2[s2[i - n] - 'a']--;
//             if (nums1 == nums2)
//                 return true;
//         }
//         return false;
//     }
// };

// int main()
// {
//     string s1 ="ab";
//     string s2 = "abcd";
//     cout<<Solution().checkInclusion(s1,s2);
//     return 0;
// }


// #include<iostream>
// #include<vector>
// using namespace std;

// class Solution
// {
// public:
//     vector<int> findAnagrams(string s, string p)
//     {
//         if (s.size() < p.size())
//             return {};
//         int n = p.size();
//         vector<int> nums1(26, 0), nums2(26, 0);
//         vector<int> ret;
//         for (int i = 0; i < n; i++)
//         {
//             nums1[s[i] - 'a']++;
//             nums2[p[i] - 'a']++;
//         }
//         if (nums1 == nums2)
//             ret.push_back(0);
//         for (int i = n; i < s.size(); i++)
//         {
//             nums1[s[i] - 'a']++;
//             nums1[s[i - n] - 'a']--;
//             if (nums1 == nums2)
//                 ret.push_back(i - n + 1);
//         }
//         return ret;
//     }
// };

// int main()
// {
//     return 0;
// }


// #include<iostream>
// #include<vector>
// using namespace std;
// class Solution
// {
// public:
//     int countSubstrings(string s)
//     {
//         int count = 0;
//         for (int i = 0; i < s.size(); i++)
//         {
//             for (int j = 0; j < 2; j++)
//             {
//                 int left = i, right = i + j;
//                 while (left >= 0 && right < s.size())
//                 {
//                     if (s[left] != s[right])
//                         break;
//                     count++;
//                     left--;
//                     right++;
//                 }
//             }
//         }
//         return count;
//     }
// };

// int main()
// {
//     string s{"abc"};
//     cout<<Solution().countSubstrings(s);
//     return 0;
// }

// #include<iostream>
// #include<vector>
// using namespace std;
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
// // class Solution
// // {
// // public:
// //     ListNode *removeNthFromEnd(ListNode *head, int n)
// //     {
// //         ListNode newhead;
// //         newhead.next = head;
// //         ListNode *fast = &newhead, *slow = &newhead;
// //         while (n && fast)
// //         {
// //             fast = fast->next;
// //             n--;
// //         }
// //         ListNode *prev = nullptr;
// //         while (fast != nullptr)
// //         {
// //             fast = fast->next;
// //             prev = slow;
// //             slow = slow->next;
// //         }
// //         if (prev == nullptr)
// //             return fast;
// //         prev->next = slow->next;
// //         return newhead.next;
// //     }
// // };

// class Solution
// {
// public:
//     void Number(ListNode *s, vector<int> &x)
//     {
//         ListNode *cur = s;
//         while (cur)
//         {
//             x.push_back(cur->val);
//             cur = cur->next;
//         }
//     }
//     ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
//     {
//         if (l1 == nullptr)
//             return l2;
//         if (l2 == nullptr)
//             return l1;
//         vector<int> nums1, nums2;
//         Number(l1, nums1);
//         Number(l2, nums2);
//         reverse(nums1.begin(), nums1.end());
//         reverse(nums2.begin(), nums2.end());
//         int flag = 0;
//         int end = nums1.size() > nums2.size() ? nums1.size() : nums2.size();
//         int begin = 0;
//         int num1, num2;
//         ListNode *prev = nullptr;
//         while (begin < end)
//         {
//             num1 = begin >= nums1.size() ? 0 : nums1[begin];
//             num2 = begin >= nums2.size() ? 0 : nums2[begin];
//             ListNode *newnode = new ListNode;
//             int sum = num1 + num2 + flag;
//             if (sum > 9)
//             {
//                 newnode->val = sum % 10;
//                 flag = sum / 10;
//             }
//             else
//             {
//                 newnode->val = sum;
//                 flag = 0;
//             }
//             newnode->next = prev;
//             prev = newnode;
//             begin++;
//         }
//         if (flag != 0)
//         {
//             ListNode *head = new ListNode;
//             head->val = flag;
//             head->next = prev;
//             prev = head;
//         }
//         return prev;
//     }
// };

// int main()
// {
//     return 0;
// }


// #include<iostream>
// #include<vector>
// using namespace std;

// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
// class Solution
// {
// public:
//     void reorderList(ListNode *head)
//     {
//         vector<ListNode *> nums;
//         ListNode *cur = head;
//         while (cur)
//         {
//             nums.push_back(cur);
//             cur = cur->next;
//         }
//         int left = 0, right = nums.size() - 1;
//         ListNode newhead; //?????????
//         ListNode *prev = &newhead;
//         while (left <= right)
//         {
//             prev->next = nums[left];
//             prev = prev->next;
//             if (left != right)
//             {
//                 prev->next = nums[right];
//                 prev = prev->next;
//             }
//             left++;
//             right--;
//         }
//         prev->next = nullptr;
//     }
// };

// int main()
// {
//     return 0;
// }


// #include<iostream>
// using namespace std;

// class Node {
// public:
//     int val;
//     Node* next;

//     Node() {}

//     Node(int _val) {
//         val = _val;
//         next = NULL;
//     }

//     Node(int _val, Node* _next) {
//         val = _val;
//         next = _next;
//     }
// };

// class Solution
// {
// public:
//     Node *insert(Node *head, int insertVal)
//     {
//         if (head == nullptr)
//         {
//             head = new Node(insertVal);
//             head->next = head;
//             return head;
//         }
//         Node *cur = head->next;
//         Node *prev = head;
//         int max = 0;
//         while (cur)
//         {
//             if (cur == head || prev->val > cur->val && insertVal > prev->val)
//             {
//                 prev->next = new Node(insertVal, cur);
//                 break;
//             }
//             if ((cur->val >= insertVal && prev->val < insertVal) || (cur->val >= insertVal && cur->val < prev->val))
//             {
//                 prev->next = new Node(insertVal, cur);
//                 break;
//             }
//             prev = cur;
//             cur = cur->next;
//         }
//         return head;
//     }
// };
// int main()
// {
//     return 0;
// }

// #include<iostream>
// #include<vector>
// #include<string>
// #include<algorithm>
// using namespace std;

// class Solution
// {
// public:
//     int findMinDifference(vector<string> &timePoints)
//     {
//         vector<int> nums;
//         for (auto e : timePoints)
//         {
//             nums.push_back(atoi(e.substr(0, 2).c_str()) * 60 + atoi(e.substr(3).c_str()));
//         }
//         sort(nums.begin(), nums.end());
//         nums.push_back(24 * 60 + nums[0]);
//         int ret = 24 * 60;
//         for (int i = 1; i < nums.size(); i++)
//         {
//             ret = min(ret, nums[i] - nums[i - 1]);
//         }
//         return ret;
//     }
// };
// int main()
// {
//     vector<string>time{"23:59","00:00"};
//     cout<<Solution().findMinDifference(time);
//     return 0;
// }


// #include<iostream>
// using namespace std;

// class Solution {
// public:
//     int countOperations(int num1, int num2) {
//         int ret = 0;
//         while(num1&&num2)
//         {
//             if(num1 >= num2)
//                 num1 -= num2;
//             else
//                 num2 -= num1;
//             ret++;
//         }
//         return ret;
//     }
// };

// int main()
// {
//     int num1 = 2,num2 = 3;
//     cout<<Solution().countOperations(num1,num2);
//     return 0;
// }


// #include<iostream>
// #include<unordered_map>
// #include<vector>
// #include<algorithm>
// #include<utility>
// using namespace std;

// class Solution
// {
// public:
// 	static bool Comp(const pair<int, int> x, const pair<int, int> y)
// 	{
// 		return x.second < y.second;
// 	}

// 	int minimumOperations(vector<int> &nums)
// 	{
//         if(nums.size() < 2)
//             return 0;
// 		unordered_map<int, int> even, old;
// 		for (int i = 0; i < nums.size(); i++)
// 		{
// 			if (i % 2 == 0)
// 				even[nums[i]]++;
// 			else
// 				old[nums[i]]++;
// 		}
// 		auto max1 = max_element(even.begin(), even.end(), Comp);
// 		auto max2 = max_element(old.begin(), old.end(), Comp);
// 		int ret = 0;
// 		if (max1->first == max2->first)
// 		{
// 			int tmp1 = max1->second;
// 			max1->second = 0;
// 			int tmp2 = max2->second;
// 			max2->second = 0;

// 			//???????????????????????????????????????
// 			int nextLargest1 = max_element(even.begin(), even.end(), Comp)->second;
// 			int nextLargest2 = max_element(old.begin(), old.end(), Comp)->second;
// 			ret = nums.size() - max(tmp1 + nextLargest2, tmp2 + nextLargest1);
// 		}
// 		else
// 			ret = nums.size() - max1->second - max2->second;
// 		return ret;
// 	}
// };

// int main()
// {
// 	vector<int>nums{ 3,1,3,2,4,3 };
// 	cout << Solution().minimumOperations(nums);
// 	return 0;
// }

// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;

// class Solution
// {
// public:
//     long long minimumRemoval(vector<int> &beans)
//     {
//         long long ret = 0;
//         sort(beans.begin(), beans.end());
//         long long sum = 0;
//         for (auto e : beans)
//             sum += e;
//         ret = sum;
//         for (int i = 0; i < beans.size(); i++)
//         {
//             ret = min(ret, (long long)(sum - beans[i] * (beans.size() - i)));
//         }
//         return ret;
//     }
// };

// int main()
// {
//     vector<int>beans{4,1,6,5};
//     cout<<Solution().minimumRemoval(beans);
//     return 0;
// }

// #include<iostream>
// #include<vector>
// #include<unordered_map>
// #include<algorithm>
// using namespace std;

// class Solution
// {
// public:
//     vector<vector<string>> groupAnagrams(vector<string> &strs)
//     {
//         unordered_map<string, vector<string>> nums;
//         for (auto e : strs)
//         {
//             string tmp = e;
//             sort(tmp.begin(), tmp.end());
//             nums[tmp].push_back(e);
//         }

//         vector<vector<string>> ret;
//         for (auto e : nums)
//         {
//             vector<string> tmp;
//             for (int i = 0; i < e.second.size(); i++)
//             {
//                 tmp.push_back(e.second[i]);
//             }
//             ret.push_back(tmp);
//         }
//         return ret;
//     }
// };

// int main()
// {
//     return 0;
// }


// #include<iostream>
// #include<stack>
// #include<vector>
// #include<string>
// using namespace std;

// class Solution
// {
// public:
//     bool Digit(const string &s)
//     {
//         if (s.size() == 1 && !isdigit(s[0]))
//             return false;
//         return true;
//     }

//     int evalRPN(vector<string> &tokens)
//     {
//         if (tokens.size() < 3)
//             return atoi(tokens[tokens.size() - 1].c_str());
//         stack<int> s;
//         for (auto e : tokens)
//         {
//             if (Digit(e))
//             {
//                 s.push(atoi(e.c_str()));
//             }
//             else
//             {
//                 int num1 = s.top();
//                 s.pop();
//                 int num2 = s.top();
//                 s.pop();
//                 int sum = 0;
//                 if (e == "+")
//                     sum = num1 + num2;
//                 else if (e == "-")
//                     sum = num2 - num1;
//                 else if (e == "*")
//                     sum = num2 * num1;
//                 else
//                     sum = num2 / num1;
//                 s.push(sum);
//             }
//         }
//         return s.top();
//     }
// };

// int main()
// {
// 	vector<string>tokens{ "10","6","9","3","+","-11","*","/","*","17","+","5","+" };
// 	cout << Solution().evalRPN(tokens);
// 	return 0;
// }


#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        stack<int> s;
        if (asteroids.size() == 0)
            return {};
        s.push(asteroids[0]);
        for (int i = 1; i < asteroids.size(); i++)
        {
            if (s.empty() ||s.top() >= 0 && asteroids[i] >= 0 || s.top() < 0 && asteroids[i] < 0)
            {
                //????????????
                s.push(asteroids[i]);
            }
            else
            {
                int flag =1;
                while (!s.empty())
                {
                    if (s.top() == asteroids[i] || s.top() < 0 && asteroids[i] >= 0
                    ||s.top() >= 0 && asteroids[i] >= 0 || s.top() < 0 && asteroids[i] < 0)
                    {
                        s.push(asteroids[i]);
                        flag = 0;
                        break;
                    }
                    if (abs(s.top()) >= abs(asteroids[i]))
                    {
                        if (s.top() + asteroids[i] == 0)
                            s.pop();
                        flag = 0;
                        break;
                    }
                    s.pop();
                }
                if(s.empty()&&flag)
                    s.push(asteroids[i]);
            }
        }
        vector<int> ret;
        while (!s.empty())
        {
            ret.push_back(s.top());
            s.pop();
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};

int main()
{
    vector<int> nums{1,-2,-2,-2};
    Solution().asteroidCollision(nums);
    return 0;
}