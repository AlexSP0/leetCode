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

    TreeNode *insert(TreeNode *root, TreeNode *newnode, int val)
    {
        if (root == nullptr)
        {
            return newnode;
        }
        if (root->val < val)
        {
            root->right = insert(root->right, newnode, val);
        }
        else
        {
            root->left = insert(root->left, newnode, val);
        }
        return root;
    }
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        TreeNode *newnode = new TreeNode(val);
        return insert(root, newnode, val);
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
    TreeNode *firstNode = solution.buildTree({40, 20, 60, 10, 30, 50, 70});
    TreeNode *result    = solution.insertIntoBST(firstNode, 22);
    std::cout << "Hello world!" << std::endl;
    return 0;
}
