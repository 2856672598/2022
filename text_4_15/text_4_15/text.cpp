//#include <iostream>
//#include <vector>
//#include <unordered_set>
//#include <math.h>
//using namespace std;
//
//bool Check(int n)
//{
//	unordered_set<int>s;
//	for (int i = 1; i <= (int)sqrt(n); i++)
//	{
//		if (n%i == 0) {
//			s.insert(i);
//			s.insert(n / i);
//		}
//	}
//	s.erase(n);
//	int sum = 0;
//	for (auto e : s)
//		sum += e;
//	return sum == n;
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	int count = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		if (Check(i))
//			count++;
//	}
//	cout << count << endl;
//	return 0;
//}

//#include <iostream>
//#include <string>
//#include <unordered_map>
//#include <vector>
//using namespace std;
//
//int main()
//{
//	unordered_map<string, int>m;
//	vector<string>flag = { "3","4","5","6","7","8","9","10","J","Q","K","A","2","joker","JOKER" };
//	for (int i = 0; i < (int)flag.size(); i++)
//		m[flag[i]] = i;
//	string tmp;
//	getline(cin, tmp);
//	string s1 = tmp.substr(0, tmp.find('-'));
//	string s2 = tmp.substr(tmp.find('-') + 1);
//	if (s1.size() == s2.size()) {
//		int sum = 0;
//		for (int i = 0; i < s1.size(); i += 2)
//		{
//			sum += m[{s1[i]}];
//			sum -= m[{s2[i]}];
//		}
//		if (sum > 0)
//			cout << s1 << endl;
//		else
//			cout << s2 << endl;
//	}
//	else if (s1.size() == 7 || s1.size() == 11 || s1.size() == 5
//		|| s2.size() == 7 || s2.size() == 11 || s2.size() == 5)
//	{
//		string ret = s1;
//		if (s1.size() <= s2.size())
//			ret = s2;
//		cout << ret << endl;
//	}
//	else
//		cout << "ERROR" << endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	if (n <= 2)
//		cout << -1;
//	else if (n % 2 == 1)
//		cout << 2;
//	else if (n % 4 == 2)
//		cout << 4;
//	else if (n % 4 == 0)
//		cout << 3;
//	return 0;
//}

//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//struct TreeNode {
//	int val;
//	struct TreeNode *left;
//	struct TreeNode *right;
//	TreeNode(int x) :
//			val(x), left(NULL), right(NULL) {
//	}
//};
//class Solution {
//public:
//
//	void sw(TreeNode* root)
//	{
//		if (root == nullptr)
//			return;
//		sw(root->left);
//		sw(root->right);
//		swap(root->left, root->right);
//	}
//
//	void Mirror(TreeNode *pRoot)
//	{
//		sw(pRoot);
//	}
//};


//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//class Solution {
//public:
//	int giveGem(vector<int>& gem, vector<vector<int>>& operations)
//	{
//		for (int i = 0; i < (int)operations.size(); i++)
//		{
//			gem[operations[i][1]] += gem[operations[i][0]] / 2;
//			gem[operations[i][0]] -= gem[operations[i][0]] / 2;
//		}
//		return *max_element(gem.begin(), gem.end()) - *min_element(gem.begin(), gem.end());
//	}
//};

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//class Solution {
//public:
//	int perfectMenu(vector<int>& materials, vector<vector<int>>& cookbooks, vector<vector<int>>& attribute, int limit) {
//		vector<vector<int>>nums;
//		for (int i = 0; i < (int)cookbooks.size(); i++)
//		{
//			vector<int>tmp = materials;
//			vector<int>sum(2, 0);
//			for (int j = i + i; j < (int)cookbooks.size(); j++)
//			{
//				if (tmp >= cookbooks[j]) {
//					for (int z = 0; z < cookbooks[j].size(); z++)
//					{
//						tmp[i] -= cookbooks[j][z];
//					}
//					sum[0] += attribute[j][0];
//					sum[1] += attribute[j][1];
//				}
//			}
//			nums.push_back(sum);
//		}
//		int ret = -1;
//		for (auto e : nums)
//		{
//			if (e[1] >= limit) {
//				if (e[0])
//					ret = max(ret, e[0]);
//			}
//		}
//		return ret;
//	}
//};

//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;

