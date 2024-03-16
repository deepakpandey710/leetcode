class Solution {
public:
    struct Comparator {
        bool operator()(const vector<int>& a, const vector<int>& b) const {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] > b[0];
        }
    };
    string minimizeStringValue(string s) {
        vector<int>d(26,0);
        vector<int>mark;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]!='?'){
                d[s[i]-'a']++;
            }else{
                mark.push_back(i);
            }
        }
        vector<int>res;
        priority_queue<vector<int>, vector<vector<int>>, Comparator> pq;
        for(int i=0;i<26;i++){
            pq.push({d[i],i});
        }
        int m=mark.size(),finals=mark.size();
        while(m){
            auto t1=pq.top();
            pq.pop();
            auto t2=pq.top();
            cout<<t1[0]<<" t1 "<<t1[1]<<endl;
            for(int i=0;i<t2[0]-t1[0]+(t1[1]<t2[1]?1:0);i++){
                res.push_back(t1[1]);
                m--;
            }
            cout<<m<<endl;
            pq.push({t2[0]+(t1[1]<t2[1]?1:0),t1[1]});
        }
        sort(res.begin(),res.end());
        for(int i=0;i<finals;i++){
            s[mark[i]]=res[i]+'a';
        }
        return s;
    }
};