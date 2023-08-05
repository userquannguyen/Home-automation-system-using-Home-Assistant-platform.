#include "esphome.h"
#include "driver/adc.h"

// ... sau đó tiến hành code cho cảm biến do am

class MyCustomSensor : public PollingComponent, public Sensor {
 public:

  MyCustomSensor() : PollingComponent(15000) { }

  void setup() override {
    bmp.begin();
  }

  void update() override {
    int pressure = bmp.readPressure(); // library returns value in in Pa, which equals 1/100 hPa
    publish_state(pressure / 100.0); // convert to hPa
  }
};
