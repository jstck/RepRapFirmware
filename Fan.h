/****************************************************************************************************

RepRapFirmware - Fan

Controls temperature-controlled fans

2014 John Stäck <john@stack.se>

Licence: GPL

****************************************************************************************************/

#ifndef FAN_H
#define FAN_H

class Fan
{

  public:

    Fan(Platform* p, GCodes* g);
    void Spin();
    void Init(float tOn, float tOff);
    void Exit();

  private:
    Platform* platform;
    GCodes* gCodes;

    float tempOn, tempOff;
    bool fanState;
};



#endif
