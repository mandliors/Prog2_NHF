#ifndef COLOR_H
#define COLOR_H

struct Color;

struct Col
{
    /**
     * @brief Constructs a new Col object
     * 
     * @param r The red value
     * @param g The green value
     * @param b The blue value
     * @param a The alpha value
     */
    Col(int r, int g, int b, int a = 255);
    /**
     * @brief Constructs a new grayscale Col object (alpha is 255)
     * 
     * @param gray The grayscale value
     */
    Col(int gray);

    /**
     * @brief Fades the color by a certain amount (changes the alpha value)
     * 
     * @param t The amount to fade by (0.0 - 1.0)
     * @return Col The faded color
     */
    Col Fade(double t) const;
    /**
     * @brief Linearly interpolates between two colors
     * 
     * @param other The other color
     * @param t The interpolation value
     * @return Col The interpolated color
     */
    Col Lerp(const Col& other, double t) const;

    /**
     * @brief Converts the color to a Color object (Raylib color)
     * 
     * @return Color The Color object
     */
    operator Color() const;

public:
    int R, G, B, A;
};

#endif