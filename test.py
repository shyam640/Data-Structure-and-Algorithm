from collections import deque
 
 

class MAP:
    def init(self, edges, n):
 
        self.adjList = [[] for _ in range(n)]
 
        for (src, dest) in edges:
            self.adjList[src].append(dest)
 
 
def isReachable(graph, src, dest, discovered, path):
 
    discovered[src] = True
 
    path.append(src)
 
    if src == dest:
        return True
 
    for i in graph.adjList[src]:
 
        if not discovered[i]:
            if isReachable(graph, i, dest, discovered, path):
                return True
 
    path.pop()
 
    return False
 
 
 
n = int(input())
edges = []
for i in range(n):
   x = list(map(int,input().split(" ")))
   for j in x:
      edges.append((i,j-1))

   
graph = MAP(edges, n)

discovered = [False] * n

(src, dest) = map(int,input().split(" "))
src = src- 1
dest = dest - 1

path = deque()

if isReachable(graph, src, dest, discovered, path):
   print(len(list(path))-1,end="")
else:
   print(-1,end="")