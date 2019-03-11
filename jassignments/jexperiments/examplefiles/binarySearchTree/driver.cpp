// enable Visual Studio's memory leak checking
#ifdef _WIN32
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif

#pragma warning(disable:4305)		// allow conversion of double constants to floats

#include "bst.h"

// This code displays binary search trees in an indented format:
//
//		R
//		|-A
//		  |
//		  |-F
//			|-B
//			  |
//			  |-C
//			|-L
//			  |-G
//			  |-M
//		|-T
//		  |-S
//		  |
//
// In the example above, R is the root node. R's left child is A. R's right child
// is T. A has no left child. A's right child is F. F's left child is B.
//
// R's right child is T. T's left child is S. T has no right child.

int main()
{
	BST*	bst = new BST();

	// insert bst
	bst->insert(data('R'));
	bst->insert(data('A'));
	bst->insert(data('F'));
	bst->insert(data('L'));
	bst->insert(data('B'));
	bst->insert(data('C'));
	bst->insert(data('T'));
	bst->insert(data('G'));
	bst->insert(data('M'));
	cout << "\noriginal BST\n\n" << *bst;

	bst->insert(data('S'));
	cout << "\nafter inserting S\n\n" << *bst;

	cout << "\n'S' is" << (bst->contains('S') ? " " : " not ") << "in the tree" << endl;
	cout << "\n'X' is" << (bst->contains('X') ? " " : " not ") << "in the tree" << endl;

	bst->remove('S');
	cout << "\nafter removing S\n\n" << *bst;

	bst->remove('B');
	cout << "\nafter removing B\n\n" << *bst;

	bst->remove('F');
	cout << "\nafter removing F\n\n" << *bst;

	//test copy constructor
	BST *copy = new BST(*bst);
	cout << "\ncopy of the data set --\n\n" << *copy;

	cout << "\nThank you for testing me!" << endl << endl;

	delete copy;
	delete bst;

// in Visual Studio, report on memory leaks in the Output window
#ifdef _WIN32
	_CrtDumpMemoryLeaks();
#endif

	return 0;
}