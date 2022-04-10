//#include <iostream>
//#include <queue>
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
//	int deepestLeavesSum(TreeNode* root)
//	{
//		if (root == nullptr)
//			return 0;
//		queue<TreeNode*>q;
//		q.push(root);
//		int prevSum = 0;
//		while (!q.empty())
//		{
//			int sz = q.size();
//			prevSum = 0;
//			while (sz)
//			{
//				if (q.front()->right != nullptr)
//					q.push(q.front()->right);
//				if (q.front()->left != nullptr)
//					q.push(q.front()->left);
//				prevSum += q.front()->val;
//				q.pop();
//				sz--;
//			}
//		}
//		return prevSum;
//	}
//};


//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Solution {
//public:
//	char nextGreatestLetter(vector<char>& letters, char target)
//	{
//		int left = 0, right = letters.size() - 1;
//		int mid = 0;
//		while (left < right)
//		{
//			mid = left + (right - left) / 2;
//			if (letters[mid] <= target)
//				left = mid + 1;
//			else if (letters[mid] > target)
//				right = mid;
//		}
//		return letters[right] <= target ? letters[0] : letters[right];
//	}
//};
//
//int main()
//{
//	vector<char>letters{ 'c','f','j' };
//	char target = 'f';
//	cout << Solution().nextGreatestLetter(letters, target);
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <math.h>
//#include <limits.h>
//using namespace std;
//
//void Approximation(vector<int>&nums, int n)
//{
//	for (int i = 2; i <= sqrt(n); i++)
//	{
//		if (n%i == 0) {
//			nums.push_back(i);
//			if (n / i != i)
//				nums.push_back(n / i);
//		}
//	}
//}
//
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	vector<int>nums(m + 1, INT_MAX);
//	nums[n] = 0;
//	for (int i = n; i < m; i++)
//	{
//		if (nums[i] != INT_MAX) {
//			//可以跳到当前位置
//			vector<int>flag;
//			Approximation(flag, i);
//			for (int j = 0; j < (int)flag.size(); j++)
//			{
//				if (i + flag[j] <= m) {
//					nums[i + flag[j]] = min(nums[i] + 1, nums[i + flag[j]]);
//				}
//			}
//		}
//	}
//	cout << (nums[m] == INT_MAX ? -1 : nums[m]) << endl;
//	return 0;
//}


//#include <iostream>
//#include <unordered_set>
//#include <algorithm>
//using namespace std;
//
//class Solution {
//public:
//	int longestConsecutive(vector<int>& nums)
//	{
//		unordered_set<int>s;
//		for (auto e : nums)
//			s.insert(e);
//		sort(nums.begin(), nums.end());
//		int i = 0;
//		int count = 0;
//		while (i < nums.size())
//		{
//			int j = 0;
//			int tmp = 0;
//			for (j = nums[i];; j++)
//			{
//				if (s.find(j) == s.end()) {
//					break;
//				}
//				tmp++;
//			}
//			count = max(count, tmp);
//			i += tmp;
//		}
//		return count;
//	}
//};


//#include <iostream>
//#include <string>
//#include <algorithm>
//#include <vector>
//#include <unordered_map>
//using namespace std;
//
//class Solution {
//public:
//	int largestInteger(int num) {
//		string tmp = to_string(num);
//		for (int i = 0; i < tmp.size(); i++)
//		{
//			//如果当前位置是偶数去后面找最大的偶数
//			for (int j = i + 1; j < (int)tmp.size(); j++)
//			{
//				if ((tmp[j] - '0') % 2 == (tmp[i] - '0') % 2)
//				{
//					if (tmp[i] < tmp[j])
//						swap(tmp[i], tmp[j]);
//				}
//			}
//		}
//		return stoi(tmp);
//	}
//};

//#include <iostream>
//using namespace std;
//class A 
//{
//public:
//	virtual ~A()
//	{
//		cout << "~A()" << endl;
//	}
//
//};
//
//class B :public A
//{
//public:
//	virtual ~B()
//	{
//		cout << "~B()" << endl;
//	}
//};
//
//int main()
//{
//	A* a = new A;
//	A* b = new B;
//	delete a;
//	delete b;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	virtual void Fun()
//	{
//		cout << "Fun()" << endl;
//	}
//
//	int _a = 0;
//};
//
//class B :public A
//{
//public:
//	virtual void Fun()
//	{
//		cout << "Fun()" << endl;
//	}
//	int _b = 0;
//};
//
//int main()
//{
//	A a;
//	B b;
//	return 0;
//}

//#include <iostream>
//#include <string>
//#include <vector>
//#include <unordered_set>
//using namespace std;
//
////class Solution {
////public:
////	int uniqueMorseRepresentations(vector<string>& words) {
////
////		vector<string>nums{ ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..",
////			"--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };
////		unordered_set<string>flag;
////		for (int i = 0; i < (int)words.size(); i++)
////		{
////			string tmp;
////			for (int j = 0; j < (int)words[i].size(); j++)
////			{
////				tmp += nums[words[i][j] - 'a'];
////			}
////			flag.insert(tmp);
////		}
////		return flag.size();
////	}
////};
//
////class Solution {
////public:
////	int arrangeCoins(int n)
////	{
////		long long prev = 0, i = 1;
////		for (; prev + i <= n; i++)
////		{
////			prev += i;
////		}
////		return i - 1;
////	}
////};


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int Find(const vector<int>&numbers, int left, int right, int target)
	{
		while (left <= right)
		{
			int mid = left + ((right - left) >> 1);
			if (numbers[mid] > target)
				right = mid - 1;
			else if (numbers[mid] < target)
				left = mid + 1;
			else
				return mid;
		}
		return -1;
	}
	vector<int> twoSum(vector<int>& numbers, int target)
	{
		for (int i = 0; i < (int)numbers.size(); i++)
		{
			int num = target - numbers[i];
			int pos = Find(numbers, i + 1, numbers.size() - 1, num);
			if (pos != -1)
				return { i + 1,pos + 1 };
		}
		return{ -1,-1 };
	}
};

int main()
{
	vector<int>numbers{ 2,3,4 };
	int target = 6;
	Solution().twoSum(numbers, target);
	return 0;
}