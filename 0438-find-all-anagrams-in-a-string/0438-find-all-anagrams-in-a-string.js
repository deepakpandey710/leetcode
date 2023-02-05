/**
 * @param {string} s
 * @param {string} p
 * @return {number[]}
 */
 function checkequal(arr1, arr2) {
    for (let i = 0; i < 26; i++) {
      if (arr1[i] !== arr2[i]) return false;
    }
    return true;
  }

 var findAnagrams = function findAnagrams(s, p) {
    const ans = [];
    const n = s.length;
    const m = p.length;
    if (n < m) return ans;
    const arr1 = Array(26).fill(0);
    for (let i = 0; i < m; i++) {
      arr1[p.charCodeAt(i) - 97]++;
    }
    let i = 0;
    const arr2 = Array(26).fill(0);
    while (i < m) {
      arr2[s.charCodeAt(i) - 97]++;
      i++;
    }
    if (checkequal(arr1, arr2)) ans.push(0);
    while (i < n) {
      arr2[s.charCodeAt(i - m) - 97]--;
      arr2[s.charCodeAt(i) - 97]++;
      i++;
      if (checkequal(arr1, arr2)) ans.push(i - m);
    }
    return ans;
  }

    
