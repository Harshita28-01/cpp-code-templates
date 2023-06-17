class Trie {
    class TrieNode{
        public:
        TrieNode* children[26];
        bool isWord;
        TrieNode():isWord(){
            for(int i=0;i<26;i++){
                children[i]=NULL;
            }
        }
    };
    TrieNode* root;
    TrieNode* getChild(TrieNode* node,char c){
        return node->children[c-'a'];
    }
    bool doesExist(TrieNode* node,char c){
        return getChild(node,c)==NULL;
    }
public:

    /** Initialize your data structure here. */
    Trie() {
        root=new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *node=root;
        for(char c:word){
            if(doesExist(node,c)){
                node->children[c-'a']=new TrieNode();
            }
            node=getChild(node,c);
        }
        node->isWord=true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *node=root;
        for(char c:word){
            node=getChild(node,c);
            if(node==NULL){
                return false;
            }
        }
        return node->isWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *node=root;
        for(char c:prefix){
            node=getChild(node,c);
            if(node==NULL){
                return false;
            }
        }
        return true;
    }
};
