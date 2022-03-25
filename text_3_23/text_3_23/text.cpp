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
//		//����
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
//		//����������λ��
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

//#include <iostream>
//#include <vector>
//using namespace std;
//
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
//		//�ҵ�������м�ڵ�
//		ListNode tmp;
//		tmp.next = head;
//		ListNode* newnode = &tmp;
//		ListNode* fast = newnode, *slow = newnode;
//		while (fast&&fast->next)
//		{
//			slow = slow->next;
//			fast = fast->next->next;
//		}
//		//��ת��벿��
//		ListNode* cur1 = head;
//		ListNode* cur2 = reverse(slow->next);
//		ListNode* next1 = nullptr, *next2 = nullptr, *prev = &tmp;
//		//���������һ��
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

////��׺���ʽת��׺
//#include <iostream>
//#include <string>
//#include <stack>
//#include <unordered_map>
//using namespace std;
//
//int main()
//{
//	string str;
//	cin >> str;
//	stack<char>s;
//	unordered_map<char, int>flag{ {'+',1},{'-',1},{'*',2},{'/',2} };
//	string ret;
//	for (int i = 0; i < str.size(); i++)
//	{
//		if (flag.find(str[i]) == flag.end()){
//			//��ǰ�ǲ�����
//			ret.push_back(str[i]);
//		}
//		else {
//			if (!s.empty()) {
//				//�жϵ�ǰλ�õ����ȼ��Ƿ����ջ��
//				while (!s.empty() && flag[s.top()] >= flag[str[i]]) {
//					//���Գ�ջ
//					ret.push_back(s.top());
//					s.pop();
//				}
//				s.push(str[i]);
//			}
//			else
//				s.push(str[i]);
//		}
//	}
//	while (!s.empty())
//	{
//		ret.push_back(s.top());
//		s.pop();
//	}
//	cout << ret;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int asubb, bsubc, aaddb, baddc;
//	cin >> asubb >> bsubc >> aaddb >> baddc;
//	for (int a = 0; a <= 30; a++)
//	{
//		for (int b = 0; b <= 30; b++)
//		{
//			for (int c = 0; c <= 30; c++)
//			{
//				if (a - b == asubb && b - c == bsubc && a + b == aaddb && b + c == baddc)
//				{
//					cout << a << " " << b << " " << c << endl;
//					return 0;
//				}
//			}
//		}
//	}
//	cout << "No" << endl;
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//	int m, n;
//	cin >> m >> n;
//	int status = 1;
//	string ret;
//	vector<char>flag{ '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
//	if (m < 0) {
//		status = -1;
//		m *= -1;
//	}
//	int tmp = m;
//	while (tmp)
//	{
//		ret += flag[tmp % n];
//		tmp /= n;
//	}
//	if (status == -1)
//		ret += '-';
//	reverse(ret.begin(), ret.end());
//	cout << ret << endl;
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
//	reverse(str.begin(), str.end());
//	int left = 0, right = 0;
//	while (right < str.size())
//	{
//		while (right < str.size() && str[right] != ' ')
//			right++;
//		reverse(str.begin() + left, str.begin() + right);
//		left = right;
//		while (left < str.size() && str[left] == ' ')
//			left++;
//		right = left;
//	}
//	cout << str;
//	return 0;
//}

////�쳣
//#include <iostream>
//#include <string>
//using namespace std;
//void fun(int x, int y)
//{
//	/*
//	�쳣�����׳��κζ��󣬵��Ǻ��иö����cath�ſ��Դ�����쳣��
//	�쳣�׳�����Ҫcath���в�׽���������ֱ�ӱ�����
//	*/
//	if (y == 0)
//		throw string("�������");
//	cout << x / y << endl;
//}
//
//int main()
//{
//	int x, y;
//	cin >> x >> y;
//	try
//	{
//		fun(x, y);
//		char *p = new char[0x7fffffff];
//	}
//	catch (const std::exception&e)
//	{
//		cout << e.what() << endl;//�������׳����쳣
//	}
//	catch (string s) {
//		cout << s << endl;
//	}
//	catch (...)//�����κ����͵��쳣
//	{
//		cout << "δ֪����" << endl;
//	}
//	return 0;
//}

