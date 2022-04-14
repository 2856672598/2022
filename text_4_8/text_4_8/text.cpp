//#include <iostream>
//#include <queue>
//using namespace std;
//
//struct TreeNode {
//	int val;
//	TreeNode *left;
//	TreeNode *right;
//	TreeNode() : val(0), left(nullptr), right(nullptr) {}
//	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//};
// 
//class Solution {
//public:
//	int deepestLeavesSum(TreeNode* root)
//	{
//		if (root == nullptr)
//			return 0;
//		queue<TreeNode*>q;
//		q.push(root);
//		int prevSum = 0;
//		while (!q.empty())
//		{
//			int sz = q.size();
//			prevSum = 0;
//			while (sz)
//			{
//				if (q.front()->right != nullptr)
//					q.push(q.front()->right);
//				if (q.front()->left != nullptr)
//					q.push(q.front()->left);
//				prevSum += q.front()->val;
//				q.pop();
//				sz--;
//			}
//		}
//		return prevSum;
//	}
//};


//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Solution {
//public:
//	char nextGreatestLetter(vector<char>& letters, char target)
//	{
//		int left = 0, right = letters.size() - 1;
//		int mid = 0;
//		while (left < right)
//		{
//			mid = left + (right - left) / 2;
//			if (letters[mid] <= target)
//				left = mid + 1;
//			else if (letters[mid] > target)
//				right = mid;
//		}
//		return letters[right] <= target ? letters[0] : letters[right];
//	}
//};
//
//int main()
//{
//	vector<char>letters{ 'c','f','j' };
//	char target = 'f';
//	cout << Solution().nextGreatestLetter(letters, target);
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <math.h>
//#include <limits.h>
//using namespace std;
//
//void Approximation(vector<int>&nums, int n)
//{
//	for (int i = 2; i <= sqrt(n); i++)
//	{
//		if (n%i == 0) {
//			nums.push_back(i);
//			if (n / i != i)
//				nums.push_back(n / i);
//		}
//	}
//}
//
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	vector<int>nums(m + 1, INT_MAX);
//	nums[n] = 0;
//	for (int i = n; i < m; i++)
//	{
//		if (nums[i] != INT_MAX) {
//			//可以跳到当前位置
//			vector<int>flag;
//			Approximation(flag, i);
//			for (int j = 0; j < (int)flag.size(); j++)
//			{
//				if (i + flag[j] <= m) {
//					nums[i + flag[j]] = min(nums[i] + 1, nums[i + flag[j]]);
//				}
//			}
//		}
//	}
//	cout << (nums[m] == INT_MAX ? -1 : nums[m]) << endl;
//	return 0;
//}


//#include <iostream>
//#include <unordered_set>
//#include <algorithm>
//using namespace std;
//
//class Solution {
//public:
//	int longestConsecutive(vector<int>& nums)
//	{
//		unordered_set<int>s;
//		for (auto e : nums)
//			s.insert(e);
//		sort(nums.begin(), nums.end());
//		int i = 0;
//		int count = 0;
//		while (i < nums.size())
//		{
//			int j = 0;
//			int tmp = 0;
//			for (j = nums[i];; j++)
//			{
//				if (s.find(j) == s.end()) {
//					break;
//				}
//				tmp++;
//			}
//			count = max(count, tmp);
//			i += tmp;
//		}
//		return count;
//	}
//};


//#include <iostream>
//#include <string>
//#include <algorithm>
//#include <vector>
//#include <unordered_map>
//using namespace std;
//
//class Solution {
//public:
//	int largestInteger(int num) {
//		string tmp = to_string(num);
//		for (int i = 0; i < tmp.size(); i++)
//		{
//			//如果当前位置是偶数去后面找最大的偶数
//			for (int j = i + 1; j < (int)tmp.size(); j++)
//			{
//				if ((tmp[j] - '0') % 2 == (tmp[i] - '0') % 2)
//				{
//					if (tmp[i] < tmp[j])
//						swap(tmp[i], tmp[j]);
//				}
//			}
//		}
//		return stoi(tmp);
//	}
//};

