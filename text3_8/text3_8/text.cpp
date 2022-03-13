//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Solution {
//public:
//	int removeDuplicates(vector<int>& nums) {
//		if (nums.size() == 0)
//			return 0;
//		int prev = 0, cur = 1;
//		while (cur < nums.size())
//		{
//			if (nums[cur] != nums[prev]) {
//				nums[++prev] = nums[cur];
//			}
//			cur++;
//		}
//		return ++prev;
//	}
//};
//
//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//	vector<vector<int>> generate(int numRows) {
//		vector<vector<int>>ret;
//		for (int i = 0; i < numRows; i++)
//		{
//			ret.push_back(vector<int>(i + 1, 1));
//		}
//
//		for (int i = 0; i < numRows; i++)
//		{
//			for (int j = 1; j < i; j++)
//			{
//				ret[i][j] = ret[i - 1][j - 1] + ret[i - 1][j];
//			}
//		}
//		return ret;
//	}
//};

//#include<iostream>
//#include<vector>
//using namespace std;
//class Solution {
//public:
//	void BackTracking(int n, int index, int& count, vector<bool>&used)
//	{
//		if (index > n)
//		{
//			count++;
//			return;
//		}
//		for (int i = 1; i <= n; i++)
//		{
//			if (used[i] == true)
//				continue;
//			if (i % index == 0 || index % i == 0)
//			{
//				used[i] = true;
//				BackTracking(n, index + 1, count, used);
//				used[i] = false;
//			}
//		}
//	}
//
//	int countArrangement(int n) {
//		vector<bool>used(n + 1, false);
//		int count = 0;
//		BackTracking(n, 1, count, used);
//		return count;
//	}
//};
//
//int main()
//{
//	int n = 2;
//	cout << Solution().countArrangement(n);
//	return 0;
//}

//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//class Solution {
//public:
//	int pivotIndex(vector<int>& nums) {
//		vector<int>sum(nums.size(), 0);
//		sum[0] = nums[0];
//		for (int i = 1; i < nums.size(); i++)
//		{
//			sum[i] = sum[i - 1] + nums[i];
//		}
//		int prev = 0;
//		for (int i = (nums.size()) - 1; i >= 0; i--)
//		{
//			sum[i] -= prev + nums[i];
//			prev += nums[i];
//		}
//		auto pos = find(sum.begin(), sum.end(), 0);
//		return pos == sum.end() ? -1 : pos - sum.begin();
//	}
//};
//
//int main()
//{
//	vector<int>nums{ 1,7,3,6,5,6 };
//	cout << Solution().pivotIndex(nums);
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//struct ListNode {
//	int val;
//	ListNode *next;
//	ListNode(int x) : val(x), next(NULL) {}
//};
//
//class Solution {
//public:
//	void deleteNode(ListNode* node) {
//		node->val = node->next->val;
//		node->next = node->next->next;
//	}
//};

//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//class AnimalShelf {
//private :
//	queue<int>cat;
//	queue<int>dog;
//public:
//	AnimalShelf() {
//
//	}
//
//	void enqueue(vector<int> animal) {
//		if (animal[1] == 0)
//			cat.push(animal[0]);
//		else
//			dog.push(animal[0]);
//	}
//
//	vector<int> dequeueAny() {
//		if (dog.empty())
//			return dequeueCat();
//		else if (cat.empty())
//			return dequeueDog();
//		else if (cat.front() < dog.front())
//			return dequeueCat();
//		else
//			return dequeueDog();
//	}
//
//	vector<int> dequeueDog() {
//		if (dog.empty())
//			return { -1,-1 };
//		int num = dog.front();
//		dog.pop();
//		return { num,1 };
//	}
//
//	vector<int> dequeueCat() {
//		if (cat.empty())
//			return { -1,-1 };
//		int num = cat.front();
//		cat.pop();
//		return { num,0 };
//	}
//};


//#include<iostream>
//#include<string>
//#include<algorithm>
//using namespace std;
//
//class Solution {
//public:
//	int lengthOfLongestSubstring(string s) {
//		int arr[256] = { 0 };
//		int left = 0, right = 0;
//		int ret = 0;
//		while (right < s.size())
//		{
//			arr[s[right]]++;
//			while (left < right &&arr[s[right]] > 1)
//			{
//				arr[s[left++]]--;
//			}
//			ret = max(ret, right - left + 1);
//			right++;
//		}
//		return ret;
//	}
//};
//
//int main()
//{
//	string s{ "abcabcbb" };
//	cout << Solution().lengthOfLongestSubstring(s);
//	return 0;
//}

