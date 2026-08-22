#ifndef KOORI_LOGGER_CONSOLE_COLOR_H
#define KOORI_LOGGER_CONSOLE_COLOR_H

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

struct ConsoleColor
{
public:
    enum class Color : uint8_t // 4
    {
        KL_COLOR_RED        =   0x0,
        KL_COLOR_GREEN      =   0x1,
        KL_COLOR_BLUE       =   0x2,
        KL_COLOR_CYAN       =   0x3,
        KL_COLOR_MAGENTA    =   0x4,
        KL_COLOR_YELLOW     =   0x5,
        KL_COLOR_GRAY       =   0x6,
        KL_COLOR_BLACK      =   0x7,
        KL_COLOR_WHITE      =   0x8
    };

    enum class Intensity : uint8_t // 1
    {
        KL_COLOR_LIGHT      =   0x0,
        KL_COLOR_DARK       =   0x1
    };

    enum class Target : uint8_t // 1
    {
        KL_COLOR_FOREGROUND =   0x0,
        KL_COLOR_BACKGROUND =   0x1
    };

    enum class Attribute : uint8_t // 2
    {
        KL_COLOR_BOLD       =   0x0,
        KL_COLOR_ITALIC     =   0x1,
        KL_COLOR_UNDERLINE  =   0x2
    };

private:
    uint8_t m_ColorDescription = 0u;

public:
    ConsoleColor(Color _color, Intensity _intensity, Target _target, Attribute _attribute);
};


#endif //KOORI_LOGGER_CONSOLE_COLOR_H