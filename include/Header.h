#pragma once

#include <string_view>
#include <string>
#include <vector>

struct HeaderPos 
{
    size_t key_start, key_len;
    size_t val_start, val_len;
};

class Header
{
    private:
    const std::string raw;
    std::vector<HeaderPos> headers;

    public:
    Header(std::string raw);
    void parse();
    std::vector<HeaderPos> get_headers_pos();
};