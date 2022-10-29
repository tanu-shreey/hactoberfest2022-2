
	
  #include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct node {
	char ch;
	node* left;
	node* right;
	node (int c) {
		ch = c;
		left = NULL;
		right = NULL;
	}
	void makeChild (node* l, node* r) {
		left = l;
		right = r;
	}
};

//dfs uses stack for traversing TC = O(N) and SC = O👎
void recursive_dfs(node* root) {
	if (root == NULL) {
		cout << "Tree is empty.\n";
		return;
	}

  
  
  
  
  
  
  cout << root->ch << " ";
	if (root->left != NULL) recursive_dfs(root->left);
	if (root->right != NULL) recursive_dfs(root->right);
}

void iterative_dfs(node* root) {
	if (root == NULL) {
		cout << "Tree is empty.\n";
		return;		
	}
	
	stack<node*> stack;
	stack.push(root);
	
	while (!stack.empty()) {
		node* current = stack.top();
		cout << current->ch << " ";
		stack.pop();
		
		if (current->right != NULL) stack.push(current->right);
		if (current->left != NULL) stack.push(current->left);
	}
}


//BFS uses queue tc and sc is same as DFS
void bfs(node* root) {
	if (root == NULL) {
		cout << "Tree is empty.\n";
		return;		
	}
	
	queue<node*> queue;
	queue.push(root);
	
	while (!queue.empty()) {
		node* current = queue.front();
		cout << current->ch << " ";
		queue.pop();
		
		if (current->left != NULL) queue.push(current->left);
		if (current->right != NULL) queue.push(current->right);
	}
}

int main() {
	node* head = NULL;
	node a('A'), b('B'), c('C'), d('D'), e('E'), f('F'), g('G'), h('H'), i('I');
	head = &a;
	a.makeChild(&b, &c);
	b.makeChild(&d, &e);
	c.makeChild(NULL, &f);
	e.makeChild(&g, NULL);
	f.makeChild(&h, &i);
/*	
				A
			  /   \	
			B      C
		  /   \     \
		 D     E     F
		     /     /   \
		    G     H     I
*/	
	cout << "Depth First Search Traversing of binary tree....\n";
	cout << "RECURSIVE : ";
	recursive_dfs(head);
	cout << "\nITERATIVE : ";
	iterative_dfs(head);
	
	cout << "\n\nBreadth First Search Travering of binary tree....\n";
	cout << "ITERATIVE : ";
	bfs(head);
}
