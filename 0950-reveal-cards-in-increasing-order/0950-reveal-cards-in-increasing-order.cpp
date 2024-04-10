class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
       //  sort(deck.begin(),deck.end());
       // vector<int>ans;
       //  int i=0,n=deck.size(),j=(n+1)/2,m=j;
       //  while(i<m && j<n){
       //      ans.push_back(deck[i++]);
       //      ans.push_back(deck[j++]);
       //  }
       //  while(i<m){
       //      ans.push_back(deck[i++]);
       //  }
       //  while(j<n){
       //      ans.push_back(deck[j++]);
       //  }
       //  if(n%2 && n>3){
       //      swap(ans[1],ans[3]);
       //  }
       //  return ans;  
        
        sort(deck.rbegin(), deck.rend());
        deque<int> d;
        d.push_back(deck[0]);
        for (int i = 1; i < deck.size(); i++) {
            d.push_front(d.back());
            d.pop_back();
            d.push_front(deck[i]);
        }
        vector<int> res(d.begin(), d.end());
        return res;
    }
};