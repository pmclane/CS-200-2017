#ifndef _IMAGE_HPP      // this code makes it so that
#define _IMAGE_HPP      // duplicates of this file don't get loaded

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Pixel
{
    int r, g, b;
};

class Image
{
    public:
    Image();
    ~Image();

    void ReadFile( const string& filename );
    void WriteFile( const string& filename );
    void PrintStats();

    void AllocateArray( int size );
    void DeallocateArray();

    void Filter_RemoveRed();
    void Filter_RemoveGreen();
    void Filter_RemoveBlue();
    void Filter_Brighten();
    void Filter_Darken();
    void Filter_ShiftColors();
    void Filter_Custom();
    void Filter_Custom2();

    private:
    string inputFilename;
    string magicNumber;
    string headerNote;
    int width;
    int height;
    int colorDepth;

    Pixel* pixelArray;
    int pixelCount;
};

#endif
