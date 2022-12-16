class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {

        unordered_set<int> res;
        unordered_set<int> frontier;
        unordered_set<int> cur;
        for(int a: A){
            cur.clear();
            cur.insert(a);
            for(int x: frontier)
                cur.insert(x | a);

            res.insert(cur.begin(), cur.end());
            frontier = cur;
        }

        return res.size();
    }
};
