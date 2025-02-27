// ======================================================================
// \title  WdBlockDriver.cpp
// \author ortega
// \brief  cpp file for WdBlockDriver component implementation class
// ======================================================================

#include "Components/WdBlockDriver/WdBlockDriver.hpp"

namespace Components {

// ----------------------------------------------------------------------
// Component construction and destruction
// ----------------------------------------------------------------------

WdBlockDriver ::WdBlockDriver(const char* const compName) : WdBlockDriverComponentBase(compName) {
    m_watchdogId = wdCreate();
}

WdBlockDriver ::~WdBlockDriver() {}

void WdBlockDriver::callIsr() {
    s_driverISR(this);
}

void WdBlockDriver::s_driverISR(void* arg) {
    FW_ASSERT(arg);
    // cast argument to component instance
    WdBlockDriver* compPtr = static_cast<WdBlockDriver*>(arg);
    compPtr->InterruptReport_internalInterfaceInvoke(0);
    FW_ASSERT(compPtr->m_watchdogId != nullptr);
    STATUS status = wdStart(compPtr->m_watchdogId, 60, reinterpret_cast<FUNCPTR>(s_driverISR),
                            reinterpret_cast<_Vx_usr_arg_t>(compPtr));
    FW_ASSERT(status == VXWORKS_OK);
}
// ----------------------------------------------------------------------
// Handler implementations for typed input ports
// ----------------------------------------------------------------------

void WdBlockDriver ::BufferIn_handler(FwIndexType portNum, Drv::DataBuffer& buff) {
    // just a pass-through
    this->BufferOut_out(0, buff);
}

void WdBlockDriver ::PingIn_handler(FwIndexType portNum, U32 key) {
    // call ping output port
    this->PingOut_out(0, key);
}

void WdBlockDriver ::Sched_handler(FwIndexType portNum, U32 context) {}

// ----------------------------------------------------------------------
// Handler implementations for user-defined internal interfaces
// ----------------------------------------------------------------------

void WdBlockDriver ::InterruptReport_internalInterfaceHandler(U32 interrupt) {
    // get time
    Os::RawTime time;
    time.now();
    // call output timing signal
    this->CycleOut_out(0, time);
    // increment cycles and write channel
    this->tlmWrite_BD_Cycles(this->m_cycles);
    this->m_cycles++;
}

}  // namespace Components
