#include "Database.h"

#include <iostream>
#include <sqlite3.h>

Database::Database(std::string fileName, std::string table)
: dbName(fileName), tableName(table)
{
    sqlite3_open((DATABASE_FOLDER + dbName).c_str(), &data);

    std::string createSql{
    R"(
        CREATE TABLE IF NOT EXISTS stadiums
        (
            id          INTEGER PRIMARY KEY,
            name        TEXT NOT NULL,
            team        TEXT NOT NULL,
            capacity    INTEGER
        );
    )"};

    sqlite3_exec(data, createSql.c_str(), nullptr, nullptr, nullptr);
}

Database::~Database() { sqlite3_close(data); }

void Database::printDatabaseActions() const
{
    std::cout << "=== Stadium Tracker ===\n"
              << "1. List stadiums\n"
              << "2. Add a stadium\n"
              << "3. Update capacity\n"
              << "4. Delete a stadium\n"
              << "5. Quit\n\n";
}

void Database::printList() const
{
    const char* sql{ "SELECT id, name, team, capacity FROM stadiums ORDER BY name;" };

    sqlite3_stmt* st{ nullptr };
    sqlite3_prepare_v2(data, sql, -1, &st, nullptr);

    while (sqlite3_step(st) == SQLITE_ROW)
    {
        int id{ sqlite3_column_int(st, 0) };
        const char* name{ reinterpret_cast<const char*>(sqlite3_column_text(st, 1)) };
        const char* team{ reinterpret_cast<const char*>(sqlite3_column_text(st, 2)) };
        int capacity{ sqlite3_column_int(st, 3) };

        std::cout << id << "  " << name << "  " << team << "  " << capacity <<'\n';
    }

    sqlite3_finalize(st);
}

void Database::addStadium(std::string name, std::string team, int capacity)
{
    sqlite3_stmt* st{ nullptr };

    std::string insertSql{
    R"(
        INSERT INTO stadiums (name, team, capacity) VALUES (?, ?, ?);
    )"};

    sqlite3_prepare_v2(data, insertSql.c_str(), -1, &st, nullptr);

    sqlite3_bind_text(st, 1, name.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(st, 2, team.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(st, 3, capacity);

    if (sqlite3_step(st) != SQLITE_DONE)
    {
    }

    sqlite3_finalize(st);
}

void Database::updateCapacity(int newCapacity)
{

}

void Database::deleteStadium(std::string name)
{

}
