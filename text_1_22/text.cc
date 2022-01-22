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
// struct TreeNode
// {
//     int val;
//     struct TreeNode* left;
//     struct TreeNode* right
// };

// void postorderTraversal(struct TreeNode *root)
// {
//     if(root==NULL)
//     return ;
//     postorderTraversal(root->left);
//     postorderTraversal(root->right);
//     printf("%d ",root->val);
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
//     for (size_t i = left; i <= right; i++)
//     {
//         nums[i] = tmp[i];
//     }
// }

// void mergeSort(int *nums, int size)
// {
//     int *tmp = malloc(sizeof(int)*size);
//     _mergeSort(nums, 0, size - 1, tmp);
//     free(tmp);
// }

// int main()
// {
//     int nums[] = {58, 34, 65, 78, 49, 23, 90, 62, 97, 76};
//     int size = sizeof(nums) / sizeof(nums[0]);
//     mergeSort(nums, size);
//     for (int i = 0; i < size; i++)
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

//148. 排序链表
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr)
            return head;
        vector<int> nums;
        ListNode *cur = head;
        while (cur)
        {
            nums.push_back(cur->val);
            cur = cur->next;
        }
        sort(nums.begin(), nums.end());
        cur = head;
        int i = 0;
        while (cur)
        {
            cur->val = nums[i++];
            cur = cur->next;
        }
        return head;
    }
};