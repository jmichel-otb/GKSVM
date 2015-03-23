# Build patched libSVM
add_library(otblibgksvm gksvm.cpp)

# Build OTB library

set(OTBGK-SVM_SRC
  otbChangeProfileKernelFunctor.cxx
  otbMixturePolyRBFKernelFunctor.cxx
  otbNonGaussianRBFKernelFunctor.cxx
  otbSpectralAngleKernelFunctor.cxx
  )

add_library(OTBGK-SVM ${OTBGK-SVM_SRC})
target_link_libraries(OTBGK-SVM 
  ${OTBGK-SVM_LIBRARIES}
  )

otb_module_target(OTBGK-SVM)

set(OTB3P_INSTALL_EXPORT_NAME "${OTBGK-SVM-targets}")
set(OTB3P_INSTALL_INCLUDE_DIR "${OTBGK-SVM_INSTALL_INCLUDE_DIR}")
set(OTB3P_INSTALL_RUNTIME_DIR "${OTBGK-SVM_INSTALL_RUNTIME_DIR}")
set(OTB3P_INSTALL_LIBRARY_DIR "${OTBGK-SVM_INSTALL_LIBRARY_DIR}")
set(OTB3P_INSTALL_ARCHIVE_DIR "${OTBGK-SVM_INSTALL_ARCHIVE_DIR}")

if(OTB_LIBRARY_PROPERTIES)
  set_target_properties(otblibgksvm PROPERTIES ${OTB_LIBRARY_PROPERTIES})
endif(OTB_LIBRARY_PROPERTIES)

install(TARGETS otblibgksvm
  EXPORT ${OTB3P_INSTALL_EXPORT_NAME}
  RUNTIME DESTINATION ${OTB3P_INSTALL_RUNTIME_DIR} COMPONENT RuntimeLibraries
  LIBRARY DESTINATION ${OTB3P_INSTALL_LIBRARY_DIR} COMPONENT RuntimeLibraries
  ARCHIVE DESTINATION ${OTB3P_INSTALL_ARCHIVE_DIR} COMPONENT Development
  )

otb_module_target( otblibgksvm NO_INSTALL)
