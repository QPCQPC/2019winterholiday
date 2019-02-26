#include <iostream>
using namespace std;

class BSTNode {
public:
    int key;
    BSTNode* left;
    BSTNode* right;
    BSTNode* parent;
    BSTNode():parent(NULL) {}
    BSTNode(int key, BSTNode* left, BSTNode* right, BSTNode* parent) :key(key), left(left), right(right), parent(parent) {}
};
class Tree {
private:
    BSTNode* root;
public:
    Tree() :root(NULL) {};
    BSTNode* getRoot() {return root;}
    void insert(int key);
    void insert(BSTNode*& root, BSTNode* node);
    void preOrder(BSTNode* root);
    void inOrder(BSTNode* root);
    void postOrder(BSTNode* root);
};
void Tree::insert(BSTNode*& root, BSTNode* node)
{
    BSTNode* y = NULL;
    BSTNode* x = root;
    while (x != NULL)
    {
        y = x;
        if (node->key > x->key)
            x = x->right;
        else x = x->left;
    }
    node->parent = y;
    if (y == NULL)
        root = node;
    else if(y->key > node->key)
        y->left = node;
    else y->right = node;
}

void Tree::insert(int key)
{
    BSTNode* node = new BSTNode(key, NULL, NULL, NULL);
    insert(root, node);
}
void Tree::preOrder(BSTNode* root)
{
    if (root != NULL)
    {
        cout << root->key;
        preOrder(root->left);
        preOrder(root->right);
    }
}
void Tree::inOrder(BSTNode* root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->key;
        inOrder(root->right);
    }
}
void Tree::postOrder(BSTNode* root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->key;
    }
}
int main()
{
	int t, num;
	Tree* tree = new Tree;
	cout << "请输入数据，输入-1时停止建树 : ";
    while (cin >> t && t != -1)
		tree->insert(t);
	while (cin >> num && num != 0)
    {
		if (num == 1)
        {
			cout << "先序遍历 :";
			tree->preOrder(tree->getRoot());
		}
		else if (num == 2)
		{
			cout << "中序遍历 :";
			tree->inOrder(tree->getRoot());
		}
		else if (num == 3)
		{
			cout << "后序遍历 :";
			tree->postOrder(tree->getRoot());
		}
		else
		cout << "Wrong!" << endl;
	}
	return 0;
}

