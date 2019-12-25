#include <iostream>
#include <list>
#include <zmq.hpp>
#include <sstream>

#include "codegenerator.h"
#include "runner.h"
#include "blockparser.h"
#include "testparser.h"

using namespace std;

int main()
{
    //TODO удаление всех блоков
//    auto functions = parser.read_file("example.json");
    zmq::context_t context (1);
    zmq::socket_t socket (context, ZMQ_REP);
    socket.bind ("tcp://127.0.0.1:5555");

    BlockParser parser;
    TestParser test_parser;
    CodeGenerator code;
    Runner runner;
    auto tests = test_parser.from_file("test_example.json");
    while (true) {
        zmq::message_t request;

        //  Wait for next request from client
        socket.recv (&request);
//        std::cout << "Received: " << std::string(static_cast<const char *>(request.data()), request.size()) << std::endl;
        std::string s = std::string(static_cast<const char *>(request.data()), request.size());
        std::cout << s;
        auto functions = parser.parse_json(nlohmann::json::parse(s));
        //  Do some 'work'
        cout << code.get_prog(functions) << endl;
        auto res = runner.run(code.get_prog(functions), tests);
        std::string rep_s;
        std::stringstream ss(rep_s);
        for(const auto & i : res){
            ss << i << " ";
        }
        rep_s = ss.str();
        std::cout << rep_s << std::endl;
        //  Send reply back to client
        zmq::message_t reply (rep_s.size());
        memcpy (reply.data (), rep_s.data(), rep_s.size());
        socket.send (reply);
    }
    return 0;

    return 0;
}
