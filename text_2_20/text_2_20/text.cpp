//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//class Solution {
//public:
//	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
//	{
//		vector<vector<int>>ret;
//		int i = 0;
//		//重叠区域的左边
//		while (i < intervals.size() && intervals[i][1] < newInterval[0])
//		{
//			ret.push_back(intervals[i]);
//			i++;
//		}
//		int left = newInterval[0], right = newInterval[1];
//		//重叠区域
//		while (i < intervals.size() && intervals[i][0] <= newInterval[1])
//		{
//			left = min(left, intervals[i][0]);
//			right = max(right, intervals[i][1]);
//			i++;
//		}
//		ret.push_back({ left,right });
//		while (i < intervals.size())
//		{
//			ret.push_back(intervals[i]);
//			i++;
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
//using namespace std;
//
//class Solution {
//public:
//	int countPairs(vector<int>& nums, int k) {
//		int count = 0;
//		for (int i = 0; i < nums.size(); i++)
//		{
//			for (int j = i + 1; j < nums.size(); j++)
//			{
//				if (nums[i] == nums[j])
//				{
//					if ((i*j) % k == 0)
//						count++;
//				}
//			}
//		}
//		return count;
//	}
//};
//
//int main()
//{
//	vector<int>nums{ 3,1,2,2,2,1,3 };
//	int k = 2;
//	cout << Solution().countPairs(nums, k);
//	return 0;
//}

//#include<iostream>
//#include<vector>
//using namespace std;
//class Solution {
//public:
//	vector<long long> sumOfThree(long long num)
//	{
//		if (num % 3 != 0)
//			return {};
//		long long  ret = num / 3;
//		return { ret - 1,ret,ret + 1 };
//	}
//};
//
//int main()
//{
//	long long num = 6675975537;
//	Solution().sumOfThree(num);
//	return 0;
//}

//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//	vector<long long> maximumEvenSplit(long long finalSum) {
//		if (finalSum % 2)
//			return {};
//		long long prev = 0, cur = 0, sum = 0;
//		vector<long long>ret;
//		while (sum < finalSum)
//		{
//			cur = prev + 2;
//			if (sum + cur > finalSum)
//			{
//				if (count(ret.begin(), ret.end(), finalSum - sum))
//				{
//					long long tmp = finalSum - sum + ret.back();
//					ret.pop_back();
//					ret.push_back(tmp);
//				}
//				else
//					ret.push_back(finalSum - sum);
//				break;
//			}
//			ret.push_back(cur);
//			prev = cur;
//			sum += cur;
//		}
//		return ret;
//	}
//};
//int main()
//{
//	long long finalSum = 8;
//	Solution().maximumEvenSplit(finalSum);
//	return 0;
//}

//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//
//int main()
//{
//	string str;
//	while (cin >> str)
//	{
//		int arr[256] = { 0 };
//		for (int i = 0; i < str.size(); i++)
//		{
//			arr[str[i]]++;
//		}
//		int flag = 1;
//		for (auto e : str)
//		{
//			if (arr[e] == 1)
//			{
//				cout << e << endl;
//				flag = 0;
//				break;
//			}
//		}
//		if (flag == 1)
//			cout << -1 << endl;
//	}
//	return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//
//class Solution {
//public:
//	string reverseWords(string s)
//	{
//		int left = 0, right = 0;
//		while (right <= s.size())
//		{
//			if (s[right] == ' ' || right == s.size())
//			{
//				reverse(s.begin() + left, s.begin() + right);
//				right++;
//				left = right;
//			}
//			else
//				right++;
//		}
//		return s;
//	}
//};

//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//	int countEven(int num) {
//		int count = 0;
//		for (int i = 2; i <= num; i++)
//		{
//			int tmp = i;
//			int sum = 0;
//			while (tmp)
//			{
//				sum += tmp % 10;
//				tmp /= 10;
//			}
//			if (sum > num)
//				break;
//			if (sum % 2 == 0)
//				count++;
//		}
//		return count;
//	}
//};
//
//int main()
//{
//	int num = 30;
//	cout << Solution().countEven(num);
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
//	ListNode* mergeNodes(ListNode* head)
//	{
//		ListNode* newhead = new ListNode;
//		ListNode* cur = head;
//		ListNode* prev = newhead;
//		int sum = 0;
//		while (cur != nullptr)
//		{
//			if (cur->val == 0 && sum != 0)
//			{
//				prev->next = new ListNode(sum);
//				sum = 0;
//				prev = prev->next;
//			}
//			else
//			{
//				sum += cur->val;
//			}
//			cur = cur->next;
//		}
//		return newhead->next;
//	}
//};

