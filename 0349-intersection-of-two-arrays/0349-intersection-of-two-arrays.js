/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersection = function(nums1, nums2) {
    const st1=new Set(nums1);
    const st2=new Set(nums2);
    return Array.from(new Set([...st1].filter((x)=>{return st2.has(x)})));
};
