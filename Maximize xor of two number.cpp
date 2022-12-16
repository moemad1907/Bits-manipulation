class Trie {
public:
  Trie(): children(2) {}
  vector<unique_ptr<Trie>> children;
};
class Solution {
public:
  int findMaximumXOR(vector<int>& nums) {
    Trie root;

    auto insert = [&](Trie* node, int num) {
      for (int i = 31; i >= 0; --i) {
        int bit = (num >> i) & 1;
        if (!node->children[bit])
          node->children[bit] = std::make_unique<Trie>();
        node = node->children[bit].get();
      }
    };

    auto query = [&](Trie* node, int num) {
      int sum = 0;
      for (int i = 31; i >= 0; --i) {
        int bit = (num >> i) & 1;
        if (node->children[1 - bit]) {
          sum += (1 << i);
          node = node->children[1 - bit].get();
        } else {
          node = node->children[bit].get();
        }
      }
      return sum;
    };

    for (int x : nums)
      insert(&root, x);

    int ans = 0;
    for (int x : nums)
      ans = max(ans, query(&root, x));
    return ans;
  }
};
