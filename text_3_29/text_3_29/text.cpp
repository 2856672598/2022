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
