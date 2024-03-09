/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var getCommon = function(nums1, nums2) {
    let i=0,j=0,n=nums1.length,m=nums2.length;
    while(i<n && j<m){
        if(nums1[i]===nums2[j])return nums1[i];
        while(i<n && nums1[i]<nums2[j]){
            i++;
        }
        while(i<n &&j<m && nums1[i]>nums2[j]){
            j++;
        }
    }
    return -1;
};