/*
One is given an integer array height of length n. There are n vertical lines drawn such 
that two endpoints of the ith line are (i,0) and (i, height[i]).  Find two lines that 
together with x-axis form a container and has the most water.

Return maximum amount of water a container can store.
Notice that one may not slant the container.

# example 1
input: 
height = [1,8,6,2,5,4,8,3,7]

output: 
49

explanation: 
The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the 
max area of water the container can contain is 49.

constraints:
n == height.length
2 <= n <= 10^5
0 <= height[i] <= 10^4

time complexity: O(n^2)

**** container with most water brute force ****

*/
const heights = [1,10,5,3,5,4,8,4,9];

const containerMostWater = function(heights) {
  let maxArea = 0;

  for(let p1 = 0; p1 < heights.length; p1++) {
    for(let p2 = p1 + 1; p2 < heights.length; p2++) {
      const height = Math.min(heights[p1],heights[p2]);
      const width = p2 - p1;
      const area = height * width;

      maxArea = Math.max(maxArea,area);
    }
  };

  return maxArea;
}

console.log("**** container with most water brute force ****");
console.log("heights:",heights);
console.log("result: " + containerMostWater(heights));