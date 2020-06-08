/**
 * @brief   Arduino library for providing a convenient C++ interface for accessing UAVCAN.
 * @license MIT
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include "CritSec.h"

#include <Arduino.h>

/**************************************************************************************
 * GLOBAL VARIABLES
 **************************************************************************************/

static uint8_t irestore = 0;

/**************************************************************************************
 * FUNCTION DEFINITION
 **************************************************************************************/

void crit_sec_enter()
{
  irestore = (__get_PRIMASK() ? 0 : 1);
  noInterrupts();
}

void crit_sec_leave()
{
  if (irestore)
  {
    interrupts();
  }
}
