//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//class Solution {
//public:
//	bool strongPasswordCheckerII(string password) {
//		if (password.size() < 8)
//			return false;
//		int flag[4] = { 0 };
//		for (int i = 0; i < (int)password.size(); i++)
//		{
//			if (islower(password[i]))
//				flag[0] = 1;
//			else if (isupper(password[i]))
//				flag[1] = 1;
//			else if (isdigit(password[i]))
//				flag[2] = 1;
//			else if (ispunct(password[i]))
//				flag[3] = 1;
//			if (i > 0 && password[i] == password[i - 1])
//				return false;
//		}
//		for (int i = 0; i < 4; i++)
//			if (flag[i] == 0)
//				return false;
//		return true;
//	}
//};
//
//
//int main()
//{
//	string password = "vpWkmkfSAcCLDBNRfH";
//	cout << Solution().strongPasswordCheckerII(password);
//	return 0;
//}


//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//class Solution {
//public:
//	vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
//		sort(potions.begin(), potions.end());
//		vector<int>ret;
//		for (int i = 0; i < (int)spells.size(); i++)
//		{
//			int left = 0, right = potions.size() - 1;
//			long long sum = 0;
//			while (left < right)
//			{
//				int mid = left + (right - left) / 2;
//				sum = (long long)potions[mid] * spells[i];
//				if (sum < success)
//					left = mid + 1;
//				else
//					right = mid;
//			}
//			sum = (long long)potions[left] * spells[i];
//			if (sum < success)
//				left += 1;
//			ret.push_back(potions.size() - left);
//		}
//		return ret;
//	}
//};
//
//int main()
//{
//	return 0;
//}

//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//class Solution {
//public:
//	bool Check(const string& str1, const string& str2)
//	{
//		char arr[256] = { 0 };
//		if (str2.size() != str1.size())
//			return false;
//		for (int i = 0; i < (int)str1.size(); i++)
//		{
//			if (arr[str1[i]] == 0) {
//				arr[str1[i]] = str2[i];
//			}
//			else if (arr[str1[i]] != str2[i])
//				return false;
//		}
//		return true;
//	}
//	vector<string> findAndReplacePattern(vector<string>& words, string pattern)
//	{
//		vector<string>ret;
//		for (int i = 0; i < (int)words.size(); i++)
//		{
//			if (Check(words[i], pattern) && Check(pattern, words[i]))
//				ret.push_back(words[i]);
//		}
//		return ret;
//	}
//};
//
//int main()
//{
//	vector<string>words{ "abc","deq","mee","aqq","dkd","ccc" };
//	string parrern{ "abb" };
//	Solution().findAndReplacePattern(words, parrern);
//	return 0;
//}


//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//class Solution {
//public:
//	int heightChecker(vector<int>& heights) {
//		vector<int>tmp(heights);
//		sort(tmp.begin(), tmp.end());
//		int ret = 0;
//		for (int i = 0; i < (int)tmp.size(); i++)
//		{
//			if (heights[i] != tmp[i])
//				ret++;
//		}
//		return ret;
//	}
//};

//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//int INF = (int)1e9;
//int main()
//{
//	int m, n;
//	cin >> m >> n;
//	vector<int>pos(m + n, 0), flag(m + n, 0);
//	for (int i = 0; i < m + n; i++)
//		cin >> pos[i];
//	for (int i = 0; i < m + n; i++)
//		cin >> flag[i];
//
//	if (n == 0 || m == 0)
//		return 0;
//
//	vector<int>distance(m + n, INF);
//	int prev = INF;
//	for (int i = 0; i < m + n; i++)
//	{
//		if (flag[i] == 0) {
//			if (prev != INF) {
//				distance[i] = pos[i] - prev;
//			}
//		}
//		else
//			prev = pos[i];
//	}
//
//	prev = INF;
//	for (int i= m + n -1;i>=0;i--)
//	{
//		if (flag[i] == 0) {
//			if (prev != INF && prev - pos[i] < distance[i]) {
//				distance[i] = -1;
//			}
//		}
//		else
//			prev = pos[i];
//	}
//	vector<int> ret(n, 0);
//	int index = -1;
//	for (int i = 0; i < n + m; i++)
//	{
//		if (flag[i] == 0 ) {
//			if (distance[i] > 0)
//				ret[index]++;
//			else {
//				ret[index + 1]++;
//			}
//		}
//		else
//			index++;
//	}
//	for (int i = 0; i < n; i++)
//		cout << ret[i] << " ";
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <unordered_set>
//using namespace std;
//
//int main()
//{
//	int n, m;
//	unordered_set<int>s;
//	cin >> n >> m;
//	vector<int>nums(n, 0);
//	for (int i = 0; i < n; i++)
//		cin >> nums[i];
//	for (int i = 0; i < m; i++)
//	{
//		int tmp;
//		cin >> tmp;
//		s.insert(tmp);
//	}
//	for (int i = 0; i < n; i++) {
//		if (s.find(nums[i]) != s.end())
//			cout << nums[i] << " ";
//	}
//	return 0;
//}


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int>ret;
	void Dfs(int n, int k)
	{
		if (k > n)
			return;
		ret.push_back(k);
		if (k * 10 > n)
			return;
		for (int i = 0; i < 10; i++)
			Dfs(n, k * 10 + i);
	}

	vector<int> lexicalOrder(int n) {
		for (int i = 1; i < 10; i++)
			Dfs(n, i);
		return ret;
	}
};
