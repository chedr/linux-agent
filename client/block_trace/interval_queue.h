#ifndef DATTO_CLIENT_BLOCK_TRACER_INTERVAL_QUEUE_H_
#define DATTO_CLIENT_BLOCK_TRACER_INTERVAL_QUEUE_H_

#include <boost/icl/interval.hpp>

namespace datto_linux_client {

// Each item in this interval is a *sector* not a block
typedef boost::icl::interval<uint64_t> TraceInterval;

}

#endif //  DATTO_CLIENT_BLOCK_TRACER_INTERVAL_QUEUE_H_