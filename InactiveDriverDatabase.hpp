#ifndef INACTIVEDRIVERDATABASE_HPP
#define INACTIVEDRIVERDATABASE_HPP
#include "SearchDatabase.hpp"

class InactiveDriverDatabase : public SearchDatabase {

    public:
        InactiveDriverDatabase(int size = 100) : SearchDatabase(size) {}
};

#endif