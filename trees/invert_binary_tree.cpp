#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 


class Solution {
public:
    // Add your methods here
    TreeNode* invertTree(TreeNode* root){
        if(!root) return nullptr; // if root is null return null ptr
        TreeNode* tempRight = root->right; // add a temp variable similar to swapping two integers 
        root->right = root->left; //swap
        root->left = tempRight;
        root->left = invertTree(root->left); // use recursive function to swap the child nodes as well 
        root->right = invertTree(root->right);
        return root;
    }
};

void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

// inorder means that the tree is printed in the following order left, root, right

int main() {
    Solution sol;
    
    // Call your methods here
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2, new TreeNode(1), new TreeNode(3));
    root->right = new TreeNode(7, new TreeNode(6), new TreeNode(9));


    cout << "Original Tree ";
    printInorder(root);
    cout << endl;

    root = sol.invertTree(root);

    cout << "Inverted Tree ";
    printInorder(root);
    cout << endl;


    
    return 0;
}