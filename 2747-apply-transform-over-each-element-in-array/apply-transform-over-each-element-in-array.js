/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    
    let res = [];

    for(let i =0 ;i<arr.length ;i++){

            res[i] = fn(arr[i] , i);
    }

    return res;
};




// like we have to do traversal to find the array index and to apply ops of function of each array elements
// we have to return  new array as result //
// returned Array [i] = fn(arr[i] , i)

// [1 , 2 , 3] 
// res = []
// i = 0 -> 1 
// res[i] = fn(1 , 0)
// fn(1,0){
     //   return n+1   n == 1 so 1+1 = 2 and return 2 at index 0 in res[0] == 2 
//}