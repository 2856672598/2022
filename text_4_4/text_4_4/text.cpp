//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Solution {
//public:
//	int searchInsert(vector<int>& nums, int target) {
//		int left = 0, right = nums.size() - 1, mid = 0;
//		while (left <= right)
//		{
//			mid = left + (right - left) / 2;
//			if (nums[mid] > target) {
//				right = mid - 1;
//			}
//			else if (nums[mid] < target)
//				left = mid + 1;
//			else return mid;
//		}
//		return nums[mid] < target ? mid + 1 : mid;
//	}
//};
//
//int main()
//{
//	vector<int>nums{ 1,3 };
//	cout << Solution().searchInsert(nums, 2);
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//class Solution {
//public:
//	int maxValue(vector<vector<int>>& grid)
//	{
//		vector<vector<int>>flag(grid);
//		for (int i = 1; i < (int)grid[0].size(); i++)
//			flag[0][i] += flag[0][i - 1];
//		for (int i = 1; i < (int)grid.size(); i++)
//			flag[i][0] += flag[i - 1][0];
//
//		for (int i = 1; i < (int)flag.size(); i++)
//		{
//			for (int j = 1; j < (int)flag[0].size(); j++)
//			{
//				flag[i][j] += max(flag[i - 1][j], flag[i][j - 1]);
//			}
//		}
//		return flag[grid.size() - 1][grid[0].size() - 1];
//	}
//};

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
////class Solution {
////public:
////	int Backtracking(vector<int>&A, int m, int bag, int index)
////	{
////		if (index == A.size() || bag > m)
////			return 0;
////		int p1 = 0, p2 = 0;
////		//当前物品要
////		if (bag + A[index] <= m)
////			p1 = Backtracking(A, m, bag + A[index], index + 1) + A[index];
////		p2 = Backtracking(A, m, bag, index + 1);
////		return max(p1, p2);
////	}
////	int backPack(int m, vector<int> &A)
////	{
////		return Backtracking(A, m, 0, 0);
////	}
////};
//
//class Solution {
//public:
//	int backPack(int m, vector<int> &A) {
//		vector<vector<int>>flag(A.size() + 1, vector<int>(m + 1, 0));
//		for (int i = A.size() - 1; i >= 0; i--)
//		{
//			for (int j = 0; j <= m; j++)
//			{
//				int p1 = 0, p2 = 0;
//				if (j + A[i] <= m)
//					p1 = A[i] + flag[i + 1][j + A[i]];
//				p2 = flag[i + 1][j];
//				flag[i][j] = max(p1, p2);
//			}
//		}
//		return flag[0][0];
//	}
//};
//
//int main()
//{
//	vector<int>nums{ 3,4,8,5 };
//	cout << Solution().backPack(10, nums);
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
////暴力
//int way1(const vector<vector<int>>&flag, int index, int over)
//{
//	if (index == flag.size() || over < 0)
//		return 0;
//	int p1 = 0, p2 = 0;
//	//要当前位置
//	if (over - flag[index][0] >= 0) {
//		p1 = way1(flag, index + 1, over - flag[index][0]) + flag[index][1];
//	}
//	//不要当前位置
//	p2 = way1(flag, index + 1, over);
//	return max(p1, p2);
//}
//
//
//int way2(const vector<vector<int>>&flag, int index, int over)
//{
//	vector<vector<int>>nums(flag.size() + 1, vector<int>(over + 1, 0));
//	for (int i = flag.size() - 1; i >= 0; i--)
//	{
//		for (int j = 0; j <= over; j++)
//		{
//			int p1 = 0, p2 = 0;
//			if (j - flag[i][0] >= 0)
//				p1 = nums[i + 1][j - flag[i][0]] + flag[i][1];
//			p2 = nums[i + 1][j];
//			nums[i][j] = max(p1, p2);
//		}
//	}
//	return nums[0][over];
//}
//
//
//int main()
//{
//	int n, v;
//	cin >> n >> v;
//	vector < vector<int >> flag(n, vector<int>(2, 0));
//	for (int i = 0; i < n; i++)
//	{
//		cin >> flag[i][0] >> flag[i][1];
//	}
//
//	cout << way2(flag, 0, v);
//	return 0;
//}

