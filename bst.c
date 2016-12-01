#include<stdio.h>
#include<process.h>
#include<malloc.h>
typedef struct bst
{
	int data;
	struct bst *left,*right;
}nd;

nd *root=NULL;

void create()
{
	int c=1;
	nd *ptr,*tmp=(nd*)malloc(sizeof(nd));
	if(root==NULL)
	{
		printf("\nBinary Search Tree Creation\n\nEnter root element:");
		scanf("%d",&tmp->data);
		tmp->left=NULL;
		tmp->right=NULL;
		root=tmp;
		printf("\nDo you want to insert more?(1/0):");
		scanf("%d",&c);
	}
	while(c)
	{
		tmp=(nd*)malloc(sizeof(nd));
		printf("\nEnter element:");
		scanf("%d",&tmp->data);
		tmp->left=NULL;
		tmp->right=NULL;
		ptr=root;
		while(1)
		{
			if(tmp->data<ptr->data)
			{
				if(ptr->left!=NULL)
				ptr=ptr->left;
				else
				{
					ptr->left=tmp;
					printf("\nDo you want to insert more?(1/0):");
					scanf("%d",&c);
					break;
				}
			}	
			else
			{
				if(ptr->right!=NULL)
				ptr=ptr->right;
				else
				{
					ptr->right=tmp;
					printf("\nDo you want to insert more?(1/0):");
					scanf("%d",&c);
					break;
				}
			}
		}
	}
}

void inorder(nd *ptr)
{
	if(ptr)
	{
		inorder(ptr->left);
		printf("%d\t",ptr->data);
		inorder(ptr->right);
	}
}

void preorder(nd *ptr)
{
	if(ptr)
	{
		printf("%d\t",ptr->data);
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

void postorder(nd *ptr)
{
	if(ptr)
	{
		postorder(ptr->left);
		postorder(ptr->right);
		printf("%d\t",ptr->data);	
	}
}

int height(nd *ptr)
{
	
	if(ptr==NULL)
	return 0;
	else
	{
		int ld=height(ptr->left);
		int rd=height(ptr->right);
	
		if(ld>rd)
		return ld+1;
		else
		return rd+1;
	}
}


int main()
{
	int c,key;
	nd *ptr=(nd*)malloc(sizeof(nd));
	create();
	ptr=root;
	printf("\nBinary Search Tree Menu\n1.Insertion\n2.Inorder\n3.Preorder\n4.Postorder\n6.Height\n7.Exit");
	while(1)
	{
		printf("\nEnter you choice:");
		scanf("%d",&c);
		switch(c)
		{
			case 1:create();break;
			case 2:inorder(ptr);break;
			case 3:preorder(ptr);break;
			case 4:postorder(ptr);break;
			case 6:printf("Height: %d",height(ptr));break;
			case 7:exit(0);
		}
	}
	return 0;
}
