// ======================================================================
// \title  WdBlockDriver.hpp
// \author ortega
// \brief  hpp file for WdBlockDriver component implementation class
// ======================================================================

#ifndef Components_WdBlockDriver_HPP
#define Components_WdBlockDriver_HPP

#include <wdLib.h>
#include "Components/WdBlockDriver/WdBlockDriverComponentAc.hpp"

namespace Components {

class WdBlockDriver : public WdBlockDriverComponentBase {
  public:
    // ----------------------------------------------------------------------
    // Component construction and destruction
    // ----------------------------------------------------------------------

    //! Construct WdBlockDriver object
    WdBlockDriver(const char* const compName  //!< The component name
    );

    //! Destroy WdBlockDriver object
    ~WdBlockDriver();

    // a little hack to get the reference running
    void callIsr(FwSizeType ticks);

    PRIVATE :
        // ----------------------------------------------------------------------
        // Handler implementations for typed input ports
        // ----------------------------------------------------------------------

        //! Handler implementation for BufferIn
        //!
        //! The input data buffer port
        void
        BufferIn_handler(FwIndexType portNum,   //!< The port number
                         Drv::DataBuffer& buff  //!< A data buffer
                         ) override;

    //! Handler implementation for PingIn
    //!
    //! Input ping port
    void PingIn_handler(FwIndexType portNum,  //!< The port number
                        U32 key               //!< Value to return to pinger
                        ) override;

    //! Handler implementation for Sched
    //!
    //! The rate group scheduler input
    void Sched_handler(FwIndexType portNum,  //!< The port number
                       U32 context           //!< The call order
                       ) override;

    PRIVATE :
        // ----------------------------------------------------------------------
        // Handler implementations for user-defined internal interfaces
        // ----------------------------------------------------------------------

        //! Handler implementation for InterruptReport
        //!
        //! Internal interrupt reporting interface
        void
        InterruptReport_internalInterfaceHandler(U32 interrupt  //!< The interrupt register value
                                                 ) override;

    // static ISR callback
    static void s_driverISR(void* arg);

    // ----------------------------------------------------------------------
    // Member variable
    // ----------------------------------------------------------------------
    WDOG_ID m_watchdogId = nullptr;
    U32 m_cycles = 0;
    FwSizeType m_tickDelay = 0;
};

}  // namespace Components

#endif
