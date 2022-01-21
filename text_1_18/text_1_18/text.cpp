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


//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//class Solution {
//public:
//	int getKthMagicNumber(int k)
//	{
//		vector<int>arr(k, 0);
//		arr[0] = 1;
//		int a1 = 0, a2 = 0, a3 = 0;
//		for (int i = 1; i < k; i++)
//		{
//			arr[i] = min(min(arr[a1] * 3, arr[a2] * 5), arr[a3] * 7);
//			if (arr[i] == arr[a1] * 3)
//				a1++;
//			else if (arr[i] == arr[a2] * 5)
//				a2++;
//			else
//				a3++;
//			if (arr[i] == arr[i - 1])
//				i--;
//		}
//		return arr[k - 1];
//	}
//};
//int main()
//{
//	int k = 10;
//	cout << Solution().getKthMagicNumber(k) << endl;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class A
//{
//public:
//	A(int a = 0)
//	{
//		_a = a;
//		cout << "A(int a)" << endl;
//	}
//
//	A(const A& a)
//	{
//		_a = a._a;
//		cout << "A(const A& a)" << endl;
//	}
//
//	A& operator=(const A& a)
//	{
//		cout << "A operator=(const A& a)" << endl;
//		return *this;
//	}
//private:
//	int _a;
//};
//
//class Date
//{
//public:
//	//Date(int _year, const A& a)
//	//	:_year(_year)
//	//	, _aa(a)
//	//{}
//
//	Date(int _year, const A& a)
//	{
//		_year = _year;
//		_aa = a;
//	}
//
//private:
//	//这是成员变量的声明，定义是在初始化列表
//	int _year;
//	A _aa;
//};
//
//int main()
//{
//	Date d(2022, A(1));
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	//这里是声明;
//	int _year = 1;
//	int _month = 1;
//	int _day = 1;
//};
//int main()
//{
//	Date d;
//	d.Print();
//	return 0;
//}

//#include<iostream>
//#include<vector>
//#include<unordered_set>
//using namespace std;
//
//class Solution {
//public:
//	bool containsNearbyDuplicate(vector<int>& nums, int k)
//	{
//		unordered_set<int>s;
//		for (int i = 0; i < nums.size(); i++)
//		{
//			if (i > k)
//				s.erase(nums[i - k - 1]);
//			if (s.count(nums[i]))
//				return true;
//			s.insert(nums[i]);
//		}
//		return false;
//	}
//};
//int main()
//{
//	vector<int>nums{ 1,2,3,1,2,3 };
//	int k = 2;
//	cout << Solution().containsNearbyDuplicate(nums, k);
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//	Date operator++(int)
//	{
//		Date tmp(*this);
//		_day++;
//		return tmp;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d;
//	d++;
//	return 0;
//}

//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//	int search(vector<int>& nums, int target)
//	{
//		int left = 0, right = nums.size() - 1;
//		int mid = 0;
//		while (left <= right)
//		{
//			mid = left + (right - left) / 2;
//			if (nums[mid] == target)
//			{
//				break;
//			}
//			else if (nums[mid] < target)
//			{
//				left = mid + 1;
//			}
//			else
//				right = mid - 1;
//		}
//		//判断下是是否存在
//		if (left <= right)
//		{
//			while (left <= mid)
//			{
//				if (target != nums[mid])
//				{
//					mid++;
//					break;
//				}
//				mid--;
//			}
//			mid = mid < left ? left : mid;
//		}
//		else
//			mid = -1;
//		return  mid;
//	}
//};
//int main()
//{
//	vector<int>nums{ 1,1,2,3,7,7,7,9,9,10 };
//	int target = 2;
//	cout << Solution().search(nums, target);
//	return 0;
//}


//#include<iostream>
//#include<vector>
//#include<unordered_set>
//#include<algorithm>
//using namespace std;
//
//class Solution {
//public:
//	int maxLength(vector<int>& arr)
//	{
//		unordered_set<int>s;
//		int ret = 0;
//		int left = 0, right = 0;
//		while (right < arr.size())
//		{
//			while (s.count(arr[right]))
//			{
//				s.erase(arr[left++]);
//			}
//			s.insert(arr[right++]);
//			ret = max(ret, right - left);
//		}
//		return ret;
//	}
//};
//int main()
//{
//	return 0;
//}

//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//class Solution {
//public:
//	int longestSubarray(vector<int>& nums)
//	{
//		int left = 0, right = 0, ret = 0;
//		int zero = 0;
//		while (right < nums.size())
//		{
//			if (nums[right] == 0)
//				zero++;
//			while (zero > 1)
//			{
//				if (nums[left] == 0)
//				{
//					zero--;
//					left++;
//					break;
//				}
//				left++;
//			}
//			ret = max(ret, right - left);
//			right++;
//		}
//		return ret;
//	}
//};
//int main()
//{
//	vector<int>nums{ 0,1,1,1,0,1,1,0,1 };
//	cout << Solution().longestSubarray(nums);
//	return 0;
//}

