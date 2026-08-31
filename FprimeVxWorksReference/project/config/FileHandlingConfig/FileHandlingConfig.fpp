module FileHandlingConfig {
    #Base ID for the FileHandling Subtopology, all components are offsets from this base ID
    constant BASE_ID = 0x05000000
    
    module QueueSizes {
        constant fileUplink    = 30
        constant fileDownlink  = 30
        constant fileManager   = 30
        constant prmDb         = 10
    }
    
    module StackSizes {
        constant fileUplink    = 64 * 1024
        constant fileDownlink  = 64 * 1024
        constant fileManager   = 64 * 1024
        constant prmDb         = 64 * 1024
    }

    module Priorities {
        constant fileUplink    = 59
        constant fileDownlink  = 57
        constant fileManager   = 58
        constant prmDb         = 62
    }

    module CpuAffinities {
        constant fileUplink    = Os.TASK_DEFAULT
        constant fileDownlink  = Os.TASK_DEFAULT
        constant fileManager   = Os.TASK_DEFAULT
        constant prmDb         = Os.TASK_DEFAULT
    }

    # File downlink configuration constants
    module DownlinkConfig {
        constant timeout        = 1000         # File downlink timeout in ms
        constant cooldown       = 1000         # File downlink cooldown in ms  
        constant cycleTime      = 1000         # File downlink cycle time in ms
        constant fileQueueDepth = 10           # File downlink queue depth
    }
}
