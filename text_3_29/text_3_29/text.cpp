//#include <iostream>
//#include <vector>
//using namespace std;
////long long BackTracking(int n, int m, int k, int p)
////{
////	long long flag = 10e9 + 7;
////	if (k == 0) {
////		return m == p ? 1 : 0;
////	}
////	//当前在最左侧只能向右走
////	if (m == 1){
////		return BackTracking(n, m + 1, k - 1, p);
////	}
////	else if (m == n) {
////		//当前位置在最右侧只能向左走
////		return BackTracking(n, m - 1, k - 1, p);
////	}
////	//既可以向左也可以向右
////	return BackTracking(n, m - 1, k - 1, p) % flag + BackTracking(n, m + 1, k - 1, p) % flag;
////}
//
//int BackTracking1(int n, int m, int k, int p, vector<vector<int>>&flag)
//{
//	if (flag[m][k] != -1)
//		return flag[m][k];
//	int gap = 1e9 + 7;
//	if (k == 0)
//		return m == p ? 1 : 0;
//	int ans = 0;
//	if (m == 1) {
//		ans = BackTracking1(n, m + 1, k - 1, p, flag);
//	}
//	else if (m == n) {
//		ans = BackTracking1(n, m - 1, k - 1, p, flag);
//	}
//	else
//		ans = (BackTracking1(n, m - 1, k - 1, p, flag) + BackTracking1(n, m + 1, k - 1, p, flag)) % gap;
//	flag[m][k] = ans;
//	return ans;
//}
//
//int fun(int n, int m, int k, int p)
//{
//	vector<vector<int>> flag(n + 1, vector<int>(k + 1, -1));
//	return BackTracking1(n, m, k, p, flag);
//}
//
//
//int way3(int n, int m, int k, int p)
//{
//	int mod = 1E9 + 7;
//	vector<vector<int>>flag(n + 1, vector<int>(k + 1));
//	flag[p][0] = 1;
//	for (int i = 1; i <= k; i++)
//	{
//		flag[1][i] = flag[2][i - 1];
//		for (int j = 2; j < n; j++)
//		{
//			flag[j][i] = (flag[j - 1][i - 1] + flag[j + 1][i - 1]) % mod;
//		}
//		flag[n][i] = flag[n - 1][i - 1];
//
//	}
//	return flag[m][k];
//}
//
//int main()
//{
//	int n, m, k, p;//n个位置 当前在M处 ，走K步，到达p位置
//	cin >> n >> m >> k >> p;
//	//cout << BackTracking(n, m, k, p) << endl;
//	//cout << fun(n, m, k, p);
//
//	cout << way3(n, m, k, p);
//	return 0;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//	int n, m, k;
//	cin >> n >> m >> k;
//	vector<vector<int>>nums(n, vector<int>(m));
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//			cin >> nums[i][j];
//	}
//	int row = 0, col = m - 1;
//	while (row < n && col >= 0)
//	{
//		if (nums[row][col] == k){
//			cout << "Yes" << endl;
//			return 0;
//		}
//		else if (nums[row][col] < k)
//			row++;
//		else if (nums[row][col] > k)
//			col--;
//	}
//	cout << "No" << endl;
//	return 0;
//}

//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//class Solution {
//public:
//	int MaxSuccessive(const string& s, int k, char ch)
//	{
//		int left = 0, right = 0, ans = 0;
//		while (right < s.size())
//		{
//			if (ch != s[right])
//				k--;
//			while (left < right && k < 0)
//			{
//				if (s[left] != ch)
//					k++;
//				left++;
//			}
//			ans = max(right - left + 1, ans);
//			right++;
//		}
//		return ans;
//	}
//
//	int maxConsecutiveAnswers(string answerKey, int k) {
//		return max(MaxSuccessive(answerKey, k, 'T'), MaxSuccessive(answerKey, k, 'F'));
//	}
//};

//#include <iostream>
//#include <vector>
//using namespace std;
//
//template<class T>
//T add(const T& x, const T& y)
//{
//	return x + y;
//}
//
//template<>
//double add(const double& x, const double& y)
//{
//	cout << "特化版本" << endl;
//	return x + y;
//}
//
//int main()
//{
//	cout << add(1, 2) << endl;
//	cout << add(1.1, 2.2) << endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//class Date
//{
//public:
//	Date(int year, int month, int day)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{}
//	//只要重载了operator bool就可以
//	operator bool()
//	{
//		return _day != 0;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d(2022, 3, 0);
//	//当想用一个对象来做布尔判断时，可以在类中重载一个operatot bool;
//	if(d){
//		cout << "hello world";
//	}
//	return 0;
//}


//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	vector<vector<int>> nums(n + 1, vector<int>(m + 1, 1));
//	nums[0][0] = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//		{
//			nums[i][j] = nums[i - 1][j] + nums[i][j - 1];
//		}
//	}
//	cout << nums[n][m];
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//class UnusualAdd {
//public:
//	int addAB(int A, int B) {
//		/*
//		1^1 = 0,1^0 = 1 ,0^0 =0
//		对应的就是加法但是没有进位
//		1&1 = 1,1&0 = 0,0&0 = 0
//		对应的就是进位
//		*/
//		while (B)
//		{
//			int tmp = 0;
//			tmp = A ^ B;
//			B = (A & B) << 1;
//			A = tmp;
//		}
//		return A;
//	}
//};
//
//int main()
//{
//	cout << UnusualAdd().addAB(4, 5);
//	return 0;
//}

//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int main()
//{
//	int n = 0;
//	cin >> n;
//	vector<string>str(n);
//	for (int i = 0; i < n; i++)
//		cin >> str[i];
//	vector<string>tmp(str);
//	sort(tmp.begin(), tmp.end());
//	int flag = 0;
//	if (tmp == str)
//		flag = 1;
//	sort(tmp.begin(), tmp.end(), [](const string& x, const string& y)->bool {
//		return x.size() < y.size();
//	});
//	if (tmp == str) {
//		if (flag == 1)
//			cout << "both" << endl;
//		else
//			cout << "lengths" << endl;
//	}
//	else if (flag == 1)
//		cout << "lexicographically" << endl;
//	else
//		cout << "none" << endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int A, B;
//	cin >> A >> B;
//
//	int x = A, y = B;
//	while (x%y)
//	{
//		int tmp = y;
//		y = x % y;
//		x = tmp;
//	}
//	cout << A * B / y << endl;
//	return 0;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Solution {
//public:
//	vector<int> selfDividingNumbers(int left, int right)
//	{
//		vector<int>ret;
//		for (int i = left; i <= right; i++)
//		{
//			int tmp = i, flag = 1;
//			while (tmp)
//			{
//				if (tmp % 10 == 0 || i % (tmp % 10) != 0) {
//					flag = 0;
//					break;
//				}
//				tmp /= 10;
//			}
//			if (flag)
//				ret.push_back(i);
//		}
//		return ret;
//	}
//};

//#include <iostream>
//#include <string>
//using namespace std;
//
//class Solution {
//public:
//	bool judgeCircle(string moves) {
//		int x = 0, y = 0;
//		for (int i = 0; i < (int)moves.size(); i++)
//		{
//			if (moves[i] == 'L')
//				x--;
//			else if (moves[i] == 'R')
//				x++;
//			else if (moves[i] == 'U')
//				y++;
//			else y--;
//		}
//		return x == 0 && y == 0;
//	}
//};

