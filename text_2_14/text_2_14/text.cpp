//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//	int singleNonDuplicate(vector<int>& nums) {
//		int ret = 0;
//		for (auto e : nums)
//		{
//			ret ^= e;
//		}
//		return ret;
//	}
//};
//
//int main()
//{
//	return 0;
//}

//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//class Solution {
//public:
//	static bool Comp(const vector<int>& nums1, const vector<int>& nums2)
//	{
//		return nums1[0] < nums2[0];
//	}
//	vector<vector<int>> merge(vector<vector<int>>& intervals) {
//		if (intervals.size() == 0)
//			return intervals;
//		sort(intervals.begin(), intervals.end(), Comp);
//		vector<vector<int>>ret;
//		vector<int>prev(intervals[0]);
//		int i = 1;
//		while (i < intervals.size())
//		{
//			if (intervals[i][0] <= prev[1])
//			{
//				prev[1] = max(intervals[i][1], prev[1]);
//			}
//			else
//			{
//				ret.push_back(prev);
//				prev = intervals[i];
//			}
//			i++;
//		}
//		ret.push_back(prev);
//		return ret;
//	}
//};
//
//int main()
//{
//	vector<vector<int>>nums{ {{1,4},{0,2},{3,5}} };
//	Solution().merge(nums);
//	return 0;
//}

////剑指 Offer II 076. 数组中的第 k 大的数字
//#include<iostream>
//#include<vector>
//#include<set>
//#include<algorithm>
//using namespace std;
//
//class Solution
//{
//public:
//	static bool Comp(int x, int y)
//	{
//		return x > y;
//	}
//	int findKthLargest(vector<int>& nums, int k)
//	{
//		if (nums.size() < k)
//			return 0;
//		sort(nums.begin(), nums.end(), Comp);
//		int ret = 0;
//		for (auto e : nums)
//		{
//			k--;
//			if (k == 0)
//			{
//				ret = e;
//				break;
//			}
//		}
//		return ret;
//	}
//};
//
//int main()
//{
//	vector<int>nums{ 3,2,3,1,2,4,5,5,6 };
//	int k = 4;
//	cout << Solution().findKthLargest(nums, k);
//	return 0;
//}


//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
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
//	ListNode* sortList(ListNode* head) {
//		vector<int>nums;
//		ListNode* cur = head;
//		while (cur)
//		{
//			nums.push_back(cur->val);
//			cur = cur->next;
//		}
//		sort(nums.begin(), nums.end());
//		ListNode* newhead = new ListNode;
//		cur = newhead;
//		for (int i = 0; i < nums.size(); i++)
//		{
//			cur->next = new ListNode(nums[i]);
//			cur = cur->next;
//		}
//		cur = newhead->next;
//		delete newhead;
//		return cur;
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
//class Solution {
//public:
//	int lenLongestFibSubseq(vector<int>& arr) {
//
//		int ret = 0;
//		for (int i = 0; i < arr.size() - 1; i++)
//		{
//			for (int j = i + 1; j < arr.size(); j++)
//			{
//				int prev = arr[i], cur = arr[j];
//				if ((prev + cur) <= arr[arr.size() - 1])
//				{
//					int count = 2;
//					while (true)
//					{
//						if (find(arr.begin(), arr.end(), (prev + cur)) != arr.end())
//						{
//							int tmp = prev + cur;
//							prev = cur;
//							cur = tmp;
//							count++;
//						}
//						else
//							break;
//					}
//					ret = max(ret, count);
//				}
//			}
//		}
//		return ret == 2 ? 0 : ret;
//	}
//};
//
//int main()
//{
//	vector<int>nums{ 2,4,7,8,9,10,14,15,18,23,32 };
//	cout << Solution().lenLongestFibSubseq(nums);
//	return 0;
//}

//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//
//class Solution {
//public:
//	//中心拓展
//	int countSubstrings(string s)
//	{
//		int count = 0;
//		for (int i = 0; i < s.size(); i++)
//		{
//			for (int j = 0; j < 2; j++)
//			{
//				int left = i, right = i + j;
//				while (left >= 0 && right < s.size())
//				{
//					if (s[left--] != s[right++])
//						break;
//					count++;
//				}
//			}
//		}
//		return count;
//	}
//};
//
//int main()
//{
//	string s{ "aaaaa" };
//	cout << Solution().countSubstrings(s);
//	return 0;
//}

//#include<iostream>
//#include<string>
//#include<algorithm>
//using namespace std;
//class Solution {
//public:
//	string longestPalindrome(string s) {
//		string ret;
//		for (int i = 0; i < s.size(); i++)
//		{
//			for (int j = 0; j < 2; j++)
//			{
//				int left = i, right = i + j;
//				int count = 0;
//				while (left >= 0 && right < s.size())
//				{
//					if (s[left] != s[right])
//						break;
//					count = right - left + 1;
//					left--;
//					right++;
//				}
//				if (left + 1 < s.size() && count > ret.size())
//				{
//					ret.resize(0);
//					ret = s.substr(left + 1, count);
//				}
//				count = 1;
//			}
//		}
//		return ret;
//	}
//};
//
//int main()
//{
//	string s{ "babad" };
//	cout << Solution().longestPalindrome(s) << endl;
//	return 0;
//}

