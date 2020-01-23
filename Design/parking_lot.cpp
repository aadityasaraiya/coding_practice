/*
1) Design a parking lot 


*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Vehicle{

    public: 
        Vehicle* vehiclePtr_= NULL; 
        string vehicleType= ""

        // Create a constructor for the vehicle 
        Vehicle(int height, int width):
               height_(height), width_(width)
        {
            
            vehicleType= getVehicleCategory();
        }
            
    private:
        int height_= 0; 
        int width_= 0; 

        string getVehicleCategory()
        {
            if(height_> 10 || width_ > 10)
            {
                // Setting a public member variable 
                vehiclePtr= new Truck;
                vehicleType= "truck";
                cout << "Hi. I am a truck" << endl; 
            }

            else
            {
                // Setting a public member variable 
                vehiclePtr= new Car;
                vehicleType= "car";
                cout << "Hi. I am a car" << endl; 
            }
        }

};

class Car: public Vehicle
{
    private:
        int numWheels= 4;
};

class Truck: public Vehicle
{
    private:
        int numWheels= 8; 
};



class ParkingLot{

    public:
        // Constructor for parking lot 
        ParkingLot(int width, int height)
        {
            createParkingLotInitGraph(width, height);
        }
    
        // New vehicle entering. The parking lot gives a status update if we can let the vehicle enter or not 
        bool enter(Vehicle vehicle)
        {
            // Check if the vehicle can enter or not 
            bool enterAllowance= checkVehicleDim(vehicle);

            if(!enterAllowance)
            {
                return enterAllowance; 
            }

            else
            {
                // Find the nearest empty location where the vehicles should park 

            }

        }



    private:
        // Create core parking lot infrastructure 
        //vector<vector<Vehicle>> parkingLotGraph;
        Vehicle parkingLotGraph[][]; 

        void createParkingLotInitGraph(int width, int height)
        {
            Vehicle tempLot[width][height]= {0}; 
            parkingLotGraph= tempLot; 
        }

        bool checkVehicleDim(Vehicle vehicle)
        {
            if(vehicle.vehicleType_ == "truck")
            {
                cout << "Sorry this parking lot does not allow trucks" << endl; 
                return false; 
            }

            if(vehicle.vehicleType_ == "car")
            {
                cout << "Hi. You can enter the lot" << endl; 
                return true; 
            }
        }



};


int main()
{
    // The parking lot is an N x M grid 
    int N= 4;
    int M= 4; 

    // Initialize the parking lot object 
    ParkingLot parkingLot(N, M);

    // Initialize a few random vehicles 
    Vehicle v1(11, 12);
    Vehicle v2(5,5);
    Vehicle v3(9,10);

    queue<Vehicle> entryQueue; 

    entryQueue.push(v1);
    entryQueue.push(v2);
    entryQueue.push(v3);

    while(!entryQueue.empty())
    {
        auto vehicleCurrent= entryQueue.front();
        
        // Query parking lot to enter 
        //bool hasParked= parkingLot.enter()

        bool hasParked= true; 
        // Save bye bye to the vehicle from the queue 
        entryQueue.pop();
    }



}
