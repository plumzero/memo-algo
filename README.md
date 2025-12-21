
*电子游戏一般不做底层算法，用什么语言写的就调用该语言的随机数，然后再去加条件。比如在腾讯游戏抽大奖，可能就在 1-10000 间随机生成一个数，当这个数等于 10001，恭喜你，你抽中极品武器了。当然实际算法更复杂。*

*你必须置身于此才能理解那种氛围，你必须体验这样的感情。为了等到这一天，我们是扳着指头一天天熬过来的。*

*我在4号线等地铁，旁边站着一位大爷，手里拿着二叉树的讲义。*

### 数据结构

- [数组](01_array)
- [链表](02_list)
- [栈](03_stack)
- [队列](04_队列)
- [矩阵](05_矩阵)
- [哈希](06_哈希)
- [树](07_tree)
- [图](08_图)
- [字符串](09_string)

### 算法

- [查找](11_search)
- [排序](12_sort)
- [递推](13_deduction)
- [分治](14_partition)
- [递归](15_recursion)
- [穷举](16_exhausion)
- [贪心](17_greed)
- [回溯](18_trace)
- [动规](19_dp)
- [数值](20_numerical)
- [非微分](21_non_differential)
- [位运算](22_bits)
- [其他](23_other)

### 熟练

- [二分查找](01_array/search.cpp)
- [数组分区(符合条件的放左边，不符合条件的放右边)](01_array/partition_array.cpp)
- [找到无序数组中前n个最小的元素](01_array/first_n_elements.cpp)

- [删除链表中的指定节点O(1)](02_list/delete_node.cpp)
- [删除排序链表中重复节点(dummy)](02_list/delete_dup.cpp)
- [删除链表中(根据值域)指定的所有元素(dummy)](02_list/remove_elements.cpp)
- [删除链表中倒数第k个节点(dummy&&快慢指针)](02_list/del_kth_from_end.cpp)
- [合并两个排序的链表(dummy)](02_list/merge_sort_list.cpp)
- [链表中倒数第k个节点(快慢指针)](02_list/kth_from_end.cpp)
- [两个链表的第一个公共节点(快慢指针)](02_list/first_common_node.cpp)
- [链表中环的入口点(快慢指针)](02_list/entry_node.cpp)
- [反转链表](02_list/reverse_list.cpp)

- [用一个队列实现一个栈](03_stack/stack_by_one_queue.cpp)
- [用两个队列实现一个栈](03_stack/stack_by_two_queues.cpp)
- [实现一个无锁栈](03_stack/freelock_stack.cpp)

- [用两个栈实现一个队列](04_queue/queue_by_two_stacks.cpp)
- [实现一个具有超时机制的循环队列](04_queue/timeout_queue.cpp)
- [实现一个无锁队列](04_queue/freelock_queue.cpp)

- [二叉树的前序遍历(根左右)](07_tree/order_pre.cpp)
- [二叉树的中序遍历(左根右)](07_tree/order_in.cpp)
- [二叉树的后序遍历(左右根)](07_tree/order_post.cpp)
- [二叉树的层序遍历(BFS)](07_tree/order_level.cpp)

- [atoi实现](09_string/atoi.cpp)
- [删除冗余空格](09_string/erase_extra_spaces.cpp)
- [替换空格](09_string/replace_blank.cpp)
- [反转字符串](09_string/reverse.cpp)

- [选择排序](12_sort/01_select/select_sort.cpp)
- [插入排序](12_sort/02_insert/insert_sort.cpp)
- [冒泡排序](12_sort/03_change/bubble_sort.cpp)
- [快速排序](12_sort/03_change/quick_sort.cpp)

- [线程交替打印](23_other/print_between_threads.cpp)