//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//class Solution {
//public:
//	int way(const string& s, int index)
//	{
//		//当前方法可以
//		if (index >= s.size())
//			return 1;
//		if (s[index] == '0')
//			return 0;
//		int result = 0;
//		if (index + 1 < s.size() && (s[index] - '0') * 10 + s[index + 1] - '0' <= 26)
//		{
//			result += way(s, index + 2);
//		}
//		return result += way(s, index + 1);
//	}
//
//	//int numDecodings(string s) {
//	//	return way(s, 0);
//	//}
//
//	int numDecodings(string s) {
//		vector<int>dp(s.size() + 1);
//		dp[s.size()] = 1;
//		for (int i = s.size() - 1; i >= 0; i--)
//		{
//			if (s[i] != '0')
//			{
//				int result = 0;
//				if (i + 1 < s.size() && (s[i] - '0') * 10 + s[i + 1] - '0' <= 26)
//					result = dp[i + 2];
//				dp[i] = result + dp[i + 1];
//			}
//		}
//		return dp[0];
//	}
//};
//
//int main()
//{
//	string str = "27";
//	cout << Solution().numDecodings(str);
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//class Solution {
//public:
//	int getMaximumGenerated(int n) {
//		if (n == 0)
//			return 0;
//		vector<int>nums(n + 1);
//		nums[1] = 1;
//		for (int i = 2; i <= n; i++)
//		{
//			nums[i] = nums[i / 2];
//			if (i % 2)
//				nums[i] += nums[i / 2 + 1];
//		}
//		return *max_element(nums.begin(), nums.end());
//	}
//};
//int main()
//{
//	int n = 15;
//	cout << Solution().getMaximumGenerated(n);
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//class Solution {
//public:
//	int Backtracking(const string& s, int n, int index)
//	{
//		if (n == 0) {
//			return 1;
//		}
//		int result = 0;
//		for (int i = index; i < (int)s.size(); i++)
//		{
//			result += Backtracking(s, n - 1, i);
//		}
//		return result;
//	}
//
//	int countVowelStrings(int n) {
//		string str = "aeiou";
//		return Backtracking(str, n, 0);
//	}
//};
//
//int main()
//{
//	int n = 33;
//	cout << Solution().countVowelStrings(n);
//	return 0;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Solution {
//public:
//	vector<int> Primer(int n)
//	{
//		vector<bool>flag(n + 1, true);
//		vector<int>ret;
//		for (int i = 2; i <= n; i++)
//		{
//			if (flag[i]){
//				for (int j = 2; j*i <= n; j++)
//				{
//					flag[i*j] = false;
//				}
//			}
//		}
//		for (int i = 2; i < (int)flag.size(); i++)
//		{
//			if (flag[i])
//				ret.push_back(i);
//		}
//		return ret;
//	}
//
//	int countPrimeSetBits(int left, int right) {
//		vector<int>primer = Primer(32);
//		int ret = 0;
//		for (int i = left; i <= right; i++)
//		{
//			int tmp = i;
//			int count = 0;
//			while (tmp)
//			{
//				tmp &= (tmp - 1);
//				count++;
//			}
//			if (find(primer.begin(), primer.end(), count) != primer.end())
//				ret++;
//		}
//		return ret;
//	}
//};
//
//int main()
//{
//	int left = 6, right = 10;
//	cout << Solution().countPrimeSetBits(left, right);
//	return 0;
//}

//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//int main()
//{
//	string str;
//	getline(cin, str);
//	vector<string>ret;
//	int left = 0, right = 0;
//	int flag = 0;
//	while (right < (int)str.size())
//	{
//		if (str[left] == '"')
//			flag = 1;
//		while (right < (int)str.size())
//		{
//			if (str[right] == ' '&&flag == 0 || str[right] == '"'&&left != right)
//				break;
//			right++;
//		}
//		right++;
//		int gap = right - left;
//		if (flag){
//			left++;
//			gap -= 2;
//			right++;
//		}
//		flag = 0;
//		ret.push_back(str.substr(left, gap));
//		left = right;
//	}
//	cout << ret.size() << endl;
//	for (const auto& e : ret)
//		cout << e << endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int main()
//{
//	int count = 0;
//	for (int i = 1; i <= 2020; i++)
//	{
//		int tmp = i;
//		while (tmp)
//		{
//			if (tmp%10 == 2)
//				count++;
//			tmp /= 10;
//		}
//	}
//	cout << count << endl;
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//struct Node
//{
//	vector<Node*>next = { 26, nullptr };
//	bool end = false;
//};
//
//class Solution {
//public:
//
//	string FindPrefix(Node* root, const string& str)
//	{
//		if (root->next[str[0] - 'a'] == nullptr)
//			return str;
//		string ret;
//		for (int i = 0; i < (int)str.size(); i++)
//		{
//			ret.push_back(str[i]);
//			if (root->next[str[i] - 'a'] == nullptr)
//				return str;
//
//			if (root->next[str[i] - 'a']->end)
//				return ret;
//			root = root->next[str[i] - 'a'];
//		}
//		return ret;
//	}
//
//	string replaceWords(vector<string>& dictionary, string sentence)
//	{
//		Node head;
//		for (const auto& e : dictionary)
//		{
//			Node* cur = &head;
//			for (auto& i : e)
//			{
//				if (cur->next[i - 'a'] == nullptr)
//					cur->next[i - 'a'] = new Node;
//				cur = cur->next[i - 'a'];
//			}
//			cur->end = true;
//		}
//		string ret, tmp;
//		for (int i = 0; i < (int)sentence.size(); i++)
//		{
//			if (sentence[i] == ' ')
//			{
//				ret += FindPrefix(&head, tmp);
//				ret += " ";
//				tmp.clear();
//				continue;
//			}
//			tmp += sentence[i];
//		}
//		ret += FindPrefix(&head, tmp);
//		return ret;
//	}
//};
//
//int main()
//{
//	vector<string>dictionary = { "a", "aa", "aaa", "aaaa" };
//	string sentence = "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa";
//	cout << Solution().replaceWords(dictionary, sentence);
//	return 0;
//}

