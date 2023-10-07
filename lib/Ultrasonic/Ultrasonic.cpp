#include "Ultrasonic.hpp"

Ultrassonic::Ultrassonic(int trigger_pin, int echo_pin) {
    TRIGGER_PIN = trigger_pin;
    ECHO_PIN = echo_pin;
    begin();
}

void Ultrassonic::begin() {
    pinMode(TRIGGER_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
}

long Ultrassonic::get_duration() {
    digitalWrite(TRIGGER_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIGGER_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER_PIN, LOW);
    return pulseIn(ECHO_PIN, HIGH);
}

float Ultrassonic::get_distance_cm() {
    long duration = get_duration();
    float distance = (duration * 0.034) / 2;
    return distance;
}

float Ultrassonic::get_distance_m() {
    float distance = get_distance_cm();
    return distance / 100;
}