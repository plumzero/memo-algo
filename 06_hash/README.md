
1. 元素无序时，可以考虑使用哈希

2. 由于 C++ 的 std::unordered_set 与 std::unordered_map 底层使用哈希实现，所以可以作为辅助

3. 选择 std::unordered_set 抑或是 std::unordered_map 需要具体看一下要保存的因子
