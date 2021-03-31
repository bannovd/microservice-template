#ifndef SERVER_H
#define SERVER_H

#include <Poco/Util/ServerApplication.h>

class ServerApp : public Poco::Util::ServerApplication
{
    protected:
        int main(const std::vector<std::string> &);
};

#endif // SERVER_H
