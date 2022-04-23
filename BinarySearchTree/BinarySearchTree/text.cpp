#include "BinarySearchTree.h"

int main()
{
	BSTree<int>root;
	vector<int>nums{ 12,5 };
	for (auto e : nums)
		root.InsertR(e);
	//root.InOrder();
	//root.EraseR(17);
	//root.EraseR(16);
	//root.EraseR(5);
	//root.Erase(12);
	root.EraseR(12);
	root.InOrder();
	cout << root.find(12);
	return 0;
}