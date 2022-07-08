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

public:
    Solution() { Solution::currentIndex = 0; }

    std::vector<int> preorderTraversal(TreeNode *root)
    {
        std::vector<int> result;

        if (root == nullptr)
        {
            return result;
        }

        if (root->left == nullptr && root->right == nullptr)
        {
            result.push_back(root->val);
            return result;
        }

        preOrderVisit(root, &result);
        return result;
    }

    void preOrderVisit(TreeNode *node, std::vector<int> *result)
    {
        if (node != nullptr)
        {
            result->push_back(node->val);
            preOrderVisit(node->left, result);
            preOrderVisit(node->right, result);
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
    TreeNode *firstNode     = solution.buildTree({1, 2, -1000, -1000, 3, 4, -1000, -1000, 5});
    std::vector<int> result = solution.preorderTraversal(firstNode);
    std::cout << "Hello world!" << std::endl;
    return 0;
}
