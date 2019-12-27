/*
Questions from the maths category 
*/

///////////////////////////////////////////////////
// [357] Count numbers with unique digits  

class Solution {
public:
    
    int countUniqueNth(int n)
    {
        int num= 9;        
        int count= 0; 
        int mul= num; 
        
        while(count< n-1 && mul>=0)
        {
            num= num* mul; 
            mul= mul- 1; 
            count ++; 
        }
        return num; 
        
    }
    
    int countNumbersWithUniqueDigits(int n) {
        
        if(n == 0)
        {
            return 1; 
        }
        
        if(n == 1)
        {
            return 10; 
        }
        
        int ans= 0;
        // For 1 digit numbers
        ans+= 10; 
        // Loop for two to n digit numbers) 
        for(int i= 2; i<=n; i++)
        {
            ans+= countUniqueNth(i);
        }
                                 
        return ans; 
    }
};