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
    vector<int>depth,tree,in,out;
    int cur = 1;
    void dfs(TreeNode* u,int p){
        if(u == NULL)return;
        in[u->val] = cur++;
        depth[u->val] = depth[p] + 1;
        tree[in[u->val]] = u->val;
        dfs(u->left,u->val);
        dfs(u->right,u->val);
        out[u->val] = cur-1;
    }

    struct SegTree {
    vector<int> tree, lazy;
    int n;
    int skip = 0;



    int merge(int l,int r) {
        return max(l,r);
    }

    void build(int oldn,vector<int> v) {
        if (__builtin_popcount(oldn) == 1)n = oldn;
        else n = 1 << (__lg(oldn)+1);

        tree.resize(n<<1,0);
        lazy.resize(n<<1,0);

        for(int i=0 ; i<oldn ; i++) {
            tree[i + n] = v[i];
        }

        for(int i=0 ; i<oldn ; i++) {
            tree[i] = skip;
        }

        for(int i= n-1 ; i>=1 ; i--) {
            tree[i] = merge(tree[i<<1],tree[i<<1|1]);
        }
    }

    void prop(int k,int sl,int sr) {
        tree[k] += lazy[k];
        if(sl!=sr)lazy[k<<1] += lazy[k],lazy[k<<1|1] += lazy[k];
        lazy[k]=0;
    }

    int query(int ql,int qr,int k,int sl,int sr) {
        prop(k,sl,sr);
        if(ql<=sl && sr<=qr) return tree[k];
        if(ql>sr || qr<sl) return skip;
        int m = (sl+sr) >> 1;
        return merge(query(ql,qr,k<<1,sl,m),query(ql,qr,k<<1|1,m+1,sr));
    }

    void update(int ql,int qr,int v,int k,int sl,int sr) {
        prop(k,sl,sr);
        if(ql<=sl && sr<=qr) {
            lazy[k] = v;
            prop(k,sl,sr);
            return;
        }
        if(ql>sr || qr<sl) return;
        int m = (sl+sr) >> 1;
        update(ql,qr,v,k<<1,sl,m);
        update(ql,qr,v,k<<1|1,m+1,sr);
        tree[k] = merge(tree[k<<1],tree[(k<<1)|1]);
    }

};

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        depth = vector<int>(1e5+5,0);
        tree = vector<int>(1e5+5,0);
        in = vector<int>(1e5+5,0);
        out = vector<int>(1e5+5,0);
        dfs(root,0);
        for(int i=1 ; i<=1e5 ; i++)tree[i] = depth[tree[i]];
        vector<int>ans;
        SegTree seg;
        seg.build(1e5+5,tree);
        for(auto q:queries){
            int res = max(seg.query(0,in[q]-1,1,0,seg.n-1),seg.query(out[q]+1,1e5,1,0,seg.n-1));
            ans.push_back(res-1);
        }
        return ans;
    }
};
