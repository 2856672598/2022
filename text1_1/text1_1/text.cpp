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


//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//class Solution {
//public:
//	int jump(vector<int>& nums)
//	{
//		int curDistance = 0;
//		int nextDistance = 0;
//		int count = 0;
//		for (int i = 0; i < (int)nums.size() - 1; i++)
//		{
//			nextDistance = max(nums[i] + i, nextDistance);
//			if (i == curDistance)
//			{
//				curDistance = nextDistance;
//				count++;
//			}
//		}
//		return count;
//	}
//};
//int main()
//{
//	vector<int> nums{ 2,0,0 };
//	cout << Solution().jump(nums) << endl;
//	return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//
//class Solution {
//public:
//	bool checkString(string s)
//	{
//		int i = 0;
//		while (i < s.size())
//		{
//			if (s[i] != 'a')
//				break;
//			i++;
//		}
//		for (i; i < s.size(); i++)
//		{
//			if (s[i] == 'a')
//				return false;
//		}
//		return true;
//	}
//};
//
//int main()
//{
//	string s{ "aaabbb" };
//	cout << Solution().checkString(s) << endl;
//	return 0;
//}


//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//	int oneSize(const string& s)
//	{
//		int count = 0;
//		for (int i = 0; i < s.size(); i++)
//		{
//			if (s[i] == '1')
//				count++;
//		}
//		return count;
//	}
//	int numberOfBeams(vector<string>& bank)
//	{
//		int i = 0;
//		int r1 = 0, r2 = 0;
//		int count = 0;
//		for (i; i < bank.size() - 1; i++)
//		{
//			r1 = oneSize(bank[i]);
//			if (r1)
//				break;
//		}
//		i++;
//		while (i < bank.size())
//		{
//			while (i < bank.size())
//			{
//				r2 = oneSize(bank[i]);
//				if (r2)
//					break;
//				i++;
//			}
//
//			count += r1 * r2;
//			r1 = r2;
//			i++;
//		}
//		return count;
//	}
//};
//int main()
//{
//	vector<string>nums{ "011001","000000","010100","001000" };
//	cout << Solution().numberOfBeams(nums) << endl;
//	return 0;
//}


//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//class Solution {
//public:
//	bool asteroidsDestroyed(int mass, vector<int>& asteroids)
//	{
//		sort(asteroids.begin(), asteroids.end());
//		long long tmp = mass;
//		for (int i = 0; i < asteroids.size(); i++)
//		{
//			if (tmp >= asteroids[i])
//				tmp += asteroids[i];
//			else
//				return false;
//		}
//		return true;
//	}
//};


//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//class Solution
//{
//public:
//	static bool compar(const int a, const int b)
//	{
//		return abs(a) > abs(b);
//	}
//
//	int largestSumAfterKNegations(vector<int>& nums, int k)
//	{
//		sort(nums.begin(), nums.end(), compar);
//		int sz = nums.size();
//		for (int i =  0; i < sz; i++)
//		{
//			if (nums[i] < 0 && k>0)
//			{
//				nums[i] = -nums[i];
//				k--;
//			}
//		}
//		//选最小的
//		while (k > 0)
//		{
//			nums[sz - 1] = -nums[sz - 1];
//			k--;
//		}
//		int sum = 0;
//		for (auto e : nums)
//		{
//			sum += e;
//		}
//		return sum;
//	}
//};
//
//int main()
//{
//	vector<int>nums{ -2,9,9,8,4 };
//	int k = 5;
//	cout << Solution().largestSumAfterKNegations(nums, k) << endl;
//	return 0;
//}


#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
	{
		for (int i = 0; i < gas.size(); i++)
		{
			int over = gas[i];
			if (gas[i] < cost[i])
				continue;
			over = gas[i] - cost[i];
			int index = (i + 1) % gas.size();
			while (index != i)
			{
				over += cost[index] - gas[index];
				index = (index + 1) % gas.size();
				if (over < 0)
					break;
			}

			if (index == i)
				return i;
		}
		return -1;
	}
};

int main()
{
	return 0;
}