//#include <iostream>
//namespace wkn
//{
//	template<class T>
//	class auto_ptr
//	{
//	public:
//		auto_ptr(T* ptr)
//			:_ptr(ptr)
//		{}
//
//		auto_ptr(auto_ptr<T>& p)
//		{
//			_ptr = p._ptr;
//			p._ptr = nullptr;
//		}
//
//		auto_ptr& operator=(auto_ptr<T>&p)
//		{
//			_ptr = p._ptr;
//			p._ptr = nullptr;
//			return *this;
//		}
//
//		T& operator*()
//		{
//			return *_ptr;
//		}
//
//		~auto_ptr()
//		{
//			delete _ptr;
//			cout << "delete _ptr" << _ptr << endl;
//		}
//	private:
//		T* _ptr;
//	};
//}
///*
//������д���У���������͸�ֱֵ�Ӱ���Է���Ȩ����ֱ�Ӹ��Լ����Է���ɿ�ָ�룬������
//����������������ָ�롣
//*/
//int main()
//{
//	int* a = new int(10);
//	wkn::auto_ptr<int>p1(a);
//	wkn::auto_ptr<int>p2(p1);
//	wkn::auto_ptr<int>p3(p2);
//	p1 = p3;
//	cout << *p1 << endl;
//	return 0;
//}

//#include <iostream>
//#include <string>
//#include <vector>
//#include <unordered_map>
//#include <unordered_set>
//using namespace std;
//
////class Solution {
////public:
////	bool canBeEqual(vector<int>& target, vector<int>& arr) {
////		unordered_map<int, int>m;
////		for (int i = 0; i < (int)target.size(); i++)
////		{
////			m[target[i]]++;
////			m[arr[i]]--;
////		}
////		for (auto e : m)
////		{
////			if (e.second != 0)
////				return false;
////		}
////		return true;
////	}
////};
//
//class Solution {
//public:
//	bool uniqueOccurrences(vector<int>& arr) {
//		unordered_map<int, int>m;
//		for (const auto& e : arr)
//			m[e]++;
//		unordered_set<int>flag;
//		for (const auto &e : m)
//		{
//			if (flag.find(e.second) == flag.end())
//				flag.insert(e.second);
//			else
//				return false;
//		}
//		return true;
//	}
//};

#include <iostream>
#include <thread>
#include <mutex>
#include <memory>
#include <functional>
#include <vector>
using namespace std;
namespace wkn
{
	template<class T>
	class DeleteArr
	{
	public:
		void operator()( T* t)
		{
			delete t;
		}
	};

	template<class T, class D = DeleteArr<T>>
	class shared_ptr
	{
	public:
		shared_ptr()
		{}

		shared_ptr(T* ptr)
			:_ptr(ptr)
			, _pcount(new int(1))
			, mx(new mutex)
		{}

		shared_ptr(T* ptr, D del)
			:_ptr(ptr)
			, _pcount(new int(1))
			, mx(new mutex)
			, _del(del)
		{}


		shared_ptr(const shared_ptr<T>& p)
		{
			_ptr = p._ptr;
			_pcount = p._pcount;
			mx = p.mx;
			_del = p._del;
			addcount();
		}

		void addcount()
		{
			mx->lock();
			(*_pcount)++;
			mx->unlock();
		}

		void reduce()
		{
			mx->lock();
			bool flag = false;
			if (--(*_pcount) == 0) {
				//thisָ���֮��ռ�û���ڹ���
				_del(_ptr);
				delete _pcount;
				flag = true;
			}
			mx->unlock();
			//������ǰ���ͷŵ������ͷŵ��ᵼ��Ұָ��ķ��ʡ�
			if (true == flag)
				delete mx;
		}

