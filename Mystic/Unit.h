#pragma once

#include"Utilities.h"
#include"Picture.h"

namespace mystic
{
    class MYSTIC_API Unit
    {
    public:
        Unit(const std::string& image, int x, int y);
        Unit(std::string&& image, int x, int y);

        int GetWidth() const;
        int GetHeight() const;

        int GetXCoord() const;
        int GetYCoord() const;
        void SetCoords(int x, int y);
        void UpdateXCoords(int amount);
        void UpdateYCoords(int amount);

    private:
        Picture mImage;
        int mXPosition;
        int mYPosition;

        template<typename T> friend class MysticApp;
        friend MYSTIC_API bool UnitsOverlap(const Unit& a, const Unit& b);
    };

    MYSTIC_API bool UnitsOverlap(const Unit& a, const Unit& b);
}