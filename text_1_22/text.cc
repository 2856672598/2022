// #include<stdio.h>
// #include<stdbool.h>
// #include<stdlib.h>
// struct Stack
// {
//     int * val;
//     int top;
//     int capacity;
// };

// void Init(struct Stack *s)
// {
//     s->capacity = 10;
//     s->top = 0;
//     s->val = malloc(sizeof(int) * s->capacity);
// }

// bool IsFull(struct Stack *s)
// {
//     return s->top >= s->capacity;
// }

// void Push(struct Stack* s,int val)
// {
//     if(IsFull(s))
//     {
//         printf("Stack Full\n");
//         return ;
//     }
//     s->val[s->top]=val;
//     s->top++;
// }
// bool Empty(struct Stack* s)
// {
//     return s->top==0;
// }
// void Destroy(struct Stack* s)
// {
//     free(s->val);
// }

// void Pop(struct Stack* s)
// {
//     if(Empty(s))
//     {
//         printf("栈为空\n");
//         return;
//     }
//     printf("出栈元素：%d\n",s->val[s->top-1]);
//     s->top--;
// }

// int main()
// {
//     struct Stack s;
//     Init(&s);
//     Push(&s,1);
//     Push(&s,2);
//     Push(&s,3);
//     Pop(&s);
//     Pop(&s);
//     Pop(&s);
//     Destroy(&s);
//     return 0;
// }


// #include<stdio.h>
// #include<stdlib.h>
// struct TreeNode
// {
//     int val;
//     struct TreeNode* left;
//     struct TreeNode* right;
// };

// void postorderTraversal(struct TreeNode *root)
// {
//     if(root==NULL)
//     return ;
//     postorderTraversal(root->left);
//     postorderTraversal(root->right);
//     printf("%d ",root->val);
// }

// int main()
// {
//     TreeNode *p1 = (TreeNode *)malloc(sizeof(TreeNode));
//     TreeNode *p2 = (TreeNode *)malloc(sizeof(TreeNode));
//     TreeNode *p3 = (TreeNode *)malloc(sizeof(TreeNode));
//     TreeNode *p4 = (TreeNode *)malloc(sizeof(TreeNode));
//     TreeNode *p5 = (TreeNode *)malloc(sizeof(TreeNode));
//     TreeNode *p6 = (TreeNode *)malloc(sizeof(TreeNode));
//     TreeNode *p7 = (TreeNode *)malloc(sizeof(TreeNode));
//     p1->val = 1;
//     p2->val = 2;
//     p3->val = 3;
//     p4->val = 4;
//     p5->val = 5;
//     p6->val = 6;
//     p7->val = 7;
//     p1->left = p2;
//     p1->right = p3;
//     p2->left = p4;
//     p2->right = p5;
//     p3->left = p6;
//     p3->right = p7;
//     p4->left = p4->right = NULL;
//     p5->left = p5->right = NULL;
//     p6->left = p6->right = NULL;
//     p7->left = p7->right = NULL;
//     postorderTraversal(p1);
//     return 0;
// }

// #include<stdio.h>
// #include<stdlib.h>
// void _mergeSort(int*nums,int left,int right,int* tmp)
// {
//     if(left>=right)
//         return ;
//     int mid = left + (right - left) / 2;
//     _mergeSort(nums, left, mid, tmp);
//     _mergeSort(nums, mid + 1, right, tmp);

//     //左右区间已经有序开始归并
//     int begin1=left,begin2=mid+1;
//     int insert =left;
//     while (begin1<=mid&&begin2<=right)
//     {
//         if(nums[begin1]<nums[begin2])
//             tmp[insert++]=nums[begin1++];
//         else
//             tmp[insert++]=nums[begin2++];
//     }

//     while(begin2<=right)
//     {
//         tmp[insert++]=nums[begin2++];
//     }

//     while (begin1 <= mid)
//     {
//         tmp[insert++] = nums[begin1++];
//     }
//     //拷会原数组
//     size_t i;
//     for (i = left; i <= right; i++)
//     {
//         nums[i] = tmp[i];
//     }
// }

// void mergeSort(int *nums, int size)
// {
//     int *tmp = (int*)malloc(sizeof(int)*size);
//     _mergeSort(nums, 0, size - 1, tmp);
//     free(tmp);
// }

