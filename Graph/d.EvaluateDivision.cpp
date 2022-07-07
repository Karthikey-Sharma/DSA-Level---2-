class Solution {
public:
    map<string , string> parent;
    map<string , double> multiples;
    void addToDSU(string a){
        parent[a] = a;
        multiples[a] = 1.0;
    }
    string find(string x){
        if(parent[x] == x){
            return parent[x];
        }else{
            string currentParent = parent[x];
            string finalParent = find(currentParent);
            parent[x] = finalParent;
            // compression
            multiples[x] = multiples[x] * multiples[currentParent];
            return finalParent;
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for(vector<string> equation : equations){
            string operand1 = equation[0];
            string operand2 = equation[1];
            addToDSU(operand1);
            addToDSU(operand2);
        }
        // Union
        int i = 0;
        for(vector<string> equation : equations){
            string l0 = find(equation[0]);
            string l1 = find(equation[1]);
            
            if(l0 != l1){
                double multiple1 = multiples[equation[0]];
                double multiple2 = multiples[equation[1]];
                parent[l0] = l1;
                multiples[l0] = (values[i] * multiple2) / multiple1;
            }
            i++;
        }
        // finding answers
        vector<double> ans;
        for(vector<string> query : queries){
            string operand1 = query[0];
            string operand2 = query[1];
        
            
            // first case - Operand hi na ho
            if(parent.find(operand1) == parent.end() || parent.find(operand2) == parent.end()){ 
                ans.push_back(-1.0);
                continue;
            }
            
            // second case - agar dono ka lead same hi na ho
            string lead1 = find(operand1);
            string lead2 = find(operand2);
            if(lead1 != lead2){
                ans.push_back(-1.0);
                continue;
            }
            // third case
            double multiple1 = multiples[operand1];
            double multiple2 = multiples[operand2];
            double mul = multiple1 / multiple2;
            ans.push_back(mul);
        }
        return ans;
    }
};