/****************************************************************************************************

RepRapFirmware - Fan

Controls temperature-controlled fan

2014 John Stäck <john@stack.se>

Licence: GPL

****************************************************************************************************/

#include "RepRapFirmware.h"

Fan::Fan(Platform* p, GCodes* g)
{
  platform = p;
  gCodes = g;
}

void Fan::Init(float tOn, float tOff)
{
  tempOn=tOn;
  tempOff=tOff;

  //Make sure off temp is at least 0.5 degrees below on temp
  if(tempOff+0.5>tempOn)
  {
    tempOff==tempOn-0.5;
  }

  fanState=false;
}

void Fan::Exit()
{
}

void Fan::Spin()
{
  float hotendTemp;
  bool stateChange=false;

  if(!fanState)
  {
    if(hotendTemp >= tempOn)
    {
      fanState=true;
      stateChange=true;
    }
  }
  else
  {
    if(hotendTemp < tempOff)
    {
      fanState=false;
      stateChange=true;
    }
  }
  if(stateChange)
  {
    platform->HotendFan(fanState);
  }
}
