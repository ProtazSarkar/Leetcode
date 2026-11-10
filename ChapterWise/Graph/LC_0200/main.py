from typing import list
from collections import deque

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        n = len(grid)
        m = len(grid[0])

        dr = [0,0,1,-1]
        dc = [1,-1,0,0]

        visited = set()


        def bfs(sr,sc):
            q = deque()
            q.append((sr,sc))
            visited.add((sr,sc))

            while q:
                r,c = q.popleft()
                for i in range(4):
                    nr = r + dr[i]
                    nc = c + dc[i]

                    if(
                        0 <= nr < n and 0<= nc < m
                        and grid[nr][nc] == "1"
                        and (nr,nc) not in visited
                    ):
                        q.append((nr,nc))
                        visited.add((nr,nc))
            

        ans = 0
        for i in range(n):
            for j in range(m):
                if (i,j) not in visited and grid[i][j] == "1":
                    ans += 1
                    bfs(i,j)
        
        return ans