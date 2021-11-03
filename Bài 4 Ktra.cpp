#include<iostream>
using namespace std;

#define M 11

struct Node
{
	int value;
	Node *next;
};

void initHash(Node *heads[]){
	for (int i = 0; i< M; i++)	
	{
		heads[i] = NULL;
	}
}

Node* createNode(int x)
{
	Node *p = new Node;
	p->value = x;
	p->next = NULL;
	return p;
}

int hashFunc(int value)
{
	return (value+5) % M;
}

void insertNode(Node *heads[],int value)
{
	int h = hashFunc(value);
	Node *r = heads[h];
	
	Node *prev = NULL;
	while(r != NULL && r->value < value)
	{
		prev = r;
		r= r->next;	
	}
	
	Node *p = createNode(value);
	if (prev == NULL)
	{
		heads[h] = p;
		p -> next = r;	
	}
	else if( r == NULL ) 
	{
		prev -> next = p;
	}
	else
	{
		p->next = r;
		prev->next = p;	
	}
}

void display( Node *heads[])
{
	for(int i = 0; i < M; i++)
	{
		if( heads[i] != NULL)
		{
			cout<<"===BUCKET "<<i<< "===="<<endl;
			Node *p = heads[i];
			
			while( p != NULL)
			{
				cout<< p -> value <<"\t";
				p = p -> next;
			}
			cout<< \endl;
		}
	}
}

Node *search(Node *heads[],int value)
{
	int h = hashFunc(value);
	Node *r = heads[h];
	while(r != NULL && r->value != value)
	{
		r = r->next;	
	}
	return r;
}

int main()
{
	Node *heads[M];
	initHash(heads);
	insertNode(heads, 12);
	insertNode(heads, 45);
	insertNode(heads, 15);
	insertNode(heads, 33);
	insertNode(heads, 94);
	insertNode(heads, 11);
	insertNode(heads, 89);
	insertNode(heads, 20);
	insertNode(heads, 16);
	insertNode(heads, 56);
	insertNode(heads, 89);
	display(heads);
	return 0;
}
