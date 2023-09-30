#
# @lc app=leetcode.cn id=210 lang=python3
#
# [210] 课程表 II
# 拓扑排序求解方法是:
# 1. 判断是否有环,没有环才能进行排序,有环则直接返回[]
# 2. 增加all_path数组,保存后续遍历顺序
# 3. 将all_path反向排列,反向后的顺序即为拓扑排序的结果.

# @lc code=start
class Solution:
    def __init__(self):
        self.has_cycle = False

    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        visited = numCourses * [False]
        on_path = numCourses * [False]
        all_path = []
        g = build_graph(numCourses, prerequisites)
        for idx in range(len(g)):
            self.dfs(g, idx, visited, on_path, all_path)
        if self.has_cycle:
            return []
        all_path.reverse()
        return all_path
    
    def dfs(self, g, idx, visited, on_path, all_path):
        if on_path[idx]:
            self.has_cycle = True
        if visited[idx] or self.has_cycle:
            return
        visited[idx] = True
        on_path[idx] = True
        for s in g[idx]:
            self.dfs(g, s, visited, on_path, all_path)
        on_path[idx] = False
        # 后序遍历
        all_path.append(idx)

def build_graph(n_nodes, prerequisites):
    g = []
    for _ in range(n_nodes):
        g.append([])
    for edge in prerequisites:
        FROM = edge[1]
        TO = edge[0]
        g[FROM].append(TO)
    return g
# @lc code=end
