// ======================================================================
// \title  Main.cpp
// \brief main program for the F' application. Intended for VxWorks.
//
// ======================================================================
// Used to access topology functions
#include <ReferenceDeployment/Top/ReferenceDeploymentTopology.hpp>
// OSAL initialization
#include <Os/Os.hpp>

// \brief main entry point for the VxWorks reference
//  
// This function is the entry point that can be dynamically loaded or jumped to from the VxWorks operating system. It
// requires two arguments to be passed in: the hostname and the port number. These are used to connect to the reference
// to the fprime GDS.
// 
// This function willl setup the topology, run the simulated cycle, and then teardown the topology when the cycle ends.
// The OSAL layer is initialized at the beginning of the function.
//
// \param address: the ip address of the GDS
// \param port: the port number of the GDS
void fsw_main(char* address, U16 port) {
    Os::init();
    // Object for communicating state to the reference topology
    ReferenceDeployment::TopologyState inputs;
    inputs.hostname = address;
    inputs.port = port;

    // Setup, cycle, and teardown topology
    ReferenceDeployment::setupTopology(inputs);
    ReferenceDeployment::startSimulatedCycle(Fw::TimeInterval(1,0));  // Program loop cycling rate groups at 1Hz
    ReferenceDeployment::teardownTopology(inputs);
}

// Include a main function when building for Linux/MacOS
#ifndef TGT_OS_TYPE_VXWORKS
// Includes needed for only the main function (Linux/MacOS)
#include <cstdio>
#include <cstdlib>

// \brief main entry point for the Linux/MacOS build
//
// \warning this code will not run as the topology priorities are inverted for VxWorks. This is only for demonstration
//   and building purposes.
int main(int argc, char* argv[]) {
    // Check for correct number of arguments
    if (argc != 3) {
        printf("Usage: %s <address> <port>\n", argv[0]);
        return -1;
    }
    // Convert port number to integer
    U16 port = atoi(argv[2]);
    // Call the main function
    fsw_main(argv[1], port);
    return 0;
}
#endif

