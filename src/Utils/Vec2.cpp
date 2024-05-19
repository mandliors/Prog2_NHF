#include "Vec2.h"

namespace Utils {
    
    Vec2d Vector2ToVec2(const Vector2& vec)
    {
        return Vec2d((double)vec.x, (double)vec.y);
    }
}