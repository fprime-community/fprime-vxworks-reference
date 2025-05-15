register_fprime_config(
    fprime-vxworks-reference-config
  CONFIGURATION_OVERRIDES
    "${CMAKE_CURRENT_LIST_DIR}/FpConfig.h"
    "${CMAKE_CURRENT_LIST_DIR}/VxWorksCfg.hpp"
  INTERFACE # No buildable files generated
)
