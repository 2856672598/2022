//#include<iostream>
//using namespace std;
//int main()
//{
//	int year, month, day;
//	cin >> year >> month >> day;
//	int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//	int ret = day;
//	for (int i = 1; i < month; i++)
//	{
//		ret += arr[i];
//	}
//	if (month > 2 && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0))
//		ret += 1;
//	cout << ret << endl;
//	return 0;
//}


//#include<iostream>
//using namespace std;
//int GetMonthDay(int year, int month)
//{
//	int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//	int ret = arr[month];
//	if (month == 2 && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0))
//		ret += 1;
//	return ret;
//}
//int main()
//{
//	int y, n;
//	int month = 1, year = 0;
//	while (cin >> y >> n)
//	{
//		year = y;
//		month = 1;
//		while (n > GetMonthDay(year, month))
//		{
//			n -= GetMonthDay(year, month);
//			month++;
//			if (month >= 13)
//			{
//				month = 1;
//				year++;
//			}
//		}
//		printf("%d-%02d-%02d\n", year, month, n);
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int GetMonthDay(int year, int month)
//{
//	int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//	int ret = arr[month];
//	if (month == 2 && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0))
//		ret += 1;
//	return ret;
//}
//int main()
//{
//	int n;
//	int year, month, day, sum;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> year >> month >> day >> sum;
//		day += sum;
//		while (day > GetMonthDay(year, month))
//		{
//			day -= GetMonthDay(year, month);
//			month++;
//			if (month >= 13)
//			{
//				month = 1;
//				year++;
//			}
//		}
//		printf("%d-%02d-%02d\n", year, month, day);
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//struct ListNode {
//	int val;
//	ListNode *next;
//	ListNode() : val(0), next(nullptr) {}
//	ListNode(int x) : val(x), next(nullptr) {}
//	ListNode(int x, ListNode *next) : val(x), next(next) {}
//};
// 
//class Solution {
//public:
//	ListNode* rotateRight(ListNode* head, int k) {
//		if (head == nullptr || k == 0)
//			return head;
//		//先遍历求出链表长度
//		int length = 0;
//		ListNode* cur = head;
//		while (cur)
//		{
//			cur = cur->next;
//			length++;
//		}
//		k = k % length;
//		if (length <= 1 || k == 0)
//			return head;
//		//找倒数第k+1个节点
//		ListNode newhead;
//		newhead.next = head;
//		ListNode* fast = &newhead, *slow = &newhead;
//		//先让fast走k步
//		while (fast&&fast->next&&k)
//		{
//			fast = fast->next;
//			k--;
//		}
//		while (fast&&fast->next)
//		{
//			fast = fast->next;
//			slow = slow->next;
//		}
//		ListNode* ret = slow->next;
//		slow->next = nullptr;
//		fast->next = newhead.next;
//		return ret;
//	}
//};

//#include<iostream>
//#include<stack>
//using namespace std;
//
//class Solution {
//public:
//	string removeDuplicates(string s) {
//		stack<char>st;
//		int  i = 0;
//		while (i < s.size())
//		{
//			if (st.empty() || st.top() != s[i])
//				st.push(s[i]);
//			else
//				st.pop();
//			i++;
//		}
//		string ret;
//		while (!st.empty())
//		{
//			ret.push_back(st.top());
//			st.pop();
//		}
//		reverse(ret.begin(), ret.end());
//		return ret;
//	}
//};
//int main()
//{
//	return 0;
//}

//#include<iostream>
//#include<algorithm>
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
////class Solution {
////public:
////	int minDepth(TreeNode* root) {
////		if (root == nullptr)
////			return 0;
////		if (root->left == nullptr&&root->right == nullptr)
////			return 1;
////		int depth = INT_MAX;
////		if (root->left != nullptr)
////			depth = min(minDepth(root->left), depth);
////		if (root->right != nullptr)
////			depth = min(minDepth(root->right), depth);
////		return depth + 1;
////	}
////};
//
////class Solution {
////public:
////	int countNodes(TreeNode* root)
////	{
////		if (root == nullptr)
////			return 0;
////		return countNodes(root->left) + countNodes(root->right) + 1;
////	}
////};
//
////class Solution
////{
////public:
////	bool hasPathSum(TreeNode* root, int targetSum)
////	{
////		if (root == nullptr)
////			return false;
////		if (targetSum - root->val == 0 && root->left == nullptr&&root->right == nullptr)
////			return true;
////		return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
////	}
////};
//
//#include<vector>
//#include<string>
//class Solution {
//public:
//	vector<string>ret;
//	void _binaryTreePaths(TreeNode* root,string s)
//	{
//		if (root == nullptr)
//			return;
//		string tmp = to_string(root->val);
//		s += tmp;
//		s += "->";
//		if (root->left == nullptr&&root->right == nullptr)
//		{
//			s.pop_back();
//			s.pop_back();
//			ret.push_back(s);
//		}
//		_binaryTreePaths(root->left, s);
//		_binaryTreePaths(root->right, s);
//		s.pop_back();
//	}
//
//	vector<string> binaryTreePaths(TreeNode* root)
//	{
//		_binaryTreePaths(root, {});
//		return ret;
//	}
//};


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int getKthMagicNumber(int k)
	{
		vector<int>arr(k, 0);
		arr[0] = 1;
		int a1 = 0, a2 = 0, a3 = 0;
		for (int i = 1; i < k; i++)
		{
			arr[i] = min(min(arr[a1] * 3, arr[a2] * 5), arr[a3] * 7);
			if (arr[i] == arr[a1] * 3)
				a1++;
			else if (arr[i] == arr[a2] * 5)
				a2++;
			else
				a3++;
			if (arr[i] == arr[i - 1])
				i--;
		}
		return arr[k - 1];
	}
};
int main()
{
	int k = 10;
	cout << Solution().getKthMagicNumber(k) << endl;
	return 0;
}