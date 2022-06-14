//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//class Solution {
//public:
//	bool strongPasswordCheckerII(string password) {
//		if (password.size() < 8)
//			return false;
//		int flag[4] = { 0 };
//		for (int i = 0; i < (int)password.size(); i++)
//		{
//			if (islower(password[i]))
//				flag[0] = 1;
//			else if (isupper(password[i]))
//				flag[1] = 1;
//			else if (isdigit(password[i]))
//				flag[2] = 1;
//			else if (ispunct(password[i]))
//				flag[3] = 1;
//			if (i > 0 && password[i] == password[i - 1])
//				return false;
//		}
//		for (int i = 0; i < 4; i++)
//			if (flag[i] == 0)
//				return false;
//		return true;
//	}
//};
//
//
//int main()
//{
//	string password = "vpWkmkfSAcCLDBNRfH";
//	cout << Solution().strongPasswordCheckerII(password);
//	return 0;
//}


//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//class Solution {
//public:
//	vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
//		sort(potions.begin(), potions.end());
//		vector<int>ret;
//		for (int i = 0; i < (int)spells.size(); i++)
//		{
//			int left = 0, right = potions.size() - 1;
//			long long sum = 0;
//			while (left < right)
//			{
//				int mid = left + (right - left) / 2;
//				sum = (long long)potions[mid] * spells[i];
//				if (sum < success)
//					left = mid + 1;
//				else
//					right = mid;
//			}
//			sum = (long long)potions[left] * spells[i];
//			if (sum < success)
//				left += 1;
//			ret.push_back(potions.size() - left);
//		}
//		return ret;
//	}
//};
//
//int main()
//{
//	return 0;
//}

//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//class Solution {
//public:
//	bool Check(const string& str1, const string& str2)
//	{
//		char arr[256] = { 0 };
//		if (str2.size() != str1.size())
//			return false;
//		for (int i = 0; i < (int)str1.size(); i++)
//		{
//			if (arr[str1[i]] == 0) {
//				arr[str1[i]] = str2[i];
//			}
//			else if (arr[str1[i]] != str2[i])
//				return false;
//		}
//		return true;
//	}
//	vector<string> findAndReplacePattern(vector<string>& words, string pattern)
//	{
//		vector<string>ret;
//		for (int i = 0; i < (int)words.size(); i++)
//		{
//			if (Check(words[i], pattern) && Check(pattern, words[i]))
//				ret.push_back(words[i]);
//		}
//		return ret;
//	}
//};
//
//int main()
//{
//	vector<string>words{ "abc","deq","mee","aqq","dkd","ccc" };
//	string parrern{ "abb" };
//	Solution().findAndReplacePattern(words, parrern);
//	return 0;
//}


//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//class Solution {
//public:
//	int heightChecker(vector<int>& heights) {
//		vector<int>tmp(heights);
//		sort(tmp.begin(), tmp.end());
//		int ret = 0;
//		for (int i = 0; i < (int)tmp.size(); i++)
//		{
//			if (heights[i] != tmp[i])
//				ret++;
//		}
//		return ret;
//	}
//};

//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//int INF = (int)1e9;
//int main()
//{
//	int m, n;
//	cin >> m >> n;
//	vector<int>pos(m + n, 0), flag(m + n, 0);
//	for (int i = 0; i < m + n; i++)
//		cin >> pos[i];
//	for (int i = 0; i < m + n; i++)
//		cin >> flag[i];
//
//	if (n == 0 || m == 0)
//		return 0;
//
//	vector<int>distance(m + n, INF);
//	int prev = INF;
//	for (int i = 0; i < m + n; i++)
//	{
//		if (flag[i] == 0) {
//			if (prev != INF) {
//				distance[i] = pos[i] - prev;
//			}
//		}
//		else
//			prev = pos[i];
//	}
//
//	prev = INF;
//	for (int i= m + n -1;i>=0;i--)
//	{
//		if (flag[i] == 0) {
//			if (prev != INF && prev - pos[i] < distance[i]) {
//				distance[i] = -1;
//			}
//		}
//		else
//			prev = pos[i];
//	}
//	vector<int> ret(n, 0);
//	int index = -1;
//	for (int i = 0; i < n + m; i++)
//	{
//		if (flag[i] == 0 ) {
//			if (distance[i] > 0)
//				ret[index]++;
//			else {
//				ret[index + 1]++;
//			}
//		}
//		else
//			index++;
//	}
//	for (int i = 0; i < n; i++)
//		cout << ret[i] << " ";
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <unordered_set>
//using namespace std;
//
//int main()
//{
//	int n, m;
//	unordered_set<int>s;
//	cin >> n >> m;
//	vector<int>nums(n, 0);
//	for (int i = 0; i < n; i++)
//		cin >> nums[i];
//	for (int i = 0; i < m; i++)
//	{
//		int tmp;
//		cin >> tmp;
//		s.insert(tmp);
//	}
//	for (int i = 0; i < n; i++) {
//		if (s.find(nums[i]) != s.end())
//			cout << nums[i] << " ";
//	}
//	return 0;
//}


//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//class Solution {
//public:
//	vector<int>ret;
//	void Dfs(int n, int k)
//	{
//		if (k > n)
//			return;
//		ret.push_back(k);
//		if (k * 10 > n)
//			return;
//		for (int i = 0; i < 10; i++)
//			Dfs(n, k * 10 + i);
//	}
//
//	vector<int> lexicalOrder(int n) {
//		for (int i = 1; i < 10; i++)
//			Dfs(n, i);
//		return ret;
//	}
//};


