//   https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    std::vector<std::vector<int>> levelOrderBottom(TreeNode* root) {
        std::deque<std::vector<int>> ret;
        std::queue<TreeNode*> q1, q2;
        int i = 0;
        if(!root){
            return std::vector<std::vector<int>>();
        }
        q1.push(root);
        ret.push_front(std::vector<int>(1,root->val));
        while(q1.size()){
            ret.push_front(std::vector<int>());
            while(q1.size()){
                if(q1.front()->left){
                    ret.front().push_back(q1.front()->left->val);
                    q2.push(q1.front()->left);
                }
                if(q1.front()->right){
                    ret.front().push_back(q1.front()->right->val);
                    q2.push(q1.front()->right);
                }
                q1.pop();
            }
            i++;
            if(q2.size()){
                ret.push_front(std::vector<int>());
            }
            while(q2.size()){
                if(q2.front()->left){
                    ret.front().push_back(q2.front()->left->val);
                    q1.push(q2.front()->left);
                }
                if(q2.front()->right){
                    ret.front().push_back(q2.front()->right->val);
                    q1.push(q2.front()->right);
                }
                q2.pop();
            }
            i++;
        }
        std::vector<std::vector<int>> ans;
        ret.pop_front();
        ans.resize(ret.size());
        i = 0;
        for(auto j:ret){
            ans[i++] = j;
        }     


        return ans;
    }
};