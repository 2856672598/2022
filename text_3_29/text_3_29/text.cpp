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

#include <iostream>
#include <unordered_map>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
	vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
		unordered_map<string, int>m1, m2;
		for (int i = 0; i < (int)list1.size(); i++)
			m1[list1[i]] = i;
		for (int i = 0; i < (int)list2.size(); i++)
			m2[list2[i]] = i;
		multimap<int, string>flag;
		for (const auto& e : m1)
		{
			auto it = m2.find(e.first);
			if (it != m2.end())
				flag.insert(make_pair(e.second + it->second, e.first));
		}
		vector<string>ret;
		int min = flag.begin()->first;
		for ( auto& e : flag)
		{
			if (e.first != min)
				break;
			ret.push_back(e.second);
		}
		return ret;
	}
};

int main()
{
	vector<string> list1 = { "Shogun", "Tapioca Express", "Burger King", "KFC" };
	vector<string> list2 = { "Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun" };

	Solution().findRestaurant(list1, list2);
	return 0;
}