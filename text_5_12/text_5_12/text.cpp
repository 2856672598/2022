//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//	vector<long long>nums(80, 1);
//	for (int i = 2; i < 80; i++) {
//		nums[i] = nums[i - 1] + nums[i - 2];
//	}
//	int begin, end;
//	while (cin >> begin >> end)
//	{
//		long long sum = 0;
//		for (int i = begin - 1; i < end; i++)
//			sum += nums[i];
//		cout << sum << endl;
//	}
//	return 0;
//}

//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//int Compar(const string s1, const string s2, int index)
//{
//	int count = 0;
//	for (int i = index; i <= (int)(s1.size() - s2.size()); i++)
//	{
//		int j, flag = 0;
//		for (j =0; j < (int)s2.size(); j++)
//		{
//			if (s1[i + j] != s2[j]) {
//				flag = 1;
//				break;
//			}
//		}
//		if (flag == 0) {
//			i += s2.size() - 1;
//			count++;
//		}
//	}
//	return count;
//}
//
//int main()
//{
//	string s1, s2;
//	while (cin >> s1 >> s2)
//	{
//		int ret = 0;
//		for (int i = 0; i < (int)s1.size(); i++)
//		{
//			ret = max(Compar(s1, s2, i), ret);
//		}
//		cout << ret << endl;
//	}
//}


//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//class Solution {
//public:
//	int minDeletionSize(vector<string>& strs)
//	{
//		int count = 0;
//		for (int i = 0; i < (int)strs[0].size(); i++)
//		{
//			for (int j = 1; j < (int)strs.size(); j++)
//			{
//				if (strs[j][i] < strs[j - 1][i]) {
//					count++;
//					break;
//				}
//			}
//		}
//		return count;
//	}
//};
//
//int main()
//{
//	vector<string> str = { "cba","daf","ghi" };
//	cout << Solution().minDeletionSize(str);
//	return 0;
//}

//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//class Solution {
//public:
//	bool oneEditAway(string first, string second)
//	{
//		if (abs((int)(first.size() - second.size())) > 1)
//			return false;
//		if (first == second)
//			return true;
//		int flag = 0;
//		if (first.size() == second.size()) {
//			for (int i = 0; i < (int)first.size(); i++)
//			{
//				if (first[i] != second[i])
//					flag++;
//			}
//		}
//		else {
//			//É¾³ýÒ»¸ö
//			if (first.size() < second.size()) {
//				first.swap(second);
//			}
//			int begin1 = 0, begin2 = 0;
//			while (begin1<first.size() && begin2<second.size()) {
//				if (first[begin1] != second[begin2]) {
//					flag++;
//					begin1++;
//				}
//				else {
//					begin1++;
//					begin2++;
//				}
//			}
//		}
//		return flag > 1 ? false : true;
//	}
//};
//
//int main()
//{
//	string first = "mart";
//	string second = "karma";
//	cout << Solution().oneEditAway(first, second);
//}


//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		getchar();
//		string tmp;
//		string ret;
//		for (int i = 0; i < n; i++) {
//			getline(cin, tmp);
//			if (i != 0)
//				ret += ", ";
//			if (tmp.find(',') != string::npos || tmp.find(' ') != string::npos) {
//				ret += "\"";
//				ret += tmp;
//				ret += "\"";
//			}
//			else
//				ret += tmp;
//		}
//		cout << ret << endl;
//	}
//	return 0;
//}

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<long long>nums(90, 0);
	nums[0] = 1;
	nums[1] = 2;
	for (int i = 2; i < 90; i++) {
		nums[i] = nums[i - 1] + nums[i - 2];
	}
	int n = 0;
	while (cin >> n)
	{
		cout << nums[n - 1] << endl;
	}
	return 0;
}