//class Solution {
//public:
//	string _digitSum(string s, int k)
//	{
//		string ret;
//		for (int i = 0; i < (int)s.size(); )
//		{
//			int sum = 0;
//			int sz = i + k > s.size() ? s.size() - i : k;
//			for (int j = 0; j < sz; j++) {
//				sum += s[i] - '0';
//				i++;
//			}
//			ret += to_string(sum);
//		}
//		return ret;
//	}
//
//	string digitSum(string s, int k) {
//		while (true)
//		{
//			if (s.size() <= k)
//				break;
//			s = _digitSum(s, k);
//		}
//		return s;
//	}
//};
//
//int main()
//{
//	string s = "11";
//	cout << Solution().digitSum(s, 3);
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <unordered_map>
//using namespace std;
//
//class Solution {
//public:
//	int minimumRounds(vector<int>& tasks) {
//		unordered_map<int, int>nums;
//		for (auto e : tasks)
//			nums[e]++;
//
//		int count = 0;
//		for (auto e : nums)
//		{
//			int tmp = -1;
//			for (int i = 0; i <= e.second / 3; i++)
//			{
//				if ((e.second - i * 3) % 2 == 0)
//					tmp = i;
//			}
//			if (tmp == -1)
//				return -1;
//			count += (e.second - tmp * 3) / 2 + tmp;
//		}
//		return count;
//	}
//};
//
//int main()
//{
//	vector<int>nums{ 2,2,3,3,2,4,4,4,4,4 };
//	cout << Solution().minimumRounds(nums);
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	int arr[2] = { 1,1 };
//	if (n < 3) {
//		cout << 1 << endl;
//	}
//	else {
//		for (int i = 2; i <= n; i++)
//		{
//			int tmp = arr[1] + arr[0];
//			arr[0] = arr[1];
//			arr[1] = tmp;
//		}
//		cout << arr[0];
//	}
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//
//bool Check(const string &s1, const string& s2, int begin1, int begin2)
//{
//	if (begin1 == s1.size() && begin2 == s2.size())
//		return true;
//	else if (begin1 == s1.size() || begin2 == s2.size())
//		return false;
//
//	if (s1[begin1] == s2[begin2] || s1[begin1] == '?') {
//		if (s1[begin1] == '?' && !isalnum(s2[begin2]))
//			return false;
//		return Check(s1, s2, begin1 + 1, begin2 + 1);
//	}
//	else if (s1[begin1] == '*') {
//		//匹配0个1个或多个
//		return Check(s1, s2, begin1 + 1, begin2) ||
//			isalnum(s2[begin2]) && Check(s1, s2, begin1 + 1, begin2 + 1)
//			|| Check(s1, s2, begin1, begin2 + 1);
//	}
//	return false;
//}
//
//int main()
//{
//	string s1;
//	string s2;
//	cin >> s1 >> s2;
//	if (Check(s1, s2, 0, 0))
//		cout << "true";
//	else
//		cout << "false";
//	return 0;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//	int n;
//	while ((cin >> n) && n != 0)
//	{
//		int count = 0;
//		while (n / 3) {
//			int tmp = n / 3;
//			count += tmp;
//			n %= 3;
//			n += tmp;
//		}
//		if (n == 2)
//			count++;
//		cout << count << endl;
//	}
//	return 0;
//}

//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//	string s1, s2;
//	cin >> s1 >> s2;
//	if (s1.size() > s2.size()) {
//		swap(s1, s2);
//	}
//	string ret;
//	for (int i = 0; i < (int)s1.size(); i++)
//	{
//		for (int j = 0; j < (int)s2.size(); j++)
//		{
//			int begin1 = i, begin2 = j;
//			while (begin1 < (int)s1.size() && begin2 < (int)s2.size() && s1[begin1] == s2[begin2])
//			{
//				if (begin1 - i + 1 > ret.size())
//					ret = s1.substr(i, begin1 - i + 1);
//				begin1++;
//				begin2++;
//			}
//		}
//	}
//	cout << ret;
//	return 0;
//}

//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	string str;
//	cin >> str;
//	int left = 0, right = str.size() - 1;
//	while (left < right)
//		swap(str[left++], str[right--]);
//	cout << str;
//	return 0;
//}

//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//	string s1, s2;
//	cin >> s1 >> s2;
//	int ret = 0;
//	for (int i = 0; i < (int)s1.size(); i++)
//	{
//		for (int j = 0; j < (int)s2.size(); j++)
//		{
//			int begin1 = i, begin2 = j;
//			while (begin1 < s1.size() && begin2 < s2.size() && s1[begin1] == s2[begin2])
//			{
//				begin1++;
//				begin2++;
//			}
//			ret = max(ret, begin2 - j);
//		}
//	}
//	cout << ret;
//	return 0;
//}


//#include <iostream>
//#include <string>
//#include <unordered_set>
//using namespace std;
//
//class Solution {
//public:
//	bool hasAllCodes(string s, int k) {
//		unordered_set<string>flag;
//		for (int i = 0; i + k <= (int)s.size(); i++)
//		{
//			flag.insert(s.substr(i, k));
//		}
//		return flag.size() == 1 << k;
//	}
//};
//
//int main()
//{
//	return 0;
//}


