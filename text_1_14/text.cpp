// #include<iostream>
// #include<vector>
// using namespace std;

// class Solution {
// public:
// 	int OneSize(unsigned int num)
// 	{
// 		int count = 0;
// 		while (num)
// 		{
// 			num &= num - 1;
// 			count++;
// 		}
// 		return count;
// 	}
// 	vector<int> findClosedNumbers(int num)
// 	{
// 		int numsize = OneSize(num);
// 		long long tmp = num;
// 		vector<int>ret;
// 		while (true)
// 		{
//             if(tmp == INT_MAX)
//             {
//                 tmp =-1;
//                 break;
//             }
// 			if (numsize == OneSize(tmp)&&num != tmp)
// 				break;
// 			tmp++;
// 		}
// 		ret.push_back(tmp);
// 		tmp = num;
// 		while (true)
// 		{
// 			if (tmp < 1 || tmp == INT_MAX)
// 			{
// 				tmp = -1;
// 				break;
// 			}
// 			if (numsize == OneSize(tmp)&&num != tmp)
// 				break;
// 			tmp -= 1;
// 		}
// 		ret.push_back(tmp);
// 		return ret;
// 	}
// };

// int main()
// {
//     int n = 1;
//     vector<int>ret = Solution().findClosedNumbers(n);
//     for(auto e : ret)
//         cout << e <<" ";
//     return 0;
// }

// // 面试题 03.05. 栈排序
// #include<iostream>
// #include<stack>
// using namespace std;

// class SortedStack
// {
// 	private:
// 		stack<int>q;
// 		stack<int>tmp;
// public:
//     SortedStack()
// 	{
//     }
    
//     void push(int val)
// 	{
// 		if(q.empty())
// 		{
// 			q.push(val);
// 		}
// 		else
// 		{
// 			while(!q.empty()&&q.top()<val)
// 			{
// 				tmp.push(q.top());
// 				q.pop();
// 			}
// 			//将val插入q中
// 			q.push(val);
// 			while(!tmp.empty())
// 			{
// 				q.push(tmp.top());
// 				tmp.pop();
// 			}
// 		}
//     }
    
//     void pop()
// 	{
// 		if(!isEmpty())
// 			q.pop();
//     }
    
//     int peek()
// 	{
// 		if(isEmpty())
// 			return -1;
// 		return q.top();
//     }
    
//     bool isEmpty()
// 	{
// 		return q.empty();
//     }
// };

// int main()
// {
// 	SortedStack s;
// 	s.pop();
// 	s.push(1);
// 	s.push(2);
// 	return 0;
// }


// #include<iostream>
// using namespace std;

// struct ListNode
// {
// 	int val;
// 	ListNode *next;
// 	ListNode(int x) : val(x), next(NULL) {}
// };

// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
//         ListNode* fast = head, *slow = head;
// 		while(fast != nullptr && fast->next != nullptr)
// 		{
// 			fast = fast->next->next;
// 			slow = slow->next;
// 			if(fast == slow)
// 				break;
// 		}
// 		if(fast == nullptr && fast->next == nullptr)
// 			return nullptr;
// 		fast = head;
// 		while(fast != slow)
// 		{
// 			fast = fast->next;
// 			slow = slow->next;
// 		}
// 		return slow;
//     }
// };


// #include<iostream>
// using namespace std;
// int main()
// {
// 	// const int a = 10;
// 	// auto b = a;
// 	// b=20;
// 	// cout<<b<<endl;
// 	// cout<<typeid(a).name()<< endl;

// 	int arr[]={1,2,3,4,5};
// 	for(auto e: arr)
// 	{
// 		cout<< e << endl;
// 	}

// 	for(auto& e:arr)
// 		e++;

// 	for(int e: arr)
// 	{
// 		cout<< e << endl;
// 	}
// 	return 0;
// }


// #include<iostream>
// using namespace std;

// class Student
// {
// 	char _name[10];
// 	int  _age;
// 	int  _id;
// public:
// 	void printf()
// 	{
// 		cout<<"hello"<<endl;
// 	}
// };

// int main()
// {
// 	Student s;
// 	s.printf();
// 	return 0;
// }

// #include<iostream>
// using namespace std;

