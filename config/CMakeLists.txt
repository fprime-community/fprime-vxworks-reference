register_fprime_config(
    fprime-vxworks-reference-config
  CONFIGURATION_OVERRIDES
    "${CMAKE_CURRENT_LIST_DIR}/CdhCoreConfig/CdhCoreConfig.fpp"
    "${CMAKE_CURRENT_LIST_DIR}/ComCcsdsConfig/ComCcsdsConfig.fpp"
    "${CMAKE_CURRENT_LIST_DIR}/ComFprimeConfig/ComFprimeConfig.fpp"
    "${CMAKE_CURRENT_LIST_DIR}/DataProductsConfig/DataProductsConfig.fpp"
    "${CMAKE_CURRENT_LIST_DIR}/FileHandlingConfig/FileHandlingConfig.fpp"
    "${CMAKE_CURRENT_LIST_DIR}/FpConfig.h"
    "${CMAKE_CURRENT_LIST_DIR}/VxWorksCfg.hpp"
  INTERFACE # No buildable files generated
)
