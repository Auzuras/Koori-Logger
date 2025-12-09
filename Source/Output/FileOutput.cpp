#include <Output/FileOutput.h>

FileOutput::FileOutput()
{
    OpenLogFile();
}

FileOutput::~FileOutput()
{
    CloseLogFile();
}

void FileOutput::WriteLog(const Log& _log)
{
    m_LogFile << _log.ToWString();
}

void FileOutput::OpenLogFile()
{
    m_LogFile.open("LogTest.log");
}

void FileOutput::CloseLogFile()
{
    m_LogFile.close();
}


