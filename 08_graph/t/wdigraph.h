
// 仅作测试用，不考虑输入异常情况

// 邻接表实现

// 有向带权图

#include <stdio.h>
#include <stdlib.h>

#include <vector>

struct ArcNode;

// 顶点节点
typedef struct VNode {
    int val;
    ArcNode* firstarc;      // 第一个与该顶点邻接的顶点
} VNode;

// 边
typedef struct ArcNode {
    int pos;                // 邻接顶点数组索引
    int weight;             // 权
    ArcNode* nextarc;       // 下一个与该顶点邻接的顶点
} ArcNode;

typedef struct Graph {
    std::vector<VNode*> vertex;    // 顶点数组
} Graph;

int locate(Graph& graph, VNode* node)
{
    std::vector<VNode*> vec = graph.vertex;
    for (auto it = vec.begin(); it != vec.end(); it++) {
        if (*it == node)
            return std::distance(vec.begin(), it);
    }
    return -1;
}

VNode* add_vertex(Graph& graph, int val)
{
    VNode* node = new VNode();
    node->val = val;
    node->firstarc = nullptr;

    graph.vertex.push_back(node);

    return node;
}

// 有向网，node 为起始点(弧尾)，adj 为终端点(弧头)
void add_arc(Graph& graph, VNode* node, VNode* adj, int weight)
{
    int pos = locate(graph, adj);
    if (pos == -1) {
        exit(-1);
    }
    ArcNode* arc = new ArcNode();
    arc->pos = pos;
    arc->weight = weight;
    arc->nextarc = nullptr;
    ArcNode* first = node->firstarc;
    if (first == nullptr) {
        node->firstarc = arc;
        return ;
    }
    ArcNode* cur = first;
    while (cur->nextarc) {
        cur = cur->nextarc;
    }
    cur->nextarc = arc;

    return ;
}

// 获取一条边上的权
int get_weight(Graph& graph, VNode* node, VNode* adj)
{
    std::vector<VNode*> vec = graph.vertex;
    ArcNode* cur = node->firstarc;
    while (cur) {
        if (vec[cur->pos] == adj)
            return cur->weight;
        cur = cur->nextarc;
    }

    return -1;
}

void destroy(Graph& graph)
{
    std::vector<VNode*> vec = graph.vertex;
    for (auto it = vec.begin(); it != vec.end(); it++) {
        ArcNode* cur = (*it)->firstarc;
        while (cur) {
            ArcNode* next = cur->nextarc;
            delete cur;
            cur = nullptr;
            cur = next;
        }
        delete (*it);
        (*it) = nullptr;
    }
}

void display(Graph& graph)
{
    std::vector<VNode*> vec = graph.vertex;
    for (auto it = vec.begin(); it != vec.end(); it++) {
        printf("%d: ", (*it)->val);
        ArcNode* cur = (*it)->firstarc;
        while (cur) {
            printf("%d(%d) ", vec[cur->pos]->val, cur->weight);
            ArcNode* next = cur->nextarc;
            cur = next;
        }
        printf("\n");
    }
}