//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//int ret = 0;
//void Bracktracking(int left, int right, int n)
//{
//	if (left <right || left > n)
//		return;
//	if (left == right && left == n)
//		ret++;
//
//	Bracktracking(left + 1, right, n);
//	Bracktracking(left, right + 1, n);
//}

//int main()
//{
//	long mold = 1E9 + 7;
//	string str;
//	cin >> str;
//	//计算括号对数
//	int left = 0, right = 0;
//	for (auto e : str)
//	{
//		if (e == '(')
//			left++;
//		else
//			right++;
//	}
//	if (left == right)
//	{
//		cout << 0;
//		return 0;
//	}
//	int n = left < right ? right : left;
//
//	Bracktracking(0, 0, n);
//	cout << ret % mold << endl;
//	return 0;
//}


//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//	int n, v;
//	cin >> n >> v;
//	vector<vector<int>>nums(n + 1, vector<int>(2, 0));
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> nums[i][0] >> nums[i][1];
//	}
//	vector<vector<int>>dp(n + 1, vector<int>(v + 1));
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 0; j <= v; j++)
//		{
//			dp[i][j] = dp[i - 1][j];
//			if (j >= nums[i][0])
//				dp[i][j] = max(dp[i][j], dp[i][j - nums[i][0]] + nums[i][1]);
//		}
//	}
//	cout << dp[n][v] << endl;
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <unordered_set>
//using namespace std;
//
//int GetRoot(vector<int>&nums, int x)
//{
//	if (nums[x] == -1)
//		return x;
//	return nums[x] = GetRoot(nums, nums[x]);
//}
//
//void Merge(vector<int>&nums, int x, int y)
//{
//	int xRoot = GetRoot(nums, x);
//	int yRoot = GetRoot(nums, y);
//	//在同一个集合里面
//	if (xRoot == yRoot)
//		return;
//	nums[xRoot] = yRoot;
//}
//
//int main()
//{
//	int m, n;
//	cin >> m >> n;
//	int k;
//	cin >> k;
//	vector<int>nums(m*n + 1, -1);
//	for (int i = 0; i < k; i++)
//	{
//		int a, b;
//		cin >> a >> b;
//		Merge(nums, a, b);
//	}
//	unordered_set<int>flag;
//	for (int i = 1; i <= m * n; i++)
//	{
//		flag.insert(GetRoot(nums, i));
//	}
//	cout << flag.size() << endl;
//	return 0;
//}

//#include <iostream>
//#include <math.h>
//using namespace std;
//
//long  long MyPowa(int x, int index)
//{
//	long long sum = x;
//	int mod = 123456789;
//	int flag = 1;
//	while (index != 1)
//	{
//		if (index % 2)
//			flag = sum;
//		sum = (sum*sum) % mod;
//		sum = (sum*flag) % mod;
//		flag = 1;
//		index /= 2;
//	}
//	return sum;
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	long long sum = 0;
//	int mod = 123456789;
//	for (int i = 1; i <= n; i++)
//	{
//		sum = (sum + (long long)MyPowa(i, 8)) % mod;
//	}
//	cout << sum;
//	return 0;
//}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
		int count = 0;
		for (int i = 0; i < (int)arr1.size(); i++)
		{
			int flag = 1;
			for (int j = 0; j < (int)arr2.size(); j++)
			{
				if (abs(arr1[i] - arr2[j]) <= d)
					flag = 0;
			}
			if (flag)
				count++;
		}
		return count;
	}
};

int main()
{
	vector<int>arr1{ 4,5,8 }, arr2{ 10,9,1,8 };
	int d = 2;
	cout << Solution().findTheDistanceValue(arr1, arr2, d);
	return 0;
}