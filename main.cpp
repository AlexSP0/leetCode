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
    std::vector<int> values;

public:
    Solution() { currentIndex = 0; }

    bool findTarget(TreeNode *root, int k)
    {
        inorderTraversal(root);
        int i = 0, j = values.size() - 1;
        while (i < j)
        {
            if (values[i] + values[j] == k)
            {
                return 1;
            }
            else if (values[i] + values[j] > k)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return 0;
    }

    void inorderTraversal(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            values.push_back(root->val);
            return;
        }
        inorderTraversal(root->left);
        values.push_back(root->val);
        inorderTraversal(root->right);
        return;
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
    TreeNode *firstNode = solution.buildTree({1, 2, -1000, -1000, 3, 4, -1000, -1000, 5});
    std::cout << solution.findTarget(firstNode, 3) << std::endl;
    return 0;
}
