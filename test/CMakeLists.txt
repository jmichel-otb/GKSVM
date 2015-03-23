otb_module_test()

set(OTBGK-SVMTests
otbGK-SVMTestDriver.cxx
otbSVMModelCopyGenericKernelTest.cxx
otbSVMModelCopyTest.cxx
otbSVMModelGenericKernelLoadSave.cxx
otbSVMModelGenericKernelsTest.cxx
otbSVMInverseCosSpectralAngleKernelFunctorImageModelEstimatorTest.cxx
otbSVMInverseCosSpectralAngleKernelFunctorImageClassificationTest.cxx
otbSVMModelCopyComposedKernelTest.cxx
)

add_executable(otbGK-SVMTestDriver ${OTBGK-SVMTests})
target_link_libraries(otbGK-SVMTestDriver ${OTBGK-SVM-Test_LIBRARIES})
otb_module_target_label(otbGK-SVMTestDriver)

# Tests Declaration
otb_add_test(NAME leTvSVMModelCopyGenericKernel COMMAND otbGK-SVMTestDriver
  --compare-ascii ${NOTOL}  ${INPUTDATA}/svm_model_generic
  ${TEMP}/svmcopygeneric_test
  otbSVMModelCopyGenericKernelTest
  ${INPUTDATA}/svm_model_generic
  ${TEMP}/svmcopygeneric_test)

  
foreach(kernelType RANGE 0 18)
  otb_add_test(NAME leTvSVMKernelTest${kernelType} COMMAND otbGK-SVMTestDriver
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

otb_add_test(NAME leTvSVMModelWithGenericKeywordKernelLoadSave COMMAND otbGK-SVMTestDriver
  --compare-ascii ${NOTOL}  ${BASELINE_FILES}/leTvsvmmodel_image_generic_version_test
  ${TEMP}/leTvsvmmodel_image_generic_version_test
  otbSVMModelGenericKernelLoadSave
  ${INPUTDATA}/svm_model_image_generic_version
  ${TEMP}/leTvsvmmodel_image_generic_version_test)

otb_add_test(NAME leTvSVMModelKernelTypeGenericLoadSave COMMAND otbGK-SVMTestDriver
  --compare-ascii ${NOTOL}  ${INPUTDATA}/svm_model_image_generic_kernel
  ${TEMP}/leTvsvmmodel_image_generic_kernel_test
  otbSVMModelGenericKernelLoadSave
  ${INPUTDATA}/svm_model_image_generic_kernel
  ${TEMP}/leTvsvmmodel_image_generic_kernel_test)

otb_add_test(NAME leTvSVMModelGenericKernelsTest COMMAND otbGK-SVMTestDriver
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
  otbSVMModelGenericKernelsTest
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

otb_add_test(NAME leTvSVMClassifierImageWithGenericKernalLinear COMMAND otbGK-SVMTestDriver
  --compare-image ${NOTOL}  ${BASELINE}/leTvSVMClassifierImageWithGenericKernalLinearOutput.png
  ${TEMP}/leTvSVMClassifierImageWithGenericKernalLinearOutput.png
  otbSVMClassifierImage
  ${INPUTDATA}/ROI_QB_MUL_4.tif
  ${INPUTDATA}/svm_model_image_generic_linear
  ${TEMP}/leTvSVMClassifierImageWithGenericKernalLinearOutput.png)


otb_add_test(NAME leTvSVMInverseCosSpectralAngleKernelFunctorImageModelEstimatorTest COMMAND otbGK-SVMTestDriver
  otbSVMInverseCosSpectralAngleKernelFunctorImageModelEstimatorTest
  ${INPUTDATA}/ROI_QB_MUL_4.tif
  ${INPUTDATA}/ROI_QB_MUL_4_train_one_class.tif
  ${TEMP}/leTvsvm_model_image_one_class)

otb_add_test(NAME leTvSVMInverseCosSpectralAngleKernelFunctorImageClassificationTest COMMAND otbGK-SVMTestDriver
  otbSVMInverseCosSpectralAngleKernelFunctorImageClassificationTest
  ${INPUTDATA}/ROI_QB_MUL_4.tif
  ${INPUTDATA}/ROI_QB_MUL_4_train_one_class.tif
  ${TEMP}/leTvsvm_model_image_one_class)


otb_add_test(NAME leTvSVMModelCopyComposedKernel COMMAND otbGK-SVMTestDriver
  --compare-ascii ${NOTOL}  ${INPUTDATA}/svm_model_composed
  ${TEMP}/svmcopycomposed_test
  otbSVMModelCopyComposedKernelTest
  ${INPUTDATA}/svm_model_composed
  ${TEMP}/svmcopycomposed_test)

