class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fc=0,tc=0,twc=0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){
                fc+=5;
            }
            else if(bills[i]==10){
                if(fc>=5){
                    fc-=5;
                    tc+=10;
                }
                else return false;
            }
            else if(bills[i]==20){
                if(fc>=5 and tc>=10){
                    fc-=5;
                    tc-=10;
                    twc+=20;
                }
                else if(fc>=15){
                    fc-=15;
                    twc+=20;
                }
                else return false;
            }
        }
        return true;
    }
};