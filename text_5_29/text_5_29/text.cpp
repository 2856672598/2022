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

//#include <iostream>
//#include <vector>
//using namespace std;
//
//struct TreeNode {
//	int val;
//	TreeNode *left;
//	TreeNode *right;
//	TreeNode() : val(0), left(nullptr), right(nullptr) {}
//	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//};
// 
//class Solution {
//public:
//	TreeNode* deleteNode(TreeNode* root, int key)
//	{
//		TreeNode* cur = root;
//		TreeNode* parent = nullptr;
//		while (cur)
//		{
//			if (cur->val > key) {
//				parent = cur;
//				cur = cur->left;
//			}
//			else if (cur->val < key) {
//				parent = cur;
//				cur = cur->right;
//			}
//			else {
//				if (cur->left == nullptr || cur->right == nullptr)
//				{
//					if (cur == root) {
//						if (cur->left == nullptr)
//							root = cur->right;
//						else
//							root = cur->left;
//					}
//					else if (cur->left == nullptr) {
//						if (cur == parent->left)
//							parent->left = cur->right;
//						else
//							parent->right = cur->right;
//					}
//					else
//					{
//						if (cur == parent->left)
//							parent->left = cur->left;
//						else
//							parent->right = cur->left;
//					}
//					delete cur;
//					break;
//				}
//				else {
//					//????????????????????????????
//					//???????? ??????????????
//					TreeNode* del = cur->left;
//					parent = cur;
//					while (del->right) {
//						parent = del;
//						del = del->right;
//					}
//					cur->val = del->val;
//					if (parent->left == del)
//						parent->left = del->left;
//					else
//						parent->right = del->left;
//					delete del;
//					break;
//				}
//			}
//		}
//		return root;
//	}
//};

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//void Sort1(vector<int>&nums)
//{
//	for (int i = 0; i < (int)nums.size() - 1; i++)
//	{
//		for (int j = 1; j <= (int)nums.size() - 1 - i; j++)
//		{
//			if (nums[j] < nums[j - 1])
//				swap(nums[j], nums[j - 1]);
//		}
//	}
//}
//
//void Sort2(vector<int>&nums)
//{
//	for (int i = 0; i < (int)nums.size() - 1; i++)
//	{
//		int mini = i;
//		for (int j = i; j < (int)nums.size(); j++)
//		{
//			if (nums[j] < nums[mini])
//				mini = j;
//		}
//		swap(nums[i], nums[mini]);
//	}
//}
//
//void Sort3(vector<int>&nums)
//{
//	for (int i = 1; i < (int)nums.size(); i++)
//	{
//		int end = i - 1;
//		int tmp = nums[i];
//		while (end >= 0) {
//			if (nums[end] > tmp)
//				nums[end + 1] = nums[end];
//			else
//				break;
//			end--;
//		}
//		nums[end + 1] = tmp;
//	}
//}
//
//void Sort4(vector<int>&nums)
//{
//	int gap = nums.size();
//	while (gap > 1)
//	{
//		gap /= 2;
//		for (int i = 0; i < (int)nums.size() - gap; i++)
//		{
//			//????????
//			int tmp = nums[i + gap];
//			int end = i;
//			while (end >= 0)
//			{
//				if (nums[end] > tmp)
//					nums[end + gap] = nums[end];
//				else
//					break;
//				end -= gap;
//			}
//			nums[end + gap] = tmp;
//		}
//	}
//}
//
//int _QuicSort(vector<int>&nums, int left, int right)
//{
//	int keyi = left;
//	while (left < right)
//	{
//		//????????
//		while (left < right)
//		{
//			if (nums[right] < nums[keyi])
//				break;
//			right--;
//		}
//		//????????
//		while (left < right)
//		{
//			if (nums[left] > nums[keyi])
//				break;
//			left++;
//		}
//		if (left < right)
//			swap(nums[left], nums[right]);
//	}
//	//??keyi????????????????????
//	swap(nums[left], nums[keyi]);
//	return left;
//}
//
//void QuicSort(vector<int>&nums, int left, int right)
//{
//	if (left >= right)
//		return;
//	int pos = _QuicSort(nums, left, right);
//	QuicSort(nums, left, pos - 1);
//	QuicSort(nums, pos + 1, right);
//}
//
//void _MergeSort(vector<int>&nums, int left, int right, vector<int>&tmp)
//{
//	if (left >= right)
//		return;
//
//	int mid = left + (right - left) / 2;
//	_MergeSort(nums, left, mid,tmp);
//	_MergeSort(nums, mid + 1, right, tmp);
//	int beginl = left, begin2 = mid + 1;
//	int i = left;
//	while (beginl <= mid && begin2 <= right)
//	{
//		if (nums[beginl] < nums[begin2])
//			tmp[i++] = nums[beginl++];
//		else
//			tmp[i++] = nums[begin2++];
//	}
//	while (beginl <= mid)
//		tmp[i++] = nums[beginl++];
//	while (begin2 <= right)
//		tmp[i++] = nums[begin2++];
//	while (left <= right)
//	{
//		nums[left] = tmp[left];
//		left++;
//	}
//}
//
//void MergeSort(vector<int>&nums)
//{
//	vector<int>tmp(nums.size());
//	_MergeSort(nums, 0, nums.size() - 1, tmp);
//}
//
//int main()
//{
//	vector<int>nums{ 5,3,8,1,90,2 };
//	//Sort1(nums);
//	//Sort2(nums);
//	//Sort3(nums);
//	//Sort4(nums);
//	//QuicSort(nums, 0, nums.size() - 1);
//	MergeSort(nums);
//	for (auto e : nums)
//		cout << e << " ";
//	return 0;
//}


