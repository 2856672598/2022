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
//			//左边找奇数
//			while (left < right)
//			{
//				if (nums[left] % 2)
//					break;
//				left++;
//			}
//			//右面找偶数
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

//#include <iostream>
//#include <vector>
//using namespace std;
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
//	TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, int& rooti, int left, int right)
//	{
//		if (left > right || rooti >= inorder.size())
//			return nullptr;
//		if (left == right)
//			return new TreeNode(inorder[left]);
//
//		TreeNode* root = new TreeNode(preorder[rooti]);
//		int pos = 0;
//		for (int i = 0; i < inorder.size(); i++)
//		{
//			if (inorder[i] == preorder[rooti]) {
//				pos = i;
//				break;
//			}
//		}
//
//		if (left <= pos - 1)
//			root->left = _buildTree(preorder, inorder, ++rooti, left, pos - 1);
//		if (pos + 1 <= right)
//			root->right = _buildTree(preorder, inorder, ++rooti, pos + 1, right);
//		return root;
//	}
//
//	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
//	{
//		int pos = 0;
//		return _buildTree(preorder, inorder, pos, 0, preorder.size() - 1);
//	}
//};

//#include <iostream>
//#include <vector>
//#include <unordered_set>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//	int count = 0;
//	int n = 0;
//	while (1)
//	{
//		cin >> n;
//		if (n == 0)
//			break;
//
//		count = 0;
//		while (n > 1)
//		{
//			count++;
//			n = n / 3 + (n % 3 > 0);
//		}
//		cout << count << endl;
//	}
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//	string str;
//	while (getline(cin, str))
//	{
//		for (int i = 0; i < str.size(); i++) {
//			if (isupper(str[i])) {
//				str[i] -= 5;
//				if (str[i] < 'A') {
//					str[i] = 91 + (str[i] - 'A');
//				}
//			}
//		}
//		cout << str << endl;
//	}
//	return 0;
//}

//#include <iostream>
//#include <unordered_set>
//#include <math.h>
//using namespace std;
//
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		unordered_set<int>nums;
//		for (int i = 2; i <= sqrt(n); i++)
//		{
//			while (n%i == 0)
//			{
//				n /= i;
//				nums.insert(i);
//			}
//			if (n == 1)
//				break;
//		}
//		int sz = nums.size();
//		if (n > 1)
//			sz += 1;
//		cout << sz << endl;
//	}
//	return 0;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Solution {
//public:
//	vector<int> findDuplicates(vector<int>& nums)
//	{
//		vector<int>ret;
//		for (int i = 0; i < (int)nums.size(); i++)
//		{
//			if (nums[abs(nums[i]) - 1] > 0) {
//				//说明第一次出现
//				nums[abs(nums[i]) - 1] *= -1;
//			}
//			else {
//				//第二次出现
//				ret.push_back(abs(nums[i]));
//			}
//		}
//		return ret;
//	}
//};
//
//int main()
//{
//	vector<int>nums{ 4,3,2,7,8,2,3,1 };
//	Solution().findDuplicates(nums);
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
//
//	bool Find(TreeNode* root, TreeNode* x)
//	{
//		if (root == nullptr)
//			return false;
//		if (root == x)
//			return true;
//		if (Find(root->left, x) || Find(root->right, x))
//			return true;
//		return false;
//	}
//public:
//	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
//	{
//		if (root == nullptr)
//			return nullptr;
//		if (root == p || root == q) {
//			return root == p ? p : q;
//		}
//		//分别去左右树查找
//		if (Find(root->left, p) && Find(root->right, q)
//			|| Find(root->left, q) && Find(root->right, p)) {
//			return root;
//		}
//		TreeNode* ret = nullptr;
//		if ((ret = lowestCommonAncestor(root->left, p, q)) || (ret = lowestCommonAncestor(root->right, p, q)));
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
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
//class Solution {
//
//	void Inorder(TreeNode* root, vector<int>&nums)
//	{
//		if (root == nullptr)
//			return;
//		Inorder(root->left, nums);
//		nums.push_back(root->val);
//		Inorder(root->right, nums);
//	}
//public:
//	int kthLargest(TreeNode* root, int k)
//	{
//		vector<int>nums;
//		Inorder(root, nums);
//		if (k > nums.size())
//			return 0;
//		return nums[nums.size() - k];
//	}
//};

//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//class Solution {
//public:
//	string largestGoodInteger(string num)
//	{
//		char ch = ' ';
//		for (int i = 0; i <= (int)num.size() - 3; i++) {
//			if (num[i] == num[i + 1] && num[i + 1] == num[i + 2]) {
//				ch = max(ch, num[i]);
//			}
//		}
//		return ch == ' ' ? "" : string(3, ch);
//	}
//};
//
//int main()
//{
//	string num("6777133339");
//	cout << Solution().largestGoodInteger(num);
//	return 0;
//}

