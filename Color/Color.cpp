#include "Color.h"

#ifndef CPORTA
#include <raylib.h>
#endif

Col::Col(int r, int g, int b, int a) : R(r), G(g), B(b), A(a) {}
Col::Col(int gray) : R(gray), G(gray), B(gray), A(255) {}

Col Col::Fade(double t) const { return Col(R, G, B, (int)(A * t)); }
Col Col::Lerp(const Col& other, double t) const
{
    return Col(
        R + (int)((other.R - R) * t),
        G + (int)((other.G - G) * t),
        B + (int)((other.B - B) * t),
        A + (int)((other.A - A) * t)
    );
}

#ifndef CPORTA
Col::operator Color() const { return Color{ (unsigned char)R, (unsigned char)G, (unsigned char)B, (unsigned char)A }; }
#endif
