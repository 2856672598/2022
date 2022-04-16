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

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int perfectMenu(vector<int>& materials, vector<vector<int>>& cookbooks, vector<vector<int>>& attribute, int limit) {
		vector<vector<int>>nums;
		for (int i = 0; i < (int)cookbooks.size(); i++)
		{
			vector<int>tmp = materials;
			vector<int>sum(2, 0);
			for (int j = i + i; j < (int)cookbooks.size(); j++)
			{
				if (tmp >= cookbooks[j]) {
					for (int z = 0; z < cookbooks[j].size(); z++)
					{
						tmp[i] -= cookbooks[j][z];
					}
					sum[0] += attribute[j][0];
					sum[1] += attribute[j][1];
				}
			}
			nums.push_back(sum);
		}
		int ret = -1;
		for (auto e : nums)
		{
			if (e[1] >= limit) {
				if (e[0])
					ret = max(ret, e[0]);
			}
		}
		return ret;
	}
};