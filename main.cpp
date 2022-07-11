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
    inline static int currentSum;
    inline static int currentIndex;
    std::vector<std::unique_ptr<TreeNode>> mNodes;
    inline static bool flag;

public:
    Solution()
    {
        Solution::currentSum = 0;
        flag                 = false;
    }

    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
        {
            return false;
        }

        if (root->left == nullptr && root->right == nullptr)
        {
            if (root->val == targetSum)
            {
                return true;
            }
            return false;
        }

        return preOrderSum(root, targetSum);
    }

    bool preOrderSum(TreeNode *node, int targetSum)
    {
        if (node != nullptr)
        {
            if (node->left == nullptr && node->right == nullptr)
            {
                if (currentSum + node->val == targetSum)
                {
                    flag = true;
                }
            }
            currentSum = currentSum + node->val;
            preOrderSum(node->left, targetSum);
            preOrderSum(node->right, targetSum);
            currentSum = currentSum - node->val;
        }
        return flag;
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
    TreeNode *firstNode = solution.buildTree(
        {5, 4, 11, 7, -1000, -1000, 2, -1000, -1000, -1000, 8, 13, -1000, -1000, 4, -1000, 1});
    std::cout << solution.hasPathSum(firstNode, 22) << std::endl;
    return 0;
}
