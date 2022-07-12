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
    Solution() { currentIndex = 0; }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root)
            return nullptr;

        if (root->val == p->val || root->val == q->val)
            return root;

        if (root->val > p->val && root->val > q->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        else if (root->val < p->val && root->val < q->val)
        {
            return lowestCommonAncestor(root->right, p, q);
        }

        TreeNode *first  = lowestCommonAncestor(root->left, p, q);
        TreeNode *second = lowestCommonAncestor(root->right, p, q);

        if (!first)
        {
            return second;
        }
        else if (!second)
        {
            return first;
        }
        else if (first && second)
        {
            return root;
        }
        return nullptr;
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

    std::cout << "solution.findTarget(firstNode, 3)" << std::endl;
    return 0;
}
