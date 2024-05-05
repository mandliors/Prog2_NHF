#ifndef COLOR_H
#define COLOR_H

#ifndef CPORTA
struct Color;
#endif

struct Col
{
    Col(int r, int g, int b, int a = 255);
    Col(int gray);

    Col Fade(double t) const;
    Col Lerp(const Col& other, double t) const;

#ifndef CPORTA
    operator Color() const;
#endif

public:
    int R, G, B, A;
};

#endif