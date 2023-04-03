class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end()); // sort the people by weight
        int left = 0, right = people.size() - 1; // initialize two pointers at the beginning and end of the array
        int boats = 0; // initialize the number of boats to 0
        while (left <= right) { // loop until the two pointers cross
            if (people[left] + people[right] <= limit) { // if the sum of the weights of the two people is at most limit
                left++; // move the left pointer to the next person
                right--; // move the right pointer to the previous person
            } else { // otherwise, the heavier person must take a boat alone
                right--; // move the right pointer to the previous person
            }
            boats++; // increment the number of boats
        }
        return boats; // return the final number of boats
    }
};