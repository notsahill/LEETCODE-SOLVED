class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) 
    {
        if(mainTank<5) return mainTank*10;
        if(additionalTank<1) return mainTank*10;
        return distanceTraveled(mainTank-5+1,additionalTank-1)+50;
    }
};