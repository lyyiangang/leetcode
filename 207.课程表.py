#
# @lc app=leetcode.cn id=207 lang=python3
#
# [207] 课程表.
# 遍历链表(只dfs(node))->遍历二叉树(dfs(node.left), dfs(node.right)-> 遍历多叉树 for(n:nodes) dfs(n) ->遍历图:for(n:nodes) visited[n]=True,dfs(n)
# 判断有向图中是否有环．遍历方式类似二叉树.课程之间的相互看依赖可以抽象为DAG有向无环图上两个节点之间的依赖，A课程完成后才能进行B
# 课程，那么可以抽象为A->B. 当图中存在环时，则课程的学习就无法完成． 代码分为三个步骤
# 1. 构建图．通过邻接表的方式构建课程之间的依赖关系．
# 2. 以每个节点为起点，遍历整个图，每访问过一个节点就将该节点visited设置为true,避免再次访问．同时，对于当前走的最深路径用onPath保存，当要遍历
# 　　的点onPath[i] = True时，表明该节点为当前dfs刚访问过的路径,即为有环.返回即可.

from typing import List
# @lc code=start

class Solution:
    def __init__(self):
        self.hasCycle = False

    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        num_nodes = numCourses
        g = build_graph(num_nodes, prerequisites)
        visited = num_nodes * [False]
        on_path = num_nodes * [False]
        for s in range(len(g)):
            self.dfs(g, s, visited, on_path)
        return not self.hasCycle

    def dfs(self, g, idx, visited, on_path):
        if on_path[idx]:
            self.hasCycle = True
        if visited[idx] or self.hasCycle:
            return
        # print(idx)
        visited[idx] = True
        on_path[idx] = True
        for s in g[idx]:
            self.dfs(g, s, visited, on_path)
        on_path[idx] = False

def build_graph(num_nodes, edges):
    g = []
    for _ in range(num_nodes):
        g.append([])
    for e in edges:
        FROM = e[1]
        TO = e[0]
        g[FROM].append(TO)
    return g
# @lc code=end
def run():
    prerequisites = [
        [1, 0],
        [0, 1]
    ]
    s = Solution()
    n_nodes = 7
    result = s.canFinish(n_nodes, prerequisites)
    print(result)
    # print 0, 1, 2,3,4,5,6
run()