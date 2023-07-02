//Lecture 22


class TreeNode{
    public: 
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left,TreeNode* right):val(x),left(left),right(right){}
};

void inorder(TreeNode *root, vector<int> &result){
    if(root==NULL) return;
    inorder(root->left);
    result.push_back(root->val); 
    inorder(root->right);
}
vector<int> inorder(TreeNode* root){
    vector<int> result;     
    inorder(root, result);     
    return result;
}

vector<int> preorder(TreeNode* root){
    if(root==NULL)  return {};
    vector<int> result;
    stack <TreeNode*> s;  
    s.push(root);
    TreeNode *temp=root;
    while(true){
        temp=s.top();
        while(temp!=NULL && temp->left!=NULL){
            result.push_back(temp->val);
            s.push(temp);
            temp=temp->left;
        }
        if(s.empty()){
            break;
        }
        temp=s.top();
        s,pop();
        temp=temp->right;
    }
    return result;
}