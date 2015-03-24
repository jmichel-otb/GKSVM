otb_module_test()

set(OTBGKSVMTests
otbGKSVMTestDriver.cxx
otbGKSVMModelCopyGenericKernelTest.cxx
otbGKSVMModelCopyTest.cxx
otbGKSVMModelGenericKernelLoadSave.cxx
otbGKSVMModelGenericKernelsTest.cxx
otbGKSVMModelCopyComposedKernelTest.cxx
)

add_executable(otbGKSVMTestDriver ${OTBGKSVMTests})
target_link_libraries(otbGKSVMTestDriver ${OTBGKSVM-Test_LIBRARIES})
otb_module_target_label(otbGKSVMTestDriver)

# Tests Declaration
otb_add_test(NAME leTvGKSVMModelCopyGenericKernel COMMAND otbGKSVMTestDriver
  --compare-ascii ${NOTOL}  ${INPUTDATA}/svm_model_generic
  ${TEMP}/svmcopygeneric_test
  otbGKSVMModelCopyGenericKernelTest
  ${INPUTDATA}/svm_model_generic
  ${TEMP}/svmcopygeneric_test)
 
otb_add_test(NAME leTvGKSVMModelWithGenericKeywordKernelLoadSave COMMAND otbGKSVMTestDriver
  --compare-ascii ${NOTOL}  ${BASELINE_FILES}/leTvsvmmodel_image_generic_version_test
  ${TEMP}/leTvsvmmodel_image_generic_version_test
  otbGKSVMModelGenericKernelLoadSave
  ${INPUTDATA}/svm_model_image_generic_version
  ${TEMP}/leTvsvmmodel_image_generic_version_test)

otb_add_test(NAME leTvGKSVMModelKernelTypeGenericLoadSave COMMAND otbGKSVMTestDriver
  --compare-ascii ${NOTOL}  ${INPUTDATA}/svm_model_image_generic_kernel
  ${TEMP}/leTvsvmmodel_image_generic_kernel_test
  otbGKSVMModelGenericKernelLoadSave
  ${INPUTDATA}/svm_model_image_generic_kernel
  ${TEMP}/leTvsvmmodel_image_generic_kernel_test)

otb_add_test(NAME leTvGKSVMModelGenericKernelsTest COMMAND otbGKSVMTestDriver
  --compare-n-ascii ${NOTOL} 17
  ${BASELINE_FILES}/leTvSVMModelGenericKernelsTest1.txt
  ${TEMP}/leTvSVMModelGenericKernelsTest1.txt
  ${BASELINE_FILES}/leTvSVMModelGenericKernelsTest2.txt
  ${TEMP}/leTvSVMModelGenericKernelsTest2.txt
  ${BASELINE_FILES}/leTvSVMModelGenericKernelsTest3.txt
  ${TEMP}/leTvSVMModelGenericKernelsTest3.txt
  ${BASELINE_FILES}/leTvSVMModelGenericKernelsTest4.txt
  ${TEMP}/leTvSVMModelGenericKernelsTest4.txt
  ${BASELINE_FILES}/leTvSVMModelGenericKernelsTest5.txt
  ${TEMP}/leTvSVMModelGenericKernelsTest5.txt
  ${BASELINE_FILES}/leTvSVMModelGenericKernelsTest6.txt
  ${TEMP}/leTvSVMModelGenericKernelsTest6.txt
  ${BASELINE_FILES}/leTvSVMModelGenericKernelsTest7.txt
  ${TEMP}/leTvSVMModelGenericKernelsTest7.txt
  ${BASELINE_FILES}/leTvSVMModelGenericKernelsTest8.txt
  ${TEMP}/leTvSVMModelGenericKernelsTest8.txt
  ${BASELINE_FILES}/leTvSVMModelGenericKernelsTest9.txt
  ${TEMP}/leTvSVMModelGenericKernelsTest9.txt
  ${BASELINE_FILES}/leTvSVMModelGenericKernelsTest10.txt
  ${TEMP}/leTvSVMModelGenericKernelsTest10.txt
  ${BASELINE_FILES}/leTvSVMModelGenericKernelsTest11.txt
  ${TEMP}/leTvSVMModelGenericKernelsTest11.txt
  ${BASELINE_FILES}/leTvSVMModelGenericKernelsTest12.txt
  ${TEMP}/leTvSVMModelGenericKernelsTest12.txt
  ${BASELINE_FILES}/leTvSVMModelGenericKernelsTest13.txt
  ${TEMP}/leTvSVMModelGenericKernelsTest13.txt
  ${BASELINE_FILES}/leTvSVMModelGenericKernelsTest14.txt
  ${TEMP}/leTvSVMModelGenericKernelsTest14.txt
  ${BASELINE_FILES}/leTvSVMModelGenericKernelsTest15.txt
  ${TEMP}/leTvSVMModelGenericKernelsTest15.txt
  ${BASELINE_FILES}/leTvSVMModelGenericKernelsTest16.txt
  ${TEMP}/leTvSVMModelGenericKernelsTest16.txt
  ${BASELINE_FILES}/leTvSVMModelGenericKernelsTest17.txt
  ${TEMP}/leTvSVMModelGenericKernelsTest17.txt
  otbGKSVMModelGenericKernelsTest
  ${TEMP}/leTvSVMModelGenericKernelsTest1.txt
  ${TEMP}/leTvSVMModelGenericKernelsTest2.txt
  ${TEMP}/leTvSVMModelGenericKernelsTest3.txt
  ${TEMP}/leTvSVMModelGenericKernelsTest4.txt
  ${TEMP}/leTvSVMModelGenericKernelsTest5.txt
  ${TEMP}/leTvSVMModelGenericKernelsTest6.txt
  ${TEMP}/leTvSVMModelGenericKernelsTest7.txt
  ${TEMP}/leTvSVMModelGenericKernelsTest8.txt
  ${TEMP}/leTvSVMModelGenericKernelsTest9.txt
  ${TEMP}/leTvSVMModelGenericKernelsTest10.txt
  ${TEMP}/leTvSVMModelGenericKernelsTest11.txt
  ${TEMP}/leTvSVMModelGenericKernelsTest12.txt
  ${TEMP}/leTvSVMModelGenericKernelsTest13.txt
  ${TEMP}/leTvSVMModelGenericKernelsTest14.txt
  ${TEMP}/leTvSVMModelGenericKernelsTest15.txt
  ${TEMP}/leTvSVMModelGenericKernelsTest16.txt
  ${TEMP}/leTvSVMModelGenericKernelsTest17.txt
  )

otb_add_test(NAME leTvGKSVMModelCopyComposedKernel COMMAND otbGKSVMTestDriver
  --compare-ascii ${NOTOL}  ${INPUTDATA}/svm_model_composed
  ${TEMP}/svmcopycomposed_test
  otbGKSVMModelCopyComposedKernelTest
  ${INPUTDATA}/svm_model_composed
  ${TEMP}/svmcopycomposed_test)

