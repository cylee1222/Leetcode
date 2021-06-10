class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        digits[digits.size()-1] += 1;
        for(int i=digits.size()-1;i>=0;--i){
            if(i == 0){
                if(digits[i] == 10){
                    digits[i] = 0;
                    digits.insert(digits.begin(),1);
                }
            }else{
                if(digits[i] == 10){
                    digits[i] = 0;
                    digits[i - 1] += 1;
                }                
            }
            
        }
        return digits;
    }
};

#####################################################

class Solution {
public:
    vector<int> plusOne(vector<int>& A) {
        int i = A.size() - 1, carry = 1;
        for (; i >= 0 && carry; --i) {
            carry += A[i];
            A[i] = carry % 10;
            carry /= 10;
        }
        if (carry) A.insert(begin(A), carry);
        return A;
    }
};
