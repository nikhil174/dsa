/* https://www.geeksforgeeks.org/problems/sum-of-two-numbers-without-using-arithmetic-operators/1
*/

// TC - O(maxNumberOfSetBits(a, b)) , SC = O(1)
class Solution
{
    public:
    int sum(int a , int b)
    {
        //code here
        int sum, carry = b;
        while (carry != 0) {
            sum = a ^ b;
            carry = (a & b) << 1;
            
            a = sum;
            b = carry;
        }
        
        return a;
    }
};