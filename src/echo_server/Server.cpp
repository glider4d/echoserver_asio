#include "Server.h"
#include "Session.h"
#include <memory>

using asio::ip::tcp;


echo_server::Server::Server(asio::io_context& io_context, short port) :
    acceptor_(io_context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port))
{
    do_accept();    
}

void echo_server::Server::do_accept() {
    acceptor_.async_accept(
        [this](std::error_code ec, tcp::socket socket){
            if(!ec){
                std::make_shared<echo_server::Session>(std::move(socket))->start();
            }
            do_accept();
        
        });
}


