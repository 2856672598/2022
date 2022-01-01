//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//	vector<vector<int>> construct2DArray(vector<int>& original, int m, int n)
//	{
//		if (m*n != (int)original.size())
//			return {};
//		vector<vector<int>>ret;
//		int i = 0;
//		while (i < original.size())
//		{
//			vector<int>path;
//			int row = 0;
//			while (row < n&&i < original.size())
//			{
//				path.push_back(original[i++]);
//				row++;
//			}
//			ret.push_back(path);
//		}
//		return ret;
//	}
//};
//
//int main()
//{
//	vector<int>original{ 1,2,3,4 };
//	int m = 2, n = 2;
//	vector<vector<int>>ret = Solution().construct2DArray(original, m, n);
//	for (auto e : ret)
//	{
//		for (auto t : e)
//			cout << t << " ";
//		cout << endl;
//	}
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution
//{
//public:
//	int maxProfit(vector<int>& prices)
//	{
//		int sum = 0;
//		for (int i = 0; i < (int)prices.size() - 1; i++)
//		{
//			if (prices[i + 1] - prices[i] > 0)
//				sum += prices[i + 1] - prices[i];
//		}
//		return sum;
//	}
//};
//int main()
//{
//	vector<int>prices{ 1,2,3,4,5 };
//	cout << Solution().maxProfit(prices);
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//	bool canJump(vector<int>& nums)
//	{
//		int max = 1;
//		for (int i = 0; i < max; i++)
//		{
//			if (i + nums[i] + 1 > max)
//				max = i + nums[i] + 1;
//			if (max >= nums.size())
//				return true;
//		}
//		return false;
//	}
//};
//
//int main()
//{
//	vector<int>nums{ 2,0,0 };
//	cout << Solution().canJump(nums) << endl;
//	return 0;
//}


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int jump(vector<int>& nums)
	{
		int curDistance = 0;
		int nextDistance = 0;
		int count = 0;
		for (int i = 0; i < (int)nums.size() - 1; i++)
		{
			nextDistance = max(nums[i] + i, nextDistance);
			if (i == curDistance)
			{
				curDistance = nextDistance;
				count++;
			}
		}
		return count;
	}
};
int main()
{
	vector<int> nums{ 2,0,0 };
	cout << Solution().jump(nums) << endl;
	return 0;
}