//#include <iostream>
//#include <vector>
//using namespace std;
//
//
//class Solution {
//public:
//	int Find(vector<int>& nums, int target, bool flag)
//	{
//		int left = 0, right = nums.size() - 1;
//		int ret = nums.size();
//		while (left <= right)
//		{
//			int mid = left + (right - left) / 2;
//			if (nums[mid] > target || (flag&&nums[mid] >= target)) {
//				right = mid - 1;
//				ret = mid;
//			}
//			else
//				left = mid + 1;
//		}
//		return ret;
//	}
//
//	vector<int> searchRange(vector<int>& nums, int target)
//	{
//		int left = Find(nums, target, true);
//		int right = Find(nums, target, false) - 1;
//		if (left <= right && right < nums.size() && nums[left] == target && nums[right] == target)
//			return { left,right };
//		return { -1,-1 };
//	}
//};
//
//
//int main()
//{
//	vector<int>nums{ 2,2 };
//	int target = 2;
//	Solution().searchRange(nums, target);
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int maxValue(int** matrix, int matrixRowLen, int* matrixColLen)
//{
//	vector<vector<int>>nums(matrixRowLen, vector<int>(*matrixColLen, 0));
//	nums[0][0] = matrix[0][0];
//	for (int i = 1; i < matrixRowLen; i++)
//		nums[i][0] = nums[i - 1][0] + matrix[i][0];
//	for (int i = 1; i < *matrixColLen; i++)
//		nums[0][i] = nums[0][i - 1] + matrix[0][i];
//	for (int i = 1; i < matrixRowLen; i++)
//	{
//		for (int j = 1; j < *matrixColLen; j++)
//		{
//			nums[i][j] = max(nums[i - 1][j], nums[i][j - 1]) + matrix[i][j];
//		}
//	}
//	return nums[matrixRowLen - 1][(*matrixColLen) - 1];
//}

