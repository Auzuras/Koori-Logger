#ifndef KOORI_LOGGER_FILEOUTPUT_H
#define KOORI_LOGGER_FILEOUTPUT_H

#include <Output/ALogOutput.h>

#include <fstream>

class FileOutput : public ALogOutput
{
public:
    FileOutput();
    ~FileOutput() override;

    void WriteLog(const Log& _log) override;

protected:

    void OpenLogFile();
    void CloseLogFile();

private:
    std::wofstream m_LogFile{};
};

#endif //KOORI_LOGGER_FILEOUTPUT_H