class Solution {
    bool isOperator(char ch) {
        return (ch == '+' || ch == '-' || ch == '*');
    }

    vector<int> getDiffWays(int i, int j, string& expression) {

        int len = j - i + 1;
        if(len <= 2) {
            return { stoi(expression.substr(i, len)) };
        }

        vector<int> res;
        for(int ind = i; ind <= j; ind++) {
            if(isOperator(expression[ind])) {
                char op = expression[ind];

                vector<int> left = getDiffWays(i, ind - 1, expression);
                vector<int> right = getDiffWays(ind + 1, j, expression);

                for(int l : left) {
                    for(int r : right) {
                        if(op == '+') {
                            res.push_back(l + r);
                        }
                        else if(op == '-') {
                            res.push_back(l - r);
                        }
                        else if(op == '*') {
                            res.push_back(l * r);
                        }
                    }
                }
            }
        }
        return res;
    }

public:
    vector<int> diffWaysToCompute(string expression) {
        int n = expression.size();
        return getDiffWays(0, n - 1, expression);
    }
};

