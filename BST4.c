#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data; //node will store an integer
    struct node *right_child; // right child
    struct node *left_child; // left child
};

int search(struct node *root, int x)
{
    if(root==NULL)//if root->data is x then the element is found
        return 0;
    
    else if(root->data==x)
    return 1;

    else if(x >root->data) // x is greater, so we will search the right subtree
        return search(root->right_child, x);
    else //x is smaller than the data, so we will search the left subtree
        return search(root->left_child,x);
}

//function to find the minimum value in a node
struct node* find_minimum(struct node *root)
{
    if(root == NULL)
        return NULL;
    else if(root->left_child != NULL) // node with minimum value will have no left child
        return find_minimum(root->left_child); // left most element will be minimum
    return root;
}

void minValue(struct node*root)  
{  
  
/* loop down to find the leftmost leaf */
while (root->left_child != NULL)  
{  
    root = root->left_child;  
}  
printf("The Minimum Value of the Tree is :%d",root->data);  
}  

void maxValue(struct node*root)  
{  
  
/* loop down to find the leftmost leaf */
while (root->right_child != NULL)  
{  
    root = root->right_child;  
}  
printf("The Maximum Value of the Tree is :%d",root->data);  
}  


//function to create a node
struct node* new_node(int x)
{
    struct node *p;
    p = malloc(sizeof(struct node));
    p->data = x;
    p->left_child = NULL;
    p->right_child = NULL;
    
    return p;
}

struct node* insert(struct node *root, int x)
{
    //searching for the place to insert
    if(root==NULL)
        return new_node(x);
    else if(x>root->data) // x is greater. Should be inserted to right
        root->right_child = insert(root->right_child, x);
    else // x is smaller should be inserted to left
        root->left_child = insert(root->left_child,x);
    return root;
}

// funnction to delete a node
struct node* delete(struct node *root, int x)
{
    //searching for the item to be deleted
    if(root==NULL)
        return NULL;
    if (x>root->data)
        root->right_child = delete(root->right_child, x);
    else if(x<root->data)
        root->left_child = delete(root->left_child, x);
    else
    {
        //No Children
        if(root->left_child==NULL && root->right_child==NULL)
        {
            free(root);
            return NULL;
        }

        //One Child
        else if(root->left_child==NULL || root->right_child==NULL)
        {
            struct node *temp;
            if(root->left_child==NULL)
                temp = root->right_child;
            else
                temp = root->left_child;
            free(root);
            return temp;
        }

        //Two Children
        else
        {
            struct node *temp = find_minimum(root->right_child);
            root->data = temp->data;
            root->right_child = delete(root->right_child, temp->data);
        }
    }
    return root;
}

void inorder(struct node *root)
{
    if(root!=NULL) // checking if the root is not null
    {
        inorder(root->left_child); // visiting left child
        printf(" %d ", root->data); // printing data at root
        inorder(root->right_child);// visiting right child
    }
}

void preorder(struct node*root)
{
    if(root!=NULL)
    {
        printf(" %d ",root->data);
        preorder(root->left_child);
        preorder(root->right_child);
    }
}

void postorder(struct node*root)
{
    if(root!=NULL)
    {
        postorder(root->left_child);
        postorder(root->right_child);
        printf(" %d ", root->data);
    }
}

int main()
{
    int choice;
    int number;
    /*
                   20
                 /    \
                /      \
               5       30
             /   \     /\
            /     |   /  \
           1      15 25  40
                /   |       \
               /    23       \
              9             45
            /   \          /
           /     \        /
          7      12      42
    */
    struct node *root;
    root = new_node(20);
    insert(root,90);
    insert(root,43);
    insert(root,15);
    insert(root,9);
    insert(root,7);
    insert(root,12);
    insert(root,30);
    insert(root,25);
    insert(root,40);
    insert(root, 45);
    insert(root, 42);
    insert(root,23);

    printf("\n");

    //root = delete(root, 1);
    /*
                   20
                 /    \
                /      \
               5       30
                 \     /\
                  \   /  \
                  15 25   40
                /           \
               /             \
              9              45
            /   \           /
           /     \         /
          7      12       42
    */

  //  root = delete(root, 40);
    /*
                   20
                 /    \
                /      \
               5       30
                 \     /\
                  \   /  \
                  15 25  45
                 /       / 
                /       /   
               9       42    
             /   \          
            /     \        
           7      12      
    */

//    root = delete(root, 45);
    /*
                   20
                 /    \
                /      \
               5       30
                 \     /\
                  \   /  \
                  15 25  42
                 /          
                /            
               9            
             /   \          
            /     \        
           7      12      
    */
    //root = delete(root, 9);
    while(1){
    printf("Enter the choice:");
    scanf("%d",&choice);
    switch(choice)
    {
    
    case 1:    
    inorder(root);
    break;
    
    case 2:
    preorder(root);
    break;
    
    case 3:
    postorder(root);
    break;
    
    case 4:
    printf("Enter the number to be searched :");
    scanf("%d",&number);
    
    if(search(root,number)==1)
    printf("Found");
    else
    printf("Not found");
    break;
    
    case 5:
    minValue(root);
    break;
    
    case 7:
    maxValue(root);
    break;
    
    case 6:
    exit(0);
    }
    printf("\n");
    }
    
    return 0;
}
