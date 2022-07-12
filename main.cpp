#include <iostream>
#include <memory>
#include <vector>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode()
        : val(0)
        , left(nullptr)
        , right(nullptr)
    {}
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x)
        , left(left)
        , right(right)
    {}
};

class Solution
{
private:
    inline static int currentIndex;
    std::vector<std::unique_ptr<TreeNode>> mNodes;
    TreeNode *prev = nullptr;

public:
    Solution() { Solution::currentIndex = 0; }

    bool isValidBST(TreeNode *root) { return isValid(root); }
    bool isValid(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }
        if (!isValid(root->left))
        {
            return false;
        }
        if (prev != nullptr && root->val <= prev->val)
        {
            return false;
        }
        prev = root;
        return isValid(root->right);
    }

    TreeNode *buildTree(std::vector<int> values)
    {
        TreeNode *newNode = nullptr;
        if (currentIndex < values.size() && values[currentIndex] < 101
            && values[currentIndex] > -101)
        {
            mNodes.push_back(
                std::make_unique<TreeNode>(TreeNode(values[currentIndex], nullptr, nullptr)));
            newNode = mNodes.back().get();
            currentIndex++;
            newNode->left  = buildTree(values);
            newNode->right = buildTree(values);
        }
        else
        {
            currentIndex++;
        }
        return newNode;
    }
};

int main()
{
    Solution solution;
    TreeNode *firstNode = solution.buildTree({1, 1});
    std::cout << solution.isValidBST(firstNode) << std::endl;
    return 0;
}
