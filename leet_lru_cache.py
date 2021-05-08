'''
Least recently used policy to remove items from cache


'''

from collections import deque

class LRUCache:
    def __init__(self,capacity: int):
        self.c = capacity
        self.m = dict()
        self.deq = deque()

    def get(self, key: int) -> int:
        if key in self.m:
            value = self.m[key]
            self.deq.remove(key)
            self.deq.append(key)
            return value
        else:
            return -1

    def put(self,key: int,value: int) -> None:
        # LRU cache object will be instantiated and called as such:
        # obj = LRUCache(capacity)
        # param1 = obj.get(key)
        # obj.put(key,value)
        if (key not in self.m):
            if len(self.deq) == self.c:
                oldest = self.deq.popleft()
                del self.m[oldest]
        else:
            self.deq.remove(key)

        self.m[key] = value
        self.deq.append(key)

    def displayDeq(self):
        print(self.deq)

if (__name__ == "__main__"):
    l = LRUCache(5)
    l.put(6,2)
    l.put(1,3)
    l.displayDeq()