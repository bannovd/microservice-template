#include "server.h"
#include "check.h"


int main(int argc, char** argv)
{
    Check::testDB();

    ServerApp srv;

    return srv.run(argc, argv);
}
