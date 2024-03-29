
### AOV网

- 定义: 在每一个工程活动中,可以将工程分为若干个子工程,这些子工程称为`活动`。如果用图中的顶点表示活动，以有向图的弧表示活动之间的优先关系，这样的有向图称为 `AOV 网`。AOV 网是以顶点表示活动的有向无环图。
- 概念
    + 在 AOV 网中，如果顶点 vi 到顶点 vj 之间存在一条路径，则顶点 vi 是顶点 vj 的`前驱`，顶点 vj 为顶点 vi 的`后继`。如果 <vi,vj> 是有向网的一条弧，则称顶点 vi 是顶点 vj 的`直接前驱`，顶点 vj 是顶点 vi 的`直接后继`。
    + AOV 网通过弧表示活动中的制约关系。
    + 在 AOV 网中，不允许出现环。如果出现环就表示某个活动是自己的先决条件。因此，需要对 AOV 网判断是否存在环，可以利用有向图的拓扑排序进行判断。


### 拓扑排序

`拓扑排序`就是将 AOV 网中的所有顶点排列成一个线性序列，并且序列满足以下条件: 在 AOV 网中，如果从顶点 vi 到 vj 存在一条路径，则在该线性序列中，顶点 vi 一定出现在顶点 vj 之前(存储结构来看)。因此，拓扑排序的过程就是将 AOV 网排成线性序列的操作。

AOV 网表示一个工程图，而拓扑排序则是将 AOV 网中的各个活动组成一个可行的实施方案。

拓扑排序方法
  1. 在 AOV 网中任意任意选择一个没有前驱的顶点，即顶点入度为零，将该顶点输出。
  2. 从 AOV 网中删除该顶点，以及从该顶点出发的弧。
  3. 重复执行步骤 1 和 2, 直到 AOV 网中所有顶点都已经被输出，或者 AOV 网中不存在无前驱的顶点为止。

采用邻接表存储结构的 AOV 网拓扑排序算法实现
- 遍历邻接表，将各个顶点的入度保存在入度数组 indegree 中。将入度为零的顶点入栈，依次将栈顶元素出栈并输出该顶点，对该顶点的邻接顶点的入度减 1，如果邻接顶点的入度为 0，则入栈。否则，将下一个邻接顶点的入度减 1 并进行相同的处理。然后继续将栈中的元素出栈，重复执行以上操作，直到栈空为止。
- 拓扑排序算法的实现，围绕入度数组 indegree 展开。
