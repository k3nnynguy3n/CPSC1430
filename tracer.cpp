// Kenny Nguyen
// This file includes the method definitions

#include "tracer.h"
#include <iostream>

// Default constructor
// Sets name to "default" and announces the start of the instances lifetime
Tracer::Tracer() {
    name = "default";
    std::cout << "lifetime of " << name << " started" << std::endl;
}

// Copy constructor
// Sets name to other.name followed by "copy" and announces the start of the instance's lifetime
Tracer::Tracer(Tracer const &other) {
    name = other.name + " copy";
    std::cout << "lifetime of " << name << " started" << std::endl;
}

// Converting constructor
// Sets name to name_str and announces the start of the instances lifetime
Tracer::Tracer(char const *name_str) {
    name = name_str;
    std::cout << "lifetime of " << name << " started" << std::endl;
}

// Assignment operator for Tracer
// Announces the assignment but does not change any values
void Tracer::operator=(Tracer const &other) {
    std::cout << "Tracer " << name << " assigned " << other.name << std::endl;
}

// Assignment operator for char const*
// Changes name to new_name and announces the rename
void Tracer::operator=(char const *new_name) {
    std::string temp = name;
    name             = new_name;
    std::cout << "tracer " << temp << " renamed to " << new_name << std::endl;
}

// Deconstructor
// Announces the end of the instances lifetime
Tracer::~Tracer() {
    std::cout << "lifetime of " << name << " ended" << std::endl;
}