//#include <iostream>
//using namespace std;
//class A 
//{
//public:
//	virtual ~A()
//	{
//		cout << "~A()" << endl;
//	}
//
//};
//
//class B :public A
//{
//public:
//	virtual ~B()
//	{
//		cout << "~B()" << endl;
//	}
//};
//
//int main()
//{
//	A* a = new A;
//	A* b = new B;
//	delete a;
//	delete b;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	virtual void Fun()
//	{
//		cout << "Fun()" << endl;
//	}
//
//	int _a = 0;
//};
//
//class B :public A
//{
//public:
//	virtual void Fun()
//	{
//		cout << "Fun()" << endl;
//	}
//	int _b = 0;
//};
//
//int main()
//{
//	A a;
//	B b;
//	return 0;
//}

//#include <iostream>
//#include <string>
//#include <vector>
//#include <unordered_set>
//using namespace std;
//
////class Solution {
////public:
////	int uniqueMorseRepresentations(vector<string>& words) {
////
////		vector<string>nums{ ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..",
////			"--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };
////		unordered_set<string>flag;
////		for (int i = 0; i < (int)words.size(); i++)
////		{
////			string tmp;
////			for (int j = 0; j < (int)words[i].size(); j++)
////			{
////				tmp += nums[words[i][j] - 'a'];
////			}
////			flag.insert(tmp);
////		}
////		return flag.size();
////	}
////};
//
////class Solution {
////public:
////	int arrangeCoins(int n)
////	{
////		long long prev = 0, i = 1;
////		for (; prev + i <= n; i++)
////		{
////			prev += i;
////		}
////		return i - 1;
////	}
////};


//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Solution {
//public:
//	int Find(const vector<int>&numbers, int left, int right, int target)
//	{
//		while (left <= right)
//		{
//			int mid = left + ((right - left) >> 1);
//			if (numbers[mid] > target)
//				right = mid - 1;
//			else if (numbers[mid] < target)
//				left = mid + 1;
//			else
//				return mid;
//		}
//		return -1;
//	}
//	vector<int> twoSum(vector<int>& numbers, int target)
//	{
//		for (int i = 0; i < (int)numbers.size(); i++)
//		{
//			int num = target - numbers[i];
//			int pos = Find(numbers, i + 1, numbers.size() - 1, num);
//			if (pos != -1)
//				return { i + 1,pos + 1 };
//		}
//		return{ -1,-1 };
//	}
//};
//
//int main()
//{
//	vector<int>numbers{ 2,3,4 };
//	int target = 6;
//	Solution().twoSum(numbers, target);
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//
//class Solution {
//public:
//	int maximumProduct(vector<int>& nums, int k) {
//		int mod = 1E9 + 7;
//		priority_queue<int, vector<int>, greater<int>>pq;
//		for (auto e : nums)
//			pq.push(e);
//		while (k)
//		{
//			int tmp = pq.top();
//			tmp++;
//			pq.pop();
//			pq.push(tmp);
//			k--;
//		}
//		long long ret = 1;
//		while (!pq.empty())
//		{
//			int tmp = pq.top();
//			pq.pop();
//			ret = (ret*tmp) % mod;
//		}
//		return ret;
//	}
//};
//
//int main()
//{
//	vector<int>nums{ 0,4 };
//	int k = 5;
//	cout << Solution().maximumProduct(nums, k);
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <unordered_map>
//#include <time.h>
//using namespace std;
//
//class RandomizedSet {
//	vector<int>nums;
//	unordered_map<int, int>m;//存放某个数对应的下标
//public:
//	RandomizedSet() {
//		srand((unsigned)time(NULL));
//	}
//
//	bool insert(int val) {
//		if (m.count(val))
//			return false;
//		int index = nums.size();
//		nums.push_back(val);
//		m[val] = index;
//		return true;
//	}
//
//	bool remove(int val) {
//		if (nums.size() == 0)
//			return false;
//		if (!m.count(val))
//			return false;
//		int index = m[val];
//		m.erase(val);
//		//将删除的位置和数组中的最后一个位置进行交换
//		nums[index] = nums.back();
//		m[nums.back()] = index;
//		m.erase(val);
//		nums.pop_back();
//		return true;
//	}
//
//	int getRandom() {
//		int pos = rand() % nums.size();
//		return nums[pos];
//	}
//};


//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//	int findKthPositive(vector<int>& arr, int k) {
//		int left = 0, right = arr.size() - 1, mid = 0;
//		while (left < right)
//		{
//			mid = left + (right - left) / 2;
//			if (arr[mid] - mid - 1 < k)
//				left = mid + 1;
//			else
//				right = mid;
//		}
//		if (arr[left] - left > k)
//			return arr[left] - ((arr[left] - left) - k);
//		else
//			return arr[left] + k - (arr[left] - left) + 1;
//	}
//};