//#include <iostream>
//#include <unordered_map>
//#include <string>
//#include <map>
//using namespace std;
//
//class Solution {
//public:
//	vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
//		unordered_map<string, int>m1, m2;
//		for (int i = 0; i < (int)list1.size(); i++)
//			m1[list1[i]] = i;
//		for (int i = 0; i < (int)list2.size(); i++)
//			m2[list2[i]] = i;
//		multimap<int, string>flag;
//		for (const auto& e : m1)
//		{
//			auto it = m2.find(e.first);
//			if (it != m2.end())
//				flag.insert(make_pair(e.second + it->second, e.first));
//		}
//		vector<string>ret;
//		int min = flag.begin()->first;
//		for ( auto& e : flag)
//		{
//			if (e.first != min)
//				break;
//			ret.push_back(e.second);
//		}
//		return ret;
//	}
//};
//
//int main()
//{
//	vector<string> list1 = { "Shogun", "Tapioca Express", "Burger King", "KFC" };
//	vector<string> list2 = { "Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun" };
//
//	Solution().findRestaurant(list1, list2);
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int>nums(32, 0);
//	int i = 0;
//	while (n)
//	{
//		nums[i++] = n % 2;
//		n /= 2;
//	}
//	reverse(nums.begin(), nums.end());
//	for (int i = 1; i < 32; i++)
//	{
//		if (nums[i - 1] && nums[i])
//			nums[i] = nums[i - 1] + 1;
//	}
//	cout << *max_element(nums.begin(), nums.end()) << endl;
//	return 0;
//}

//#include <iostream>
//#include <unordered_set>
//using namespace std;
//class LCA {
//public:
//	int getLCA(int a, int b) {
//		unordered_set<int>s;
//		s.insert(1);
//		s.insert(a < b ? a : b);
//		while (a)
//		{
//			a /= 2;
//			if (a)
//				s.insert(a);
//		}
//
//		while (b)
//		{
//			b /= 2;
//			if (s.find(b) != s.end())
//				return b;
//		}
//		return 1;
//	}
//};
//
//int main()
//{
//	int a, b;
//	cin >> a >> b;
//	cout << LCA().getLCA(a, b) << endl;
//	return 0;
//}


//#include <iostream>
//#include <string>
//#include <stack>
//using namespace std;
//
//class Solution {
//public:
//	string removeDuplicateLetters(string s)
//	{
//		int arr[26] = { 0 };
//		for (int i = 0; i < (int)s.size(); i++)
//		{
//			arr[s[i] - 'a']++;
//		}
//		stack<char>st;
//		bool used[26] = { false };
//		for (int i = 0; i < (int)s.size(); i++)
//		{
//			//判断栈中是否存在当前元素
//			if (used[s[i] - 'a']) {
//				arr[s[i] - 'a']--;
//				continue;
//			}
//
//			while (!st.empty() && s[i] < st.top() && arr[st.top() - 'a']>1)
//			{
//				arr[st.top() - 'a']--;
//				used[st.top() - 'a'] = false;
//				st.pop();
//			}
//			st.push(s[i]);
//			used[s[i] - 'a'] = true;
//		}
//		string ret;
//		while (!st.empty())
//		{
//			ret.push_back(st.top());
//			st.pop();
//		}
//		reverse(ret.begin(), ret.end());
//		return ret;
//	}
//};
//
//int main()
//{
//	string s = "bddbccd";
//	cout << Solution().removeDuplicateLetters(s);
//	return  0;
//}

//#include <iostream>
//using namespace std;
//
//class Solution {
//public:
//	int minBitFlips(int start, int goal) {
//		int ret = 0;
//		int tmp = start ^ goal;
//		while (tmp)
//		{
//			ret++;
//			tmp &= tmp - 1;
//		}
//
//		return ret;
//	}
//};
//
//int main()
//{
//	int start = 10, goal = 7;
//	cout << Solution().minBitFlips(start, goal);
//	return 0;
//}

//#include <vector>
//#include <iostream>
//using namespace std;
//
//class Solution {
//public:
//	int triangularSum(vector<int>& nums)
//	{
//		int sz = nums.size() - 1;
//		while (sz)
//		{
//			for (int i = 1; i <= (int)sz; i++)
//			{
//				nums[i - 1] = (nums[i - 1] + nums[i]) % 10;
//			}
//			sz--;
//		}
//		return nums[0];
//	}
//};
//
//int main()
//{
//	vector<int>nums{ 5 };
//	cout << Solution().triangularSum(nums);
//	return 0;
//}


