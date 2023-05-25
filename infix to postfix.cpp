    string infixToPostfix(string s) {
        unordered_map<char,int> pre({{'^',2},{'*',1},{'/',1},{'+',0},{'-',0},{'(',-1},{')',-1}});
        string res;
        stack<char> stk;
        for(char c:s){
            if(c=='('){
                stk.push('(');
            }else if(c==')'){
                while(stk.top()!='('){
                    res.push_back(stk.top());
                    stk.pop();
                }
                stk.pop();
            }else if(pre.count(c)){
                while(stk.size() && pre[stk.top()]>=pre[c]){
                    res.push_back(stk.top());
                    stk.pop();
                }
                stk.push(c);
            }else{
                res.push_back(c);
            }
        }
        while(stk.size()){
            res.push_back(stk.top());
            stk.pop();
        }
        return res;
    }
