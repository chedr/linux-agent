#ifndef DATTO_CLIENT_BACKUP_BACKUP_H_
#define DATTO_CLIENT_BACKUP_BACKUP_H_

#include <memory>
#include <vector>

#include "backup/backup_coordinator.h"
#include "backup_status_tracker/backup_event_handler.h"
#include "device_synchronizer/device_synchronizer_interface.h"

namespace datto_linux_client {

class Backup {
 public:
  explicit Backup(
      std::vector<std::shared_ptr<DeviceSynchronizerInterface>> syncs_to_do,
      std::shared_ptr<BackupCoordinator> coordinator);

  // This blocks until the backup is done. This won't throw an exception.
  virtual void DoBackup(std::shared_ptr<BackupEventHandler> event_handler);

  virtual ~Backup();

  Backup(const Backup &) = delete;
  Backup& operator=(const Backup &) = delete;

 protected:
  // For unit testing
  Backup() {}
 private:
  std::vector<std::shared_ptr<DeviceSynchronizerInterface>> syncs_to_do_;
  std::shared_ptr<BackupCoordinator> coordinator_;
};

} // datto_linux_client

#endif  // DATTO_CLIENT_BACKUP_BACKUP_H_
