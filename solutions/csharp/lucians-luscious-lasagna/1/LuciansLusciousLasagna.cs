class Lasagna
{
    public int ExpectedMinutesInOven(){
        return 40;
    }

    // TODO: define the 'RemainingMinutesInOven()' method
    public int RemainingMinutesInOven(int p){
        return 40-p;
    }

    // TODO: define the 'PreparationTimeInMinutes()' method
public int PreparationTimeInMinutes(int p){
        return 2*p;
    }
    // TODO: define the 'ElapsedTimeInMinutes()' method
    public int ElapsedTimeInMinutes(int l,int t){
        return 2*l+t;
    }
}
