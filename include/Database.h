#pragma once

#include <sqlite3.h>
#include <string>

class Database
{
public:
    Database(std::string fileName, std::string table);\
    ~Database();

    void printDatabaseActions() const;
    void printList() const;
    void addStadium(std::string name, std::string team, int capacity);
    void updateCapacity(int newCapacity);
    void deleteStadium(std::string name);

private:
    static constexpr std::string DATABASE_FOLDER{ "sql/" };

    std::string tableName;
    std::string dbName;
    sqlite3* data;

};
