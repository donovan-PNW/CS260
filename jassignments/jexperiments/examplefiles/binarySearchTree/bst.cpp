#include "BST.h"
#include <ostream>
using namespace std;

/************************
private:
	node * root;	
	int size;
************************/
BST::BST() : root(NULL), size(0)
{
}

BST::BST(const BST& aTable):root(NULL), size(aTable.size)
{
	*this = aTable;
}

const BST& BST::operator= (const BST& aTable)
{
	if(this == &aTable)
		return *this;
	else
	{
		//release dynamically allocated memory held by current object
		destroyTree(root); 

		//copy the table
		copyTree(root, aTable.root);
		return *this;
	}
}
void BST::copyTree (node*& newRoot, node * root)
{
	if(root)
	{
		//copy root
		newRoot = new node(root->item);
		copyTree(newRoot->left, root->left);
		copyTree(newRoot->right, root->right);
	}
	else
	{
		newRoot = NULL;
	}
}

BST::~BST()
{
	destroyTree(root); 
}

void BST::destroyTree (node *& root)
{
	if(root)
	{
		destroyTree(root->left);
		destroyTree(root->right);
		delete root;
		root = NULL;
	}
}

void BST::insert (const data& aData)
{	
	insert(root, aData);
}

void BST::insert (node*& root, const data& aData)
{
	if(!root)
	{
		root = new node(aData);
		size++;
	}
	else if(aData < root->item )
	{
		insert(root->left, aData);
	}
	else
	{
		insert(root->right, aData);
	}
}

bool BST::remove (char ch)
{
	return remove(root, ch);
}

bool BST::remove (node*& root, char ch)
{
	if(!root)
		return false;
	else if(ch == root->item.ch) {
		deleteNode(root);
		return true;
		}
	else if (ch < root->item.ch)
		return remove(root->left, ch);
	else
		return remove(root->right, ch);
}

void BST::deleteNode (node *& target)
{
	node * temp;

	//a leaf
	if(!target->left && !target->right)
	{
		delete target;
		target = NULL;
	}
	//no left child
	else if(!target->left)
	{
		temp = target;
		target = target->right;
		temp->right = NULL;
		delete temp;
	}
	//no right child
	else if(!target->right)
	{
		temp = target;
		target = target->left;
		temp->left = NULL;
		delete temp;
	}
	//two children
	else
	{
		//find the inorder successor
		node * prev = NULL;
		node * curr = target->right;
		while(curr->left)
		{
			prev = curr;
			curr = curr->left;
		}

		//copy data at curr (the inorder successor) into target
		target->item = curr->item;

		//disconnect curr (the inorder successor)
		if(!prev)
			target->right = curr->right;
		else
			prev->left = curr->right; //the inorder successor could have a right child

		//delete curr (the inorder successor)
		curr->right = NULL;
		delete curr;
	}
	size--;
}


bool BST::contains (char ch) const
{
	return contains(*root, ch);
}

bool BST::contains(node& root, char ch) const
{
	if(ch == root.item.ch)
		return true;
	else if(ch < root.item.ch)
		return root.left  ? contains(*root.left, ch)  : false;
	else
		return root.right ? contains(*root.right, ch) : false;
}

static void printLevelSpacers(ostream& out, int spacers)
{
	for (int i = 0; i < spacers; i++)
		out << "  ";
}

void BST::display (ostream& out, node * root, int level)const
{
	if (root) {
		printLevelSpacers(out, level - 1);
		if (level)
			out << "|-";
		out << root->item << endl;
		if (root->left || root->right) {
			if (root->left)
				display(out, root->left, level + 1);
			else {
				printLevelSpacers(out, level);
				out << '|' << endl;
				}
			if (root->right)
				display(out, root->right, level + 1);
			else {
				printLevelSpacers(out, level);
				out << '|' << endl;
				}
			}
		}
}

ostream& operator<<(ostream& out, BST& bst)
{
	bst.display(out, bst.root, 0);
	return out;
}

int BST::getSize (void) const
{
	return size;
}

	


