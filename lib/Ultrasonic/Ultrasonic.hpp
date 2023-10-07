#ifndef Ultrasonic_h
#define Ultrasonic_h

#include <Arduino.h>

class Ultrassonic {
	private:
		int TRIGGER_PIN;
		int ECHO_PIN;
		void begin();

	long get_duration();

	public:
		Ultrassonic(int trigger_pin, int echo_pin);
		float get_distance_cm();
		float get_distance_m();
};

#endif