#include "AVLTree.h"

int main()
{
	AVLTree<int, int> tree;
	tree.Insert({ 1,1 });
	tree.Insert({ 2,2 });
	tree.Insert({ 3,3 });
	tree.Insert({ 4,4 });

	return 0;
}