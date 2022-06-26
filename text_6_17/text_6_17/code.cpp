//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//class Solution {
//public:
//	void duplicateZeros(vector<int>& arr) {
//		int left = 0, right = arr.size() - 1;
//		while (left < right)
//		{
//			if (arr[left] == 0)
//				right--;
//			left++;
//		}
//
//		int index = arr.size() - 1;
//		while (right >= 0)
//		{
//			arr[index] = arr[right];
//			if (arr[right] == 0 && left != right)
//				arr[--index] = arr[right];
//			right--;
//			index--;
//		}
//	}
//};
//
//int main()
//{
//	vector<int>arr{ 1,5,2,0,6,8,0,6,0 };
//	Solution().duplicateZeros(arr);
//	for (auto e : arr)
//		cout << e << " ";
//	return 0;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Solution {
//public:
//	int findMin(vector<int>& nums) {
//		if (nums.size() == 0)
//			return -1;
//		int left = 0, right = nums.size() - 1;
//		while (left < right)
//		{
//			int mid = left + (right - left) / 2;
//			//最小值在右侧
//			if (nums[mid] > nums[right])
//				left = mid + 1;
//			else if (nums[left] < nums[mid])
//				right = mid - 1;
//			else
//				right -= 1;
//		}
//		return nums[left];
//	}
//};
//
//int main()
//{
//	vector<int>nums{ 1,0,1,1,1 };
//	cout << Solution().findMin(nums);
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
////void Function()
////{
////	return;
////}
////
//////可变参数
////template<class V,class... T>
////void Function(V val, T... args)
////{
////	cout << sizeof...(args) << " ";
////	cout << val << endl;
////	Function(args...);
////}
//
//template<class T>
//int Print(T val = 0)
//{
//	cout << val << endl;
//	return 0;
//}
//
//template<class ...Args>
//void Function(Args... args)
//{
//	int arr[] = { Print(args)... };
//}
//
//int main()
//{
//	Function(1, 12.2, 'h');
//	return 0;
//}


//#include <iostream>
//#include <vector>
//#include <queue>
//
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
//	vector<int> largestValues(TreeNode* root) {
//		if (root == nullptr)
//			return {};
//		vector<int>ret;
//		queue<TreeNode*>q;
//		q.push(root);
//		while (!q.empty()) {
//			int size = q.size();
//			TreeNode* cur = nullptr;
//			int tmp = INT_MIN;
//			for (int i = 0; i < size; i++){
//				cur = q.front();
//				q.pop();
//				if (cur->left)
//					q.push(cur->left);
//				if (cur->right)
//					q.push(cur->right);
//				tmp = max(cur->val, tmp);
//			}
//			ret.push_back(tmp);
//		}
//		return ret;
//	}
//};

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool checkXMatrix(vector<vector<int>>& grid)
	{
		int n = grid.size();
		int x = 0, y = n - 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (j == x || j == y) {
					if (grid[i][j] == 0)
						return false;
				}
				else if (grid[i][j] != 0)
					return false;
			}
			x++;
			y--;
		}
		return true;
	}
};

int main()
{
	vector<vector<int>>grid{ {2,0,0,1},{0,3,1,0},{0,5,2,0},{4,0,0,2} };
	cout << Solution().checkXMatrix(grid);
	return 0;
}