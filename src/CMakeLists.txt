set(OTBGK-SVM_SRC
  otbChangeProfileKernelFunctor.cxx
  otbMixturePolyRBFKernelFunctor.cxx
  otbNonGaussianRBFKernelFunctor.cxx
  otbSpectralAngleKernelFunctor.cxx
  gksvm.cpp
  )

add_library(OTBGK-SVM ${OTBGK-SVM_SRC})
target_link_libraries(OTBGK-SVM 
  ${OTBGK-SVM_LIBRARIES}
  )

otb_module_target(OTBGK-SVM)
