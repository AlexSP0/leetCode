#include <iostream>
#include <vector>

#include <memory>

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
    inline static int currentLevel;
    inline static int maxLevel;
    std::vector<std::unique_ptr<TreeNode>> mNodes;

public:
    Solution() {
        Solution::currentLevel = 0;
        Solution::maxLevel = 0;
    }

    int maxDepth(TreeNode *root)
    {
        std::vector<std::vector<int>> result;

        if (root == nullptr)
        {
            return 0;
        }

        if (root->left == nullptr && root->right == nullptr)
        {
            return 1;
        }

        visitNode(root, result);
        return maxLevel;
    }

    void visitNode(TreeNode *node, std::vector<std::vector<int>> &result)
    {
        if (node != nullptr)
        {
            currentLevel++;
            if(maxLevel < currentLevel) maxLevel = currentLevel;
            visitNode(node->left, result);
            visitNode(node->right, result);
            currentLevel--;
        }
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
    TreeNode *firstNode     = solution.buildTree({3,9,-1000, -1000, 20, 15,-1000,-1000,7});
    std::cout << solution.maxDepth(firstNode) << std::endl;
    return 0;
}
