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

    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        if (root->left == nullptr && root->right == nullptr)
        {
            return root;
        }

        preOrderVisit(root);
        return root;
    }

    void preOrderVisit(TreeNode *node)
    {
        if (node != nullptr)
        {
            preOrderVisit(node->left);
            preOrderVisit(node->right);
            TreeNode *temp = node->left;
            node->left     = node->right;
            node->right    = temp;
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
    TreeNode *firstNode = solution.buildTree(
        {4, 2, 1, -1000, -1000, 3, -1000, -1000, 7, 6, -1000, -1000, 9});
    TreeNode *result = solution.invertTree(firstNode);
    std::cout << "Hello world!" << std::endl;
    return 0;
}
