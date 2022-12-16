class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ret = 0;
        for (int i = 30; i >= 0; --i) {
            int mask = (1 << i);
            if ((right & mask) > 0) {
                if ((left & mask) > 0) {
                    ret ^= (1 << i);
                } else {
                    break;
                }
            }
        }
        return ret;
    }
};
