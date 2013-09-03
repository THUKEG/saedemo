#include "gflags/gflags.h"
#include "glog/logging.h"
#include "zrpc/zrpc.hpp"
#include "event.hpp"

DEFINE_int32(port, 40112, "server port");
DEFINE_int32(threads, 20, "server threads");

using namespace std;
using namespace zrpc;

int main(int argc, char** argv) {
    gflags::ParseCommandLineFlags(&argc, &argv, true);

    LOG(INFO) << "Demo Server Starting...";
    RpcServer* server = RpcServer::CreateServer(FLAGS_port, FLAGS_threads);

    LOG(INFO) << "Setting up services...";
    event::Trigger("init_service", nullptr, server);

    LOG(INFO) << "Trying to bringing our services up...";
    server->run();

    LOG(INFO) << "Exiting...";
    return 0;
}