from collections import deque, defaultdict
from typing import List, Generator


class Solution:
    def numBusesToDestination(self, routes: List[List[int]], source: int, target: int) -> int:
        if source == target:
            return 0

        def generate_next(route_index: int) -> Generator[int, None, None]:
            for station in routes[route_index]:
                for next_route_index in station_route_mapping[station]:
                    if next_route_index not in visited_route_index:
                        visited_route_index.add(next_route_index)
                        yield next_route_index

        station_route_mapping = defaultdict(set)
        for route_index in range(len(routes)):
            for station in routes[route_index]:
                station_route_mapping[station].add(route_index)

        routes.append([source])
        q = deque([(-1, 0)])
        visited_route_index = set()
        while q:
            route_index, steps = q.popleft()
            for next_route_index in generate_next(route_index):
                if target in routes[next_route_index]:
                    return steps + 1
                q.append((next_route_index, steps + 1))

        return -1


solution = Solution()
print(solution.numBusesToDestination([[1, 2, 7], [3, 6, 7]], 1, 6))
print(solution.numBusesToDestination([[7, 12], [4, 5, 15], [6], [15, 19], [9, 12, 13]], 15, 12))