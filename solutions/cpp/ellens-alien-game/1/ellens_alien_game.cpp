namespace targets {
// TODO: Insert the code for the alien class here
    
class Alien{
    public:
    int x_coordinate;
    int y_coordinate;

    int health =3;

public:
    Alien(int x, int y){
        x_coordinate=x;
        y_coordinate=y;
    }

     int get_health(){
        return health;
    }
public:
     bool hit(){
        if(health > 0)
        {
            health--;
            return true;
        }
        return false;
    }

     bool is_alive(){
        return health>0;
    }

     bool teleport(int x, int y){
        x_coordinate=x;
        y_coordinate=y;

         return true;
    }

     bool collision_detection(Alien a){
        if (x_coordinate == a.x_coordinate and y_coordinate == a.y_coordinate)
            return true;

        return false;
    }
};
}  // namespace targets