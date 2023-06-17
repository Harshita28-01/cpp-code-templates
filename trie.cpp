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
        TrieNode* getChild(char c){
            return children[c-'a'];
        }
        bool doesExist(char c){
            return getChild(c)==NULL;
        }
        void createTrieNode(char c){
            children[c-'a']= new TrieNode();
        }
    };
    TrieNode* root;
    
    
public:

    /** Initialize your data structure here. */
    Trie() {
        root=new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *node=root;
        for(char c:word){
            if(node->doesExist(c)){
                node->createTrieNode(c);
            }
            node=node->getChild(c);
        }
        node->isWord=true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *node=root;
        for(char c:word){
            node=node->getChild(c);
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
            node=node->getChild(c);
            if(node==NULL){
                return false;
            }
        }
        return true;
    }
};