//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//	int year, month, day;
//	cin >> year >> month >> day;
//	int count = day;
//	vector<int>nums{ 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
//		nums[2] += 1;
//	for (int i = 1; i < month; i++) {
//		count += nums[i];
//	}
//	cout << count << endl;
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int Backtracking(const vector<int>& nums, int index, int product, int sum)
//{
//	int ret = 0;
//	for (int i = index; i < (int)nums.size(); i++)
//	{
//		product *= nums[i];
//		sum += nums[i];
//		if (sum > product) {
//			ret++;
//			ret += Backtracking(nums, index + 1, product, sum);
//		}
//		else if (nums[i] == 1) {
//			ret += Backtracking(nums, index + 1, product, sum);
//		}
//		else
//			break;
//		product /= nums[i];
//		sum -= nums[i];
//		while (i < (int)nums.size() - 1 && nums[i] == nums[i + 1]) {
//			++i;
//		}
//	}
//	return ret;
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int>nums(n);
//	for (int i = 0; i < n; i++)
//		cin >> nums[i];
//	sort(nums.begin(), nums.end());
//	cout << Backtracking(nums, 0, 1, 0) << endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//int main()
//{
//	long n;
//	while (cin >> n)
//	{
//		int count = 0;
//		while (n) {
//			count++;
//			n = n & n - 1;
//		}
//		cout << count << endl;
//	}
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//class Gloves {
//public:
//	int findMinimum(int n, vector<int> left, vector<int> right) {
//		// write code here
//		int count = 0, leftSum = 0, rightSum = 0;
//		int leftMin = INT_MAX, rightMin = INT_MAX;
//		for (int i = 0; i < n; i++)
//		{
//			if (left[i] == 0 || right[i] == 0)
//				count += left[i] + right[i];
//			else {
//				leftSum += left[i];
//				rightSum += right[i];
//				leftMin = min(leftMin, left[i]);
//				rightMin = min(rightMin, left[i]);
//			}
//		}
//		return count += min(leftSum - leftMin + 1, rightSum - rightMin + 1) + 1;
//	}
//};

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//class Solution {
//public:
//	int maximumWealth(vector<vector<int>>& accounts) {
//		int ret = 0;
//		for (int i = 0; i < (int)accounts.size(); i++)
//		{
//			int tmp = 0;
//			for(int j=0;j<(int)accounts[i].size();j++)
//			{
//				tmp += accounts[i][j];
//			}
//			ret = max(ret, tmp);
//		}
//		return ret;
//	}
//};

//#include <algorithm>
//#include <vector>
//using namespace std;
//
//class Solution {
//public:
//	int findMin(vector<int>& nums) {
//		int left = 0, right = nums.size() - 1;
//		if (nums[left] < nums[right])
//			return nums[left];
//		while (left < right)
//		{
//			int mid = left + (right - left) / 2;
//			if (nums[mid] < nums[right]) {
//				//后半部分有序
//				right = mid;
//			}
//			else {
//				left = mid + 1;
//			}
//		}
//		return nums[left];
//	}
//};

//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Solution {
//public:
//	int search(vector<int>& nums, int target) {
//		int left = 0, right = nums.size() - 1;
//		while (left <= right)
//		{
//			int mid = left + (right - left) / 2;
//			if (nums[mid] == target)
//				return mid;
//			if (nums[left] <= nums[mid]) {
//				//左边是有序的
//				if (nums[left] <= target && target < nums[mid]) {
//					//可能在当前区间中
//					right = mid - 1;
//				}
//				else {
//					left = mid + 1;
//				}
//			}
//			else {
//				if (target > nums[mid] && target <= nums[right])
//					left = mid + 1;
//				else
//					right = mid - 1;
//			}
//		}
//		return -1;
//	}
//};
//
//int main()
//{
//	vector<int>nums{ 3,1 };
//	int target = 1;
//	cout << Solution().search(nums, target);
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//class Solution {
//public:
//
//	bool Check(const vector<int>&nums, int target)
//	{
//		int left = 0, right = nums.size() - 1;
//		while (left < right)
//		{
//			int mid = left + (right - left) / 2;
//			if (nums[mid] > target) {
//				right = mid - 1;
//			}
//			else if (nums[mid] < target)
//				left = mid + 1;
//			else
//				right = mid;
//		}
//		if (nums[left] < target)
//			left++;
//		if (nums.size() - left == target)
//			return true;
//		return false;
//	}
//
//	int specialArray(vector<int>& nums) {
//		sort(nums.begin(), nums.end());
//		for (int i = nums.size(); i >= 0; i--)
//		{
//			if (Check(nums, i))
//				return i;
//		}
//		return -1;
//	}
//};
//
//int main()
//{
//	vector<int>nums{ 0,0 };
//	cout << Solution().specialArray(nums);
//	return 0;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Solution {
//public:
//	int countNegatives(vector<vector<int>>& grid) {
//		int count = 0;
//		for (int i = 0; i < (int)grid.size(); i++)
//		{
//			for (int j = grid[i].size() - 1; j >= 0; j--)
//			{
//				if (grid[i][j] < 0)
//					count++;
//				else
//					break;
//			}
//		}
//		return count;
//	}
//};