//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
////class Solution {
////public:
////	long long ret = 0;
////	void Backtracking(const string& s, int index, vector<char>&way)
////	{
////		if (way.size() == 3) {
////			if (way[1] != way[0] && way[1] != way[2])
////				ret++;
////			return;
////		}
////		for (int i = index; i < (int)s.size(); i++)
////		{
////			way.push_back(s[i]);
////			Backtracking(s, i + 1, way);
////			way.pop_back();
////		}
////	}
////
////	long long numberOfWays(string s)
////	{
////		vector<char>way;
////		Backtracking(s, 0, way);
////		return ret;
////	}
////};
//
//class Solution {
//public:
//	long long numberOfWays(string s) {
//		vector<int>prefix(s.size()), suffix(s.size());
//
//		int onesize = 0, zerosize = 0;
//		for (int i = 0; i < s.size(); i++)
//		{
//			if (s[i] == '0') {
//				prefix[i] = onesize;
//				zerosize++;
//			}
//			else {
//				prefix[i] = zerosize;
//				onesize++;
//			}
//		}
//		onesize = 0, zerosize = 0;
//		for (int i = s.size() - 1; i >= 0; i--)
//		{
//			if (s[i] == '0') {
//				suffix[i] = onesize;
//				zerosize++;
//			}
//			else {
//				suffix[i] = zerosize;
//				onesize++;
//			}
//		}
//		int long long ret = 0;
//		for (int i = 1; i < (int)s.size() - 1; i++)
//		{
//			ret += prefix[i] * suffix[i];
//		}
//		return ret;
//	}
//};
//
//int main()
//{
//	string s = "001101";
//	cout << Solution().numberOfWays(s);
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <string>
//#include <unordered_map>
//#include <set>
//#include <algorithm>
//using namespace std;

//class Solution {
//public:
//	int convertTime(string current, string correct) {
//		int time1 = stoi(current.substr(0, 2)) * 60;
//		time1 += stoi(current.substr(3));
//
//		int time2 = stoi(correct.substr(0, 2)) * 60;
//		time2 += stoi(correct.substr(3));
//
//		int time = time2 - time1;
//		int count = 0;
//		count += time / 60;
//		time %= 60;
//		count += time / 15;
//		time %= 15;
//		count += time / 5;
//		time %= 5;
//		count += time;
//		return count;
//	}
//};

//class Solution {
//public:
//	vector<vector<int>> findWinners(vector<vector<int>>& matches)
//	{
//		//输掉比赛的人
//		unordered_map<int, int>flag;
//		for (const auto&e : matches)
//		{
//			flag[e[1]]++;
//		}
//		vector<vector<int>>ret;
//		set<int>tmp1, tmp2;
//		for (const auto&e : matches)
//		{
//			if (flag.find(e[0]) == flag.end())
//				tmp1.insert(e[0]);
//		}
//		for (const auto&e : flag)
//		{
//			if (e.second == 1)
//				tmp2.insert(e.first);
//		}
//		ret.push_back(vector<int>(tmp1.begin(), tmp1.end()));
//		ret.push_back(vector<int>(tmp2.begin(), tmp2.end()));
//		return ret;
//	}
//};