// int main()
// {
//     int nums[] = {58, 34, 65, 78, 49, 23, 90, 62, 97, 76};
//     int size = sizeof(nums) / sizeof(nums[0]);
//     mergeSort(nums, size);
//     int i=0;
//     for (i = 0; i < size; i++)
//     {
//         printf("%d ", nums[i]);
//     }
//     return 0;
// }

// #include<iostream>
// #include<algorithm>
// #include<vector>
// using namespace std;
// // class Solution {
// // public:
// //     vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
// //         sort(input.begin(),input.end());
// //         input.resize(k);
// //         return input;
// //     }
// // };

// // 1332. 删除回文子序列
// class Solution
// {
// public:
//     int removePalindromeSub(string s)
//     {
//         int left = 0, right = s.size() - 1;
//         while (left < right)
//         {
//             if (s[left] != s[right])
//                 return 2;
//             left++;
//             right--;
//         }
//         return 1;
//     }
// };

// //238. 除自身以外数组的乘积
// #include<iostream>
// #include<vector>
// using namespace std;

// class Solution
// {
// public:
//     vector<int> productExceptSelf(vector<int> &nums)
//     {
//         vector<int> prefix(nums.size(), 1), suffix(nums.size(), 1);
//         int size = nums.size();
//         prefix[0] = nums[0], suffix[size - 1] = nums[size - 1];
//         for (int i = 1; i < size; i++)
//         {
//             prefix[i] = prefix[i - 1] * nums[i];
//         }
//         for (int i = size - 2; i >= 0; i--)
//         {
//             suffix[i] = suffix[i + 1] * nums[i];
//         }
//         vector<int> ret(size, 0);
//         ret[0] = suffix[1], ret[size - 1] = prefix[size - 2];
//         for (int i = 1; i < size - 1; i++)
//         {
//             ret[i] = suffix[i + 1] * prefix[i - 1];
//         }
//         return ret;
//     }
// };

// int main()
// {
//     vector<int>nums{1,2,3,4};
//     Solution().productExceptSelf(nums);
//     return 0;
// }

// //230. 二叉搜索树中第K小的元素
// #include<iostream>
// #include<vector>
// using namespace std;
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
// class Solution {
// public:
//     void InOrder(TreeNode* root,vector<int>& nums)
//     {
//         if(root ==nullptr)
//             return;
//         InOrder(root->left,nums);
//         nums.push_back(root->val);
//         InOrder(root->right,nums);
//     }
//     int kthSmallest(TreeNode* root, int k) {
//         vector<int>nums;
//         //中序遍历
//         InOrder(root,nums);
//         return nums[k-1];
//     }
// };

// //148. 排序链表
// #include<iostream>
// #include<vector>
// #include<algorithm>
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
//     ListNode *sortList(ListNode *head)
//     {
//         if (head == nullptr)
//             return head;
//         vector<int> nums;
//         ListNode *cur = head;
//         while (cur)
//         {
//             nums.push_back(cur->val);
//             cur = cur->next;
//         }
//         sort(nums.begin(), nums.end());
//         cur = head;
//         int i = 0;
//         while (cur)
//         {
//             cur->val = nums[i++];
//             cur = cur->next;
//         }
//         return head;
//     }
// };

// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;

// class Solution
// {
// public:
//     int countElements(vector<int> &nums)
//     {
//         sort(nums.begin(), nums.end());
//         int ret = 0;
//         for (int i = 1; i < nums.size() - 1; i++)
//         {
//             if (nums[i] > nums[0] && nums[i] < nums[nums.size() - 1])
//                 ret++;
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
//     vector<int> rearrangeArray(vector<int> &nums)
//     {
//         vector<int> nums1, nums2;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             if (nums[i] >= 0)
//                 nums1.push_back(nums[i]);
//             else
//                 nums2.push_back(nums[i]);
//         }
//         vector<int> ret;
//         int begin1 = 0, begin2 = 0;
//         while (begin1 < nums1.size() && begin2 < nums2.size())
//         {
//             ret.push_back(nums1[begin1++]);
//             ret.push_back(nums2[begin2++]);
//         }
//         return ret;
//     }
// };

// int main()
// {
//     vector<int> nums{3, 1, -2, -5, 2, -4};
//     vector<int> ret = Solution().rearrangeArray(nums);
//     for (auto e : ret)
//         cout << e << " ";
//     return 0;
// }

