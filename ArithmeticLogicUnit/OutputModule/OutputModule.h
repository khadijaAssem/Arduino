/*
  OutputModule.h - Library for OutputModule.
*/
#ifndef OutputModule_h
#define OutputModule_h

#include "Arduino.h"

class OutputModule
{
  public:
    OutputModule();
    void setOutput(String s,int i);
    String getOutput(int i);
  private:
    String _output[];
};

#endif