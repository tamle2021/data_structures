'''
There is a robot starting at position (0,0), the origin, on a 2D plane. Given a sequence of its moves,
judge if this robot ends up at (0,0) after it completes moves.

One is given a string moves that represents the move sequence of robot where moves[i] represents its ith
move.  Valid moves are 'R' for right, 'L' for left, 'U' for up, and 'D' for down.  Return true if robot
returns to origin after it finishes all of its moves or false otherwise.

The way that robot is "facing" is irrelevant. 'R' will always make robot move to right once and 'L'
will make it move left.  Also, assume that magnitude of robot's movement is same for each move.

# example 1
input:
moves = "UD"

output:
true

explanation:
The robot moves up once and then down once. All moves have same magnitude, so it ended up at origin
where it started. Therefore, the answer is true.

constraints:
1 <= moves.length <= 2 * 10^4
Moves only contain characters in set {'U','D','L','R'}.


**** robot return to origin ****


'''
class RobotReturnToOrigin():
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

print("**** robot return to origin ****")
r = RobotReturnToOrigin()
moves1 = "LDRRLRUULR"
result1 = r.judgeCircle(moves1)
print("moves1: %s\nresult1: %s" % (moves1,result1))

moves2 = "LLLRRRUUUDDD"
result2 = r.judgeCircle(moves2)
print("moves2: {0}\nresult2: {1}".format(moves2,result2))
