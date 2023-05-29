class ParkingSystem {
public:
    int BC,MC,SC,B=0,M=0,S=0;
    ParkingSystem(int big, int medium, int small) 
    {
        BC=big;
        MC=medium;
        SC=small;
    }
    
    bool addCar(int c) 
    {
        if(c==1)
        {
            if(B>=BC) return false;
            B++;
            return true;
        }
        if(c==2)
        {
            if(M>=MC) return false;
            M++;
            return true;
        }
        if(c==3)
        {
            if(S>=SC) return false;
            S++;
            return true;
        }
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */