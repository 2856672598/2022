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

#include<iostream>
#include <unordered_map>
#include<vector>
#include <ctime>
using namespace std;

class RandomizedSet {
private:
	unordered_map<int,int> s;
	vector<int>arr;
public:
	/** Initialize your data structure here. */
	RandomizedSet() {
		srand((unsigned)time(nullptr));
	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) {
		if (s.find(val) != s.end())
			return false;
		arr.push_back(val);
		s.insert(make_pair(val, arr.size() - 1));
		return true;
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) {
		if (s.find(val) == s.end())
			return false;
		int tmp = arr[arr.size() - 1];
		swap(arr[s[val]], arr[arr.size() - 1]);
		s[tmp] = s[val];
		s.erase(val);
		arr.pop_back();
		return true;
	}

	/** Get a random element from the set. */
	int getRandom() {
		int pos = rand() % arr.size();
		return arr[pos];
	}
};