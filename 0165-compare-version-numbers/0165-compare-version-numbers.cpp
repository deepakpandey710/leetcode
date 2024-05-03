class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n=version1.size();
        int m=version2.size();
        int i=0,j=0;
        while(i<n || j<m){
            string v1="",v2="";
            if(version1[i]=='.')
                i++;
            if(version2[j]=='.')
                j++;
            while(i<n&&version1[i]!='.'){
                    v1 +=version1[i];
                     i++;
            }
            while(j<m&&version2[j]!='.'){
                v2 +=version2[j];
                  j++;
            }
            if(v1.size()==0) v1="0";
            if(v2.size()==0) v2="0";
            if(stoi(v1)>stoi(v2))
                return 1;
            else if(stoi(v1)<stoi(v2))
                return -1;
            else
                continue;
            i++;j++;
        }
        return 0;
    }
};