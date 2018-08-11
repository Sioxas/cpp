//
// Created by AAPPED on 2016/3/16 0016.
//

#ifndef GCD_TIMECOUNTER_H
#define GCD_TIMECOUNTER_H


#include <time.h>

class TimeWatch {
private :
    clock_t startT;
    clock_t stopT;
public:
    void start(){
        startT=clock();
    }
    void stop(){
        stopT=clock();
    }
    int time(){
        return stopT-startT;
    }
};


#endif //GCD_TIMECOUNTER_H
