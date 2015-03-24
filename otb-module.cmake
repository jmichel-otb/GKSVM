set(DOCUMENTATION "This module contains the deprecated patched libSVM version (adding generic kernels to libSVM), as well as the classes to use it.")

otb_module(OTBGKSVM
  DEPENDS
    OTBCommon
    OTBITK

  TEST_DEPENDS
    OTBImageBase
    OTBImageIO
    OTBSVMLearning
    OTBTestKernel

  DESCRIPTION
    "${DOCUMENTATION}"
)
