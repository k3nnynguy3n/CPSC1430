// Kenny Nguyen
// Class definition for the class 'Tracer'
// with included members, methods, and deconstructors

#include <string>

// Definition of class named Tracer
class Tracer {

    // Members
    private:
    std::string name;
    
    // Methods
    public:
    Tracer();
    Tracer(Tracer const &other);
    Tracer(char const *name_str);
    void operator=(Tracer const &other);
    void operator=(char const *new_name);

    // Deconstructors
    ~Tracer();
};