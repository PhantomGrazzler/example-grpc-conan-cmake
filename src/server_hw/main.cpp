#include <grpcpp/grpcpp.h>
#include <helloworld.grpc.pb.h>

class GreeterServiceImpl final : public helloworld::Greeter::Service
{
    grpc::Status SayHello(
        grpc::ServerContext*,
        const helloworld::HelloRequest* request,
        helloworld::HelloReply* reply ) override
    {
        const std::string prefix( "Hello " );
        reply->set_message( prefix + request->name() );
        return grpc::Status::OK;
    }
};

void RunServer()
{
    const std::string server_address( "0.0.0.0:50051" );
    GreeterServiceImpl service;

    grpc::EnableDefaultHealthCheckService( true );
    //grpc::reflection::InitProtoReflectionServerBuilderPlugin();
    grpc::ServerBuilder builder;
    // Listen on the given address without any authentication mechanism.
    builder.AddListeningPort( server_address, grpc::InsecureServerCredentials() );
    // Register "service" as the instance through which we'll communicate with
    // clients. In this case it corresponds to a *synchronous* service.
    builder.RegisterService( &service );
    // Finally assemble the server.
    std::unique_ptr<grpc::Server> server( builder.BuildAndStart() );
    std::cout << "Server listening on " << server_address << std::endl;

    // Wait for the server to shutdown. Note that some other thread must be
    // responsible for shutting down the server for this call to ever return.
    server->Wait();
}

int main()
{
    RunServer();

    return 0;
}
