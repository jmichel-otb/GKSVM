otb_module_test()

set(OTBGKSVMTests
otbGKSVMTestDriver.cxx
otbGKSVMModelCopyGenericKernelTest.cxx
otbGKSVMModelCopyTest.cxx
otbGKSVMModelGenericKernelLoadSave.cxx
otbGKSVMModelGenericKernelsTest.cxx
otbSVMInverseCosSpectralAngleKernelFunctorImageModelEstimatorTest.cxx
otbSVMInverseCosSpectralAngleKernelFunctorImageClassificationTest.cxx
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

  
foreach(kernelType RANGE 0 18)
  otb_add_test(NAME leTvSVMKernelTest${kernelType} COMMAND otbGKSVMTestDriver
    --compare-ascii ${EPSILON_9}
      ${BASELINE_FILES}/leTvSVMKernelTest${kernelType}.txt
      ${TEMP}/leTvSVMKernelTest${kernelType}.txt
    otbSVMKernelsTest
      ${EXAMPLEDATA}/qb_RoadExtract.tif
      ${EXAMPLEDATA}/qb_RoadExtract_easyClassification.shp
      ${TEMP}/leTvSVMKernelTest${kernelType}.txt
      ${kernelType}
  )
endforeach()

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
  ${BASELINE_FILES}/leTvGKSVMModelGenericKernelsTest1.txt
  ${TEMP}/leTvGKSVMModelGenericKernelsTest1.txt
  ${BASELINE_FILES}/leTvGKSVMModelGenericKernelsTest2.txt
  ${TEMP}/leTvGKSVMModelGenericKernelsTest2.txt
  ${BASELINE_FILES}/leTvGKSVMModelGenericKernelsTest3.txt
  ${TEMP}/leTvGKSVMModelGenericKernelsTest3.txt
  ${BASELINE_FILES}/leTvGKSVMModelGenericKernelsTest4.txt
  ${TEMP}/leTvGKSVMModelGenericKernelsTest4.txt
  ${BASELINE_FILES}/leTvGKSVMModelGenericKernelsTest5.txt
  ${TEMP}/leTvGKSVMModelGenericKernelsTest5.txt
  ${BASELINE_FILES}/leTvGKSVMModelGenericKernelsTest6.txt
  ${TEMP}/leTvGKSVMModelGenericKernelsTest6.txt
  ${BASELINE_FILES}/leTvGKSVMModelGenericKernelsTest7.txt
  ${TEMP}/leTvGKSVMModelGenericKernelsTest7.txt
  ${BASELINE_FILES}/leTvGKSVMModelGenericKernelsTest8.txt
  ${TEMP}/leTvGKSVMModelGenericKernelsTest8.txt
  ${BASELINE_FILES}/leTvGKSVMModelGenericKernelsTest9.txt
  ${TEMP}/leTvGKSVMModelGenericKernelsTest9.txt
  ${BASELINE_FILES}/leTvGKSVMModelGenericKernelsTest10.txt
  ${TEMP}/leTvGKSVMModelGenericKernelsTest10.txt
  ${BASELINE_FILES}/leTvGKSVMModelGenericKernelsTest11.txt
  ${TEMP}/leTvGKSVMModelGenericKernelsTest11.txt
  ${BASELINE_FILES}/leTvGKSVMModelGenericKernelsTest12.txt
  ${TEMP}/leTvGKSVMModelGenericKernelsTest12.txt
  ${BASELINE_FILES}/leTvGKSVMModelGenericKernelsTest13.txt
  ${TEMP}/leTvGKSVMModelGenericKernelsTest13.txt
  ${BASELINE_FILES}/leTvGKSVMModelGenericKernelsTest14.txt
  ${TEMP}/leTvGKSVMModelGenericKernelsTest14.txt
  ${BASELINE_FILES}/leTvGKSVMModelGenericKernelsTest15.txt
  ${TEMP}/leTvGKSVMModelGenericKernelsTest15.txt
  ${BASELINE_FILES}/leTvGKSVMModelGenericKernelsTest16.txt
  ${TEMP}/leTvGKSVMModelGenericKernelsTest16.txt
  ${BASELINE_FILES}/leTvGKSVMModelGenericKernelsTest17.txt
  ${TEMP}/leTvGKSVMModelGenericKernelsTest17.txt
  otbGKSVMModelGenericKernelsTest
  ${TEMP}/leTvGKSVMModelGenericKernelsTest1.txt
  ${TEMP}/leTvGKSVMModelGenericKernelsTest2.txt
  ${TEMP}/leTvGKSVMModelGenericKernelsTest3.txt
  ${TEMP}/leTvGKSVMModelGenericKernelsTest4.txt
  ${TEMP}/leTvGKSVMModelGenericKernelsTest5.txt
  ${TEMP}/leTvGKSVMModelGenericKernelsTest6.txt
  ${TEMP}/leTvGKSVMModelGenericKernelsTest7.txt
  ${TEMP}/leTvGKSVMModelGenericKernelsTest8.txt
  ${TEMP}/leTvGKSVMModelGenericKernelsTest9.txt
  ${TEMP}/leTvGKSVMModelGenericKernelsTest10.txt
  ${TEMP}/leTvGKSVMModelGenericKernelsTest11.txt
  ${TEMP}/leTvGKSVMModelGenericKernelsTest12.txt
  ${TEMP}/leTvGKSVMModelGenericKernelsTest13.txt
  ${TEMP}/leTvGKSVMModelGenericKernelsTest14.txt
  ${TEMP}/leTvGKSVMModelGenericKernelsTest15.txt
  ${TEMP}/leTvGKSVMModelGenericKernelsTest16.txt
  ${TEMP}/leTvGKSVMModelGenericKernelsTest17.txt
  )

