#ifndef DATTO_CLIENT_BLOCK_DEVICE_BLOCK_DEVICE_EXCEPTION_H_
#define DATTO_CLIENT_BLOCK_DEVICE_BLOCK_DEVICE_EXCEPTION_H_

#include <stdexcept>

namespace datto_linux_client {
class BlockDeviceException : public std::runtime_error {
 public: 
  explicit BlockDeviceException(std::string &what) : runtime_error(what) {};
};
}

#endif //  DATTO_CLIENT_BLOCK_DEVICE_BLOCK_DEVICE_EXCEPTION_H_
