'''
There is a robot starting at the position (0,0), the origin, on a 2D plane. Given a sequence of its moves, judge
if this robot ends up at (0, 0) after it completes its moves.

One is given a string moves that represents the move sequence of the robot where moves[i] represents its ith move.
Valid moves are 'R' for right, 'L' for left, 'U' for up, and 'D' for down.  Return true if the robot returns to
the origin after it finishes all of its moves, or false otherwise.

The way that the robot is "facing" is irrelevant. 'R' will always make the robot move to the right once, 'L'
will always make it move left, etc.  Also, assume that the magnitude of the robot's movement is the same
for each move.

constraints:
1 <= moves.length <= 2 * 104
moves only contains the characters in the set {'U','D','L','R'}
'''

class RobotOrigin:
    def judgeCircle(self,moves: str) -> bool:
        x = 0
        y = 0

        for move in moves:
            if (move == 'U'):
                y += 1
            elif (move == 'R'):
                x += 1
            elif (move == 'D'):
                y -= 1
            elif (move == 'L'):
                x -= 1
        return x == 0 and y == 0

r = RobotOrigin()
moves1 = "LDRRLRUULR"
result1 = r.judgeCircle(moves1)
print("return to origin? %s" % result1)

moves2 = "LLLRRRUUUDDD"
result2 = r.judgeCircle(moves2)
print("return to origin? {0}".format(result2))
