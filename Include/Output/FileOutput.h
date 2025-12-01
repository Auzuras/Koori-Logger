#ifndef KOORI_LOGGER_FILEOUTPUT_H
#define KOORI_LOGGER_FILEOUTPUT_H

#include <Output/ILogOutput.h>

class FileOutput : public ILogOutput
{
    FileOutput() = default;
    ~FileOutput() override;
};

#endif //KOORI_LOGGER_FILEOUTPUT_H