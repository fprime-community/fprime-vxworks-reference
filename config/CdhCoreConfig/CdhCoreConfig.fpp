module CdhCoreConfig {
    #Base ID for the CdhCore Subtopology, all components are offsets from this base ID
    constant BASE_ID = 0x01000000
    
    module QueueSizes {
        constant cmdDisp     = 20
        constant events      = 10
        constant tlmSend     = 10
        constant $health     = 25
    }
    

    module StackSizes {
        constant cmdDisp     = 64 * 1024
        constant events      = 64 * 1024
        constant tlmSend     = 64 * 1024
    }

    module Priorities {
        constant cmdDisp     = 54
        constant $health     = 154
        constant events      = 60
        constant tlmSend     = 61

    }
}
