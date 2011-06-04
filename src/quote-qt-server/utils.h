#ifndef UTILS_H
#define UTILS_H

#include <fstream>
#include <QString>

using std::fstream;

#define UTF(X) QString::fromUtf8(X)


/*constants*/
const int SERVER_PORT = 44444;

/*log file*/
class Log {
public:
    Log();
    ~Log();
    void addLog(QString line);

    static QString LOGFILENAME() { return UTF("serverlog.txt"); }
private:
    fstream file;
    unsigned id;
};


#endif // UTILS_H
