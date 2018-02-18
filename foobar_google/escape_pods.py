from collections import deque
import copy

def level_construct(entrances, exits, dist_s, level, caps, graph):
    #dist_s is all - initially
    #level is all [] initially
    k_path = -1
    qu = deque()
    for i in entrances:
        dist_s[i] = 0
        qu.append(i)
    #start running BFS
    while len(qu) > 0:
        u = qu.popleft()
        for v in graph[u]:
            if dist_s[v] == -1:
                if k_path == -1:
                    if caps[u][v] > 0:
                        dist_s[v] = dist_s[u] + 1
                        level[u].append(v)
                        if v in exits:
                            k_path = dist_s[v]
                        else:
                            qu.append(v)
                elif dist_s[u] < k_path and caps[u][v] > 0:
                    dist_s[v] = k_path
    return k_path

def find_single(entrances, exits, \
        dist_s, level, caps, k_path, curve):
    for u in entrances:
        if dist_s[u] == 0:
            del curve[0:]
            #start DFS
            qu = deque([u])
            while len(qu) > 0:#and len(curve) < k_path + 1:
                c = qu.pop()
                while len(curve) > 0 and dist_s[curve[-1]] >= dist_s[c]:
                    curve.pop()
                curve.append(c)
                dry = True
                for v in level[c]:
                    if caps[c][v] > 0 and dist_s[v] != -1:
                        qu.append(v)
                        dry = False
                        if dist_s[v] == k_path and v in exits:
                            curve.append(v)
                            return True
                if dry:
                    #update curve
                    dist_s[c] = -1
                    curve.pop()
    return False

def update_flow(caps, k_path, curve):
    cap_min = caps[curve[0]][curve[1]]
    for i in range(1, k_path):
        cap_min = min(cap_min,\
                caps[curve[i]][curve[i + 1]])
    for i in range(k_path):
        caps[curve[i]][curve[i + 1]] -= cap_min
        caps[curve[i + 1]][curve[i]] += cap_min
    return cap_min

def answer (entrances, exits, path):
    flow = 0
    nvert = len(path)
    caps = copy.deepcopy(path)
    graph = [[] for i in range(nvert)]
    for i in range(nvert):
        for j in range(i, nvert):
            if caps[i][j] > 0 or caps[j][i] > 0:
                graph[i].append(j)
                graph[j].append(i)
    k_path = 0
    while k_path != -1:
        level_graph = [[] for i in range(nvert)]
        dist_s = [-1]*nvert
        k_path = level_construct(entrances, exits, \
                dist_s, level_graph, caps, graph)
        if k_path != -1:
            while True:
                curve = []
                pathQ = find_single(entrances, exits, \
                    dist_s, level_graph, caps, k_path, curve)
                if not pathQ:
                    break
                flow += update_flow(caps, k_path, curve)
    return flow

