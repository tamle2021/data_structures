'''
Design a data structure that follows the constraints of a least recently used (LRU) cache.

Implement LRUCache class:
* LRUCache(int capacity) - initialize the LRU cache with positive size capacity.
* int get(int key) - return the value of the key if the key exists, otherwise return -1.
* void put(int key,int value) - update the value of key if key exists. Otherwise, add the key-value pair to the
cache. If number of keys exceeds the capacity from this operation, evict the least recently used key.

The functions get and put must each run in O(1) average time complexity.

input:
["LRUCache","put","put","get","put","get","put","get","get","get"]
[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]
output:
[null,null,null,1,null,-1,null,-1,3,4]

explanation:
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1,1);  // cache is {1=1}
lRUCache.put(2,2);  // cache is {1=1,2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3,3);  // LRU key was 2, evicts key 2, cache is {1=1,3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4,4); // LRU key was 1, evicts key 1, cache is {4=4,3=3}
lRUCache.get(1);   // return -1 (not found)
lRUCache.get(3);   // return 3
lRUCache.get(4);   // return 4

constraints:
1 <= capacity <= 3000
0 <= key <= 10^4
0 <= value <= 10^5
At most 2 * 10^5 calls will be made to get and put.

**** least recently used cache ****

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
    print("**** least recently used cache ****")
    l = LRUCache(5)
    l.put(6,2)
    l.put(1,3)
    get1 = l.get(1)
    print("1: {0}".format(get1))
    l.put(4,6)
    get4 = l.get(4)
    print("4: %s" % get4)
    get6 = l.get(6)
    print("6: {0}".format(get6))

    l.put(9,144)
    l.put(3,11)
    get3 = l.get(3)
    print("3: %s" % get3)

    l.put(7,1)
    l.put(6,3)
    get6After = l.get(6)
    print("get 6 after: {0}".format(get6After))

    get1 = l.get(1)
    # 1 evicted ?
    print("1: %s" % get1)
    l.displayDeq()
    l.displayMap()
