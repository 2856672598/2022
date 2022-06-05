#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

//class Solution {
//public:
//	int minMaxGame(vector<int>& nums)
//	{
//		while (nums.size() != 1)
//		{
//			vector<int>newNums;
//			for (int i = 0; i < (int)nums.size() / 2; i++)
//			{
//				if (i % 2 == 0) {
//					newNums.push_back(min(nums[2 * i], nums[2 * i + 1]));
//				}
//				else
//					newNums.push_back(max(nums[2 * i], nums[2 * i + 1]));
//			}
//			nums = newNums;
//		}
//		return nums[0];
//	}
//};

//class Solution {
//public:
//	vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations)
//	{
//		unordered_map<int, int>m;
//		for (int i = 0; i < nums.size(); i++)
//			m.insert({ nums[i],i });
//		for (auto e : operations)
//		{
//			int  pos = m[e[0]];
//			int tmp = nums[pos];
//			nums[pos] = e[1];
//			m.erase(tmp);
//			m.insert({ e[1],pos });
//		}
//		return nums;
//	}
//};


class Solution {
public:
	int partitionArray(vector<int>& nums, int k)
	{
		sort(nums.begin(), nums.end());
		int ret = 1, min = nums[0];
		for (int i = 0; i < (int)nums.size(); i++)
		{
			if (nums[i] - min > k)
			{
				ret++;
				min = nums[i];
			}
		}
		return ret;
	}
};

int main()
{
	vector<int>nums{ 1,2,3 };
	int k = 1;
	cout << Solution().partitionArray(nums, k);
	return 0;
}