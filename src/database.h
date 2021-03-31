#ifndef DATABASE_H
#define DATABASE_H

#include <memory>
#include <mutex>
#include <libpq-fe.h>

class Database
{
public:
    Database();
    std::shared_ptr<PGconn> getConnection() const;
    bool executeSQL(const std::string& sql);

private:
    void establish_connection();
    void loadEnvVariables();

    std::string m_dbhost;
    int         m_dbport;
    std::string m_dbname;
    std::string m_dbuser;
    std::string m_dbpass;

    std::shared_ptr<PGconn>  m_connection;
};

#endif // DATABASE_H
