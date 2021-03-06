#ifndef _DS18B20_QUERY_H
#define _DS18B20_QUERY_H

#include <Arduino.h>

typedef struct
{
  bool Negative;
  int Whole;
  int Fract;
  
} DS18B20Temperature;

typedef enum
{
  temp9bit = 0x1F,
  temp10bit = 0x3F,
  temp11bit = 0x5F,
  temp12bit = 0x7F
  
} DS18B20Resolution;

typedef enum
{
  DS18B20,
  DS18S20
} DSSensorType; // тип сенсора

class DS18B20Support
{
  private:

  uint8_t pin;

  public:
    DS18B20Support() : pin(0) {};

    void begin(uint8_t _pin) {pin = _pin;}
    bool readTemperature(DS18B20Temperature* result, DSSensorType type);
    void setResolution(DS18B20Resolution res); 
    
};

#endif
