class ParkingSystem {
public:
    vector<int>temp;
    ParkingSystem(int big, int medium, int small) {
        temp.resize(4,0);
        temp[1]=big;
        temp[2]=medium;
        temp[3]=small;
    }
    
    bool addCar(int carType) {
        if(temp[carType]>0){
            temp[carType]--;
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */