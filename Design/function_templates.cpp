#include<iostream>


// Function templates 
// Keywords 'class' and 'typename' are interchangeable
//template <typename T>    
template <class T>
T max_val(T i, T j)
{   
    T maxNum; 
    if(i< j) maxNum = j;
    else maxNum = i;

    std::cout << "Max number is: "<< maxNum << std::endl; 
    return maxNum; 
}

int main()

{
    // Trial with templates 
    float i = 0.2, j= 1.2;
    float ans = max_val(i, j);
    // This is an alternative way to call the same function with two variables 
    max_val<int>(1,2);

    return 0; 
}