otb_add_test(NAME leTvSVMClassifierImageWithGenericKernalLinear COMMAND otbGKSVMTestDriver
  --compare-image ${NOTOL}  ${BASELINE}/leTvSVMClassifierImageWithGenericKernalLinearOutput.png
  ${TEMP}/leTvSVMClassifierImageWithGenericKernalLinearOutput.png
  otbSVMClassifierImage
  ${INPUTDATA}/ROI_QB_MUL_4.tif
  ${INPUTDATA}/svm_model_image_generic_linear
  ${TEMP}/leTvSVMClassifierImageWithGenericKernalLinearOutput.png)


otb_add_test(NAME leTvSVMInverseCosSpectralAngleKernelFunctorImageModelEstimatorTest COMMAND otbGKSVMTestDriver
  otbSVMInverseCosSpectralAngleKernelFunctorImageModelEstimatorTest
  ${INPUTDATA}/ROI_QB_MUL_4.tif
  ${INPUTDATA}/ROI_QB_MUL_4_train_one_class.tif
  ${TEMP}/leTvsvm_model_image_one_class)

otb_add_test(NAME leTvSVMInverseCosSpectralAngleKernelFunctorImageClassificationTest COMMAND otbGKSVMTestDriver
  otbSVMInverseCosSpectralAngleKernelFunctorImageClassificationTest
  ${INPUTDATA}/ROI_QB_MUL_4.tif
  ${INPUTDATA}/ROI_QB_MUL_4_train_one_class.tif
  ${TEMP}/leTvsvm_model_image_one_class)


otb_add_test(NAME leTvGKSVMModelCopyComposedKernel COMMAND otbGKSVMTestDriver
  --compare-ascii ${NOTOL}  ${INPUTDATA}/svm_model_composed
  ${TEMP}/svmcopycomposed_test
  otbGKSVMModelCopyComposedKernelTest
  ${INPUTDATA}/svm_model_composed
  ${TEMP}/svmcopycomposed_test)

