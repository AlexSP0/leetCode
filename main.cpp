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
    inline static int currentLevel;
    std::vector<std::unique_ptr<TreeNode>> mNodes;

public:
    Solution() {
        Solution::currentIndex = 0;
        Solution::currentLevel = 0;
    }

    std::vector<std::vector<int>> levelOrder(TreeNode *root)
    {
        std::vector<std::vector<int>> result;

        if (root == nullptr)
        {
            return result;
        }

        if (root->left == nullptr && root->right == nullptr)
        {
            result.push_back({root->val});
            return result;
        }

        visitNode(root, result);
        return result;
    }

    void visitNode(TreeNode *node, std::vector<std::vector<int>> &result)
    {
        if (node != nullptr)
        {

            if(result.size() == currentLevel) {
                result.push_back({});
            }
            result[currentLevel].push_back(node->val);
            currentLevel++;
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
    std::vector<std::vector<int>> result = solution.levelOrder(firstNode);
    std::cout << "Hello world!" << std::endl;
    return 0;
}
