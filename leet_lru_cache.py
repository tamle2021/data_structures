'''
Least recently used policy to remove items from cache

'''

from collections import deque

class LRUCache:
    def __init__(self,capacity: int):
        self.capacity = capacity
        self.map = dict()
        self.deq = deque()

    def get(self,key: int) -> int:
        if (key in self.map):
            value = self.map[key]
            self.deq.remove(key)
            self.deq.append(key)
            return value
        else:
            return -1

    def put(self,key: int,value: int) -> None:
        # LRU cache object will be instantiated and called as such: obj = LRUCache(capacity)
        # param1 = obj.get(key)
        # obj.put(key,value)
        if (key not in self.map):
            if len(self.deq) == self.capacity:
                oldest = self.deq.popleft()
                del self.map[oldest]
        else:
            self.deq.remove(key)

        self.map[key] = value
        self.deq.append(key)

    def displayDeq(self):
        print(self.deq)

    def displayMap(self):
        print("map: {0}".format(self.map))

if (__name__ == "__main__"):
    l = LRUCache(5)
    l.put(6,2)
    l.put(1,3)
    l.put(4,4)
    l.put(9,144)
    l.displayDeq()
    l.displayMap()
