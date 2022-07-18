#include "vars.h"

const uint16_t temp_minC = 50; // Minimum temperature the controller can check accurately
const uint16_t temp_maxC = 600; // Maximum possible temperature
const uint16_t temp_ambC = 25; // Average ambient temperature
const uint16_t temp_max = 1023; // Maximum possible temperature in internal units
const uint16_t temp_tip[3] = {999, 1062, 1023}; // Temperature reference points for calibration
const uint16_t max_fan_speed = 256; // Maximum Hot Air Gun Fan speed
const uint16_t min_fan_speed	= 10;
const uint16_t tune_fan_speed	= 128; // Hot Air Gun speed in tune mode
