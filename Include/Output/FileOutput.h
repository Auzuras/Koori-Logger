#ifndef KOORI_LOGGER_FILE_OUTPUT_H
#define KOORI_LOGGER_FILE_OUTPUT_H

#include <Output/ALogOutput.h>

#include <fstream>

/**
 * File Output override of the Log Output abstract class
 */
class FileOutput : public ALogOutput
{
public:

    /**
     * Default FileOutput's constructor
     */
    FileOutput();

    /**
     * Override of the FileOutput destructor
     */
    ~FileOutput() override;

    /**
     * Write a log in a file output
     * @param _log Reference of the log that should be written in the file
     */
    void WriteLog(const Log& _log) override;

protected:

    /**
     * Open a new log file
     */
    void OpenLogFile();

    /**
     * Close the currently opened log file
     */
    void CloseLogFile();

private:

    /**
     * Reference of currently opened log file output
     */
    std::wofstream m_LogFile{};
};

#endif //KOORI_LOGGER_FILE_OUTPUT_H