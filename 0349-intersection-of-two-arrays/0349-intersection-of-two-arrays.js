/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersection = function(nums1, nums2) {
    const st=new Set();
    const ans=new Set();
    for (const num of nums1){
        st.add(num);
    }
    for (const num of nums2){
        if(st.has(num)){
            ans.add(num);
        }
    }
    const ansArr=[];
    ans.forEach((num)=>{
        ansArr.push(num);
    })
    return ansArr;
};