//#include <iostream>
//#include <vector>
//#include <map>
//#include <algorithm>
//using namespace std;
//
//vector<int> PrimeNumber(int n)
//{
//	vector<bool>flag(n + 1, true);
//	for (int i = 2; i <= n; i++)
//	{
//		if (flag[i])
//		{
//			for (int j = 2; i*j <= n; j++)
//			{
//				flag[i*j] = false;
//			}
//		}
//	}
//	vector<int>ret;
//	for (int i = 0; i < (int)flag.size(); i++)
//	{
//		if (flag[i] == true)
//			ret.push_back(i);
//	}
//	return ret;
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	//素数筛
//	vector<int>flag = PrimeNumber(n);
//	multimap<int, pair<int, int>>m;
//	for (int i = flag.size() - 1; i >= 0; i--)
//	{
//		if (find(flag.begin(), flag.end(), n - flag[i]) != flag.end())
//		{
//			int nums1 = flag[i];
//			int nums2 = n - flag[i];
//			m.insert({ abs(nums1 - nums2), make_pair(nums1, nums2) });
//		}
//	}
//	int nums1 = m.begin()->second.first;
//	int nums2 = m.begin()->second.second;
//	if (nums2 < nums1)
//		swap(nums1, nums2);
//	cout << nums1 << endl << nums2 << endl;
//	return 0;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//class BinInsert {
//public:
//
//	vector<int> ToBinary(int n)
//	{
//		vector<int>ret;
//		while (n)
//		{
//			ret.push_back(n % 2);
//			n /= 2;
//		}
//		return ret;
//	}
//
//	int binInsert(int n, int m, int j, int i)
//	{
//		vector<int> nBinary = ToBinary(n);
//		vector<int> mBinary = ToBinary(m);
//		int k = 0;
//		for (int z = j; z <= i; z++)
//		{
//			nBinary[z] = mBinary[k++];
//		}
//		reverse(nBinary.begin(), nBinary.end());
//		int ret = 0;
//		int flag = 0;
//		for (int i = (int)nBinary.size() - 1; i >= 0; i--)
//		{
//			ret += nBinary[i] * (1 << flag);
//			flag++;
//		}
//		return ret;
//	}
//};
//
//int main()
//{
//	int n, m, j, i;
//	cin >> n >> m >> j >> i;
//	cout << BinInsert().binInsert(n, m, j, i);
//	return 0;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//	bool Check(const vector<int>& candies, long target, long long k)
//	{
//		for (auto e : candies)
//		{
//			if (k <= 0)
//				break;
//			k -= e / target;
//		}
//		return k <= 0;
//	}
//
//	int maximumCandies(vector<int>& candies, long long k)
//	{
//		long sum = 0;
//		for (auto e : candies)
//			sum += e;
//		if (sum < k)
//			return 0;
//		long left = 1, right = sum;
//		int ret = 0;
//		while (left <= right)
//		{
//			long mid = left + (right - left) / 2;
//			if (Check(candies, mid, k)) {
//				ret = mid;
//				left = mid + 1;
//			}
//			else
//				right = mid - 1;
//		}
//		return ret;
//	}
//};
//
//int main()
//{
//	vector<int>nums{ 4,7,5 };
//	cout << Solution().maximumCandies(nums, 4);
//	return 0;
//}

//#include <iostream>
//#include <string>
//#include <stack>
//using namespace std;
//
//int main()
//{
//	string str;
//	cin >> str;
//	int sz = str.size() / 2;
//	stack<char>st;
//	for (int i = 0; i < sz; i++)
//		st.push(str[i]);
//
//	if (str.size() % 2)
//		sz++;
//	for (int i = sz; i < (int)str.size(); i++)
//	{
//		if (str[i] != st.top()) {
//			cout << str << "不是回文" << endl;
//
//			return 0;
//		}
//		st.pop();
//	}
//	cout << str << "是回文" << endl;
//	return 0;
//}

//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//class Solution {
//public:
//	char nextGreatestLetter(vector<char>& letters, char target) {
//		for (int i = 0; i < (int)letters.size(); i++)
//		{
//			if (letters[i] > target)
//				return letters[i];
//		}
//		return -1;
//	}
//};

//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//class Solution {
//public:
//	vector<int> numberOfLines(vector<int>& widths, string s) {
//		int count = 0;
//		int row = 0;
//		for (const auto& e : s)
//		{
//			if (count + widths[e - 'a'] > 100)
//			{
//				count = widths[e - 'a'];
//				row++;
//			}
//			else
//				count += widths[e - 'a'];
//		}
//		if (count != 0)
//			row++;
//		return { row,count };
//	}
//};

#include <iostream>
#include <vector>
using namespace std;

//class Solution {
//public:
//	int search(vector<int>& nums, int target)
//	{
//		int left = 0, right = nums.size() - 1;
//		while (left <= right)
//		{
//			int mid = left + (right - left) / 2;
//			if (nums[mid] == target)
//				return mid;
//			if (nums[mid] > target)
//				right = mid - 1;
//			else
//				left = mid + 1;
//		}
//		return -1;
//	}
//};
