/*
To Do:
1) Create a generic image class 
2) Add support for operations 
- Kernel based Filtering 
   1. Median
   2. Mean
   3. Gaussian
   4. Laplacian
   5. DoG
   6. Box
- Morphological operations
    1. Erosion 
    2. Dilation 
-  Geometric Operations 
    1. Rotate 
    2. Scale 
    3. Resize 
    4. Translate
    5. Crop 
- Gradients and features 
    1. Gradients 
    2. Edge detection (Canny, SobelX, SobelY)
    3. Jacobians and Hessians
    4. Corner detection 
    5. Descriptors (BRIEF descriptor)
- Segmentation 
    1. Foreground and background subtraction (Max flow, min cut)
    2. Convex hull 
    3. Connected components 
    4. Clustering 
    5. Minimum distance between two clusters 
    6. Template matching 
- Geometry
    1. RANSAC
    2. Estimate homography 
*/

#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;

class Image
{
    public:
        vector<vector<int>> image_ ; 
         int numRows_ = 0, numCols_ = 0; 
   
    //////////////////////// Class constructor 
    Image ()= default; 
    // Create an image of all zeros 
    Image (int numRows, int numCols, int val=0)
    {
        // Initialize an image with all values assigned as a particular value 
        vector<vector<int>>imageTemp(numRows, vector<int>(numCols, val));
        // Assign image to already existing public image 
        image_ = imageTemp; 
        // Set number of rows and columns 
        numRows_ = numRows;    numCols_ = numCols; 
    }

    // Create an image from a given input vector of vectors 
    Image(vector<vector<int>>& inputImage)
    {
        // Take input image 
        image_= inputImage; 
        // Set private variables, number of rows and columns 
        numRows_ = inputImage.size();
        numCols_= inputImage[0].size();
    }
  

    //////////////////////// Utility functions 
    void printImage()
    {
        for(int r = 0; r < numRows_; r++)
        {
            for(int c = 0; c < numCols_; c++) cout << image_[r][c] << " ";
            cout << "" << endl;  
        }
    }
};

//////////////////////// Filtering operations
// Options: Zero pad, Copy the boundary values 
Image averagingFilter(int k, Image& image)
{
    // Kernels can only be odd numbers 
    assert(k % 2 != 0 && k >= 1); 
    // Base case, where kernel size is 1, return the same image 
    if(k == 1) return image; 

    // Create a dummy image 
    Image ansImage = Image(image.numRows_, image.numRows_);
    
    // O(n^2* k^2 approach)
    for(int r = 0; r < ansImage.numRows_; r++)
    {
        for(int c = 0; c < ansImage.numCols_; c++)
        {
            for(int dr = -(k-2); dr <= (k-2); dr++)
            {
                for(int dc = -(k-2); dc <= (k-2); dc++)
                {
                    if(r + dr >=0 && r + dr< ansImage.numRows_ && c + dc >=0 && c + dc< ansImage.numCols_)
                    {
                        ansImage.image_[r][c]+= image.image_[r+ dr][c+ dc];
                    }
                }
            }
        cout << r << " " << c << " " << ansImage.image_[r][c] << " " << ((float)ansImage.image_[r][c]) / (k*k) << endl; 
        ansImage.image_[r][c]= ((float)(ansImage.image_[r][c])) / (k*k);
        }    
    }

    return ansImage;         
} 



int main()
{
    // Create a dummy image 5 x 5 
    vector<vector<int>> dummyImage{{1,1,1,1,1}, 
                                   {1,1,1,1,1}, 
                                   {1,1,1,1,1}, 
                                   {1,1,1,1,1}, 
                                   {1,1,1,1,1}, 
                                   };

    // Create an empty image with zeros 
    Image image(dummyImage);
    // Print image 
    cout << "Printing input image: " << endl; 
    image.printImage();
    // Apply brute force mean filtering on the image 
    Image ans = averagingFilter(3, image);
    cout << "Printing output image: " << endl;  
    ans.printImage();
    return 0; 
}