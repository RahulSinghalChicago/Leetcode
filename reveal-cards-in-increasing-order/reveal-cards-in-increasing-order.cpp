/*

sort the input array
create the deck backwards using a list that can be accessed from both ends
loop through the sorted array backwards
alternate adding one card at a time from the end of the array
between adding cards, take the last element from the queue and place it in front
after all sorted elements are added, read back from the front.
*/



class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        std::sort(deck.begin(),deck.end());
        for (int i = 0; i<deck.size(); i++)
            cout << deck[i] << " ";
        cout << endl;

        list<int> lst;
        vector<int> result(deck.size());
        for (int i = deck.size()-1; i >= 0; i--) {
            lst.push_front(lst.back());
            lst.pop_back();
            lst.push_front(deck[i]);
        }
        result.assign(lst.begin(), lst.end());
        return result;
    }
};