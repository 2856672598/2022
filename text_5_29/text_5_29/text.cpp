//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//class Solution {
//public:
//	int rearrangeCharacters(string s, string target)
//	{
//		vector<int>nums1(26, 0), nums2(26, 0);
//		for (auto e : s)
//			nums1[e - 'a']++;
//		for (auto e : target)
//			nums2[e - 'a']++;
//		int ret = INT_MAX;
//		for (auto e : target)
//			ret = min(ret, nums1[e - 'a'] / nums2[e - 'a']);
//		return ret;
//	}
//};
//
//int main()
//{
//	string s = "abbaccaddaeea";
//	string target = "aaaaa";
//	cout << Solution().rearrangeCharacters(s, target);
//	return 0;
//}

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
	string discountPrices(string sentence, int discount)
	{
		stringstream ss(sentence);
		string ret, tmp;
		int i = 0;
		while (ss >> tmp)
		{
			if (tmp[0] == '$') {
				for (int i = 1; i < (int)tmp.size(); i++) {
					if (!isdigit(tmp[i]))
						break;
					if (i == tmp.size() - 1) {
						double num = atof(tmp.substr(1).c_str());
						num = num * ((100 - discount)*0.01);
						tmp = "$";
						//string flag;
						//flag = to_string(num);
						//tmp += flag.substr(0, flag.find('.') + 3);
						char arr[100];
						sprintf(arr, "$%.2lf", num);
						tmp = arr;
						break;
					}
				}
			}
			if (i != 0)
				ret += " ";
			ret += tmp;
			i++;
		}
		return ret;
	}
};
int main()
{
	string sentence = "$2$3 $10 $100 $1 200 $33 33$ $$ $99 $99999 $9999999999";
	int discount = 0;
	cout << Solution().discountPrices(sentence, discount);
	return 0;
}