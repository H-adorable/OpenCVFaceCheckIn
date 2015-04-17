#ifndef INFORMATION_H
#define INFORMATION_H

#include <QString>

class Information
{
public:
    Information();
    ~Information();

    // Return information according to the code
    QString get(int);

};

#endif // INFORMATION_H
