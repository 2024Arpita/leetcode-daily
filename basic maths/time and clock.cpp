//lc 1344
class Solution {
public:
    double angleClock(int hour, int minutes) {
        //1 hour=30 degree
        //1 min=6 degree
        //hour hand movement due to minutehand
        //30 degree=1hour=60min
        //1 min=0.5 degree
        //total hour hand=30*(hour%12)+(0.5*minutes)
        //totalmin hand=6*minutes;
        //take min of diff;
        double hrhand=(hour%12)*30+(double)minutes*0.5;
        double minhand=minutes*6;
        return min(abs(hrhand-minhand),360-abs(hrhand-minhand));
    }
};