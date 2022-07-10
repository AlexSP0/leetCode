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
    Solution() {
        currentIndex = 0;
    }

    bool isSymmetric(TreeNode* root) {
        return visitNode(root->left,root->right);
    }

    bool visitNode (TreeNode* left,TreeNode* right){
        if(left==nullptr && right==nullptr)
            return true;

        if((left==nullptr && right!=nullptr) || (left!=nullptr && right==nullptr) || (left->val != right->val))
            return false;

        return visitNode(left->left,right->right) && visitNode(left->right,right->left);

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
    TreeNode *firstNode     = solution.buildTree({1,2, 3, -1000, -1000, 4, -1000, -1000, 2, 3, -1000, -1000, 4});

    std::cout << solution.isSymmetric(firstNode) << std::endl;
    return 0;
}
