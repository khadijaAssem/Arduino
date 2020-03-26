/*
  OutputModule.h - Library for OutputModule.
*/

#include "Arduino.h"
#include "OutputModule.h"

OutputModule::OutputModule()
{
  
}

void OutputModule::setOutput(String s,int i)
{
  _output[i] = s;
}

String OutputModule::getOutput(int i)
{
  return s[i];
}