//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//string AddStrings(string num1, string num2)
//{
//
//	string ret;
//	int begin1 = 0, begin2 = 0;
//	int tmp1, tmp2, flag = 0;
//	while (begin1 < num1.size() || begin2 < num2.size())
//	{
//		tmp1 = begin1 >= num1.size() ? '0' : num1[begin1++];
//		tmp2 = begin2 >= num2.size() ? '0' : num2[begin2++];
//
//		int sum = tmp1 - '0' + tmp2 - '0' + flag;
//		if (sum > 9)
//		{
//			flag = sum / 10;
//			sum %= 10;
//		}
//		else
//			flag = 0;
//		ret += sum + '0';
//	}
//	if (flag > 0)
//		ret += 1 + '0';
//	return ret;
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	string ret = "1";
//	for (int i = 2; i <= n; i++)
//	{
//		string tmp;
//		int flag = 0;
//		string str = to_string(i);
//		reverse(str.begin(), str.end());
//		for (int j = 0; j < (int)str.size(); j++)
//		{
//			string tmp1(j, '0');
//			for (int z = 0; z < (int)ret.size(); z++)
//			{
//				int sum = (str[j] - '0')*(ret[z] - '0') + flag;
//				if (sum > 9) {
//					flag = sum / 10;
//					sum %= 10;
//				}
//				else
//					flag = 0;
//				tmp1 += sum + '0';
//			}
//			if (flag != 0)
//				tmp1 += flag + '0';
//			flag = 0;
//			tmp = AddStrings(tmp, tmp1);
//		}
//		ret = tmp;
//	}
//	reverse(ret.begin(), ret.end());
//	cout << ret << endl;
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <string>
//#include <unordered_set>
//using namespace std;
//class Solution {
//public:
//	int numUniqueEmails(vector<string>& emails)
//	{
//		unordered_set<string>s;
//		for (int i = 0; i < (int)emails.size(); i++)
//		{
//			string tmp = emails[i].substr(0, emails[i].find("@"));
//			string tail = emails[i].substr(emails[i].find("@"));
//			string str;
//			for (int i = 0; i < (int)tmp.size(); i++)
//			{
//				if (tmp[i] == '+') {
//					break;
//				}
//				if (tmp[i] != '.')
//					str += tmp[i];
//			}
//			str += tail;
//			s.insert(str);
//		}
//		return s.size();
//	}
//};
//
//int main()
//{
//	vector<string>emails{ "test.email+alex@leetcode.com", "test.email@leetcode.com" };
//	cout << Solution().numUniqueEmails(emails);
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
//	TreeNode() : val(0), left(nullptr), right(nullptr) {}
//	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//};
// 
//class Solution {
//public:
//
//	void Inorder(vector<int>&nums, TreeNode* root)
//	{
//		if (root == nullptr)
//			return;
//		Inorder(nums, root->left);
//		nums.push_back(root->val);
//		Inorder(nums, root->right);
//	}
//
//	bool findTarget(TreeNode* root, int k)
//	{
//		vector<int>nums;
//		Inorder(nums, root);
//		for (int i = 0; i < (int)nums.size(); i++)
//		{
//			int left = 0, right = nums.size() - 1;
//			int mid = 0, target = k - nums[i];
//			if (target == nums[i])
//				continue;
//			while (left <= right)
//			{
//				int mid = left + (right - left) / 2;
//				if (nums[mid] > target)
//					right = mid - 1;
//				else if (nums[mid] < target)
//					left = mid + 1;
//				else
//					return true;
//			}
//		}
//		return false;
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
 
class BSTIterator {
private:
	vector<int>nums;
	int index;
public:
	void Inorder(TreeNode* root, vector<int>&nums)
	{
		if (root == nullptr)
			return;
		Inorder(root->left, nums);
		nums.push_back(root->val);
		Inorder(root->right, nums);
	}
	BSTIterator(TreeNode* root) {
		Inorder(root, nums);
		index = 0;
	}

	int next() {
		return nums[index++];
	}

	bool hasNext() {
		return index < nums.size();
	}
};