//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//class Solution {
//public:
//	string repeatLimitedString(string s, int repeatLimit)
//	{
//		vector<int>arr(26, 0);
//		for (auto e : s)
//		{
//			arr['z' - e]++;
//		}
//		string ret;
//		for (int i = 0; i < 26; i++)
//		{
//			while (arr[i] != 0)
//			{
//				int n = arr[i] <= repeatLimit ? arr[i] : repeatLimit;
//				arr[i] -= n;
//				ret.append(n, ('z' - i));
//				if (arr[i] == 0)
//					break;
//				//找次大的；
//				int j = i + 1;
//				while (j < 26 && arr[j] == 0)
//					j++;
//				if (j == 26)
//					return ret;
//				ret.push_back('z' - j);
//				arr[j] -= 1;
//			}
//		}
//		return ret;
//	}
//};
//
//int main()
//{
//	string s("cczazcc");
//	int k = 3;
//	cout << Solution().repeatLimitedString(s, k);
//	return 0;
//}

////438. 找到字符串中所有字母异位词
//#include<iostream>
//#include<vector>
//#include<unordered_map>
//using namespace std;
//
//class Solution {
//public:
//	vector<int> findAnagrams(string s, string p)
//	{
//		if (p.size() > s.size())
//			return {};
//		vector<int>nums(26, 0), flag(26, 0);
//		int i = 0;
//		for (i = 0; i < p.size(); i++)
//		{
//			nums[s[i] - 'a'] ++;
//			flag[p[i] - 'a']++;
//		}
//		vector<int>ret;
//		if (nums == flag)
//			ret.push_back(0);
//		int left = 0, right = i;
//		while (right < s.size())
//		{
//			nums[s[left++] - 'a']--;
//			nums[s[right++] - 'a']++;
//			if (nums == flag)
//				ret.push_back(left);
//		}
//		return ret;
//	}
//};
//int main()
//{
//	string s("abab"), p("ab");
//	Solution().findAnagrams(s, p);
//	return 0;
//}


//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//class Solution {
//public:
//	int findUnsortedSubarray(vector<int>& nums)
//	{
//		if (nums.size() == 1)
//			return 0;
//		vector<int>tmp = nums;
//		sort(tmp.begin(), tmp.end());
//		int left = 0, right = nums.size() - 1;
//		while (left < right)
//		{
//			if (nums[left] != tmp[left] && nums[right] != tmp[right])
//				break;
//			if (nums[left] == tmp[left])
//				left++;
//			if (nums[right] == tmp[right])
//				right--;
//		}
//		return left == right ? 0 : right - left + 1;
//	}
//};
//
//int main()
//{
//	vector<int>nums{ 1,2,3,3,3 };
//	cout << Solution().findUnsortedSubarray(nums);
//	return 0;
//}

//#include<iostream>
//#include<vector>
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
//	ListNode* partition(ListNode* head, int x)
//	{
//		vector<int>nums;
//		ListNode newhead(0);
//		ListNode* prev = &newhead, *cur = head;
//		while (cur)
//		{
//			if (cur->val < x)
//			{
//				prev->next = new ListNode(cur->val);
//				prev = prev->next;
//			}
//			else
//				nums.push_back(cur->val);
//			cur = cur->next;
//		}
//		for (int i = 0; i < nums.size(); i++)
//		{
//			prev->next = new ListNode(nums[i]);
//			prev = prev->next;
//		}
//		return newhead.next;
//	}
//};

//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//class Solution
//{
//public:
//	int BackTracking(const vector<int>&v, const vector<int>&w, int volnme, int index)
//	{
//		if (index == v.size() || volnme < 0)
//			return 0;
//		int p1 = BackTracking(v, w, volnme, index+1);
//		int p2 = 0;
//		if (volnme - v[index] >= 0)
//			p2 = BackTracking(v, w, volnme - v[index], index + 1) + w[index];
//		return max(p1, p2);
//	}
//};
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	vector<int>v(n, 0), w(n, 0);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> v[i] >> w[i];
//	}
//	cout << Solution().BackTracking(v, w, m, 0);
//	return 0;
//}

