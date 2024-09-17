#pragma once
#include <asio.hpp>

namespace echo_server{
    class Server {
    public:
        Server(asio::io_context& io_context, short port);
            
    private:
        void do_accept();
        asio::ip::tcp::acceptor acceptor_;
    };
}