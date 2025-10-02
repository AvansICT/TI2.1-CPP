#include <iostream>
#include "chronotimer.hpp"
using namespace std::chrono_literals;

// Constructor
ChronoTimer::ChronoTimer(void) {
}

// Destructor
ChronoTimer::~ChronoTimer(void) {
}

// Copy constructor
ChronoTimer::ChronoTimer(const ChronoTimer& other)
    : _start(other._start), _stop(other._stop) {
}

// Copy assignment
ChronoTimer& ChronoTimer::operator=(const ChronoTimer& other) {
    if (this != &other) {
        _start = other._start;
        _stop = other._stop;
    }
    return *this;
}

// Move constructor
ChronoTimer::ChronoTimer(ChronoTimer&& other) noexcept
    : _start(std::move(other._start)),
    _stop(std::move(other._stop)) {
}

// Move assignment
ChronoTimer& ChronoTimer::operator=(ChronoTimer&& other) noexcept {
    if (this != &other) {
        _start = std::move(other._start);
        _stop = std::move(other._stop);
    }
    return *this;
}

// Timer functions
void ChronoTimer::startTimer(void) {
    _start = std::chrono::system_clock::now();
}

void ChronoTimer::stopTimer(void) {
    _stop = std::chrono::system_clock::now();
}

double ChronoTimer::elapsedTime(void) const {
    std::chrono::duration<double> diff = _stop - _start;
    return diff.count();
}