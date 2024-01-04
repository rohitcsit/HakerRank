/*
You are an IPL team owner. Auctions are going to take place today evening. You want to buy exactly 11 players for your team.
You are also a business-man so you do not have the time to analyse all the players. You ask your assistant for help.
Your assistant has short-listed N players for you.
On your way to the auction, you wonder, how many distinct teams can you pick if you choose all your 11 players from the N players that your assistant has shortlisted.
Two teams are different if atleast one player is present in one team and absent in the other.

Input
Input consists of one number only, N.

Output
Output consists of one integer only, the number of distinct teams that you can pick.

Notes
1 ≤ N ≤ 50
Be careful to avoid overflow
Think of the tricky case for this problem
Sample Input 0

12
Sample Output 0

12
*/

// Solution

#include <iostream>
#include <cmath>

int main() {
    int x;
    std::cin >> x;

    if (x >= 11) {
        long long result = 1;
        for (int i = x; i > x - 11; --i) {
            result *= i;
        }
        for (int i = 2; i <= 11; ++i) {
            result /= i;
        }

        std::cout << result << std::endl;
    } else {
        std::cout << 0 << std::endl;
    }

    return 0;
}