// struct TreeNode
// {
// 	int val;
// 	TreeNode *left;
// 	TreeNode *right;
// 	TreeNode() : val(0), left(nullptr), right(nullptr) {}
// 	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// 	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
// class Solution {
// public:
// 	bool _isBalanced(TreeNode* root,int& height)
// 	{
// 		if(root == nullptr)
// 			return true;
// 		int left = 0;
// 		if(_isBalanced(root->left,left) == false)
// 		{
// 			return false;
// 		}
// 		int right = 0;
// 		if(_isBalanced(root->right,right) == false)
// 			return false;
// 		if(abs(left-right)>1)
// 			return false;
// 		height = left<right?right+1:left+1;
// 		return true;
// 	}

//     bool isBalanced(TreeNode* root)
// 	{
// 		int height = 0;
// 		return _isBalanced(root,height);
//     }
// };

// int main()
// {
// 	return 0;
// }


// #include<iostream>
// using namespace std;

// class Student
// {
// 	char _name[10];
// 	int _age;
// 	int _id;
// };
// class A
// {

// };
// class B
// {
// public:
// 	void Print()
// 	{
// 		cout<<"hello"<<endl;
// 	}
// };
// int main()
// {
// 	Student s;
// 	A a;
// 	B b;
// 	cout<<sizeof(s)<<endl;//20
// 	cout<<sizeof(a)<<endl;//1
// 	cout<<sizeof(b)<<endl;//1
// 	return 0;
// }

// #include<iostream>
// #include<vector>
// using namespace std;

// struct TreeNode
// {
// 	int val;
// 	TreeNode *left;
// 	TreeNode *right;
// 	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

// // class Solution
// // {
// // public:
// // 	void InOrder(TreeNode* root,vector<int>&number)
// // 	{
// // 		if(root == nullptr)
// // 			return;
// // 		InOrder(root->left,number);
// // 		number.push_back(root->val);
// // 		InOrder(root->right,number);
// // 	}
// // 	bool isValidBST(TreeNode *root)
// // 	{
// // 		vector<int>number;
// // 		InOrder(root,number);
// // 		for(int i = 1;i<number.size();i++)
// // 		{
// // 			if(number[i]<=number[i-1])
// // 				return false;
// // 		}
// // 		return true;
// // 	}
// // };

// class Solution
// {
// public:
// 	bool _isValidBST(TreeNode* root ,long min,long max)
// 	{
// 		if(root == nullptr)
// 			return true;
// 		if(root->val >= max || root->val <= min)
// 			return false;
// 		return _isValidBST(root->left,min,root->val)
// 			&& _isValidBST(root->right,root->val,max);
// 	}
// 	bool isValidBST(TreeNode *root)
// 	{
// 		return _isValidBST(root,LONG_MIN,LONG_MAX);
// 	}
// };


// #include<iostream>
// #include<vector>
// #include<algorithm>
// #include<unordered_map>
// using namespace std;

// class Solution
// {
// public:
// 	vector<int> twoSum(vector<int> &nums, int target)
// 	{
// 		unordered_map<int,int>m;
// 		for(int i = 0;i < nums.size();i++)
// 		{
// 			int tmp = target - nums[i];
// 			auto it = m.find(tmp);
// 			if(it != m.end())
// 			{
// 				//找到
// 				return {(*it).second,i};
// 			}
// 			m.insert(make_pair(nums[i],i));
// 		}
// 		return {};
// 	}
// };

// int main()
// {
// 	vector<int>nums{3,2,4};
// 	int target = 6;
// 	vector<int>ret = Solution().twoSum(nums,target);
// 	for(auto e:ret)
// 		cout<<e<<endl;
// 	return 0;
// }

// #include<iostream>
// using namespace std;
// struct ListNode
// {
// 	int val;
// 	ListNode *next;
// 	ListNode(int x) : val(x), next(NULL) {}
// };

// class Solution {
// public:
// 	ListNode* Reverse(ListNode* heard)
// 	{
// 		ListNode* prev= nullptr, *cur = heard;
// 		while(cur)
// 		{
// 			ListNode* next = cur->next;
// 			cur->next = prev;
// 			prev = cur;
// 			cur = next;
// 		}
// 		return prev;
// 	}
// 	int ToNumber(ListNode* head)
// 	{
// 		int number =0;
// 		while(head)
// 		{
// 			number*=10+head->val;
// 			head = head->next;
// 		}
// 		return number;
// 	}
//     int addTwoNumbers(ListNode* l1, ListNode* l2)
// 	{
// 		ListNode* p1 = Reverse(l1);
// 		ListNode* p2 = Reverse(l2);
// 		return ToNumber(p1) + ToNumber(p2);
//     }
// };

