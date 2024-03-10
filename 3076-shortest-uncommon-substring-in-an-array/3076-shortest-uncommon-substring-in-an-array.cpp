// class Solution {
// public:
//     bool isSubstring(const std::string& n, const std::string& m) {
//     return n.find(m) != std::string::npos;
//     }
//     vector<string> shortestSubstrings(vector<string>& arr) {
//         set<string>st;
//         int n=arr.size(),m;
//         string cur="",mn="";
//         vector<string>ans(n);
//         for(int i=0;i<n;i++){
//             m=arr[i].size();
//             for(int j=0;j<m;j++){
//                 cur="";
//                 for(int k=j;k<m;k++){
//                     cur+=arr[i][k];
//                     if(st.find(cur)==st.end()){
//                         bool f=false;
//                         for(int l=i+1;l<n;l++){
//                             if(isSubstring(arr[l],cur)){
//                                 f=true;
//                                 break;
//                             }
//                         }
//                         if(!f && (mn.size()==0 || cur.size()<mn.size() ||(cur.size()==mn.size() && mn>cur))){
//                             // cout<<cur<<(mn>cur)<<endl;
//                                       mn=cur;
//                         }
//                     }
//                     st.insert(cur);
//                 }
//             }
//             ans[i]=mn;
//             mn="";
//         }
//         return ans;
//     }
// };
class Solution {
public:
    // Function to check if string m is a substring of string n
    bool isSubstring(const string& n, const string& m) {
        return n.find(m) != string::npos;
    }

    vector<string> shortestSubstrings(vector<string>& arr) {
        // Set to store unique substrings
        set<string> uniqueSubstrings;

        // Variables for array size and substring length
        int n = arr.size();
        int substringLength;

        // Variables to store the current substring, minimum substring, and the final result
        string currentSubstring = "", minSubstring = "";
        vector<string> result(n);

        // Loop through each element in the array
        for (int i = 0; i < n; i++) {
            substringLength = arr[i].size();

            // Loop to generate all possible substrings
            for (int j = 0; j < substringLength; j++) {
                currentSubstring = "";
                for (int k = j; k < substringLength; k++) {
                    currentSubstring += arr[i][k];

                    // Check if the substring is unique 
                    if (uniqueSubstrings.find(currentSubstring) == uniqueSubstrings.end()) {
                        bool isSubstringFound = false;

                        // Check if the substring is a substring of any other element in the array
                        for (int l = i + 1; l < n; l++) {
                            if (isSubstring(arr[l], currentSubstring)) {
                                isSubstringFound = true;
                                break;
                            }
                        }

                        // Update the minimum substring if necessary
                        if (!isSubstringFound && (minSubstring.empty() || currentSubstring.size() < minSubstring.size()
                            || (currentSubstring.size() == minSubstring.size() && currentSubstring < minSubstring))) {
                            minSubstring = currentSubstring;
                        }
                    }

                    // Insert the substring into the set
                    uniqueSubstrings.insert(currentSubstring);
                }
            }

            // Store the minimum substring for the current element
            result[i] = minSubstring;

            // Reset the minimum substring for the next iteration
            minSubstring = "";
        }

        return result;
    }
};