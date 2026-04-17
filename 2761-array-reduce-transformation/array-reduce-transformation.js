/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    let res = init;

    for(let i =0 ;i < nums.length ;i++){

            res = fn(res , nums[i]);
    }
    return res;
};





// (0) + nums[0] == 1 (init , arr[i])
// (1) + nums[1] == 3
// (3) + nums[2] == 6

//  [1,2,3,4] ||  first traversal = i =0 , 1 --> fn(1 , 100){  }