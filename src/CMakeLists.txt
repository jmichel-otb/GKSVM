set(OTBGKSVM_SRC
  otbChangeProfileKernelFunctor.cxx
  otbMixturePolyRBFKernelFunctor.cxx
  otbNonGaussianRBFKernelFunctor.cxx
  otbSpectralAngleKernelFunctor.cxx
  gksvm.cpp
  )

add_library(OTBGKSVM ${OTBGKSVM_SRC})
target_link_libraries(OTBGKSVM
  ${OTBCommon_LIBRARIES}
  )

otb_module_target(OTBGKSVM)