// #include<iostream>
// struct ListNode
// {
// 	int val;
// 	ListNode *next;
// 	ListNode(int x) : val(x), next(NULL) {}
// };

// class Solution
// {
// public:
// 	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
// 	{
// 		int flag = 0;
// 		ListNode ret(0);
// 		ListNode*cur =&ret;
// 		while(l1 || l2)
// 		{
// 			int val1 = 0,val2 = 0;
// 			val1 = l1 == nullptr?0:l1->val;
// 			val2 = l2 == nullptr?0:l2->val;
// 			int sum = val1 + val2 + flag;
// 			if(sum/10)
// 			{
// 				flag = 1;
// 				sum%=10;
// 			}
// 			else
// 				flag =0;
// 			cur->next =new ListNode(sum);
// 			cur =cur ->next;
// 			if(l1 != nullptr)
// 				l1 = l1->next;
// 			if(l2 != nullptr)
// 				l2 = l2->next;
// 		}

// 		if(flag != 0)
// 		{
// 			cur ->next = new ListNode(flag);
// 			cur = cur->next;
// 		}
// 		return ret.next;
// 	}
// };


// #include<iostream>
// using namespace std;

// struct TreeNode
// {
// 	int val;
// 	TreeNode *left;
// 	TreeNode *right;
// 	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

// class Solution
// {
// public:
// 	int ans = 0;
// 	void _pathSum(TreeNode *root, int sum)
// 	{
// 		if (root == nullptr)
// 			return;
// 		sum -= root->val;	
// 		if (sum == 0)
// 			ans++;
// 		_pathSum(root->left, sum);
// 		_pathSum(root->right, sum);
// 	}

// 	int pathSum(TreeNode *root, int sum)
// 	{
// 		if (root == nullptr)
// 			return 0;
// 		_pathSum(root, sum);
// 		pathSum(root->left, sum);
// 		pathSum(root->right, sum);
// 		return ans;
// 	}
// };


// #include<iostream>
// #include<vector>
// using namespace std;

// class Solution
// {
// public:
// 	int search(vector<int> &arr, int target)
// 	{
// 		int left = 0,right = arr.size()-1,mid = 0;
// 		while(left <= right)
// 		{
// 			mid = left+(right-left)/2;
// 			if(arr[mid] == target)
// 			{
// 				break;
// 			}
// 			if(arr[mid]>=arr[left])
// 			{
// 				//左边有序
// 				if(target>=arr[left]&& target<=arr[mid])
// 				{
// 					right =mid -1;
// 				}
// 				else 
// 					left =mid+1;
// 			}
// 			else
// 			{
// 				//左面无序，在左边
// 				if(target>=arr[left] || target<= arr[mid])
// 					right = mid -1;
// 				else 
// 					left = mid + 1;
// 			}
// 		}
// 		if(left > right)
// 			mid=-2;
// 		while(mid>=0)
// 		{
// 			if(arr[mid]!=target)
// 				break;
// 			mid--;
// 		}
// 		return mid+1;
// 	}
// };

// int main()
// {
// 	vector<int>arr{15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
// 	int target = 11;
// 	cout<<Solution().search(arr,target);
// 	return 0;
// }

// #include<iostream>
// using namespace std;
// class A
// {
// public:
// 	A()
// 	{
// 		cout<<"A默认构造函数"<<endl;
// 	}
// private:
// 	int _a;
// 	int _b;
// };

// class Date
// {
// private:
// 	A a;
// 	int _day;
// 	int _year;
// 	int _month;
// public:
// 	Date(int a)
// 	{
// 		cout<<"Date构造函数"<<endl;
// 	}
// 	void Print()
// 	{
// 		cout<<"hello"<<endl;
// 	}
// };

// int main()
// {
// 	Date  d(10);
// 	d.Print();
// 	return 0;
// }


// #include<iostream>
// using namespace std;

// class Date
// {
// private:
// 	int _month;
// 	int _year;
// 	int _day;
// public:
// 	Date(int year = 2022,int month = 1,int day = 15)
// 	{
// 		_year = year;
// 		_month = month;
// 		_day = day;
// 		cout<<this<<endl;
// 	}
// 	//传值会造成死递归
// 	Date(Date& d)
// 	{
// 		_month = d._month;
// 		_year = d._year;
// 		_day = d._day;
// 	}

// 	void Print()
// 	{
// 		cout<<_year<<"-"<<_month<<"-"<<_day<<endl;
// 	}
// };

// int main()
// {
// 	Date d1;
// 	Date d2(d1);
// 	d1.Print();
// 	d2.Print();
// 	return 0;
// }

