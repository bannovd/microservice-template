#include "check.h"
#include "database.h"


void Check::testDB()
{
    Database db;
    db.executeSQL("select 1;");
}
