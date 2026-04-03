#include "Header.h"

#include <iostream>
#include <vector>
#include <string_view>
#include <string>

Header::Header(std::string raw): raw(std::move(raw)) { }

void Header::parse()
{
    size_t curr = 0;
    size_t line_end, colon;
    std::string_view vraw = raw;

    while ((line_end = vraw.find("\r\n", curr)) != std::string_view::npos &&
            (colon = vraw.find(":", curr)) != std::string_view::npos)
    {
        HeaderPos pos;
        pos.key_start = curr;
        pos.key_len = colon - curr;
        pos.val_start = curr + pos.key_len + 2;
        pos.val_len = line_end - pos.val_start;

        headers.push_back(pos);

        curr = line_end + 2;
    }
}

std::span<const HeaderPos> Header::get_headers_pos() { return headers; }