// #include<iostream>
// #include<string>
// using namespace std;

// class Solution
// {
// public:
// 	int strToInt(string str)
// 	{
// 		//去掉前导空格
// 		int i = 0;
// 		int size = str.size();
// 		while(i<size)
// 		{
// 			if(str[i]!=' ')
// 				break;
// 			i++;
// 		}
// 		int flag = 1;
// 		if(str[i]=='-'||str[i] == '+')
// 		{
// 			if(str[i] == '-')
// 				flag = -1;
// 			i++;
// 		}
// 		long long sum = 0;
// 		while(i<str.size())
// 		{
// 			if(isdigit(str[i]))
// 			{
// 				sum = sum * 10 + (str[i] - '0')*flag;
// 				if(sum>INT_MAX)
// 					return INT_MAX;
// 				else if(sum<INT_MIN)
// 					return INT_MIN;
// 			}
// 			else
// 				break;
// 			i++;
// 		}
// 		return sum;
// 	}
// };

// int main()
// {
// 	string str("42");
// 	cout<<Solution().strToInt(str);
// 	return 0;
// }

// #include<iostream>
// #include<algorithm>
// #include<string>
// #include<vector>
// #include<unordered_map>
// using namespace std;

// class Solution
// {
// public:
// 	int findClosest(vector<string> &words, string word1, string word2)
// 	{
// 		unordered_map<string,vector<int>>flag;
// 		for(int i = 0;i < words.size();i++)
// 		{
// 			flag[words[i]].push_back(i);
// 		}
// 		int minlength = words.size();
// 		//可能查找的单词不存在
// 		if(flag.find(word1)==flag.end()|| flag.find(word2)==flag.end())
// 			return minlength;
// 		for(int i = 0,j = 0;i < flag[word1].size()&&j < flag[word2].size();)
// 		{
// 			if(flag[word1][i] == flag[word2][j])
// 				return 0;
// 			minlength = min(minlength,abs(flag[word1][i] - flag[word2][j]));
// 			flag[word1][i] > flag[word2][j]?j++:i++;
// 		}
// 		return minlength;
// 	}
// };
// int main()
// {
// 	vector<string>words{"I","am","a","student","from","a","university","in","a","city"};
// 	string word1("a"),word2("student");
// 	cout<<Solution().findClosest(words,word1,word2);
// 	return 0;
// }

// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// class Solution
// {

// public:
// 	int maxAliveYear(vector<int> &birth, vector<int> &death)
// 	{
// 		vector<int>arr(101,0);
// 		for(auto e: birth)
// 		{
// 			arr[e-1900]++;
// 		}
// 		for(auto e: death)
// 		{
// 			if(e-1900+1<arr.size())
// 				arr[e-1900+1]--;
// 		}
// 		//求每一年的人数
// 		int ret = 0;
// 		for(int i = 1;i < arr.size();i++)
// 		{
// 			arr[i]+=arr[i-1];
// 			if(arr[i]> arr[ret])
// 				ret = i;
// 		}
// 		return 1900+ret;
// 	}
// };

// int main()
// {
// 	vector<int>birth {1972,1908,1915,1957,1960,1948,1912,1903,1949,1977,1900,1957,1934,1929,1913,1902,1903,1901};
// 	vector<int>death {1997,1932,1963,1997,1983,2000,1926,1962,1955,1997,1998,1989,1992,1975,1940,1903,1983,1969};
// 	cout<<Solution().maxAliveYear(birth,death);
// 	return 0;
// }

// #include<iostream>
// #include<vector>
// using namespace std;
// class Solution
// {
// public:
// 	bool searchMatrix(vector<vector<int>> &matrix, int target)
// 	{
// 		if (matrix.size() == 0)
// 			return false;
// 		int i = 0, j = matrix[0].size() - 1;
// 		while (i < matrix.size() && j >= 0)
// 		{
// 			if (matrix[i][j] > target)
// 				j--;
// 			else if (matrix[i][j] < target)
// 				i++;
// 			else
// 				return true;
// 		}
// 		return false;
// 	}
// };

// int main()
// {
// 	return 0;
// }


// #include<iostream>
// #include<vector>
// #include<queue>
// using namespace std;

// struct TreeNode
// {
// 	int val;
// 	TreeNode *left;
// 	TreeNode *right;
// 	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

