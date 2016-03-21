#include <iostream>

#include <thrift/server/TThreadedServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TTransportUtils.h>

#include <boost/make_shared.hpp>
#include "./models/gen-cpp/Greeter.h"

using namespace hello;
using namespace std;
using namespace apache::thrift::server;
using namespace apache::thrift::transport;

class GreeterHandler : public GreeterIf {
public:
    GreeterHandler() {}
    void greet(std::string& _return, const Human& h) {
        std::cout << "incoming rpc" << std::endl;
        std::cout << "Human: " << h.name << ", age: " << h.age << std::endl;

        _return = "Hello, " + h.name;
    }
};

class GreeterCloneFactory : virtual public GreeterIfFactory {
public:
    virtual ~GreeterCloneFactory(){}
    virtual GreeterIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) {
        return new GreeterHandler;
    }
    virtual void releaseHandler(GreeterIf* handler) {
        delete handler;
    }
};

int main() {
    cout << "Hello, World!" << endl;

    TThreadedServer server(
            boost::make_shared<GreeterProcessorFactory>(boost::make_shared<GreeterCloneFactory>()),
            boost::make_shared<TServerSocket>(9090),
            boost::make_shared<TBufferedTransportFactory>(),
            boost::make_shared<TBinaryProtocolFactory>()
    );
    server.serve();
    cout << "Done." << endl;

    return 0;
}