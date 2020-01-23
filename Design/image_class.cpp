#include<iostream>
#include<vector>
#include <typeinfo>


/*
Next tasks:

1) Read an OpenCV Image into a Mat object. 
2) Write a function to copy contents of this image into our custom image class. 
3) Add two 'Image' objects by overloading the + operator 
4) Convert the result back into a MAT object and display 
*/

// To maintain simplicity, the image representation will be a vector of vectors 
template<typename T>
class Image
{
    public:
        
        // Number of columns in the image
        int _numCols;
        // Number of rows in the image 
        int _numRows; 
        
        // Constructor for class (Using initializer lists for initializing member variables)
        Image(int numRows, int numCols, T val): _numRows(numRows), _numCols(numCols)
        {
            std::vector<std::vector<T> > image(numRows, std::vector<T>(numCols, val)); 
            // Storing copy of the image as a private variable 
            _image = image; 
        }

        void printImageMetaData()
        {
            std::cout << "Number of rows: " << _numRows << std::endl;
            std::cout << "Number of columns: " << _numCols << std::endl;  
        }

        Image operator + (Image const& img2)
        {            
            if(img2._numCols!= _numCols || img2._numRows!= _numRows)
            {
                throw ("Image sizes don't match. They cannot be added");
            }

            else
            {
                std::cout << _numRows << _numCols << std::endl; 
                for(int i=0; i < _numRows; i++)
                {                    
                    for(int j=0; j <_numCols; j++)
                    {
                        std::cout << i << j << std::endl; 
                        _image[i][j]+= img2._image[i][j];
                    }
                }

                std::cout << "Exited for loop" <<  std::endl; 
            }

        }
    
    private:

        // Storing copy of the image as a private member variable  
        std::vector<std::vector<T> > _image; 
};


int main()

{
    Image<float> image1(11, 11, 1.5);
    Image<float> image2(11, 11, 2.5);

    image1 + image2; 

    return 0; 
}