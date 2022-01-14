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

#include<iostream>
#include<vector>
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
	void InOrder(TreeNode* root,vector<int>&number)
	{
		if(root == nullptr)
			return;
		InOrder(root->left,number);
		number.push_back(root->val);
		InOrder(root->right,number);
	}
	bool isValidBST(TreeNode *root)
	{
		vector<int>number;
		InOrder(root,number);
		for(int i = 1;i<number.size();i++)
		{
			if(number[i]<=number[i-1])
				return false;
		}
		return true;
	}
};
