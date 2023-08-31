#include <iostream>
#include <cmath>


#define LOG(x)  std::cout << x << '\n'
#define LOGF(x) std::cout << x

struct vec2
{
    float x;
    float y;
    vec2(float x, float y) : x { x }, y { y }{}
    
    vec2 operator+(vec2 v)
    {
        float xVal = this->x + v.x;
        float yVal = this->y + v.y;
        
        return {xVal, yVal};
    }
    
    // A unit vector has a magnitude of 1 in both directions
    // this means we can 'normalise' a vector by dividing each of the values in a vector by its magnitude
    static vec2 toUnitVector(vec2 val)
    {
        float magnitude = sqrt(val.x * val.x + val.y * val.y);
        return {val.x / magnitude, val.y / magnitude};
    }
    
    float magnitude()
    {
        return sqrt(x * x + y * y);
    }
};

int main()
{
    // vectors contain a direction and magnitude
    // magnitude can be gained using pythagorus therum
    
    vec2 origin = {0,0};
    vec2 vector1 = {32, 89};
    
    float magnitude = sqrt(vector1.x * vector1.x + vector1.y * vector1.y);
    std::cout << "MAGNITUDE OF VECTOR 1 = " << magnitude << '\n';
    
    vec2 vector1Unit = vec2::toUnitVector(vector1);
    std::cout << "VECTOR 1 AS A UNIT VECTOR = " << vector1Unit.x << ", " << vector1Unit.y << '\n';
    
    
    // check that the magnitude of the unit vector is roughly 1 (floating point maths is sometimes inaccurate)
    // we now make a method inside the vec2 structure
    float magnitudeOfUnitVec = vector1Unit.magnitude();
    std::cout << "MAGNITUDE OF VECTOR 1 AS A UNIT VECTOR = " << magnitudeOfUnitVec << '\n';
    
    
    
    
    return 0;
}