//#include<iostream>
//#include <unordered_map>
//#include<vector>
//#include <ctime>
//using namespace std;
//
//class RandomizedSet {
//private:
//	unordered_map<int,int> s;
//	vector<int>arr;
//public:
//	/** Initialize your data structure here. */
//	RandomizedSet() {
//		srand((unsigned)time(nullptr));
//	}
//
//	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
//	bool insert(int val) {
//		if (s.find(val) != s.end())
//			return false;
//		arr.push_back(val);
//		s.insert(make_pair(val, arr.size() - 1));
//		return true;
//	}
//
//	/** Removes a value from the set. Returns true if the set contained the specified element. */
//	bool remove(int val) {
//		if (s.find(val) == s.end())
//			return false;
//		int tmp = arr[arr.size() - 1];
//		swap(arr[s[val]], arr[arr.size() - 1]);
//		s[tmp] = s[val];
//		s.erase(val);
//		arr.pop_back();
//		return true;
//	}
//
//	/** Get a random element from the set. */
//	int getRandom() {
//		int pos = rand() % arr.size();
//		return arr[pos];
//	}
//};


//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//	int searchInsert(vector<int>& nums, int target) {
//		int left = 0, right = nums.size() - 1, mid = 0;
//		while (left <= right)
//		{
//			mid = left + (right - left) / 2;
//			if (nums[mid] == target)
//				return mid;
//			else if (nums[mid] > target)
//				right = mid - 1;
//			else
//				left = mid + 1;
//		}
//		return nums[mid] > target ? mid : mid + 1;
//	}
//};
//
//int main()
//{
//	vector<int>nums{ 1,3,5,6 };
//	int target = 2;
//	cout << Solution().searchInsert(nums, target);
//	return 0;
//}

////剑指 Offer II 119. 最长连续序列
//#include<iostream>
//#include<vector>
//#include<unordered_set>
//#include<algorithm>
//using namespace std;
//
//class Solution {
//public:
//	int longestConsecutive(vector<int>& nums) {
//		unordered_set<int>setnums;
//		for (auto e : nums)
//			setnums.insert(e);
//		int ret = 0;
//		for (auto e : setnums)
//		{
//			if (!setnums.count(e - 1))
//			{
//				int i = e + 1;
//				while (setnums.find(i) != setnums.end())
//				{
//					i++;
//				}
//				ret = max(ret, i - e);
//			}
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
//
////class Solution {
////public:
////	int MoreThanHalfNum_Solution(vector<int> numbers)
////	{
////		sort(numbers.begin(), numbers.end());
////		int end = numbers.size() / 2, i = 0;
////		while (end < numbers.size())
////		{
////			if (numbers[i] == numbers[end])
////				break;
////			i++;
////			end++;
////		}
////		return numbers[i];
////	}
////};
//
//class Solution {
//public:
//	int FindGreatestSumOfSubArray(vector<int> array) {
//		vector<int>dp(array.size(), 0);
//		dp[0] = array[0];
//		for (int i = 1; i < array.size(); i++)
//		{
//			dp[i] = max(array[i], dp[i - 1] + array[i]);
//		}
//		return *max_element(dp.begin(), dp.end());
//	}
//};


//#include<iostream>
//#include<vector>
//#include<stack>
//using namespace std;
//
//class Solution {
//public:
//	vector<int> dailyTemperatures(vector<int>& temperatures) {
//		vector<int>nums(temperatures.size(), 0);
//		int end = temperatures.size() - 2;
//		while (end >= 0)
//		{
//			for (int i = end + 1; i < nums.size(); i++)
//			{
//				if (temperatures[i] > temperatures[end])
//				{
//					nums[end] = i - end;
//					break;
//				}
//			}
//			end--;
//		}
//		return nums;
//	}
//};
//
//class Solution {
//public:
//	vector<int> dailyTemperatures(vector<int>& temperatures) {
//		vector<int>nums(temperatures.size(), 0);
//		stack<pair<int, int>>s;
//		for (int i = 0; i < temperatures.size(); i++)
//		{
//			if (s.empty())
//			{
//				s.push(make_pair(temperatures[i], i));
//				continue;
//			}
//			while (!s.empty() && temperatures[i] > s.top().first)
//			{
//				nums[s.top().second] = i - s.top().second;
//				s.pop();
//			}
//			s.push(make_pair(temperatures[i], i));
//		}
//		return nums;
//	}
//};
//
//int main()
//{
//	vector<int>temperatures{ 73, 74, 75, 71, 69, 72, 76, 73 };
//	Solution().dailyTemperatures(temperatures);
//	return 0;
//}
//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<unordered_set>
//using namespace std;

//class Solution {
//public:
//	vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
//		unordered_set<int>s;
//		for (int i = 0; i < nums.size(); i++)
//		{
//			if (nums[i] == key)
//			{
//				int left = (i - k) < 0 ? 0 : i - k;
//				int right = (i + k) >= nums.size() ? nums.size() - 1 : i + k;
//				for (int j = left; j <= right; j++)
//				{
//					if (abs(j - i) <= k)
//						s.insert(j);
//				}
//			}
//		}
//		vector<int>ret(s.begin(), s.end());
//		sort(ret.begin(), ret.end());
//		return  ret;
//	}
//};