//#include <iostream>
//using namespace std;
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
//	pair<int, int> Prevorder(TreeNode* root, int& count)
//	{
//		if (root == nullptr)
//			return { 0,0 };
//		auto retval = Prevorder(root->left, count);
//		int sum = retval.first;
//		int num = retval.second;
//		retval = Prevorder(root->right, count);
//		sum += retval.first;
//		num += retval.second;
//		sum += root->val;
//		num++;
//		if (sum / num == root->val)
//			count++;
//		return { sum,num };
//	}
//	int averageOfSubtree(TreeNode* root)
//	{
//		int count = 0;
//		Prevorder(root, count);
//		return count;
//	}
//};


//#include <iostream>
//#include <vector>
//using namespace std;
//
//bool IsLeapYear(int year)
//{
//	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
//		return true;
//	return false;
//}
//
//int Day(int year, int month)
//{
//	int day = 1;
//	int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//	for (int i = 1; i < month; i++) {
//		if (IsLeapYear(year) && i == 2)
//			day += 1;
//		day += arr[i];
//	}
//	return day;
//}
//
//int Week(int day)
//{
//	return (day + 3) % 7;
//}
//
//int Print(int month, int day, int week, int nums)
//{
//	int ret = 1;
//	while (1)
//	{
//		if (Week(day) == week)
//			nums--;
//		if (nums == 0)
//			break;
//		day++;
//		ret++;
//	}
//	return ret;
//}
//
//int main()
//{
//	//通过一个日期计算出当前是星期几。
//	int year;
//	while (cin >> year)
//	{
//		int day = 0;
//		for (int i = 1970; i < year; i++)
//		{
//			day += 365;
//			if (IsLeapYear(i))
//				day += 1;
//		}
//		int tmp = day;
//		printf("%d-%02d-%02d\n", year, 1, 1);
//		tmp = day + Day(year, 1);
//		printf("%d-%02d-%02d\n", year, 1, Print(1, tmp, 1, 3));
//		tmp = day + Day(year, 2);
//		printf("%d-%02d-%02d\n", year, 2, Print(2, tmp, 1, 3));
//		//最后一个星期一
//		tmp = day + Day(year, 6) - 1;
//		for (int i = 31; i > 0; i--)
//		{
//			if (Week(tmp) == 1) {
//				printf("%d-%02d-%02d\n", year, 5, i);
//				break;
//			}
//			tmp--;
//		}
//		printf("%d-%02d-%02d\n", year, 7, 4);
//		tmp = day + Day(year, 9);
//		printf("%d-%02d-%02d\n", year, 9, Print(9, tmp, 1, 1));
//		tmp = day + Day(year, 11);
//		printf("%d-%02d-%02d\n", year, 11, Print(11, tmp, 4, 4));
//		printf("%d-%02d-%02d\n", year, 12, 25);
//		printf("\n");
//	}
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		vector<int>nums;
//		int tmp = n;
//		for (int i = 2;; i++)
//		{
//			while (tmp%i == 0)
//			{
//				tmp /= i;
//				nums.push_back(i);
//			}
//			if (tmp == 1)
//				break;
//		}
//		string ret = to_string(n);
//		ret += " = ";
//		for (int i = 0; i < (int)nums.size() - 1; i++)
//		{
//			ret += to_string(nums[i]);
//			ret += " * ";
//		}
//		ret += to_string(nums[nums.size() - 1]);
//		cout << ret << endl;
//	}
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <stack>
//using namespace std;
//struct TreeNode {
//	int val;
//	TreeNode *left;
//	TreeNode *right;
//	TreeNode() : val(0), left(nullptr), right(nullptr) {}
//	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//};
// 
////class Solution {
////public:
////	vector<int> postorderTraversal(TreeNode* root)
////	{
////		stack<TreeNode*>s;
////		vector<int>ret;
////		TreeNode* cur = root;
////		TreeNode* prev = nullptr;
////		while (!s.empty() || cur)
////		{
////			while (cur)
////			{
////				s.push(cur);
////				prev = cur;
////				cur = cur->left;
////			}
////			//进入到右子树
////			TreeNode* tmp = s.top()->right;
////			if (tmp == nullptr || tmp == prev) {
////				ret.push_back(s.top()->val);
////				prev = s.top();
////				s.pop();
////			}
////			else {
////				cur = tmp;
////			}
////		}
////		return ret;
////	}
////};
//
////class Solution {
////public:
////	vector<int> inorderTraversal(TreeNode* root)
////	{
////		stack<TreeNode*>s;
////		vector<int>ret;
////		TreeNode* cur = root;
////		while (cur || !s.empty())
////		{
////			//左路走到底
////			while (cur)
////			{
////				s.push(cur);
////				cur = cur->left;
////			}
////			ret.push_back(s.top()->val);
////			//判断右子树是否存在
////			TreeNode* tmp = s.top();
////			s.pop();
////			if (tmp->right != nullptr)
////				cur = tmp->right;
////		}
////		return ret;
////	}
////};
//
//
////class Solution {
////public:
////	vector<int> preorderTraversal(TreeNode* root)
////	{
////		stack<TreeNode*>s;
////		vector<int>ret;
////		TreeNode* cur = root;
////		while (cur || !s.empty())
////		{
////			while (cur)
////			{
////				ret.push_back(cur->val);
////				s.push(cur);
////				cur = cur->left;
////			}
////			TreeNode*tmp = s.top();
////			s.pop();
////			if (tmp->right)
////				cur = tmp->right;
////		}
////		return ret;
////	}
////};
//
////class Solution {
////public:
////	TreeNode*_buildTree(vector<int>& inorder, vector<int>& postorder, int& index, int left, int right)
////	{
////		if (index < 0)
////			return nullptr;
////		TreeNode* node = new TreeNode(postorder[index]);
////		int pos = 0;
////		for (int i = left; i <= right; i++) {
////			if (inorder[i] == postorder[index]) {
////				pos = i;
////				break;
////			}
////		}
////		if (pos < right) {
////			index -= 1;
////			node->right = _buildTree(inorder, postorder, index, pos + 1, right);
////		}
////
////		if (left < pos) {
////			//有左区间
////			index -= 1;
////			node->left = _buildTree(inorder, postorder, index, left, pos - 1);
////		}
////		return node;
////	}
////	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
////	{
////		int index = postorder.size() - 1;
////		int left = 0, right = index;
////		return _buildTree(inorder, postorder, index, left, right);
////	}
////};
//
//class Solution {
//public:
//	TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, int& index, int left, int right)
//	{
//		if (index == preorder.size())
//			return nullptr;
//		TreeNode* node = new TreeNode(preorder[index]);
//		//判断下当前节点是否有左子树
//		int pos = 0;
//		for (int i = left; i <= right; i++)
//		{
//			if (inorder[i] == preorder[index]) {
//				pos = i;
//				break;
//			}
//		}
//		if (left < pos) {
//			index++;
//			node->left = _buildTree(preorder, inorder, index, left, pos - 1);
//		}
//		if (pos < right) {
//			index++;
//			node->right = _buildTree(preorder, inorder, index, pos + 1, right);
//		}
//		return node;
//	}
//	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//		int left = 0, right = preorder.size() - 1, index = 0;
//		return _buildTree(preorder, inorder, index, left, right);
//	}
//};