// struct ListNode
// {
// 	int val;
// 	ListNode *next;
// 	ListNode(int x) : val(x), next(NULL) {}
// };
// class Solution
// {
// public:
// 	vector<ListNode *> listOfDepth(TreeNode *tree)
// 	{
// 		queue<TreeNode *> q;
// 		q.push(tree);
// 		vector<ListNode *> ret;
// 		while (!q.empty())
// 		{
// 			int size = q.size();
// 			//size也就是当前层的节点数
// 			ListNode *head = new ListNode(0);
// 			ListNode *cur = head;
// 			for (int i = 0; i < size; i++)
// 			{
// 				TreeNode *node = q.front();
// 				q.pop();
// 				if (node->left != nullptr)
// 					q.push(node->left);
// 				if (node->right != nullptr)
// 					q.push(node->right);
// 				cur->next = new ListNode(node->val);
// 				cur = cur->next;
// 			}
// 			ret.push_back(head->next);
// 		}
// 		return ret;
// 	}
// };

// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;

// class Solution
// {
// public:
// 	void wiggleSort(vector<int> &nums)
// 	{
// 		if(nums.size()<2)
// 			return;
// 		sort(nums.begin(), nums.end());
// 		for(int i=1;i<nums.size()-1;i+=2)
// 		{
// 			swap(nums[i],nums[i+1]);
// 		}
// 	}
// };

// int main()
// {
// 	vector<int>nums{5, 3, 1, 2, 3};
// 	Solution().wiggleSort(nums);
// 	return 0;
// }

// #include<iostream>
// #include<string>
// #include<vector>
// using namespace std;
// class Solution {
// public:
//     vector<string> divideString(string s, int k, char fill) {
//         vector<string>ret;
// 		int flag = 0;
// 		string tmp;
// 		for(int i=0;i<s.size();i++)
// 		{
// 			tmp.push_back(s[i]);
// 			flag++;
// 			if(flag==k)
// 			{
// 				ret.push_back(tmp);
// 				tmp.clear();
// 				flag = 0;
// 			}
// 		}
// 		if(tmp.size()!=0)
// 		{
// 			while(tmp.size()!=k)
// 			{
// 				tmp.push_back(fill);
// 			}
// 			ret.push_back(tmp);
// 		}
// 		return ret;
//     }
// };

// //5194. 得到目标值的最少行动次数
// #include<iostream>
// using namespace std;
// class Solution
// {
// public:
// 	int minMoves(int target, int maxDoubles)
// 	{
// 		int count = 0;
// 		int tmp = 0;
// 		while (maxDoubles && target > 1)
// 		{
// 			if (target % 2)
// 				count++;
// 			target /= 2;
// 			maxDoubles--;
// 			count++;
// 		}
// 		count += target - 1;
// 		return count;
// 	}
// };

// int main()
// {
// 	return 0;
// }


// #include<iostream>
// #include<vector>
// using namespace std;

// void Prime(vector<bool> &number)
// {
// 	for (int i = 2; i < number.size(); i++)
// 	{
// 		if (number[i] == true)
// 		{
// 			for (int j = 2 * i; j < number.size(); j += i)
// 			{
// 				number[j] = false;
// 			}
// 		}
// 	}
// }

// int main()
// {
// 	vector<bool> number(100000, true);
// 	Prime(number);
// 	int k = 10;
// 	for (int i = 2; i < number.size() - 10; i++)
// 	{
// 		if (number[i] == true)
// 		{
// 			//公差值
// 			for (int z = 2; z < 1000; z++)
// 			{
// 				int j=0;
// 				for (j = 0; j < k; j++)
// 				{
// 					if (number[i + z * j] == false)
// 						break;
// 				}

// 				if (j == k)
// 				{
// 					cout << z << endl;
// 					return 0;
// 				}
// 			}
// 		}
// 	}
// 	return 0;
// }

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
	vector<vector<int>> levelOrder(TreeNode *root)
	{
		if (root == nullptr)
			return {};
		vector<vector<int>> ret;
		queue<TreeNode *> q;
		q.push(root);
		int flag = 0;
		while (!q.empty())
		{
			vector<int> tmp;
			int size = q.size();
			for (int i = 0; i < size; i++)
			{
				TreeNode *node = q.front();
				tmp.push_back(node->val);
				if (node->left != nullptr)
					q.push(node->left);
				if (node->right != nullptr)
					q.push(node->right);
				q.pop();
			}

			if (flag == 1)
				reverse(tmp.begin(), tmp.end());
			flag = flag == 0 ? 1 : 0;
			ret.push_back(tmp);
		}
		return ret;
	}
};