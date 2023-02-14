#include "taptempo.h"

namespace taptempo {

void TapTempo::init(int sample_rate, float averaging_coeff) {
  this->sample_rate = sample_rate;
  ticks_since_last_tap = 0.0f;
  average_ticks = 0.0f;
  this->averaging_coeff = averaging_coeff;
}

void TapTempo::tap() {
  update_average();
  ticks_since_last_tap = 0;
}

void TapTempo::tick() { ++ticks_since_last_tap; }

void TapTempo::update_average() {
  average_ticks += averaging_coeff * (ticks_since_last_tap - average_ticks);
}

float TapTempo::get_tempo_hz() { return (float)sample_rate / average_ticks; }

float TapTempo::get_tempo_samples() { return int(average_ticks); }
} // namespace taptempo