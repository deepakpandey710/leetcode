/**
 * @param {string} order
 * @param {string} s
 * @return {string}
 */
var customSortString = function(order, s) {
    const arr={};
    for (const ch of s){
        if(arr[ch])
            arr[ch]++;
        else
            arr[ch]=1;
    }
    console.log(arr);
    let ans="";
    for (const ch of order){
        console.log(ch);
        let n=arr[ch];
        for(let i=0;i<n;i++){
            ans+=ch;
        }
        arr[ch]=0;
    }
    console.log(ans);
    for (const it in arr){       
        let n=arr[it];
        for(let j=0;j<n;j++){
            ans+=it;
        }
    }
    return ans;
};