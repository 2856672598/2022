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


//#include<iostream>
//#include<vector>
//using namespace std;
//
////class Solution {
////public:
////	int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
////	{
////		for (int i = 0; i < gas.size(); i++)
////		{
////			int over = gas[i];
////			if (gas[i] < cost[i])
////				continue;
////			over = gas[i] - cost[i];
////			int index = (i + 1) % gas.size();
////			while (index != i)
////			{
////				over = over - cost[index] + gas[index];
////				if (over < 0)
////					break;
////				index = (index + 1) % gas.size();
////			}
////
////			if (index == i)
////				return i;
////		}
////		return -1;
////	}
////};
//
//
//class Solution {
//public:
//	int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
//	{
//		int curSum = 0;
//		int totalSum = 0;
//		int statu = 0;
//		for (int i = 0; i < gas.size(); i++)
//		{
//			curSum += gas[i] - cost[i];
//			totalSum += gas[i] - cost[i];
//			if (curSum < 0)
//			{
//				statu = i + 1;
//				curSum = 0;
//			}
//		}
//
//		if (totalSum < 0)
//			return -1;
//		return statu;
//	}
//};
//
//
//int main()
//{
//	vector<int>gas{ 2,3,4 };
//	vector<int>cost{ 3,4,3 };
//	cout << Solution().canCompleteCircuit(gas, cost) << endl;
//	return 0;
//}


//#include<iostream>
//using namespace std;
//
//class Solution
//{
//public:
//	string dayOfTheWeek(int day, int month, int year)
//	{
//		string week[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
//		int count = 0;
//		for (int i = 1971; i < year; i++)
//		{
//			if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
//				count += 366;
//			else
//				count += 365;
//		}
//		int nums[13] = { 0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//		for (int i = 1; i < month; i++)
//		{
//			count += nums[i];
//			if ((year % 4 == 0 && year % 100 != 0 || year % 400 == 0) && i == 2)
//				count += 1;
//		}
//		count += day;
//		return week[((count % 7) + 4) % 7];
//	}
//};
//
//int main()
//{
//	return 0;
//}


//#include<iostream>
//#include<string>
//using namespace std;
//
//
//class Solution
//{
//public:
//	int balancedStringSplit(string s)
//	{
//		int count = 0;
//		int flag = 0;
//		for (auto e : s)
//		{
//			if (e == 'L')
//				flag++;
//			else
//				flag--;
//
//			if (flag == 0)
//				count++;
//		}
//		return count;
//	}
//};
//
//int main()
//{
//	string s = { "RLRRLLRLRL" };
//	cout << Solution().balancedStringSplit(s);
//	return 0;
//}

//#include<iostream>
//#include<cstdlib>
//#include<string>
//using namespace std;
//
//class Solution {
//public:
//	int maximum69Number(int num)
//	{
//		string s = to_string(num);
//		for (auto& e : s)
//		{
//			if (e == '6')
//			{
//				e = '9';
//				break;
//			}
//		}
//		return stoi(s);
//	}
//};
//
//int main()
//{
//	int num = 9996;
//	cout << Solution().maximum69Number(num) << endl;
//	return 0;
//}

////1827. 最少操作使数组递增
//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//	int minOperations(vector<int>& nums)
//	{
//		int count = 0;
//		for (int i = 1; i < (int)nums.size(); i++)
//		{
//			if (nums[i] <= nums[i-1])
//			{
//				int tmp = nums[i - 1] + 1;
//				count += tmp - nums[i];
//				nums[i] = tmp;
//			}
//		}
//		return count;
//	}
//};
//
//int main()
//{
//	vector<int>nums{ 1,5,2,4,1 };
//	cout << Solution().minOperations(nums) << endl;
//	return  0;
//}


//#include<iostream>
//#include<string>
//#include<algorithm>
//using namespace std;
//
//class Solution {
//public:
//	int minTimeToType(string word)
//	{
//		int count = 0;
//		int cur = 'a', prev = 'a';
//		for (auto e : word)
//		{
//			cur = e;
//			count += 1 + min(abs(cur - prev), 26 - abs(cur - prev));
//			prev = cur;
//		}
//		return count;
//	}
//};
//
//int main()
//{
//	string word{ "abc" };
//	cout << Solution().minTimeToType(word) << endl;
//	return 0;
//}

//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//class Solution {
//public:
//	int maxIncreaseKeepingSkyline(vector<vector<int>>& grid)
//	{
//		vector<int>row, col;
//		row.resize(grid.size()), col.reserve(grid.size());
//		for (int i = 0; i < (int)grid.size(); i++)
//		{
//			for (int j = 0; j < (int)grid[i].size(); j++)
//			{
//				row[i] = max(grid[i][j], row[i]);
//				col[j] = max(grid[i][j], col[j]);
//			}
//		}
//		int sum = 0;
//		for (int i = 0; i < (int)grid.size(); i++)
//		{
//			for (int j = 0; j < (int)grid[i].size(); j++)
//			{
//				sum += min(row[i], col[j]) - grid[i][j];
//			}
//		}
//		return sum;
//	}
//};
//int main()
//{
//	return 0;
//}


//1877. 数组中最大数对和的最小值
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int minPairSum(vector<int>& nums)
	{
		sort(nums.begin(), nums.end());
		int left = 0, right = nums.size() - 1;
		int ret = nums[left] + nums[right];
		while (left < right)
		{
			ret = max(ret, nums[left++] + nums[right--]);
		}
		return ret;
	}
};

int main()
{
	vector<int>nums = { 3,5,4,2,4,6 };
	cout << Solution().minPairSum(nums) << endl;
	return 0;
}