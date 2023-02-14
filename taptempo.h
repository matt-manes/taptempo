#pragma once
/* Simple class to track the amount of time between "tap" events.
  The sample_rate is the number of times your "tap" source is checked per
  second. The tick() method should be called once every loop. The tempo can be
  obtained in Hertz or in samples using get_tempo_hz() and get_tempo_samples(),
  respectively.*/
namespace taptempo {

class TapTempo {
public:
  void init(int sample_rate, float averaging_coeff = 0.9f);
  void tap();
  void tick();
  float get_tempo_hz();
  float get_tempo_samples();

private:
  int sample_rate; // How many times a second tap source will be checked
  int ticks_since_last_tap;
  float average_ticks;
  float averaging_coeff;
  void update_average();
};

} // namespace taptempo