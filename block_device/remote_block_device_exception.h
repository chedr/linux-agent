#ifndef DATTO_CLIENT_BLOCK_DEVICE_REMOTE_BLOCK_DEVICE_EXCEPTION_H_
#define DATTO_CLIENT_BLOCK_DEVICE_REMOTE_BLOCK_DEVICE_EXCEPTION_H_

#include <stdexcept>

namespace datto_linux_client {
class RemoteBlockDeviceException : public std::runtime_error {
 public: 
  explicit RemoteBlockDeviceException(const std::string &a_what)
    : runtime_error(a_what) {};
};
}

#endif //  DATTO_CLIENT_BLOCK_DEVICE_REMOTE_BLOCK_DEVICE_EXCEPTION_H_