// #include<iostream>
// #include<vector>
// #include<unordered_map>
// using namespace std;

// class Solution
// {
// public:
//     vector<int> findLonely(vector<int> &nums)
//     {
//         unordered_map<int, int> m;
//         for (auto e : nums)
//         {
//             m[e]++;
//         }
//         vector<int> ret;
//         for (auto e : m)
//         {
//             if (e.second == 1)
//             {
//                 auto it = m.find(e.first + 1);
//                 if (it == m.find(e.first - 1) && it == m.end())
//                     ret.push_back(e.first);
//             }
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
// #include<algorithm>
// using namespace std;

// class Solution
// {
// public:
//     int minimumCost(vector<int> &cost)
//     {
//         sort(cost.begin(), cost.end());
//         int ret = 0;
//         int right = cost.size() - 1, left = right - 1;
//         while (left >= 0)
//         {
//             ret += cost[left];
//             ret += cost[right];
//             right -= 3;
//             left = right - 1;
//         }
//         if (right == 0)
//             ret += cost[right];
//         return ret;
//     }
// };

// int main()
// {
//     vector<int>nums{1,2,3};
//     cout<<Solution().minimumCost(nums);
//     return 0;
// }

// #include <iostream>
// #include <vector>
// using namespace std;
// int main()
// {
// 	int n, m;
// 	cin >> n >> m;
// 	vector<int> nums;
// 	for (int i = 0; i < n; i++)
// 	{
// 		int tmp;
// 		cin >> tmp;
// 		nums.push_back(tmp);
// 	}
// 	//求出差分数组
// 	vector<int> diff(n);
// 	diff[0] = nums[0];
// 	for (int i = 1; i < nums.size(); i++)
// 	{
// 		diff[i] = nums[i] - nums[i - 1];
// 	}
// 	while (m--)
// 	{
// 		int left, right, c;
// 		cin >> left >> right >> c;
// 		if (left >= 0)
// 			diff[left - 1] += c;
// 		if (right < n)
// 			diff[right] -= c;
// 	}
// 	int sum = 0;
// 	for (int i = 0; i < diff.size(); i++)
// 	{
// 		sum += diff[i];
// 		cout << sum << " ";
// 	}
// 	return 0;
// }

// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;

// class Solution
// {
// public:
// 	int numberOfArrays(vector<int> &differences, int lower, int upper)
// 	{
// 		vector<long long> nums(differences.size() + 1);
// 		nums[0] = differences[0];
// 		for (int i = 0; i < differences.size(); i++)
// 		{
// 			nums[i + 1] = nums[i] + differences[i];
// 		}
// 		long long minnum = INT_MAX, maxnum = INT_MIN;
// 		for (int i = 0; i < nums.size(); i++)
// 		{
// 			minnum = min(nums[i], minnum);
// 			maxnum = max(nums[i], maxnum);
// 		}
// 		int interval1 = upper - lower;
// 		int interval2 = maxnum - minnum;
// 		if (interval2 > interval1)
// 			return 0;
// 		return interval1 - interval2 + 1;
// 	}
// };
// int main()
// {
// 	vector<int>diff{ 3,-4,5,1,-2 };
// 	int lower = -4, upper = 5;
// 	cout << Solution().numberOfArrays(diff, lower, upper);
// 	return 0;
// }


// #include<iostream>
// using namespace std;

// class Solution
// {
// public:
//     int numberOfMatches(int n)
//     {
//         int ret = 0;
//         while (n > 1)
//         {
//             if (n % 2 == 1)
//             {
//                 ret += n / 2;
//                 n++;
//             }
//             else
//                 ret += n / 2;
//             n /= 2;
//         }
//         return ret;
//     }
// };

// int main()
// {
//     int n=7;
//     cout<<Solution().numberOfMatches(n);
//     return 0;
// }

// #include<iostream>
// #include<map>
// using namespace std;

// class StreamRank
// {
// public:
//     map<int, int> m;
//     StreamRank()
//     {
//     }

//     void track(int x)
//     {
//         m[x]++;
//     }

//     int getRankOfNumber(int x)
//     {
//         int ret = 0;
//         for (auto e : m)
//         {
//             if (e.first > x)
//                 break;
//             ret += e.second;
//         }
//         return ret;
//     }
// };

