#include <iostream>
#include <cmath>


#define LOG(x)  std::cout << x << '\n'
#define LOGF(x) std::cout << x

struct vec2
{
    float x;
    float y;
    vec2(float x, float y) : x { x }, y { y }{}
    vec2(){}
    
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

const float PI = 3.14159265;

static float DegToRads(float degrees)
{
    return degrees * (PI / 180);
}

int main()
{
    // vectors contain a direction and magnitude
    
    vec2 origin = {0,0};
    vec2 vector1 = {32, 89};
    
    // magnitude can be gained using pythagorus therum
    float magnitude = sqrt(vector1.x * vector1.x + vector1.y * vector1.y);
    std::cout << "MAGNITUDE OF VECTOR 1 = " << magnitude << '\n';
    
    vec2 vector1Unit = vec2::toUnitVector(vector1);
    std::cout << "VECTOR 1 AS A UNIT VECTOR = " << vector1Unit.x << ", " << vector1Unit.y << '\n';
    
    
    // check that the magnitude of the unit vector is roughly 1 (floating point maths is sometimes inaccurate)
    // we now make a method inside the vec2 structure so we can simplify the lines above
    // as we can see::
    /*
        float mag = vector.magnitude()
        
        -- is much cleaner code than
     
        float mag = sqrt(vector.x * vector.x + vector.y * vector.y);
     
        -- In addition, by using a method for this inside the vector structure, we conform to the DRY rules (Dont Repeat Yourself)
     
     */
    float magnitudeOfUnitVec = vector1Unit.magnitude();
    std::cout << "MAGNITUDE OF VECTOR 1 AS A UNIT VECTOR = " << magnitudeOfUnitVec << '\n';
    
    // What about if we want to add vectors based on the magnitude and direction angle (from the x axis)
    /*
     
     example ||v|| = 6 (the magnitude of v = 6)
     direction angle of v = 160
     
     
     example ||w|| = 4
     direction angle of w = 290
     
      ^
      |\
      | \
     O|  \ 6 = H
      |   \
      |____\ 160^
         A
        
     using trigonometry, we can find the vector of v.
     
     sin(theta) = opposite / Hypoteneuse
     cos(theta) = adjacent / hypoteneuse
     tan(theta) = opposite / adjacent
     
     
     from the previous example, we can calculate the magnitude of a vector by using pythag. this must mean that the magnitude of the vector is the equivalent of the hypoteneuse
     
     therefore, we know the angle of the triangle, just like basic algebra, we can rearrange the equation to find what we need.
     
     in this case: sin(theta) * hypoteneuse = opposite
     
        and also:  cos(theta) * hypoteneuse = adjacent
     
     sin(160) * 6 = 2.05
     cos(160) * 6 = -5.64
     
     
     adjacent is same as the X acis in this instance
     opposite is same as the Y axis in this instance
     
     therefore: v = (-5.64, 2.05)      <---- THIS WOULD MAKE SENSE, look at my terrible drawing of the triangle above, the arrow is clearly pointing up and to the left, which would work with a
                                            negative x value and positive y value
     
     
     lets do the same with w vector.
     
     w.x = cos(290) * 4
     w.y = sin(290) * 4
     
     therefore w = (1.37, -3.76)
     
     
     
     we now have the vector properties of both v and w
     
     we can now do some simple vector addition, lets have a look
       
                  v.x     w.x       v.y     w.y
     v + w = ( ( -5.64 + 1.37 ), ( 2.05 + -3.76 ) )
     
     v + w = (-4.27, -1.71)
     
     
     Lets now do this in code! (code will often use radians rather than degrees -- the conversion is simple - radians = degrees * ( PI / 180 ))
     
     */
    
    float vectorAMagnitude = 6;
    float vectorAAngle = DegToRads(160);
    
    float vectorBMagnitude = 4;
    float vectorBAngle = DegToRads(290);
    
    vec2 vecA;
    vecA.x = vectorAMagnitude * cos(vectorAAngle);
    vecA.y = vectorAMagnitude * sin(vectorAAngle);
    
    vec2 vecB;
    vecB.x = vectorBMagnitude * cos(vectorBAngle);
    vecB.y = vectorBMagnitude * sin(vectorBAngle);
    
    vec2 vecA_ADD_vecB = vecA + vecB;
    std::cout << "THE ADDED VECTORS IS: " << vecA_ADD_vecB.x << ", " << vecA_ADD_vecB.y << '\n'; // this output -4.2700, -1.70665  -- exactly the same as we got above!
    
    
    
    return 0;
}