//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	vector<int>v(n, 0), w(n, 0);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> v[i] >> w[i];
//	}
//	vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));
//
//	for (int i = 1; i < dp.size(); i++)
//	{
//		for (int j = 1; j < dp[i].size(); j++)
//		{
//			if (v[i - 1] > j)
//				dp[i][j] = dp[i - 1][j];
//			else
//				dp[i][j] = max(dp[i-1][j], dp[i - 1][j - v[i-1]] + w[i-1]);
//		}
//	}
//	cout << dp[n][m] << endl;
//	return 0;
//}

//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//	int fib(int n) {
//		vector<int>f(31, 0);
//		f[1] = 1;
//		for (int i = 2; i <= n; i++)
//		{
//			f[i] = f[i - 1] + f[i - 2];
//		}
//		return f[n];
//	}
//};
//
//int main()
//{
//	int n = 4;
//	cout << Solution().fib(n);
//	return 0;
//}

//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//	int tribonacci(int n)
//	{
//		vector<int>f(38, 0);
//		f[1] = f[2] = 1;
//		for (int i = 3; i <= n; i++)
//		{
//			f[i] = f[i - 1] + f[i - 2] + f[i - 3];
//		}
//		return f[n];
//	}
//};
//
//int main()
//{
//	int n = 0;
//	cout << Solution().tribonacci(n);
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Solution {
//public:
//	int count = 0;
//	void Backtracking(int n)
//	{
//		if (n <= 0)
//		{
//			if (n == 0)
//				count++;
//			return;
//		}
//		Backtracking(n - 1);
//		Backtracking(n - 2);
//	}
//
//	int climbStairs(int n)
//	{
//		Backtracking(n);
//		return count;
//	}
//};
//
//int main()
//{
//	int n = 3;
//	cout << Solution().climbStairs(n);
//	return 0;
//}

//#include<iostream>
//#include<vector>
//using namespace std;
//class Solution {
//public:
//	int climbStairs(int n) {
//		vector<int>dp(n + 1, 0);
//		dp[0] = 1;
//		dp[1] = 1;
//		for (int i = 2; i <= n; i++)
//		{
//			dp[i] = dp[i - 1] + dp[i - 2];
//		}
//		return dp[n];
//	}
//};
//
//int main()
//{
//	int n = 1;
//	cout << Solution().climbStairs(n);
//	return 0;
//}

//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//class Solution {
//public:
//	int minCostClimbingStairs(vector<int>& cost) {
//		vector<int>dp(cost.size() + 1, 0);
//		for (int i = 2; i <= cost.size(); i++)
//		{
//			dp[i] = min(dp[i - 2] + cost[i - 2], dp[i - 1] + cost[i - 1]);
//		}
//		return dp[cost.size()];
//	}
//};
//
//int main()
//{
//	vector<int>nums{ 1,100,1,1,1,100,1,1,100,1 };
//	cout << Solution().minCostClimbingStairs(nums);
//	return 0;
//}

//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//class Solution {
//public:
//	int rob(vector<int>& nums) {
//		if (nums.size() == 1)
//			return nums[0];
//		vector<int>dp(nums.size(), 0);
//		dp[0] = nums[0];
//		dp[1] = max(nums[0], nums[1]);
//		//偷还是不偷
//		for (int i = 2; i < nums.size(); i++)
//		{
//			dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
//		}
//		return dp[nums.size() - 1];
//	}
//};
//
//int main()
//{
//	vector<int>nums{ 2,7,9,3,1,4,1,7 };
//	cout << Solution().rob(nums);
//	return 0;
//}


//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//class Solution {
//public:
//	int _rob(vector<int>&nums, int begin, int end)
//	{
//		if (begin == end)
//			return nums[begin];
//		if (end - begin == 1)
//			return max(nums[begin], nums[end]);
//		vector<int>dp(nums.size() + 1, 0);
//		dp[begin] = nums[begin];
//		dp[begin + 1] = max(nums[begin], nums[begin + 1]);
//		for (int i = begin + 2; i <= end; i++)
//		{
//			dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
//		}
//		return dp[end];
//	}
//
//	int rob(vector<int>& nums) {
//		if (nums.size() == 0)
//			return 0;
//		return max(_rob(nums, 0, nums.size() - 2), _rob(nums, 1, nums.size() - 1));
//	}
//};
//
//int main()
//{
//	vector<int>nums{ 1,2,3,1 };
//	cout << Solution().rob(nums);
//	return 0;
//}


//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//class Solution {
//public:
//	int _deleteAndEarn(const vector<int>& nums)
//	{
//		vector<int>dp(nums.size(), 0);
//		dp[0] = nums[0];
//		dp[1] = max(nums[1], nums[0]);
//		if (nums.size() <= 2)
//			return dp[nums.size() - 1];
//
//		for (int i = 2; i < nums.size(); i++)
//		{
//			dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
//		}
//		return dp[nums.size() - 1];
//	}
//
//	int deleteAndEarn(vector<int>& nums) {
//		int maxnum = 0;
//		for (auto e : nums)
//			maxnum = max(maxnum, e);
//		vector<int>arr(maxnum + 1, 0);
//		for (int i = 0; i < nums.size(); i++)
//		{
//			arr[nums[i]] += nums[i];
//		}
//		return _deleteAndEarn(arr);
//	}
//};
//
//int main()
//{
//	vector<int>nums{ 3,2,4 };
//	cout << Solution().deleteAndEarn(nums);
//	return 0;
//}

//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//class Solution {
//public:
//	int maxSubArray(vector<int>& nums)
//	{
//		vector<int>dp(nums.size(), 0);
//		dp[0] = nums[0];
//		for (int i = 1; i < nums.size(); i++)
//		{
//			dp[i] = max(dp[i - 1] + nums[i], nums[i]);
//		}
//		int ret = dp[0];
//		for (auto e : dp)
//			ret = max(e, ret);
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
//	int minCost(vector<vector<int>>& costs)
//	{
//		vector<vector<int>>dp(3, vector<int>(costs.size(), 0));
//		dp[0][0] = costs[0][0];
//		dp[1][0] = costs[0][1];
//		dp[2][0] = costs[0][2];
//		for (int i = 1; i < costs.size(); i++)
//		{
//			dp[0][i] = min(dp[1][i - 1], dp[2][i - 1]) + costs[i][0];
//			dp[1][i] = min(dp[0][i - 1], dp[2][i - 1]) + costs[i][1];
//			dp[2][i] = min(dp[0][i - 1], dp[1][i - 1]) + costs[i][2];
//		}
//		return min(min(dp[0][costs.size() - 1], dp[1][costs.size() - 1])
//			, dp[2][costs.size() - 1]);
//	}
//};
//
//int main()
//{
//	vector<vector<int>>costs{ {17,2,17},{16,16,5},{14,3,19} };
//	cout << Solution().minCost(costs) << endl;
//	return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//
//class Solution {
//public:
//	string reverseOnlyLetters(string s) {
//
//		int left = 0, right = s.size() - 1;
//		while (left < right)
//		{
//			//左边找字母
//			while (left < right)
//			{
//				if (isalpha(s[left]))
//					break;
//				left++;
//			}
//
//			//右面找
//			while (left < right)
//			{
//				if (isalpha(s[right]))
//					break;
//				right--;
//			}
//			if (left < right)
//				swap(s[left], s[right]);
//			left++, right--;
//		}
//		return s;
//	}
//};
//
//int main()
//{
//	string s{ "ab-cd" };
//	cout << Solution().reverseOnlyLetters(s);
//	return 0;
//}

//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//class Solution {
//public:
//	int minimumTotal(vector<vector<int>>& triangle) {
//		vector<vector<int>>dp(triangle.size());
//		dp[0].push_back(triangle[0][0]);
//		for (int i = 1; i < triangle.size(); i++)
//		{
//			for (int j = 0; j < triangle[i].size(); j++)
//			{
//				if (j == 0)
//					dp[i].push_back(dp[i - 1][j] + triangle[i][j]);
//				else if (j == triangle[i].size() - 1)
//					dp[i].push_back(dp[i - 1][j - 1] + triangle[i][j]);
//				else
//					dp[i].push_back(min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j]);
//			}
//		}
//		int ret = INT_MAX;
//		for (int i = 0; i < dp[triangle.size() - 1].size(); i++)
//		{
//			ret = min(ret, dp[triangle.size() - 1][i]);
//		}
//		return ret;
//	}
//};
//
//int main()
//{
//	vector<vector<int>>triangle{ { {-10}} };
//	cout << Solution().minimumTotal(triangle);
//	return 0;
//}

//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//	int uniquePaths(int m, int n) {
//		vector<vector<int>>dp(n, vector<int>(m));
//		for (int i = 0; i < m; i++)
//		{
//			dp[0][i] = 1;
//		}
//		for (int i = 0; i < n; i++)
//			dp[i][0] = 1;
//
//		for (int i = 1; i < n; i++)
//		{
//			for (int j = 1; j < m; j++)
//			{
//				dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
//			}
//		}
//		return dp[n - 1][m - 1];
//	}
//};
//
//int main()
//{
//	return 0;
//}

