import numpy as np
import math
import matplotlib.pyplot as plt

def gen_kmean_test_data():
    centers = np.array([(0, 3),(3, 0), (0, 6)])
    pts = []
    for ctx in centers:
        pts.append(np.random.rand(20, 2) * 2 + ctx)
    return np.vstack(pts)

def test_kmeans():
    def dist(pt1, pt2):
        return np.linalg.norm(pt1 - pt2)

    pts = gen_kmean_test_data()
    n_clusters = 3
    cluster_centers = pts[:n_clusters]
    i_iter = 0
    while True:
        print(f'start iter {i_iter}')
        # 清理每个聚类中的点
        clusters = [ [] for _ in range(n_clusters)]
        # 给每个点分配一个最近的聚类中心
        for cur_pt in pts:
            clu_id = 0
            min_dist = math.inf
            for i, clu in enumerate(cluster_centers):
                cur_dist = dist(clu, cur_pt)
                if  cur_dist < min_dist:
                    clu_id = i
                    min_dist = cur_dist
            clusters[clu_id].append(cur_pt)
        # 每个聚类取一个中心点
        new_ctx = [] 
        for i, cluster_pts in enumerate(clusters):
            new_ctx.append(np.mean(cluster_pts, axis = 0))
        # 如果新旧聚类中心没有改变就停止迭代
        if np.all(np.allclose(np.asarray(new_ctx), cluster_centers, atol = 1e-6)):
            break
        else:
            cluster_centers = np.asarray(new_ctx)
        i_iter += 1
    print(f'cluster center:{cluster_centers}')
            
    plt.scatter(pts[:, 0], pts[:, 1])
    plt.scatter(cluster_centers[:, 0], cluster_centers[:, 1], marker = 'o')
    plt.show()


if __name__ == '__main__':
    test_kmeans()