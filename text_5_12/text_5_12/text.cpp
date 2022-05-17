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

//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//	vector<long long>nums(90, 0);
//	nums[0] = 1;
//	nums[1] = 2;
//	for (int i = 2; i < 90; i++) {
//		nums[i] = nums[i - 1] + nums[i - 2];
//	}
//	int n = 0;
//	while (cin >> n)
//	{
//		cout << nums[n - 1] << endl;
//	}
//	return 0;
//}

//#include <iostream>
//#include <string>
//#include <unordered_set>
//using namespace std;
//
//int main()
//{
//	string s1, s2;
//	while (getline(cin, s1))
//	{
//		getline(cin, s2);
//		unordered_set<string>s;
//		int i = 0;
//		while (i < (int)s1.size())
//		{
//			string tmp;
//			if (s1[i] == '\"') {
//				i++;
//				while (i < (int)s1.size() && s1[i] != '\"') {
//					tmp += s1[i];
//					i++;
//				}
//				i += 2;
//			}
//			else {
//				while (i < (int)s1.size() && s1[i] != ',')
//				{
//					tmp += s1[i];
//					i++;
//				}
//				i++;
//			}
//			s.insert(tmp);
//		}
//		if (s.find(s2) != s.end())
//			cout << "Ignore" << endl;
//		else
//			cout << "Important!" << endl;
//	}
//	return 0;
//}


//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//	vector<long long>nums(21, 0);
//	nums[1] = 0;
//	nums[2] = 1;
//	for (int i = 3; i < (int)nums.size(); i++)
//	{
//		nums[i] = (i - 1)*(nums[i - 1] + nums[i - 2]);
//	}
//	int n;
//	while (cin >> n)
//	{
//		long long sum = 1;
//		for (int i = 2; i <= n; i++)
//			sum *= i;
//		printf("%2.2lf%%\n", nums[n] * 1.0 / sum * 100);
//	}
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
////class Solution {
////public:
////	vector<string> removeAnagrams(vector<string>& words)
////	{
////		vector<string>ret;
////		ret.push_back(words[0]);
////		for (int i = 1; i < (int)words.size(); i++)
////		{
////			string prev = ret.back();
////			string cur = words[i];
////			sort(prev.begin(), prev.end());
////			sort(cur.begin(), cur.end());
////			if (prev != cur)
////				ret.push_back(words[i]);
////		}
////		return ret;
////	}
////};
//
//class Solution {
//public:
//	int maxConsecutive(int bottom, int top, vector<int>& special)
//	{
//		special.push_back(bottom-1);
//		special.push_back(top + 1);
//		sort(special.begin(), special.end());
//		int ret = 0;
//		for (int i = 1; i < (int)special.size(); i++)
//		{
//			ret = max(ret, special[i] - special[i - 1] - 1);
//		}
//		return ret;
//	}
//};


//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
////class Solution {
////public:
////	bool isAlienSorted(vector<string>& words, string order)
////	{
////		int arr[26] = { 0 };
////		for (int i = 0; i < (int)order.size(); i++) {
////			arr[order[i] - 'a'] = i;
////		}
////		for (int i = 1; i < (int)words.size(); i++)
////		{
////			int begin1 = 0, begin2 = 0;
////			while (begin1 < (int)words[i - 1].size() && begin2 < (int)words[i].size()) {
////				if (arr[words[i - 1][begin1] - 'a'] > arr[words[i][begin2] - 'a'])
////					return false;
////				else if (arr[words[i - 1][begin1] - 'a'] < arr[words[i][begin2] - 'a'])
////					break;
////				begin1++;
////				begin2++;
////			}
////			if (begin1 != (int)words[i - 1].size() && begin2 == (int)words[i].size())
////				return false;
////		}
////		return true;
////	}
////};
//
//class Solution {
//public:
//	bool isAlienSorted(vector<string>& words, string order)
//	{
//		int arr[26] = { 0 };
//		for (int i = 0; i < (int)order.size(); i++) {
//			arr[order[i] - 'a'] = i + 'a';
//		}
//		for (auto& e : words) {
//			for (auto& i : e) {
//				i = arr[i - 'a'];
//			}
//		}
//		return is_sorted(words.begin(), words.end());
//	}
//};
//
//int main()
//{
//	vector<string>words = { "kuvp","q" };
//	string order = "ngxlkthsjuoqcpavbfdermiywz";
//	cout << Solution().isAlienSorted(words, order);
//	return 0;
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
//		int flag = 0, count = 0;
//		string str;
//		char tmp;
//		while (n--)
//		{
//			cin >> tmp >> str;
//			if (str == "connect") {
//				if (flag == 0) {
//					count++;
//					flag++;
//				}
//				flag--;
//			}
//			else if (str == "disconnect") {
//				flag++;
//			}
//		}
//		cout << count << endl;
//	}
//	return 0;
//}


//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		vector<string>arr(n);
//		vector<bool>flag(n, true);
//		for (int i = 0; i < n; i++)
//			cin >> arr[i];
//		sort(arr.begin(), arr.end());
//		for (int i = 0; i < n - 1; i++)
//		{
//			string tmp = arr[i] + '/';
//			if (arr[i + 1].find(tmp) != string::npos || arr[i] == arr[i + 1]) {
//				flag[i] = false;
//			}
//		}
//		for (int i = 0; i < n; i++)
//		{
//			if (flag[i])
//				cout << "mkdir -p " << arr[i] << endl;
//		}
//		cout << endl;
//	}
//	return 0;
//}

