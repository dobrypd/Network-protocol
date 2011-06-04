#include <cstdlib>
#include <ctime>
#include "utils.h"

Log::Log() {
    file.open(LOGFILENAME().toAscii(), fstream::in | fstream::out | fstream::app);
    srandom(time(NULL));
    id = rand(); //identyfikator włączenia programu
}

Log::~Log() {
    if (file.is_open())
        file.close();
}

void Log::addLog(QString line){
    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    file << "[" << timeinfo->tm_hour << ":"
         << timeinfo->tm_min << ":"
         << timeinfo->tm_sec << ";"
         << timeinfo->tm_mday << "-"
         << timeinfo->tm_mon + 1 << "-"
         << timeinfo->tm_year + 1900
         << "|" << id << "]: "
         << line.toStdString()
         << std::endl;
}
