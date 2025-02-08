class Solution {
public:
    Node* connect(Node* root) {
        if(!root)return nullptr;
        queue<Node*>q;
        q.push(root);
        deque<Node*>v;
        v.push_back(root);
        while (!q.empty()){
            int sz = q.size();
            for (int i = 0; i < sz-1; ++i) {
                v.front()->next = *(v.begin()+1);
                if(v.front()->left) {
                    q.push(v.front()->left);
                    v.push_back(v.front()->left);
                }
                if(v.front()->right) {
                    q.push(v.front()->right);
                    v.push_back(v.front()->right);
                }
                q.pop();
                v.pop_front();
            }
            v.front()->next = nullptr;
            if(v.front()->left) {
                q.push(v.front()->left);
                v.push_back(v.front()->left);
            }
            if(v.front()->right) {
                q.push(v.front()->right);
                v.push_back(v.front()->right);
            }
            q.pop();
            v.pop_front();

        }
        return root;
    }
};