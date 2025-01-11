#include <string>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false; 
        string x_str = to_string(x); 
        string x_rev; 
        int length = x_str.length()-1; 
        for (int i =0 ; i<= length; i+=1 )
        {
            x_rev[i] = x_str[length-i];
        }

        for (int i =0 ; i<= length; i+=1 )
        {
            if (x_str[i]!=x_rev[i])
            {
                return false; 
            }
        }
        return true; 
        
}
};