//#include<iostream>
//#include<vector>
//#include<set>
//using namespace std;
//////暴力
////class Solution {
////public:
////	int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
////		vector<vector<int>>nums(n, vector<int>(n, 0));
////		for (int i = 0; i < dig.size(); i++)
////		{
////			nums[dig[i][0]][dig[i][1]] = 1;
////		}
////		int ret = 0;
////		for (int i = 0; i < artifacts.size(); i++)
////		{
////			int flag = 1;
////			for (int col = artifacts[i][1]; col <= artifacts[i][3]; col++)
////			{
////				for (int row = artifacts[i][0]; row <= artifacts[i][2]; row++)
////				{
////					if (nums[row][col] == 0)
////					{
////						flag = 0;
////						break;
////					}
////				}
////				if (flag == 0)
////					break;
////			}
////			if (flag == 1)
////				ret++;
////		}
////		return ret;
////	}
////};
//
//class Solution {
//public:
//	bool Check(const set<pair<int, int>>&s, vector<int>&nums)
//	{
//		int row = nums[0];
//		for (row; row <= nums[2]; row++)
//		{
//			int col = nums[1];
//			for (col; col <= nums[3]; col++)
//			{
//				if (s.find(make_pair(row, col)) == s.end())
//					return false;
//			}
//		}
//		return true;
//	}
//
//	int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
//		set<pair<int, int>>s;
//		for (auto& e : dig)
//		{
//			s.insert(make_pair(e[0], e[1]));
//		}
//		int ret = 0;
//		for (int i = 0; i < (int)artifacts.size(); i++)
//		{
//			if (Check(s, artifacts[i]))
//				ret++;
//		}
//		return ret;
//	}
//};
//
//int main()
//{
//	vector<vector<int>> artifacts{ {0,0,0,0},{0,1,1,1} };
//	vector<vector<int>> dig{ {0,0},{0,1} };
//	int n = 2;
//	Solution().digArtifacts(n, artifacts, dig);
//	return 0;
//}

//#include<iostream>
//#include<vector>
//#include<queue>
//#include <algorithm>
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
//	vector<int> largestValues(TreeNode* root)
//	{
//		if (root == nullptr)
//			return{};
//		queue<TreeNode*>q;
//		q.push(root);
//		vector<int>result;
//		while (!q.empty())
//		{
//			int sz = q.size();
//			int flag = INT_MIN;
//			TreeNode* cur = nullptr;
//			for (int i = 0; i < sz; i++)
//			{
//				cur = q.front();
//				q.pop();
//				flag = max(flag, cur->val);
//				if (cur->left)
//					q.push(cur->left);
//				if (cur->right)
//					q.push(cur->right);
//			}
//			result.push_back(flag);
//		}
//		return result;
//	}
//};

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//	vector<int>nums{ 2,5,5,2,4,1,6,5 };
//	sort(nums.begin(), nums.end());
//	//auto it = unique(nums.begin(), nums.end());
//
//	vector<int>result(10);//使用unique_copy，需要提前开好空间，去重的数组一定要有序。
//	auto it = unique_copy(nums.begin(), nums.end(), result.begin());
//
//	//auto start = nums.begin();
//	auto start = result.begin();
//	while (start != it)
//	{
//		cout << *start << " ";
//		start++;
//	}
//	return 0;
//}
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//	vector<int>nums{ 6,1,9,2,6,4 };
//	make_heap(nums.begin(), nums.end());
//	cout << "max:" << nums.front() << endl;
//	nums.push_back(99);
//	push_heap(nums.begin(), nums.end());//调整堆
//	pop_heap(nums.begin(), nums.end());//将堆顶元素和底部的元素交换，重新建堆（排序的过程）；
//	cout << "max:" << nums.front() << endl;
//	return 0;
//}

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//
//class Solution {
//public:
//	int findBottomLeftValue(TreeNode* root) {
//		if (root == nullptr)
//			return 0;
//		queue<TreeNode*>q;
//		q.push(root);
//		int ret = root->val;
//
//		while (!q.empty())
//		{
//			int sz = q.size();
//			for (int i = 0; i < sz; i++)
//			{
//				TreeNode* tmp = q.front();
//				if (i == 0)
//					ret = tmp->val;
//				q.pop();
//				if (tmp->left)
//					q.push(tmp->left);
//				if (tmp->right)
//					q.push(tmp->right);
//			}
//		}
//		return ret;
//	}
//};

class Solution {
public:
	vector<int> rightSideView(TreeNode* root) {
		if (root == nullptr)
			return {};
		queue<TreeNode*>q;
		vector<int>ret;
		q.push(root);
		while (!q.empty())
		{
			int sz = q.size();
			for (int i = 0; i < sz; i++)
			{
				TreeNode* cur = q.front();
				if (i == sz - 1)
					ret.push_back(cur->val);
				q.pop();
				if (cur->left)
					q.push(cur->left);
				if (cur->right)
					q.push(cur->right);
			}
		}
		return ret;
	}
};