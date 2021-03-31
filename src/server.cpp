#include "server.h"

#include <iostream>

#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Net/HTTPServer.h>
#include <Poco/Net/HTTPRequestHandlerFactory.h>
#include <Poco/Net/HTMLForm.h>
#include <Poco/StringTokenizer.h>
#include <Poco/URI.h>


using namespace Poco;
using namespace Poco::Net;
using namespace Poco::Util;

class ServerAppHandler : public HTTPRequestHandler
{
public:
    void handleRequest(HTTPServerRequest &req, HTTPServerResponse &resp)
    {
        URI uri(req.getURI());
        std::string method = req.getMethod();

        std::cout << "URI: " << uri.toString() << std::endl;
        std::cout << "Method: " << req.getMethod() << std::endl;

        StringTokenizer tokenizer(uri.getPath(), "/", StringTokenizer::TOK_TRIM);
        HTMLForm form(req,req.stream());

        if(!method.compare("POST"))
        {
            std::cout << "POST" << std::endl;
        }
        else if(!method.compare("PUT"))
        {
            std::cout << "PUT" << std::endl;
        }
        else if(!method.compare("DELETE"))
        {
            std::cout << "DELETE" << std::endl;
        }

        resp.setStatus(HTTPResponse::HTTP_OK);
        resp.setContentType("application/json");
        std::ostream& out = resp.send();

        out << "{\"hello\":1}" << std::endl;

        out.flush();
    }
};

class RequestHandlerFactory : public HTTPRequestHandlerFactory
{
public:
    virtual HTTPRequestHandler* createRequestHandler(const HTTPServerRequest & request)
    {
        return new ServerAppHandler;
    }
};

int ServerApp::main(const std::vector<std::string> &)
{
    HTTPServerParams* pParams = new HTTPServerParams;

    pParams->setMaxQueued(100);
    pParams->setMaxThreads(16);

    HTTPServer s(new RequestHandlerFactory, ServerSocket(8000), pParams);

    s.start();
    std::cout << "Server started" << std::endl;

    waitForTerminationRequest();  // wait for CTRL-C or kill

    std::cout << "Shutting down..." << std::endl;
    s.stop();

    return Application::EXIT_OK;
}