//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Solution {
//public:
//	bool searchMatrix(vector<vector<int>>& matrix, int target) {
//		int row = 0, col = matrix[0].size() - 1;
//		while (row < (int)matrix.size() && col >= 0)
//		{
//			if (matrix[row][col] > target)
//				col--;
//			else if (matrix[row][col] < target)
//				row++;
//			else
//				return true;
//		}
//		return false;
//	}
//};

//#include <iostream>
//#include <vector>
//#include <map>
//using namespace std;
//class Solution {
//public:
//	vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
//		multimap<int, int>m;
//		for (int i =  0; i < (int)mat.size(); i++)
//		{
//			int count = 0;
//			for (int j = 0; j < (int)mat[i].size(); j++)
//			{
//				if (!mat[i][j])
//					break;
//				count++;
//			}
//			m.insert({ count,i });
//		}
//		vector<int>ret;
//		auto it = m.begin();
//		while (k)
//		{
//			ret.push_back(it->second);
//			it++;
//			k--;
//		}
//		return ret;
//	}
//};
//int main()
//{
//	vector<vector<int>>mat = { {1, 0, 0, 0},
//		{1, 1, 1, 1},
//		{1, 0, 0, 0},
//		{1, 0, 0, 0} };
//	int k = 2;
//	Solution().kWeakestRows(mat, k);
//	return 0;
//}

//#include <iostream>
//#include <unordered_map>
//#include <vector>
//using namespace std;
//
//class Solution {
//public:
//	bool checkIfExist(vector<int>& arr) {
//		unordered_map<int, int>nums;
//		for (int i = 0; i < (int)arr.size(); i++)
//			nums[arr[i]]++;
//		for (int i = 0; i < (int)arr.size(); i++)
//		{
//			if (2 * arr[i] == arr[i] && nums[arr[i]] == 1)
//				continue;
//
//			if (nums.count(2 * arr[i]))
//				return true;
//		}
//		return false;
//	}
//};

//#include <vector>
//#include <unordered_map>
//#include <algorithm>
//using namespace std;
//
//class Solution {
//public:
//	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
//		unordered_map<int, int>n1, n2;
//		for (auto e : nums1)
//			n1[e]++;
//		for (auto e : nums2)
//			n2[e]++;
//		vector<int>ret;
//		for (auto e : n1)
//		{
//			auto it = n2.find(e.first);
//			if (it != n2.end())
//			{
//				int count = min(it->second, e.second);
//				ret.insert(ret.end(), count, e.first);
//			}
//		}
//		return ret;
//	}
//};

//#include <iostream>
//using namespace std;
//
//class Solution {
//public:
//	bool judgeSquareSum(int c) {
//		for (long long i = 0; i*i <= c; i++)
//		{
//			double tmp = sqrt(c - i * i);
//			if (tmp == (int)tmp)
//				return true;
//		}
//		return false;
//	}
//};

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maxDistance(vector<int>& nums1, vector<int>& nums2) {
		int i1 = 0, i2 = 0;
		for (int i = 0; i < (int)nums1.size(); i++)
		{
			int j = 0;
			for (j = i; j < (int)nums2.size(); j++)
			{
				if (nums1[i] > nums2[j])
					break;
			}
			if (j - i > i2 - i1) {
				i2 = j;
				i1 = i;
			}
		}
		return i2 - i1;
	}
};