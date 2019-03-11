#ifndef BST_H
#define BST_H

#include <ostream>
#include "data.h"

class BST
{
public:
	BST();
	BST(const BST& aTable);
	~BST();

	const BST& operator= (const BST& aTable);

	void insert(const data& aData);
	bool remove(char ch);
	bool contains(char ch) const;
	int getSize(void) const;

	friend ostream& operator<<(ostream& out, BST& bst);

private:
	struct node
	{
		data item;
		node * left, * right;
		node(const data& aData) :
			item(aData), left(0), right(0)
		{
		}
	};
	node * root;	
	int size;
	
	void insert(node*& root, const data& aData);
	bool contains(node& root, char ch) const;
	bool remove(node*& root, char ch);
	void deleteNode(node *& target);
	void display(ostream& out, node * root, int level) const;
	void destroyTree(node*& root);
	void copyTree(node*& newRoot, node * root);
};
#endif