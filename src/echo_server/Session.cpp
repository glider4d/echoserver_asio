#include "Session.h"
#include <iostream>

using asio::ip::tcp;

void echo_server::Session::start(){
    do_read();
}

void echo_server::Session::do_read(){
    auto self(shared_from_this());

    socket_.async_read_some(asio::buffer(data_, max_length),
        [this, self](std::error_code ec, std::size_t length){
            if(!ec){
                do_write(length);
            } 
        });
}

void echo_server::Session::do_write(std::size_t length){
        auto self(shared_from_this());
        asio::async_write(socket_, asio::buffer(data_, length),
            [this, self](std::error_code ec, std::size_t /*length*/) {
                if (!ec) {
                    socket_.shutdown(tcp::socket::shutdown_both, ec);
                    //  do_read();
                } 
            });
}