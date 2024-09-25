class Solution {
public:

class Trie {
    struct Node {
        bool isEndOfWord;
        unordered_map< char , Node* > child;
        int cnt;
        Node( ) {
        cnt = 0;
        }
        };
    Node* root;
    public:
    Trie( ) { root = new Node( ); }
    void insert( string& s ) {
        Node* tamp = root;
        for ( auto& i : s ) {
        char c = i;
        if ( tamp->child.count( c ) == 0 || tamp->child [ c ]->cnt == 0 )
            tamp->child [ c ] = new Node( );
        tamp = tamp->child [ c ];
        tamp->cnt++;
        }
        }
   
    int search( string& s ) {
        Node* tamp = root;
        int ans = 0;
        for ( auto& i : s ) {
        char c = i;
        if ( tamp->child.count( c ) == 0 || tamp->child [ c ]->cnt == 0 )
            return false;
        tamp = tamp->child [ c ];
        ans += tamp->cnt;
        }
        return ans;
    }
    
    };
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;
        for(auto s:words){
            trie.insert(s);
        }
        vector<int>ans;
        for(auto s:words){
            int cnt = trie.search(s);
            ans.push_back(cnt);
        }
        return ans;
    }
};
