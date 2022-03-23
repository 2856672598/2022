//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int>nums(n);
//	for (int i = 0; i < n; i++)
//		cin >> nums[i];
//	int ret = 1;
//	int left = 0, right = left + 1;
//	int flag = 0;
//	while (right < n)
//	{
//		if (flag == -1 && nums[right] > nums[right - 1] || flag == 1 && nums[right] < nums[right - 1]) {
//			ret++;
//			left = right;
//			flag = 0;
//		}
//
//		//升序
//		if (nums[left] < nums[right]) {
//			flag = 1;
//
//		}
//		else if (nums[left] > nums[right]) {
//			flag = -1;
//		}
//		right++;
//	}
//	cout << ret;
//	return 0;
//}

//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//	string str;
//	getline(cin, str);
//	int left = 0, right = 0;
//	while (left < str.size())
//	{
//		while (right < str.size() && str[right] != ' ')
//			right++;
//		reverse(str.begin() + left, str.begin() + right);
//
//		while (right < str.size() && !isalpha(str[right]))
//			right++;
//		left = right;
//	}
//	reverse(str.begin(), str.end());
//	string ret;
//	int i = 0;
//	while (i < str.size())
//	{
//		while (i < str.size() && str[i] == ' ')
//			i++;
//
//		while (i < str.size() && str[i] != ' ')
//		{
//			ret += str[i];
//			i++;
//		}
//		if (i < str.size())
//			ret += ' ';
//	}
//	if (str[str.size() - 1] == ' ')
//		ret.pop_back();
//	cout << ret;
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//	string str;
//	cin >> str;
//	string ret;
//	int left = 0, right = 0;
//	while (right < str.size())
//	{
//		//找数字所在位置
//		while (left < str.size() && !isdigit(str[left]))
//			left++;
//		right = left + 1;
//		while (right < str.size() && isdigit(str[right]))
//			right++;
//		if (right - left > ret.size())
//			ret = str.substr(left, right - left);
//		left = right;
//	}
//	cout << ret;
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//class Solution {
//public:
//	int MoreThanHalfNum_Solution(vector<int> numbers) {
//		sort(numbers.begin(), numbers.end());
//		int left = 0;
//		int mid = (numbers.size() - left) / 2;
//		while (mid < numbers.size())
//		{
//			if (numbers[mid] == numbers[left])
//				break;
//			left++;
//			mid++;
//		}
//		return numbers[mid];
//	}
//};

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
//class Solution {
//public:
//	void reorderList(ListNode* head) {
//		vector<ListNode*>v;
//		while (head)
//		{
//			v.push_back(head);
//			head = head->next;
//		}
//		int left = 0, right = v.size() - 1;
//		ListNode tmp;
//		ListNode* prev = &tmp;
//		while (left < right)
//		{
//			prev->next = v[left];
//			v[left]->next = v[right];
//			v[right]->next = nullptr;
//			prev = v[right];
//			left++;
//			right--;
//		}
//		if (left == right) {
//			prev->next = v[right];
//			v[right]->next = nullptr;
//		}
//	}
//};


//class Solution {
//public:
//	ListNode* reverse(ListNode* head)
//	{
//		ListNode* prev = nullptr, *next = nullptr;
//		while (head)
//		{
//			next = head->next;
//			head->next = prev;
//			prev = head;
//			head = next;
//		}
//		return prev;
//	}
//
//	void reorderList(ListNode* head) {
//		//找到链表的中间节点
//		ListNode tmp;
//		tmp.next = head;
//		ListNode* newnode = &tmp;
//		ListNode* fast = newnode, *slow = newnode;
//		while (fast&&fast->next)
//		{
//			slow = slow->next;
//			fast = fast->next->next;
//		}
//		//翻转后半部分
//		ListNode* cur1 = head;
//		ListNode* cur2 = reverse(slow->next);
//		ListNode* next1 = nullptr, *next2 = nullptr, *prev = &tmp;
//		//两个链表归一个
//		while (cur2)
//		{
//			next1 = cur1->next;
//			next2 = cur2->next;
//			prev->next = cur1;
//			cur1->next = cur2;
//			prev = cur2;
//			cur1 = next1;
//			cur2 = next2;
//		}
//		prev->next = nullptr;
//		if (cur1 == slow)
//		{
//			cur1->next = nullptr;
//			prev->next = cur1;
//		}
//	}
//};

//#include <iostream>
//#include <unordered_map>
//#include <string>
//using namespace std;
//
//class Solution {
//public:
//	bool areOccurrencesEqual(string s) {
//		unordered_map<int, int>flag(26);
//		int sz = s.size();
//		for (const auto&e : s)
//		{
//			flag[e - 'a']++;
//		}
//		int tmp = flag.begin()->second;
//		for (auto e : flag)
//		{
//			if (e.second != tmp)
//				return false;
//		}
//		return true;
//	}
//};

//中缀表达式转后缀
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

int main()
{
	string str;
	cin >> str;
	stack<char>s;
	unordered_map<char, int>flag{ {'+',1},{'-',1},{'*',2},{'/',2} };
	string ret;
	for (int i = 0; i < str.size(); i++)
	{
		if (flag.find(str[i]) == flag.end()){
			//当前是操作数
			ret.push_back(str[i]);
		}
		else {
			if (!s.empty()) {
				//判断当前位置的优先级是否大于栈顶
				while (!s.empty() && flag[s.top()] >= flag[str[i]]) {
					//可以出栈
					ret.push_back(s.top());
					s.pop();
				}
				s.push(str[i]);
			}
			else
				s.push(str[i]);
		}
	}
	while (!s.empty())
	{
		ret.push_back(s.top());
		s.pop();
	}
	cout << ret;
	return 0;
}