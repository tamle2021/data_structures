'''
Given an m x n grid of characters board and a string word, return true if word exists in the grid.
The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or
vertically neighboring. The same letter cell may not be used more than once.

example 1:
A B C E
S F C S
A D E E

input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
output: true

example 2:
A B C E
S F C S
A D E E

input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
output: true

Example 3:
A B C E
S F C S
A D E E

input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
output: false

constraints:
m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters
'''
from typing import List

class WordSearch:
    dx = [0,0,-1,1]
    dy = [1,-1,0,0]

    def recurse(self,board,word,x,y,cur):
        if (x < 0 or x >= len(board) or y < 0 or y >= len(board[x]) or board[x][y] == ' '):
            return False
        cur += board[x][y]

        if (len(cur) > len(word)):
            return False
        if (cur[len(cur) - 1] != word[len(cur)-  1]):
            return False
        if (cur == word):
            return True

        temp = board[x][y]
        board[x][y] = ' '

        for i in range(4):
            if (self.recurse(board,word,x + self.dx[i],y + self.dy[i],cur)):
                return True

        board[x][y] = temp
        return False

    def exist(self,board: List[List[str]],word: str) -> bool:
        if (len(word) == 0):
            return True
        n = len(board)

        for i in range(n):
            m = len(board[i])
            for j in range(m):
                if (word[0] == board[i][j] and self.recurse(board,word,i,j,"")):
                    return True
        return False

w = WordSearch()
board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
result1 = w.exist(board,"ESE")
result2 = w.exist(board,"ABFF")

print("word exists (ESE): {0}".format(result1))
print("word exists (ABFF): {0}".format(result2))