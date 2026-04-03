#include <gtest/gtest.h>
#include "Header.h"

TEST(Header, HeaderParse)
{
    const std::string raw =
"Host: www.google.com\r\n\
User-Agent: Mozilla/5.0 (X11; Linux x86_64; rv:148.0) Gecko/20100101 Firefox/148.0\r\n\
Accept: */*\r\n\
Accept-Language: en-US,en;q=0.9\r\n\
Accept-Encoding: gzip, deflate, br, zstd\r\n\
Sec-Fetch-Storage-Access: none\r\n\
Connection: keep-alive\r\n\
Referer: https://learncpp.com/\r\n\
Sec-Fetch-Dest: script\r\n\
Sec-Fetch-Mode: no-cors\r\n\
Sec-Fetch-Site: cross-site\r\n\r\n";

    Header h{raw};
    h.parse();
    std::vector<HeaderPos> headers = h.get_headers_pos();
    std::vector<HeaderPos> expected = {
        {0, 4, 6, 14},
        {22, 10, 34, 70},
        {106, 6, 114, 3},
        {119, 15, 136, 14},
        {152, 15, 169, 23},
        {194, 24, 220, 4},
        {226, 10, 238, 10},
        {250, 7, 259, 21},
        {282, 14, 298, 6},
        {306, 14, 322, 7},
        {331, 14, 347, 10}
    };

    ASSERT_EQ(headers.size(), expected.size());
    ASSERT_EQ(headers, expected);
}