//#include <iostream>
//#include <vector>
//using namespace std;
//
//vector<int> Shuffle(const vector<int>&nums)
//{
//	vector<int>ret;
//	ret.reserve(nums.size());
//	int left = 0, right = nums.size() / 2;
//
//	while (right < nums.size())
//	{
//		ret.push_back(nums[left++]);
//		ret.push_back(nums[right++]);
//	}
//	return ret;
//}
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int n, k;
//		cin >> n >> k;
//		vector<int>nums(2 * n);
//		for (int i = 0; i < 2 * n; i++)
//			cin >> nums[i];
//		while (k--) {
//			nums = Shuffle(nums);
//		}
//		for (int i = 0; i < nums.size(); i++) {
//			cout << nums[i];
//			if (i + 1 < nums.size())
//				cout << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}


//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//	int n;
//	string str;
//	cin >> n >> str;
//	int flag = 1, tail = 4;
//	for(auto e:str)
//	{
//		if (e == 'U') {
//			flag--;
//			if (flag + 3 < tail) {
//				tail--;
//			}
//			if (flag <= 0) {
//				flag = n;
//				tail = flag;
//			}
//		}
//		else if (e == 'D') {
//			flag++;
//			if (flag > n)
//			{
//				flag = 1;
//				tail = 4;
//			}
//			if (flag > tail) {
//				tail++;
//			}
//		}
//	}
//	int begin = (tail - 3) > 0 ? tail - 3 : 1;
//	for (int i = begin; i <= tail; i++)
//		cout << i << " ";
//	cout << endl << flag;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int n, a;
//	while (cin >> n >> a)
//	{
//		int num;
//		for (int i = 0; i < n; i++)
//		{
//			cin >> num;
//			if (num <= a) {
//				a += num;
//			}
//			else {
//				int flag = a;
//				int tmp = 0;
//				while (num%flag)
//				{
//					tmp = num % flag;
//					num = flag;
//					flag = tmp;
//				}
//				a += flag;
//			}
//		}
//		cout << a << endl;
//	}
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//	int arr[255] = { 0 };
//	string str;
//	cin >> str;
//	for (int i = 0; i < (int)str.size(); i++)
//	{
//		arr[str[i]]++;
//	}
//	int ret = -1;
//	for (int i = 0; i < (int)str.size(); i++)
//	{
//		if (arr[str[i]] == 1) {
//			cout << str[i];
//			return 0;
//		}
//	}
//	cout << ret;
//	return 0;
//}


//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//vector<vector<string>>ret;
//
//void BackTracking(const vector<string>&nums, int index, vector<string> tmp, int count, vector<int>&isued)
//{
//	//当找到count个元素后就跳出。
//	if (count == 0) {
//		ret.push_back(tmp);
//	}
//	for (int i = index; i < (int)nums.size(); i++)
//	{
//		//判断当前位置的元素是否被使用
//		if (isued[i] == false) {
//			//递归去找下一个位置
//			tmp.push_back(nums[i]);
//			isued[i] = true;
//			BackTracking(nums, index + 1, tmp, count - 1, isued);
//			isued[i] = false;
//
//			tmp.pop_back();
//		}
//	}
//}
//
//int  main()
//{
//	vector<string>nums;
//	string tmp;
//	int n;
//	cin >> n;
//	while (n--) {
//		cin >> tmp;
//		nums.push_back(tmp);
//	}
//	int m;
//	cin >> m;
//
//	//记录元素的使用情况
//	vector<int>isued(nums.size(), false);
//	BackTracking(nums, 0, {}, m, isued);
//	for (auto e : ret)
//	{
//		for (int i = 0; i < (int)e.size(); i++)
//			cout << e[i] << " ";
//		cout << endl;
//	}
//	return 0;
//}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//class Solution {
//public:
//	int maxRotateFunction(vector<int>& nums)
//	{
//		int left = nums.size() - 1, sz = nums.size();
//		nums.insert(nums.end(), nums.begin(), nums.end());
//		int ret = INT_MIN;
//		while (left >= 0)
//		{
//			int tmp = 0;
//			for (int i = 0; i < sz; i++) {
//				tmp += i * nums[left + i];
//			}
//			ret = max(ret, tmp);
//			left--;
//		}
//		return ret;
//	}
//};


class Solution {
public:
	int maxRotateFunction(vector<int>& nums)
	{
		int sum = 0, ret = 0, i = 0;
		for (auto e : nums) {
			sum += e;
			ret += e * i;
			i++;
		}
		int tmp = ret, n = nums.size();
		for (i = nums.size() - 1; i > 0; i--)
		{
			tmp += sum - n * nums[i];
			ret = max(ret, tmp);
		}
		return ret;
	}
};

int main()
{
	vector<int>nums{ 4,3,2,6 };
	cout << Solution().maxRotateFunction(nums);
	return 0;
}