//#include<iostream>
//using namespace std;
//class Solution
//{
//public:
//	bool IsAutonomicNumber(int n)
//	{
//		//计算位数
//		int flag = 1;
//		int tmp = n;
//		while (tmp)
//		{
//			tmp /= 10;
//			flag *= 10;
//		}
//		if ((n*n) % flag == n)
//			return true;
//		return false;
//	}
//};
//
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		int count = 0;
//		for (int i = 0; i <= n; i++)
//		{
//			if (Solution().IsAutonomicNumber(i))
//				count++;
//		}
//		cout << count << endl;
//	}
//	return 0;
//}


//#include<iostream>
//using namespace std;
//
//int main()
//{
//	long long input;
//	cin >> input;
//	int s = input / 1000;
//	int m = s / 60;
//	int h = m / 60;
//	printf("%02d:%02d:%02d\n", h % 24, m % 60, s % 60);
//	return 0;
//}

//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//bool comp(int i, int j)
//{
//	return i > j;
//}
//
//int main()
//{
//	int n, m;
//	vector<int>v;
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++)
//	{
//		v.push_back(i);
//	}
//	while (m)
//	{
//		int tmp1, tmp2;
//		cin >> tmp1 >> tmp2;
//		if (tmp1 == 0)
//		{
//			sort(v.begin(), v.begin() + tmp2, comp);
//		}
//		else
//		{
//			sort(v.begin() + tmp2 - 1, v.end());
//		}
//		m--;
//	}
//	for (int i = 0; i < n; i++)
//		cout << v[i] << " ";
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Date
//{
//	friend istream& operator>>(istream& _cin, Date& d1);
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	int GetMonthDay(int year, int month)const
//	{
//		int arr[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//		int day = arr[month];
//		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
//			day += 1;
//		return day;
//	}
//
//	int Days(const Date& init)const
//	{
//		int ret = _day;
//		for (int i = init._year; i < _year; i++)
//		{
//			ret += 365;
//			if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
//				ret += 1;
//		}
//		//计算月
//		for (int i = 1; i < _month; i++)
//		{
//			ret += GetMonthDay(_year, i);
//		}
//		return ret;
//	}
//
//	bool operator>(const Date &d)const
//	{
//		if (_year > d._year)
//			return true;
//		else if (_year == d._year && _month > d._month)
//			return true;
//		else if (_year == d._year && _month > d._month && _day > d._day)
//			return true;
//		return false;
//	}
//
//	int operator-(const Date& d)
//	{
//		Date min = *this > d ? d : *this;
//		int ret = abs(this->Days(min) - d.Days(min));
//		if (ret != 0)
//			ret += 1;
//		return ret;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//istream& operator>>(istream& _cin, Date& d1)
//{
//	int tmp;
//	cin >> tmp;
//	d1._day = tmp % 100;
//	tmp /= 100;
//	d1._month = tmp % 100;
//	tmp /= 100;
//	d1._year = tmp;
//	return _cin;
//}
//
//int main()
//{
//	Date d1, d2;
//	while (cin >> d1 >> d2)
//	{
//		cout << d1 - d2 << endl;
//	}
//	return 0;
//}


//#include<iostream>
//using namespace std;
//struct ListNode {
//	int val;
//	ListNode *next;
//	ListNode(int x) : val(x), next(NULL) {}
//};
// 
//class Solution {
//public:
//	int kthToLast(ListNode* head, int k) {
//
//		ListNode* fast = head, *slow = head;
//		while (fast&&k)
//		{
//			fast = fast->next;
//			k--;
//		}
//		while (fast != nullptr)
//		{
//			fast = fast->next;
//			slow = slow->next;
//		}
//		return slow->val;
//	}
//};

////539. 最小时间差
//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//	int GetMinute(const string& s)
//	{
//		int hour = (s[0] - '0') * 10 + s[1] - '0';
//		int minute = (s[3] - '0') * 10 + s[4] - '0';
//		minute += hour * 60;
//		return minute;
//	}
//	int findMinDifference(vector<string>& timePoints) {
//		sort(timePoints.begin(), timePoints.end());
//		int ret = INT_MAX;
//		for (int i = 1; i < timePoints.size(); i++)
//		{
//			ret = min(abs(GetMinute(timePoints[i]) - GetMinute(timePoints[i - 1])), ret);
//		}
//		ret = min(abs(GetMinute(timePoints[0]) + 1440 - GetMinute(timePoints[timePoints.size() - 1])), ret);
//		return ret;
//	}
//};
//int main()
//{
//	vector<string>timePoints{ "23:59","00:00" };
//	cout << Solution().findMinDifference(timePoints) << endl;
//	return 0;
//}

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int largestAltitude(vector<int>& gain)
	{
		int ret = 0, cur = 0;
		for (int i = 0; i < gain.size(); i++)
		{
			ret = max(ret, cur + gain[i]);
			cur = cur + gain[i];
		}
		return ret;
	}
};

int main()
{
	return 0;
}