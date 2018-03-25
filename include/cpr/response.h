#ifndef CPR_RESPONSE_H
#define CPR_RESPONSE_H

#include <cstdint>
#include <string>

#include "cpr/cookies.h"
#include "cpr/cprtypes.h"
#include "cpr/defines.h"
#include "cpr/error.h"

namespace cpr {

class Response {
  public:
    Response() = default;

    template <typename TextType, typename HeaderType, typename UrlType, typename CookiesType,
              typename ErrorType>
    Response(const std::int32_t& p_status_code, TextType&& p_text, HeaderType&& p_header, UrlType&& p_url,
             const double& p_elapsed, const double& p_connect_time, const double& p_speed, const double& p_size, 
             CookiesType&& p_cookies = Cookies{},
             ErrorType&& p_error = Error{})
            : status_code{p_status_code}, text{CPR_FWD(p_text)}, header{CPR_FWD(p_header)},
              url{CPR_FWD(p_url)}, elapsed{p_elapsed}, connect_time{p_connect_time}, speed{p_speed}, size{p_size},
              cookies{CPR_FWD(p_cookies)}, error{CPR_FWD(p_error)} {}

    std::int32_t status_code;
    std::string text;
    Header header;
    Url url;
    double elapsed;
    double connect_time;
    double speed;
    double size;
    Cookies cookies;
    Error error;
};

} // namespace cpr

#endif
