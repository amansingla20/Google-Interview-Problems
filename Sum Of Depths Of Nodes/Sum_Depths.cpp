#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node * newNode(int data)
{
    struct node *new_node= (struct node *) malloc (sizeof(struct node));
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;
}
int answer=0; //global variable I have used here........

//Following depth first search approach is used 
// to calculate the sum of depths of each node at each level
void dfs(node *a, int depth)
{
    answer+=depth;
    if(a->left) dfs(a->left, depth+1);
    if(a->right) dfs(a->right, depth+1);
}
//Function used to return the value of sum of depths of nodes......
int Sum_depths(node *root)
{
    answer=0;
    dfs(root,0);
    return answer;
}
int main() {
	struct node* root=newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	root->left->left=newNode(4);
	root->left->right=newNode(5);
	root->right->left=newNode(6);
	root->right->right=newNode(7);
	cout<<"Sum of depths of nodes is: "<<Sum_depths(root);
	return 0;
}
