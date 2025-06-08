class Solution {
public:
    /**
     * Finds the lowest common ancestor (LCA) of two nodes with values startValue and destValue.
     *
     * @param root Root of the binary tree
     * @param startValue Value of the starting node
     * @param destValue Value of the destination node
     * @return Pointer to the LCA node
     */
    TreeNode* commonAncestor(TreeNode* root, int startValue, int destValue) {
        if (!root) return nullptr;

        // If the current node is either start or destination, return it
        if (root->val == startValue || root->val == destValue) return root;

        // Recur on left and right subtrees
        TreeNode* left = commonAncestor(root->left, startValue, destValue);
        TreeNode* right = commonAncestor(root->right, startValue, destValue);

        // If both left and right return non-null, current node is LCA
        if (left && right) return root;

        // Else return whichever is non-null
        return left ? left : right;
    }

    /**
     * Performs DFS to build the path from root to target node.
     *
     * @param root Current node
     * @param target Target value to reach
     * @param path Current path (mutable)
     * @param res Stores the final path when target is found
     * @return True if target is found, false otherwise
     */
    bool dfs(TreeNode* root, int target, string& path, string& res) {
        if (!root) return false;

        if (root->val == target) {
            res = path;
            return true;
        }

        // Explore left subtree
        path.push_back('L');
        if (dfs(root->left, target, path, res)) return true;
        path.pop_back();

        // Explore right subtree
        path.push_back('R');
        if (dfs(root->right, target, path, res)) return true;
        path.pop_back();

        return false;
    }

    /**
     * Returns the directions to go from startValue to destValue.
     *
     * @param root Root of the binary tree
     * @param startValue Start node's value
     * @param destValue Destination node's value
     * @return A string of directions (e.g., "UURL")
     */
    string getDirections(TreeNode* root, int startValue, int destValue) {
        // Step 1: Find Lowest Common Ancestor
        TreeNode* common = commonAncestor(root, startValue, destValue);

        // Step 2: Get path from LCA to start and destination
        string path, toStart, toDest;
        dfs(common, startValue, path, toStart);
        path.clear();  // Reset path for next traversal
        dfs(common, destValue, path, toDest);

        // Step 3: Combine results
        // Replace each step in toStart with 'U' to go up, then append toDest
        return string(toStart.length(), 'U') + toDest;
    }
};