//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//bool IsLeapYear(int year)
//{
//	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
//		return true;
//	return false;
//}
//
//bool IsPrime(int month)
//{
//	vector<int>prime{ 2,3,5,7,11 };
//	return find(prime.begin(), prime.end(), month) != prime.end();
//}
//
//int day(int year, int month)
//{
//	vector<int>arr{ 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//	int ret;
//	if (IsLeapYear(year) && month == 2)
//		arr[2] = 29;
//	ret = arr[month];
//	//if (!IsPrime(month))
//	//	ret *= 2;
//	return ret;
//}
//int main()
//{
//	int byear, bmonth, bday;
//	int eyear, emonth, eday;
//	while (cin >> byear >> bmonth >> bday >> eyear >> emonth >> eday)
//	{
//		int sum = 0, count = 0;
//		for (int i = byear + 1; i < eyear; i++)
//		{
//			for (int j = 1; j <= 12; j++)
//			{
//				int tmp = day(i, j);
//				if (!IsPrime(j)) {
//					tmp *= 2;
//				}
//				sum += tmp;
//			}
//		}
//		if (byear == eyear) {
//			if (bmonth == emonth) {
//				count = eday - bday + 1;
//			}
//			else {
//				count = day(byear, bmonth) - eday + 1;
//			}
//			if (!IsPrime(bmonth))
//				count *= 2;
//			if (bmonth != emonth) {
//				for (int i = bmonth + 1; i < emonth; i++)
//				{
//					int tmp = day(eyear, i);
//					if (!IsPrime(i))
//						tmp *= 2;
//					count += tmp;
//				}
//				int tmp = eday;
//				if (!IsPrime(emonth))
//					tmp *= 2;
//				count += tmp;
//			}
//		}
//		else {
//			count = day(byear, bmonth) - bday + 1;
//			if (!IsPrime(bmonth))
//				count *= 2;
//			for (int i = bmonth + 1; i <= 12; i++)
//			{
//				int tmp = day(byear, i);
//				if (!IsPrime(i))
//					tmp *= 2;
//				count += tmp;
//			}
//			//下一年
//			for (int i = 1; i < emonth; i++)
//			{
//				int tmp = day(eyear, i);
//				if (!IsPrime(i))
//					tmp *= 2;
//				count += tmp;
//			}
//			int tmp = eday;
//			if (!IsPrime(emonth))
//				tmp *= 2;
//			count += tmp;
//		}
//		cout << sum + count << endl;
//	}
//	return 0;
//}


#include <iostream>
using namespace std;

int main()
{
	int arr[100001];
	arr[1] = 1;
	arr[2] = 2;
	int prev1 = 2, prev2 = 1;
	for (int i = 3; i <= 100000; i++)
	{
		arr[i] = (arr[i - 1] + arr[i - 2]) % 1000000;
	}
	int n;
	while (cin >> n)
	{
		printf((n < 29 ? "%d\n" : "%06d\n"), arr[n]);
	}
	return 0;
}