#ifndef MOVIE_H
#define MOVIE_H
#include <qstring.h>

class movie
{
public:
    movie();
    QString name;
    QString genre;
    QString actor;
    QString released;
    QString director;
    QString capacity;
    bool suggested;
};

#endif // MOVIE_H
