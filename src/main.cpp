#include <asio.hpp>
#include <iostream>
#include "Server.h"

int main(int argc, char* argv[]) {
    try {
        if (argc != 2) {
            std::cerr << "Usage: echo_server <port>\n";
            return 1;
        }

        asio::io_context io_context;
        echo_server::Server s(io_context, std::atoi(argv[1]));
        io_context.run();
        std::cout<<"after run"<<std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n"; 
    }

    return 0;
}
