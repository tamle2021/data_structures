/*


time complexity: O(n^2)

**** two sum brute force ****

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
