#include "BinarySearchTree.h"

int main()
{
	BSTree<int>root;
	vector<int>nums{ 12,5,18,2,9,15,19,17,16 };
	for (auto e : nums)
		root.InsertR(e);
	root.InOrder();
	root.EraseR(17);
	root.EraseR(16);
	root.EraseR(5);
	root.EraseR(2);

	root.InOrder();
	cout << root.find(12);
	return 0;
}