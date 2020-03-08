#include <grpcpp/grpcpp.h>
#include <helloworld.grpc.pb.h>

#include <iostream>

int main()
{
    const auto channel = grpc::CreateChannel( "localhost:50051", grpc::InsecureChannelCredentials() );
    const auto stub = helloworld::Greeter::NewStub( channel );
    grpc::ClientContext context;
    helloworld::HelloRequest request;
    request.set_name( "client_hw" );
    helloworld::HelloReply reply;
    grpc::Status status = stub->SayHello( &context, request, &reply );

    if ( status.ok() )
    {
        std::cout << "Status was ok: " << reply.message() << '\n';
    }
    else
    {
        std::cout << "Status was not ok: " << status.error_message() << '\n';
    }

    return 0;
}
