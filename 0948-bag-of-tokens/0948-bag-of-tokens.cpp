class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int score=0,i=0,j=tokens.size()-1,cur=0;
        while(i<=j){
            if(power>=tokens[i]){
                cur++;
                power-=tokens[i];
                score=max(score,cur);
                i++;
            }else if(cur>0){
                power+=tokens[j];
                cur--;
                j--;
            }else{
                break;
            }
        }
        return score;
    }
};