// #include<iostream>
// #include<vector>
// #include<string>
// #include<algorithm>
// using namespace std;

// class Solution {
// public:
//     bool Check(string s1,string s2)
//     {
//         char arr[26];
//         for(int i=0;i<s1.size();i++)
//         {
//             arr[s1[i]-'a']++;
//         }
//         for(int i=0;i<s2.size();i++)
//         {
//             if(arr[s2[i]-'a']!=0)
//                 return false;
//         }
//         return true;
//     }
//     int maxProduct(vector<string>& words) {
//         int ret =0;
//         for(int i=0;i<words.size();i++)
//         {
//             for(int j=i+1;j<words.size();j++)
//             {
//                 if(Check(words[i],words[j]))
//                 {
//                     ret = max(ret,(int)(words[i].size()*words[j].size()));
//                 }
//             }
//         }
//         return ret;
//     }
// };

// int main()
// {
//     vector<string> words{"a","ab","abc","d","cd","bcd","abcd"};
//     cout<<Solution().maxProduct(words)<<endl;
//     return 0;
// }

// #include<iostream>
// #include<vector>
// using namespace std;
// // class Solution {
// // public:
// //     int findFinalValue(vector<int>& nums, int original) {
// //         while(find(nums.begin(),nums.end(),original)!=nums.end())
// //         {
// //             original*=2;
// //         }
// //         return original;
// //     }
// // };

// class Solution {
// public:
//     vector<int> maxScoreIndices(vector<int>& nums) {
//         vector<int>ret;
//         vector<int>leftnums(nums.size()+1,0);
//         vector<int>rightnums(nums.size()+1,0);
//         for (int i = 1; i < leftnums.size(); i++)
//         {

//             leftnums[i] = leftnums[i - 1];
//             if (nums[i-1] == 0)
//                 leftnums[i] += 1;
//         }

//         for (int i = rightnums.size() - 2; i >= 0; i--)
//         {
//             rightnums[i] = rightnums[i + 1];
//             if (nums[i] == 1)
//                 rightnums[i] += 1;
//         }
//         vector<int>sum(rightnums.size());
//         sum[0] =rightnums[0];
//         sum[rightnums.size()-1]=leftnums[rightnums.size()-1];
//         for(int i=1;i<sum.size()-1;i++)
//         {
//             sum[i]=leftnums[i]+rightnums[i];
//         }
//         int max = 0;
//         for (int i = 0; i < sum.size(); i++)
//         {
//             if (sum[i] > max)
//             {
//                 ret.resize(0);
//                 ret.push_back(i);
//                 max = sum[i];
//             }
//             else if (sum[i] == max)
//                 ret.push_back(i);
//         }
//         return ret;
//     }
// };
// int main()
// {
//     vector<int>nums{0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1};
//     Solution().maxScoreIndices(nums);
//     return 0;
// }

// #include<iostream>
// #include<vector>
// using namespace std;

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
// class Solution
// {
// public:
//     vector<TreeNode*>nums;
//     int flag=0;
//     void Inorder(TreeNode *root)
//     {
//         if(root ==nullptr)
//             return ;
//         Inorder(root->left);
//         nums.push_back(root);
//         Inorder(root->right);
//     }
//     TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p)
//     {
//         Inorder(root);
//         auto it =find(nums.begin(),nums.end(),p);
//         it++;
//         if(it == nums.end())
//             return nullptr;
//         return *it;
//     }
// };
// int main()
// {
//     return 0;
// }


#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

class Solution
{
public:
    bool oneEditAway(string first, string second)
    {
        if (abs(int(first.size() - second.size())) > 1)
            return false;
        int flag = 0;
        int begin1 = 0, begin2 = 0;
        if (first.size() == second.size())
        {
            while (begin1 < first.size() && begin2 < second.size())
            {
                if (first[begin1++] != second[begin2++])
                    flag++;
            }
        }
        else
        {
            string lo = first, sh = second;
            if (lo.size() < sh.size())
            {
                lo = second;
                sh = first;
            }
            while (begin1 < lo.size() && begin2 < sh.size())
            {
                if (lo[begin1] != sh[begin2])
                {
                    begin1++;
                    flag++;
                }
                else
                {
                    begin1++;
                    begin2++;
                }
            }
        }
        if (flag > 1)
            return false;
        return true;
    }
};

int main()
{
    return 0;
}