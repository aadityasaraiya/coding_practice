#include<iostream>
#include<vector>
#include<algorithm>

void printVector(std::vector<int> vec)
{
    for (int i=0; i< vec.size(); i++)
    {
        std::cout << vec[i] << " "; 
    }
    std::cout << "" << std::endl; 
    return; 
}


////////////////// Binary Search //////////////////

/*
Time complexity: O(log n)
*/

int midIndex(std::vector<int> vec, int startIndex, int endIndex)
{
    // Automatically takes floor
    int midIndex= (endIndex + startIndex)/2;
    return (midIndex);
}

int binarySearch(std::vector<int> vec, int elem)
{
    // Initialize start and end index 
    int start= 0;
    int end= vec.size()-1;
    int mid= 0;

    while(start!=end)
    {
        std::cout << "Start 1: " << start << " End 1: "<< end << std::endl; 
        // Find middle element 
        mid= midIndex(vec, start, end);
        
        if(vec[mid] == elem)
        {
            return (mid);
        }

        // If not found, check which subarray to check 
        // Update start and end accordingly

        else if(elem > vec[mid])
        {
            start= mid+1;
        }

        else if(elem < vec[mid])
        {
            end= mid-1; 
        }

    std::cout << "Start 2: " << start << " End 2: "<< end << std::endl; 

    }

    return -1; 
}
///////////////////////////////////////////////////
int main()
{
    std::vector<int> vec= {1,0, 12, 15, 13, 22, 37, 10, 12, 17};
    sort(vec.begin(), vec.end());
    printVector(vec);
    // Binary search 
    int ans= binarySearch(vec, 22);

    if(ans== -1)
    {
        std::cout << "Element not found" << std::endl; 
    }

    else
    {
        std::cout << "Element found at index: " << ans << std::endl; 
    }
}