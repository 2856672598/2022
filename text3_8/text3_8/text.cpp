//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Solution {
//public:
//	int removeDuplicates(vector<int>& nums) {
//		if (nums.size() == 0)
//			return 0;
//		int prev = 0, cur = 1;
//		while (cur < nums.size())
//		{
//			if (nums[cur] != nums[prev]) {
//				nums[++prev] = nums[cur];
//			}
//			cur++;
//		}
//		return ++prev;
//	}
//};
//
//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//	vector<vector<int>> generate(int numRows) {
//		vector<vector<int>>ret;
//		for (int i = 0; i < numRows; i++)
//		{
//			ret.push_back(vector<int>(i + 1, 1));
//		}
//
//		for (int i = 0; i < numRows; i++)
//		{
//			for (int j = 1; j < i; j++)
//			{
//				ret[i][j] = ret[i - 1][j - 1] + ret[i - 1][j];
//			}
//		}
//		return ret;
//	}
//};

//#include<iostream>
//#include<vector>
//using namespace std;
//class Solution {
//public:
//	void BackTracking(int n, int index, int& count, vector<bool>&used)
//	{
//		if (index > n)
//		{
//			count++;
//			return;
//		}
//		for (int i = 1; i <= n; i++)
//		{
//			if (used[i] == true)
//				continue;
//			if (i % index == 0 || index % i == 0)
//			{
//				used[i] = true;
//				BackTracking(n, index + 1, count, used);
//				used[i] = false;
//			}
//		}
//	}
//
//	int countArrangement(int n) {
//		vector<bool>used(n + 1, false);
//		int count = 0;
//		BackTracking(n, 1, count, used);
//		return count;
//	}
//};
//
//int main()
//{
//	int n = 2;
//	cout << Solution().countArrangement(n);
//	return 0;
//}

