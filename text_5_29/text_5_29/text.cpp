//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//class Solution {
//public:
//	int rearrangeCharacters(string s, string target)
//	{
//		vector<int>nums1(26, 0), nums2(26, 0);
//		for (auto e : s)
//			nums1[e - 'a']++;
//		for (auto e : target)
//			nums2[e - 'a']++;
//		int ret = INT_MAX;
//		for (auto e : target)
//			ret = min(ret, nums1[e - 'a'] / nums2[e - 'a']);
//		return ret;
//	}
//};
//
//int main()
//{
//	string s = "abbaccaddaeea";
//	string target = "aaaaa";
//	cout << Solution().rearrangeCharacters(s, target);
//	return 0;
//}

//#include <iostream>
//#include <string>
//#include <sstream>
//using namespace std;
//
//class Solution {
//public:
//	string discountPrices(string sentence, int discount)
//	{
//		stringstream ss(sentence);
//		string ret, tmp;
//		int i = 0;
//		while (ss >> tmp)
//		{
//			if (tmp[0] == '$') {
//				for (int i = 1; i < (int)tmp.size(); i++) {
//					if (!isdigit(tmp[i]))
//						break;
//					if (i == tmp.size() - 1) {
//						double num = atof(tmp.substr(1).c_str());
//						num = num * ((100 - discount)*0.01);
//						tmp = "$";
//						//string flag;
//						//flag = to_string(num);
//						//tmp += flag.substr(0, flag.find('.') + 3);
//						char arr[100];
//						sprintf(arr, "$%.2lf", num);
//						tmp = arr;
//						break;
//					}
//				}
//			}
//			if (i != 0)
//				ret += " ";
//			ret += tmp;
//			i++;
//		}
//		return ret;
//	}
//};
//int main()
//{
//	string sentence = "$2$3 $10 $100 $1 200 $33 33$ $$ $99 $99999 $9999999999";
//	int discount = 0;
//	cout << Solution().discountPrices(sentence, discount);
//	return 0;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//struct TreeNode {
//	int val;
//	TreeNode *left;
//	TreeNode *right;
//	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
// 
//class Solution {
//public:
//	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
//	{
//		if (root == nullptr)
//			return nullptr;
//		if (root == p || root == q)
//			return root == p ? p : q;
//
//		if ((_lowestCommonAncestor(root->left, p) && _lowestCommonAncestor(root->right, q))
//			|| (_lowestCommonAncestor(root->left, q) && _lowestCommonAncestor(root->right, p))
//			)
//			return root;
//		TreeNode* ret = lowestCommonAncestor(root->left, p, q);
//		if (ret != nullptr)
//			return ret;
//		return lowestCommonAncestor(root->right, p, q);
//	}
//
//	bool _lowestCommonAncestor(TreeNode* root, TreeNode* node)
//	{
//		if (root == nullptr)
//			return false;
//		if (root == node)
//			return true;
//		return _lowestCommonAncestor(root->left, node) || _lowestCommonAncestor(root->right, node);
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
	TreeNode* deleteNode(TreeNode* root, int key)
	{
		TreeNode* cur = root;
		TreeNode* parent = nullptr;
		while (cur)
		{
			if (cur->val > key) {
				parent = cur;
				cur = cur->left;
			}
			else if (cur->val < key) {
				parent = cur;
				cur = cur->right;
			}
			else {
				if (cur->left == nullptr || cur->right == nullptr)
				{
					if (cur == root) {
						if (cur->left == nullptr)
							root = cur->right;
						else
							root = cur->left;
					}
					else if (cur->left == nullptr) {
						if (cur == parent->left)
							parent->left = cur->right;
						else
							parent->right = cur->right;
					}
					else
					{
						if (cur == parent->left)
							parent->left = cur->left;
						else
							parent->right = cur->left;
					}
					delete cur;
					break;
				}
				else {
					//左右子树都不为空进行替换删除
					//与左子树 的最右节点替换
					TreeNode* del = cur->left;
					parent = cur;
					while (del->right) {
						parent = del;
						del = del->right;
					}
					cur->val = del->val;
					if (parent->left == del)
						parent->left = del->left;
					else
						parent->right = del->left;
					delete del;
					break;
				}
			}
		}
		return root;
	}
};