		shared_ptr& operator=(const shared_ptr<T>&p)
		{
			//�Լ���Ҫ���Լ���ֵ
			if (_ptr != p._ptr){
				reduce();
				_ptr = p._ptr;
				_pcount = p._pcount;
				mx = p.mx;
				addcount();
			}
			return *this;
		}

		~shared_ptr()
		{
			reduce();
			if (*_pcount == 0) {
				cout << "delete" << _ptr << endl;
				_del(_ptr);
				delete mx;
			}
		}

		T operator*()
		{
			return  *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		int count()
		{
			return *_pcount;
		}

		T* get()const
		{
			return _ptr;
		}
	private:
		T* _ptr;
		int* _pcount;//��¼�����м�����ָ��_ptr;
		mutex* mx;
		D _del;
	};

	template<class T>
	class weak_ptr
	{
	public:
		weak_ptr(T* ptr)
			:_ptr(ptr)
		{}

		weak_ptr(const shared_ptr<T>& x)
		{
			_ptr = x.get();
		}

		weak_ptr<T>& operator=(const weak_ptr& x)
		{
			_ptr = x._ptr;
			return *this;
		}

		T operator*()
		{
			return  *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}
	private:
		T* _ptr;
	};
 }

class Date
{
public:
	Date(int year = 1, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{}
public:
	int _year;
	int _month;
	int _day;
};

void text1()
{
	wkn::shared_ptr<int>p1 = new int(10);
	wkn::shared_ptr<int>p2(p1);
	wkn::shared_ptr<int>p3(p2);
	wkn::shared_ptr<int>p4 = new int(20);
	p4 = p1;
}

void text2()
{
	wkn::shared_ptr<Date> p1 = new Date(2022, 3, 25);
	cout << p1->_year << "/" << p1->_month << "/" << p1->_day << endl;
}

void fun(wkn::shared_ptr<int> p, int n)
{
	for (int i = 0; i < n; i++)
	{
		new wkn::shared_ptr<int>(p);
	}
}

void fun1(wkn::shared_ptr<int> p, int n)
{
	for (int i = 0; i < n; i++)
	{
		p.reduce();
	}
}

void text3()
{
	//�����̰߳�ȫ������Ϊ++��--����ԭ���Ե�
	wkn::shared_ptr<int>tmp = new int(10);
	int n = 10000;
	thread p1 = thread(fun, tmp, n);
	thread p2 = thread(fun, tmp, n);
	p1.join();
	p2.join();
	cout << tmp.count() << endl;
	vector<thread>vthread(2);
	//ÿ���߳�ִ��--����
	for (int i = 0; i < (int)vthread.size(); i++)
	{
		vthread[i] = thread(fun1, tmp, n);
	}

	for (int i = 0; i < (int)vthread.size(); i++)
		vthread[i].join();

	cout << tmp.count() << endl;
}

struct Node
{
	//weak_ptr���Է�ֹѭ�����á�
	wkn::weak_ptr<Node> _next = nullptr;
	wkn::weak_ptr<Node> _prev = nullptr;

	Node()
	{}

	~Node()
	{
		cout << "~Node()" << endl;
	}
};

void text4()
{
	wkn::shared_ptr<Node> p1 = new Node;
	wkn::shared_ptr<Node> p2 = new Node;
	p1->_next = p2;
	p2->_prev = p1;
}

int main()
{
	//text1();
	//text2();
	//text3();
	//text4();
	
	function<void(Node*)> del = [](Node* ptr) {delete[]ptr; };
	//shared_ptr<Node> p(new Node[10], del);

	//wkn::shared_ptr<Node, function<void(Node*)>> p(new Node[10], del);
	wkn::shared_ptr<Node>p = new Node;
	return 0;
}