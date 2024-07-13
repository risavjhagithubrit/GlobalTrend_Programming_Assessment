#include<bits/stdc++.h>

// Define the structure of a tree node
struct TreeNode {
    int val;           // Value of the node
    TreeNode *left;    // Pointer to the left child
    TreeNode *right;   // Pointer to the right child
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Function to find the maximum path sum in the binary tree
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;   // Initialize maxSum to the smallest possible integer value
        maxGain(root, maxSum);  // Start the recursive calculation from the root
        return maxSum;          // Return the calculated maximum path sum
    }

private:
    // Helper function to calculate the maximum gain from each node
    int maxGain(TreeNode* node, int &maxSum) {
        if (node == nullptr) {  // Base case: if the node is null, return 0
            return 0;
        }
        
        // Recursively get the maximum gain from the left and right subtrees
        int leftGain = std::max(maxGain(node->left, maxSum), 0);
        int rightGain = std::max(maxGain(node->right, maxSum), 0);
        
        // Calculate the current path sum including the current node and both subtrees
        int currentPathSum = node->val + leftGain + rightGain;
        
        // Update the global maximum sum if the current path sum is greater
        maxSum = std::max(maxSum, currentPathSum);
        
        // Return the maximum gain if the current node is considered as the endpoint of the path
        return node->val + std::max(leftGain, rightGain);
    }
};

// Helper function to create a new tree node
TreeNode* newNode(int data) {
    TreeNode* node = new TreeNode(data);
    node->left = node->right = nullptr;
    return node;
}

int main() {
    // Create a sample binary tree
    TreeNode* root = newNode(5);
    root->left = newNode(4);
    root->right = newNode(8);
    root->right->left = newNode(7);
    root->right->right = newNode(9);

    // Create an instance of the Solution class and find the maximum path sum
    Solution solution;
    std::cout << "Maximum Path Sum: " << solution.maxPathSum(root) << std::endl;

    return 0;
}
