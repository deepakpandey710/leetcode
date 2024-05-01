/**
 * @param {string} word
 * @param {character} ch
 * @return {string}
 */
var reversePrefix = function(word, ch) {
    let i=word.indexOf(ch);
    if(i!=-1){
        word=word.substr(0,i+1).split('').reverse().join('')+word.substr(i+1);
    }
    return word;
};