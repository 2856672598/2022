//#include <iostream>
//using namespace std;
//
//class Solution {
//public:
//	int Add(int num1, int num2)
//	{
//		while (num2)
//		{
//			int tmp = num1 & num2;
//			num1 ^= num2;
//			num2 = tmp << 1;
//		}
//		return num1;
//	}
//};
//
//int main()
//{
//	cout << Solution().Add(4, 7);
//	return 0;
//}

//#include <iostream>
//#include <math.h>
//using namespace std;
//
//int main()
//{
//	int n;
//	while (true)
//	{
//		cin >> n;
//		if (n == 0)
//			break;
//		long long sum = pow(5, n) - 4;
//		long long end = (sum + 4) * pow(0.8, n) + n - 4;
//		cout << sum << " " << end << endl;
//	}
//}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//class Solution {
//public:
//	vector<int> sortArrayByParity(vector<int>& nums)
//	{
//		int left = 0, right = nums.size() - 1;
//		while (left < right)
//		{
//			//×ó±ßÕÒÆæÊý
//			while (left < right)
//			{
//				if (nums[left] % 2)
//					break;
//				left++;
//			}
//			//ÓÒÃæÕÒÅ¼Êý
//			while (left < right)
//			{
//				if (nums[right] % 2 == 0)
//					break;
//				right--;
//			}
//			if (left < right)
//				swap(nums[left], nums[right]);
//		}
//		return nums;
//	}
//};


//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <queue>
//using namespace std;
//
//struct TreeNode {
//	int val;
//	TreeNode *left;
//	TreeNode *right;
//	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
//
////class Solution {
////public:
////	TreeNode* mirrorTree(TreeNode* root)
////	{
////		if (root == nullptr)
////			return nullptr;
////		mirrorTree(root->left);
////		mirrorTree(root->right);
////		swap(root->left, root->right);
////		return root;
////	}
////};
//
////class Solution {
////public:
////
////	bool _isSymmetric(TreeNode* root1, TreeNode* root2)
////	{
////		if (root1 == nullptr || root2 == nullptr)
////			return root1 == root2;
////
////		if (root1->val != root2->val)
////			return false;
////
////		return _isSymmetric(root1->left, root2->right) && _isSymmetric(root1->right, root2->left);
////	}
////
////	bool isSymmetric(TreeNode* root)
////	{
////		if (root == nullptr)
////			return true;
////		return _isSymmetric(root->left, root->right);
////	}
////};
//
//class Solution {
//public:
//	vector<vector<int>> levelOrder(TreeNode* root)
//	{
//		if (root == nullptr)
//			return {};
//		queue<TreeNode*>q;
//		q.push(root);
//		vector<vector<int>>ret;
//		while (!q.empty())
//		{
//			int sz = q.size();
//			vector<int>nums;
//			TreeNode* tmp = nullptr;
//			for (int i = 0; i < sz; i++)
//			{
//				tmp = q.front();
//				q.pop();
//				nums.push_back(tmp->val);
//				if (tmp->left)
//					q.push(tmp->left);
//				if (tmp->right)
//					q.push(tmp->right);
//			}
//			ret.push_back(nums);
//		}
//		return ret;
//	}
//};

#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:

	TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, int& rooti, int left, int right)
	{
		if (left > right || rooti >= inorder.size())
			return nullptr;
		if (left == right)
			return new TreeNode(inorder[left]);

		TreeNode* root = new TreeNode(preorder[rooti]);
		int pos = 0;
		for (int i = 0; i < inorder.size(); i++)
		{
			if (inorder[i] == preorder[rooti]) {
				pos = i;
				break;
			}
		}

		if (left <= pos - 1)
			root->left = _buildTree(preorder, inorder, ++rooti, left, pos - 1);
		if (pos + 1 <= right)
			root->right = _buildTree(preorder, inorder, ++rooti, pos + 1, right);
		return root;
	}

	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
	{
		int pos = 0;
		return _buildTree(preorder, inorder, pos, 0, preorder.size() - 1);
	}
};