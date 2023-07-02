//Lecture 24

// Diameter of a Binary Tree
#include <bits/stdc++.h>
using namespace std;

struct Node  
{ 
  int key; 
  struct Node *left; 
  struct Node *right; 
  Node(int k){
      key=k;
      left=right=NULL;
  }
};

int res=0;
int height(Node *root){
    if(root==NULL)
        return 0;
    int lh=height(root->left);
    int rh=height(root->right);
    res=max(res,1+lh+rh);
    
        return 1+max(lh,rh);
}
// efficient approach
int diameter(TreeNode *root,int *height){
    if(root==NULL){
        *height=0;
        return 0;
    }
    int lh=0,rh=0,ld=0,rd=0;
    ld =diameter(root->left,&lh); 
    rd =diameter(root->right,&rh);

    *height=max(lh,rh)+1;
    return max(lh,rh+1,max(ld,rd));
}

int main() {
	
	Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->right->left=new Node(40);
	root->right->right=new Node(60);
	root->right->left->left=new Node(50);
	root->right->right->right=new Node(70);
	
	cout<<"Height: "<<height(root)<<endl;
	cout<<"Diameter: "<<res;
}

#include <bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	Node *left, *right;
};

struct Node* newNode(int key)
{
	struct Node* node = new Node;
	node->key = key;
	node->left = node->right = NULL;
	return node;
}


void getVerticalOrder(Node* root, int hd,
					map<int, vector<int> >& m)
{
	if (root == NULL)
		return;
	m[hd].push_back(root->key);
	getVerticalOrder(root->left, hd - 1, m);
	getVerticalOrder(root->right, hd + 1, m);
}

void printVerticalOrder(Node* root)
{
	map<int, vector<int> > m;
	int hd = 0;
	getVerticalOrder(root, hd, m);

	map<int, vector<int> >::iterator it;
	for (it = m.begin(); it != m.end(); it++) {
		for (int i = 0; i < it->second.size(); ++i)
			cout << it->second[i] << " ";
		cout << endl;
	}
}


int main()
{
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->right->left->right = newNode(8);
	root->right->right->right = newNode(9);
	cout << "Vertical order traversal is \n";

	
	printVerticalOrder(root);
	return 0;
}

class Solution {
public:
    map<int,map<int,multiset<int>>>m;
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>a;
        if(!root)return a;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(q.size()){
            auto x = q.front();
            TreeNode* node=x.first;
            q.pop();
            int val = x.first->val;
            int v=x.second.first,l=x.second.second;
            m[v][l].insert(val);
            if(node->left){
                q.push({node->left,{v-1,l+1}});
            }
            if(node->right){
                q.push({node->right,{v+1,l+1}});
            }
        }
        for(auto i : m){
            vector<int>v;
            for(auto j:i.second){
                for(auto g : j.second)
                v.push_back(g);
            }
            a.push_back(v);
        }
        return a;
    }
};
