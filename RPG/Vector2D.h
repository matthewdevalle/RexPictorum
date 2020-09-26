//
//  Vector2D.h
//  RPG
//
//  Created by Matthew Colvin de Valle on 26/09/2020.
//  Copyright © 2020 Matthew Colvin de Valle. All rights reserved.
//

#ifndef Vector2D_h
#define Vector2D_h

#endif /* Vector2D_h */
#pragma once
#include <iostream>

class Vector2D
{
private:
    
public:
    float x;
    float y;
    
    Vector2D();
    Vector2D(float x, float y);
    
    Vector2D& Add(const Vector2D& vec);
    Vector2D& Subtract(const Vector2D& vec);
    Vector2D& Multiply(const Vector2D& vec);
    Vector2D& Divide(const Vector2D& vec);
    
    friend Vector2D& operator+(Vector2D& v1, const Vector2D v2);
    friend Vector2D& operator-(Vector2D& v1, const Vector2D v2);
    friend Vector2D& operator*(Vector2D& v1, const Vector2D v2);
    friend Vector2D& operator/(Vector2D& v1, const Vector2D v2);
    
    Vector2D& operator+=(const Vector2D& vec);
    Vector2D& operator-=(const Vector2D& vec);
    Vector2D& operator*=(const Vector2D& vec);
    Vector2D& operator/=(const Vector2D& vec);
    
    friend std::ostream& operator<<(std::ostream& stream, const Vector2D& vec);
    
};