//#include<iostream>
//#include<vector>
//#include<unordered_map>
//using namespace std;
//
//class Solution {
//public:
//	int subarraySum(vector<int>& nums, int k) {
//		unordered_map<int, int> m;
//		int sum = 0;
//		int count = 0;
//		m[0] = 1;
//		for (int i = 0; i < nums.size(); i++)
//		{
//			sum += nums[i];
//			if (m.find(sum - k) != m.end())
//			{
//				count += m[sum - k];
//			}
//			m[sum]++;
//		}
//		return count;
//	}
//};
//int main()
//{
//	vector<int>nums{ 0,0,0,0 };
//	int k = 0;
//	cout << Solution().subarraySum(nums, k);
//	return 0;
//}

//#include<iostream>
//#include<vector>
//#include<unordered_map>
//using namespace std;
//
//class Solution {
//public:
//	bool checkSubarraySum(vector<int>& nums, int k) {
//		unordered_map<int,int>m;
//		m[0] = -1;
//		int sum = 0;
//		for (int i = 0; i < nums.size(); i++)
//		{
//			sum = (sum + nums[i]) % k;
//			if (m.find(sum) != m.end())
//			{
//				if (i - m[sum] >= 2)
//					return true;
//			}
//			else
//				m[sum] = i;
//		}
//		return false;
//	}
//};
//
//int main()
//{
//	vector<int>nums{ 1,0,0 };
//	int k = 6;
//	cout << Solution().checkSubarraySum(nums, k);
//	return 0;
//}

//#include<iostream>
//#include<vector>
//#include<unordered_map>
//#include<algorithm>
//using namespace std;
//
//class Solution {
//public:
//	int findMaxLength(vector<int>& nums) {
//		unordered_map<int, int>m;
//		int sum = 0;
//		int count = 0;
//		m[0] = -1;
//		for (int i = 0; i < nums.size(); i++)
//		{
//			if (nums[i] == 0)
//				sum -= 1;
//			else
//				sum += 1;
//			if (m.find(sum) != m.end())
//			{
//				count = max(count, i - m[sum]);
//			}
//			else
//				m[sum] = i;
//		}
//		return count;
//	}
//};
//
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//bool Check(int x)
//{
//	int day = x % 100;
//	x /= 100;
//	int month = x % 100;
//	x /= 100;
//	int year = x;
//	if (day <= 0 || day > 31 || month == 0 || month > 12)
//		return false;
//	int m[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
//		m[2] = 29;
//	if (day > m[month])
//		return false;
//	return true;
//}
//int main()
//{
//	int n = 0;
//	cin >> n;
//	int flag = 1;
//	for (int i = n+1; i <= 89991231; i++)
//	{
//		if (!Check(i))
//			continue;
//		//先判断是不是回文;
//		int j = i;
//		vector<int>tmp;
//		while (j)
//		{
//			tmp.push_back(j % 10);
//			j /= 10;
//		}
//		int left = 0, right = 7;
//		while (left <= right)
//		{
//			if (tmp[left] != tmp[right])
//				break;
//			left++;
//			right--;
//		}
//		if (left > right)
//		{
//			if (flag == 1)
//			{
//				cout << i << endl;
//				flag = 0;
//			}
//			if (tmp[0] == tmp[2] && tmp[1] == tmp[3])
//			{
//				cout << i << endl;
//				break;
//			}
//		}
//	}
//	return 0;
//}


//#include<iostream>
//#include<cstdio>
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	int max = 0, min = 100, tmp = 0, sum = 0;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> tmp;
//		if (tmp > max)
//			max = tmp;
//		else if (tmp < min)
//			min = tmp;
//		sum += tmp;
//	}
//	cout << max << endl << min << endl;
//	printf("%.2lf", sum*1.0 / n);
//}

//#include<iostream>
//#include<unordered_set>
//#include<string>
//using namespace std;
//
//int main()
//{
//	string s;
//	cin >> s;
//	int sum = 0;
//	for (int i = 0; i < s.size(); i++)
//	{
//		unordered_set<char>nums;
//		for (int j = i; j < s.size(); j++)
//		{
//			nums.insert(s[j]);
//			sum += nums.size();
//		}
//	}
//	cout << sum << endl;
//	return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//
//class Solution {
//public:
//	int _translateNum(string& s, int i)
//	{
//		if (i == s.size())
//			return 1;
//		if (s[i] == '1')
//		{
//			int count = _translateNum(s, i + 1);
//			if (i + 1 < s.size())
//				count += _translateNum(s, i + 2);
//			return count;
//		}
//		if (s[i] == '2')
//		{
//			int count = _translateNum(s, i + 1);
//			if (i + 1 < s.size() && s[i + 1] <= '5')
//				count += _translateNum(s, i + 2);
//			return count;
//		}
//		return _translateNum(s, i + 1);
//	}
//
//	int translateNum(int num) {
//		string nums = to_string(num);
//		return  _translateNum(nums, 0);
//	}
//};
//int main()
//{
//	int num = 25;
//	cout << Solution().translateNum(num);
//	return 0;
//}


//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//	bool dfs(const vector<int>& nums, int target, int index)
//	{
//		if (target < 0 || index >= nums.size())
//			return false;
//		if (target == 0)
//			return true;
//		return dfs(nums, target - nums[index], index + 1)
//			|| dfs(nums, target, index + 1);
//	}
//
//	bool canPartition(vector<int>& nums) {
//		int sum = 0;
//		for (auto e : nums)
//			sum += e;
//		if (sum % 2)
//			return false;
//		return dfs(nums, sum / 2, 0);
//	}
//};
//
//int main()
//{
//	return 0;
//}


