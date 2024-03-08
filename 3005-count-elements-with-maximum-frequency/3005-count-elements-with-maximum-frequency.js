/**
 * @param {number[]} nums
 * @return {number}
 */
var maxFrequencyElements = function(nums) {
    const mpp=new Map();
    nums.forEach((i)=>{
        mpp.set(i,(mpp.get(i)||0)+1);
    });
    let mx=Math.max(...mpp.values());
    let arr=[...mpp.keys()].filter(num=> mpp.get(num)===mx);
    // console.log(mx,arr)
    return mx*arr.length;
    
};