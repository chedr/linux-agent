#ifndef DATTO_CLIENT_BLOCK_DEVICE_NBD_EXCEPTION_H_
#define DATTO_CLIENT_BLOCK_DEVICE_NBD_EXCEPTION_H_

#include <stdexcept>

namespace datto_linux_client {
class NbdException : public std::runtime_error {
 public: 
  explicit NbdException(const std::string &a_what)
    : runtime_error(a_what) { };
};
}

#endif //  DATTO_CLIENT_BLOCK_DEVICE_NBD_EXCEPTION_H_
