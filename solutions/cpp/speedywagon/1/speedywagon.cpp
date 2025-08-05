#include "speedywagon.h"

namespace speedywagon {

// Enter your code below:
bool connection_check(pillar_men_sensor* sensor){
    return sensor!=nullptr;
}

int activity_counter(pillar_men_sensor* p,int count){
int sum=0;

    for(int i=0;i<count;i++){
        sum+=(p+i)->activity;
    }

    return sum;
}

bool alarm_control(pillar_men_sensor* p){
    bool res=false;
        if(connection_check(p)){
            if(p->activity>0)
                res=true;
        }

        return res;
    }
   bool uv_alarm(pillar_men_sensor* p ){
        if(!connection_check(p))
            return false;
       int r = uv_light_heuristic(&p->data);

       return r > p->activity;
    }
// Please don't change the interface of the uv_light_heuristic function
int uv_light_heuristic(std::vector<int>* data_array) {
    double avg{};
    for (auto element : *data_array) {
        avg += element;
    }
    avg /= data_array->size();
    int uv_index{};
    for (auto element : *data_array) {
        if (element > avg) ++uv_index;
    }
    return uv_index;
}

}  // namespace speedywagon
