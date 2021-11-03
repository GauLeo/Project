#include <iostream>

using namespace std;

struct NODE
{
    int data;
    NODE* pLeft;
    NODE* pRight;
};

NODE* CreateNode(int x)
{
    NODE* p = new NODE();
    p->data = x;
    p->pLeft = p->pRight = NULL;
    return p;
}

NODE* FindInsert(NODE* root, int x)
{
    if (root == NULL)
    {
        return NULL;
    }
    NODE* p = root;
    NODE* f = p;
    while (p != NULL)
    {
        f = p;
        if (p->data > x)
        {
            p = p->pLeft;
        }
        else
        {
            p = p->pRight;
        }
    }        
    return f;
}

void InsertNode(NODE* &root, int x)
{
    NODE* n = CreateNode(x);
    if (root == NULL)
    {
        root = n;
        return;
    }
    else
    {
        NODE* f = FindInsert(root, x);
        if (f != NULL)
        {
            if (f->data > x)
            {
                f->pLeft = n;
            }
            else
            {
                f->pRight = n;
            }
        }
    }
}

void CreateTree(NODE* &root, int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        InsertNode(root, a[i]);
    }
}
NODE* SearchNode_Re(NODE* root, int x)
{
    if (root == NULL)
	{
        return NULL;
	}
	if (root->data == x)
	{
		return root;
	}
	if (root->data > x)
	{
		SearchNode_Re(root->pLeft, x);
	}
	else
	{
		SearchNode_Re(root->pRight, x);
	}
}

void NLR(NODE* root)
{
	if (root != NULL)
	{
		cout<<" \t"<<root -> data;
		NLR(root -> pLeft);
		NLR(root -> pRight);
	}
}

void LNR(NODE* root)
{
	if (root != NULL)
	{
		LNR(root->pLeft);
		cout<<" \t"<<root -> data;
		LNR(root->pRight);
	}
}

void LRN(NODE* root)
{
	if (root != NULL)
	{
		LRN(root->pLeft);
		LRN(root->pRight);
		cout<<" \t"<<root -> data;
	}
}

void XoaNode(NODE *root,int data)
{
	if ( root = NULL)
	{
		return;
	}
	else
	{
		if (data < root -> data)
		{
			XoaNode( root -> pLeft, data);
		}
		else (data > root -> data);
		{
			XoaNode( root -> pRight, data);
		}
	}
}

int main()
{
	NODE* root = NULL;
	int a[] = { 10, 6, 2, 7, 15, 12, 29, 14, 34 };
	int n = 9;
	CreateTree(root, a, n);
	LRN(root);
	
	return 0;
}

asdasd
asdasd
asdasd
