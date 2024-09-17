#pragma once
#include <asio.hpp>

namespace echo_server{
    class Session: public std::enable_shared_from_this<Session>{
    public:
        Session(asio::ip::tcp::socket socket) : socket_(std::move(socket)) {}

        void start();
    private:
        void do_read();
        void do_write(std::size_t length);

        asio::ip::tcp::socket socket_;
        enum {max_length = 1024};
        char data_[max_length];
    };
}