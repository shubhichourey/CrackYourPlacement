/*There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.
*/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        const int n = cardPoints.size();
    const int sum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
    int windowSum =
        accumulate(cardPoints.begin(), cardPoints.begin() + n - k, 0);
    int ans = sum - windowSum;

    for (int i = 0; i < k; ++i) {
      windowSum -= cardPoints[i];
      windowSum += cardPoints[i + n - k];
      ans = max(ans, sum - windowSum);
    }

    return ans;
    }
};