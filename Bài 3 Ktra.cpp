#include <iostream>

using namespace std;

struct Node{
    int key;
    int bal;
    Node *left; //0 ko lech -1 lech trai 1 lech phai
    Node *right;
    Node *parent;
};

struct Tree{
   Node *root;
   int NumberNode;
   int NumeberLeaf;
   int Hight;

};
Node* createNode(int k);
void InitTree(Tree &T);
int Put(Node *&root, Node* x, Node* parent);
int PutNodeTree(Tree &tree, int x);
void Rotate_LL(Node *&T);
void Rotate_LR(Node *&T);
void Rotate_RR(Node *&T);
void Rotate_RL(Node *&T);

Node* createNode(int k){
   Node *n=new Node;
   n->key=k;
   n->bal=0;
   n->left=NULL;
   n->right=NULL;
   n->parent=NULL;
   return n;
}
int HightTree(Node* t);
int NodeLeaf(Node* t);
void InitTree(Tree &T){
   T.root=NULL;
   T.NumberNode=0;
   T.NumberNode=0;
   T.NumeberLeaf=0;
   T.Hight=0;
}

int Put(Node* &root, Node * x, Node* parent)
{
    // return 0 neu khong lm thay doi chieu cao
    // return 1 chieu cao thay doi
    // return -1 khong chen
    int res=0;
	if(root!=NULL)
	{
		if(root->key == x->key)return -1;
		if(root->key>x->key){
                res=Put(root->left, x,root);
                if(res<1) return res;  // khong lm thay doi chieu cao
                switch(root->bal){
                    case -1:if(root->left->bal==-1)  // LL
                                Rotate_LL(root);
                        
                            if(root->left->bal==1)   // LR
                                Rotate_LR(root);
                            return 0;
                    case 0:  root->bal=-1; return 1;
                    case 1:  root->bal=0 ;  return 0;
                }
              }
		else {
                res=Put(root->right, x,root);
                if(res<1) return res;  // khong lm thay doi chieu cao
                    switch(root->bal){
                        case 1: if(root->right->bal==-1)  // RL
                                    Rotate_RL(root);
                                if(root->right->bal==1)   // RR
                                    Rotate_RR(root);
                                return 0;
                        case 0:  root->bal=1; return 1;
                        case -1:  root->bal=0 ;  return 0;
                    }

	         }
    }
    
	x->parent=parent;
	root=x;
	return 1;
}
int PutNodeTree(Tree &tree, int x){ //insert Node into tree
    Node *p=tree.root;
    Node *X = createNode(x);
    if(Put(p,X,NULL)!=-1){
        if (tree.root !=p)
        {
            tree.root =p;
        }
        
        tree.NumberNode++;
        }
    tree.Hight = HightTree(tree.root);
    tree.NumeberLeaf = NodeLeaf(tree.root);
}
void Rotate_LL(Node * &T)
{
    Node *T1 = T->left, *T2 = T1->left;
	T->left = T1->right; T1->right=T;
	switch(T1->bal)
	{
		case 0:	T->bal =0;
                T1->bal = 1;
                break;
		case -1:T->bal=1;
                T1->bal = 0;
				break;
	}
    
	T=T1;
}

void Rotate_LR(Node *&T){
    Node *T1 = T->left, *T2=T1->right;
    T->left = T2->right; T2->right = T;
    T1->right = T2->left;T2->left = T1;
    switch (T2->bal)
    {
    case -1:
        T->bal = 1;
        T1->bal = 0;
        break;
    case 1:
        T->bal = 0;
        T1->bal = -1;
        break;
    case 0:
        T->bal = 0;
        T1->bal = -1;
        break;
    }
    T2->bal = 0;
    T = T2;
}
int HightTree(Node* t){
    if (t == NULL) return -1;
    if (t->left == NULL && t->right ==NULL){
        return 0;
    }
    else{
        int a = HightTree(t->left);
        int b = HightTree(t->right);
        return a>b?a+1:b+1;
    }
}
void Rotate_RR(Node *&T){
    
    Node *T1 = T->right;
    T->right = T1->left;
    T1->left = T;
    switch (T1->bal)
    {
    case 1:
        T1->bal = 0;
        T->bal = -1;
        break;
    case 0:
        T1->bal = 0;
        T->bal = 0;
        break;
    }
    T = T1;
}
void Rotate_RL(Node *&T){
    
    Node *T1 = T->right, *T2=T1->left;
    T->right = T2->left; T2->left = T;
    T1->left = T2->right;T2->right = T1;
    switch (T2->bal)
    {
    case -1:
        T->bal = 0;
        T1->bal = 1;
        break;
    case 1:
        T->bal = -1;
        T1->bal = 0;
        break;
    case 0:
        T->bal = -1;
        T1->bal = 1;
        break;
    }
    T2->bal = 0;
    T = T2;
}

void TravelLNR(Node *t){
    if(t!=NULL){
      TravelLNR(t->left);
      cout<<t->key<<'\t';
      TravelLNR(t->right);
   }
}

int NodeLeaf(Node* t){
    if (t == NULL) return 0;
    if (t->left == NULL && t->right ==NULL){
        return 1;
    }
    else return NodeLeaf(t->left) + NodeLeaf(t->right);
}


int main()
{
    Tree AVL;
    InitTree(AVL);
    
    PutNodeTree(AVL,15);
    PutNodeTree(AVL,22);
    PutNodeTree(AVL,27);
    PutNodeTree(AVL,5);
    PutNodeTree(AVL,8);
    PutNodeTree(AVL,11);
    PutNodeTree(AVL,30);
    PutNodeTree(AVL,3);
    PutNodeTree(AVL,1);
    PutNodeTree(AVL,2);
    cout <<"Root: " <<AVL.root->key<<"\nHight: "<<AVL.Hight<<"\nNumber Leaf: "<<AVL.NumeberLeaf<<endl;
    TravelLNR(AVL.root);

    return 0;
}
