#include "AVLTree.h"
#include "RBTree.h"
#include <vector>
#include <time.h>
int main()
{
	srand((long long)time(nullptr));
	//AVLTree<int, int> tree;
	wkn::RBTree<int, int>tree;
	vector<int>nums{ 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	//for (int i = 0; i < (int)nums.size(); i++)
	//{
	//	tree.Insert({ nums[i],nums[i] });
	//}

	for (int i = 0; i < 10000; i++)
	{
		int tmp = rand() % 10000;
		tree.Insert({ tmp,1 });
	}

	tree.Inorder();
	cout << tree.IsBalance() << endl;
	return 0;
}