//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Solution {
//public:
//	void DFS(vector<vector<char>>& board, int row, int col)
//	{
//		if (row >= board.size() || row < 0
//			|| col >= board[0].size() || col < 0
//			|| board[row][col] != 'O')
//			return;
//		board[row][col] = 'A';
//		DFS(board, row + 1, col);
//		DFS(board, row - 1, col);
//		DFS(board, row, col + 1);
//		DFS(board, row, col - 1);
//	}
//
//	void solve(vector<vector<char>>& board) {
//		int row = board.size(), col = board[0].size();
//		for (int i = 0; i < row; i++) {
//			DFS(board, i, col - 1);
//			DFS(board, i, 0);
//		}
//		for (int i = 0; i < col; i++) {
//			DFS(board, row - 1, i);
//			DFS(board, 0, i);
//		}
//		for (int i = 0; i < row; i++)
//		{
//			for (int j = 0; j < col; j++) {
//				if (board[i][j] == 'A')
//					board[i][j] = 'O';
//				else
//					board[i][j] = 'X';
//			}
//		}
//	}
//};


//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Solution {
//public:
//	vector<int> findDiagonalOrder(vector<vector<int>>& mat)
//	{
//		int m = mat.size(), n = mat[0].size();
//		vector<int>ret;
//		int row = 0, col = 0;
//		for (int i = 0; i < m + n - 1; i++)
//		{
//			//i为偶数向上走，奇数向下走
//			if (i % 2 == 0) {
//				row = i < m ? i : m - 1;
//				col = i < m ? 0 : i - m + 1;
//				while (row >= 0 && col < n) {
//					ret.push_back(mat[row][col]);
//					row--;
//					col++;
//				}
//			}
//			else {
//				row = i < n ? 0 : i - n + 1;
//				col = i < n ? i : n - 1;
//				while (row < m&&col >= 0) {
//					ret.push_back(mat[row][col]);
//					row++;
//					col--;
//				}
//			}
//		}
//		return ret;
//	}
//};


//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Solution {
//public:
//	vector<int>nums;
//
//	int Find(int index)
//	{
//		if (nums[index] == index)
//			return index;
//		return Find(nums[index]);
//	}
//
//	void merge(int index1, int index2)
//	{
//		int pos1 = Find(index1); 
//		int pos2 = Find(index2);
//		if (pos1 != pos2) {
//			nums[pos2] = pos1;
//		}
//	}
//
//	int findCircleNum(vector<vector<int>>& isConnected) {
//
//		for (int i = 0; i < (int)isConnected.size(); i++)
//		{
//			nums.push_back(i);
//		}
//
//		for (int i = 0; i < (int)isConnected.size(); i++)
//		{
//			for (int j = 0; j < (int)isConnected.size(); j++)
//			{
//				if (isConnected[i][j] == 1) {
//					merge(i, j);
//				}
//			}
//		}
//		int ret = 0;
//		for (int i = 0; i < (int)nums.size(); i++)
//		{
//			if (nums[i] == i)
//				ret++;
//		}
//		return ret;
//	}
//};
//
//int main()
//{
//	vector<vector<int>>isConnected = { {1, 1, 0},{1, 1, 0},{0, 0, 1} };
//	cout << Solution().findCircleNum(isConnected);
//	return 0;
//}


//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Solution {
//public:
//
//	vector<int>nums;
//
//	int find(int index)
//	{
//		if (nums[index] == index)
//			return index;
//		nums[index] = find(nums[index]);
//		return nums[index];
//	}
//
//	void merge(int index1, int index2)
//	{
//		int x = find(index1);
//		int y = find(index2);
//		if (x == y)
//			return;
//		nums[x] = y;
//	}
//
//	int makeConnected(int n, vector<vector<int>>& connections) {
//		if (connections.size() < n - 1)
//			return -1;
//		nums.resize(n);
//		for (int i = 0; i < n; i++)
//			nums[i] = i;
//		for (int i = 0; i < (int)connections.size(); i++)
//		{
//			int pos = find(connections[i][0]);
//			merge(connections[i][1], pos);
//		}
//		int ret = 0;
//		for (int i = 0; i < n; i++)
//			if (nums[i] == i)
//				ret++;
//		return ret - 1;
//	}
//};
//
//int main()
//{
//	vector<vector<int>>connections{ {0,1},{0,2},{1,2} };
//	int n = 4;
//	cout << Solution().makeConnected(n, connections);
//	return 0;
//}

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<int>arr;

	int find(int index)
	{
		if (arr[index] == index)
			return index;
		arr[index] = find(arr[index]);
		return arr[index];
	}

	void merge(int index1, int index2)
	{
		int pos1 = find(index1);
		int pos2 = find(index2);
		if (pos1 == pos2)
			return;
		arr[pos2] = pos1;
	}

	bool equationsPossible(vector<string>& equations)
	{
		for (int i = 0; i < 26; i++)
			arr.push_back(i);

		for (int i = 0; i < (int)equations.size(); i++)
		{
			if (equations[i].find("==") != string::npos)
				merge(equations[i][0] - 'a', equations[i][3] - 'a');
		}
		for (int i = 0; i < (int)equations.size(); i++)
		{
			if (equations[i].find("!=") != string::npos) {
				if (find(equations[i][0] - 'a') == find(equations[i][3] - 'a'))
					return false;
			}
		}
		return true;
	}
};

int main()
{
	vector<string> equations{ "a==b","b!=a" };
	cout << Solution().equationsPossible(equations);
	return 0;
}