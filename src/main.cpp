#include <iostream>
#include <sqlite3.h>
#include "Database.h"

int main()
{
    std::string table = "table";
    std::string file = "stadiums.db";
    Database stadiumDatabase(file, table);

    stadiumDatabase.printDatabaseActions();

    stadiumDatabase.addStadium("Joshua Stadium", "Goated Joshes", 1000);

    stadiumDatabase.printList();

    return 0;
}
