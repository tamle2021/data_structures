/*
Given an array of integers nums and an integer target, return indices of the two numbers
such that they add up to target.  One may assume that each input would have exactly one 
solution and cannot use the same element twice.  One can return the answer in any 
order.

# example 1
input: 
nums = [2,7,11,15], target = 9

output: 
[0,1]

explanation: 
Because nums[0] + nums[1] == 9, we return [0,1].

# example 2
input: 
nums = [3,2,4], target = 6

output: 
[1,2]

# example 3
input: 
nums = [3,3], target = 6

output: 
[0,1]
 
constraints:
2 <= nums.length <= 10^4
-10^9 <= nums[i] <= 10^9
-10^9 <= target <= 10^9
Only one valid answer exists.


time complexity: O(n^2)

**** two sum brute force ***


*/
const numsArray = [4,7,11,16,9];
const target = 20;

const twoSum = function(nums,target) {
  for (let p1 = 0; p1 < nums.length; p1++) {
    const numberToFind = Math.abs(target - nums[p1]);

    for (let p2 = p1 + 1; p2 < nums.length; p2++) {
      if (numberToFind === nums[p2]) {
        return [p1,p2];
      }
    }
  }

  return null;
};

console.log("**** two sum brute force ****");
console.log("array: [" + numsArray + "]");
console.log("target: " + target);
console.log("result index:",twoSum(numsArray,target));