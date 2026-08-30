#ifndef KOORI_LOGGER_CONSOLE_COLOR_H
#define KOORI_LOGGER_CONSOLE_COLOR_H

#include <cstdint>

// Windows colors       
                        
// 0 - Black            
// 1 - blue             
// 2 - green            
// 3 - cyan             
// 4 - red              
// 5 - purple           
// 6 - yellow           
// 7 - gray             
// 8 - dark gray        
// 9 - light blue       
// 10 - light green     
// 11 - light cyan      
// 12 - light red       
// 13 - light purple    
// 14 - light yellow    
// 15 - white           

// Windows Color = Foreground + background * 16
// or (Background << 4) | foreground

struct ConsoleColor
{
public:
    enum class Color : uint8_t
    {
        KL_COLOR_BLACK      =   0,
        KL_COLOR_RED        =   1,
        KL_COLOR_GREEN      =   2,
        KL_COLOR_YELLOW     =   3,
        KL_COLOR_BLUE       =   4,
        KL_COLOR_MAGENTA    =   5,
        KL_COLOR_CYAN       =   6,
        KL_COLOR_WHITE      =   8
    };

    enum class Intensity : uint8_t
    {
        KL_COLOR_INTENSITY_LIGHT      =   30,
        KL_COLOR_INTENSITY_DARK       =   90
    };

    enum class Target : uint8_t
    {
        KL_COLOR_TARGET_FOREGROUND =   0x0,
        KL_COLOR_TARGET_BACKGROUND =   0x1
    };

    enum class Attribute : uint8_t
    {
        KL_COLOR_ATTRIBUTE_NONE                 =   0,
        KL_COLOR_ATTRIBUTE_BOLD                 =   0x1 << 1,
        KL_COLOR_ATTRIBUTE_DIM                  =   0x1 << 2,
        KL_COLOR_ATTRIBUTE_ITALIC               =   0x1 << 3,
        KL_COLOR_ATTRIBUTE_UNDERLINE            =   0x1 << 4,
        KL_COLOR_ATTRIBUTE_BLINK                =   0x1 << 5,
        KL_COLOR_ATTRIBUTE_RAPID_BLINK          =   0x1 << 6,
        KL_COLOR_ATTRIBUTE_REVERSE              =   0x1 << 7,
        KL_COLOR_ATTRIBUTE_CONCEAL              =   0x1 << 8,
        KL_COLOR_ATTRIBUTE_STRIKETHROUGH        =   0x1 << 9,
        KL_COLOR_ATTRIBUTE_DOUBLE_UNDERLINE     =   0x1 << 10
    };

private:
    uint16_t m_ColorDescription = 0u;


public:
    ConsoleColor(Color _color, Intensity _intensity = Intensity::KL_COLOR_INTENSITY_LIGHT, Target _target = Target::KL_COLOR_TARGET_FOREGROUND, Attribute _attribute = Attribute::KL_COLOR_ATTRIBUTE_NONE);

    void SetColor();
    void ResetColor();

protected:
    static bool CheckForANSISupport();

private:
    static bool WIN_CheckForANSISupport();

};


#endif //KOORI_LOGGER_CONSOLE_COLOR_H