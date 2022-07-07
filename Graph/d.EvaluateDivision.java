class Solution {
    // DSU
    HashMap<String , String> parent;
    HashMap<String , Double> multiple;   
    void addToDSU(String x) {
        if(parent.containsKey(x) == false){
            parent.put(x , x);
            multiple.put(x , 1.0);
        }
    }
    String find(String x) {
        if(parent.get(x).equals(x)){
            return parent.get(x);
        }else{
            String currentParent = parent.get(x);
            String finalParent = find(currentParent);
            parent.put(x , finalParent);
            ///compression
            multiple.put(x , multiple.get(currentParent) * multiple.get(x));
            return finalParent;
        }
    }
    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        parent = new HashMap<>();
        multiple = new HashMap<>();
        for(List<String> equation : equations){
            addToDSU(equation.get(0));
            addToDSU(equation.get(1));
        }
        int i = 0;
        for(List<String> equation : equations){
            String l0 = find(equation.get(0));
            String l1 = find(equation.get(1));
            
            if(l0.equals(l1) == false) {
                // union
                double m0 = multiple.get(equation.get(0));
                double m1 = multiple.get(equation.get(1));
                parent.put(l0 , l1);
                multiple.put(l0 , (values[i] * m1)/ m0);
            }
            i++;
        }
        double[] res = new double[queries.size()];
        i = 0;
        for(List<String> query : queries){
            String q0 = query.get(0);
            String q1 = query.get(1);
            
            if(parent.containsKey(q0) == false || parent.containsKey(q1) == false){
                res[i] = -1;
                i++;
                continue;
            }
            
            String l0 = find(q0);
            String l1 = find(q1);
            if(l0.equals(l1) == false){
                res[i] = -1;
                i++;
                continue;
            }
            double m0 = multiple.get(q0);
            double m1 = multiple.get(q1);
            res[i] = m0 / m1;
            i++;
        }
        return res;
    }
}