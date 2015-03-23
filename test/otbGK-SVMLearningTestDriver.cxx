#include "otbTestMain.h"
void RegisterTests()
{
  REGISTER_TEST(otbSVMModelCopyGenericKernelTest);
  REGISTER_TEST(otbSVMModelCopyTest);
  REGISTER_TEST(otbSVMModelGenericKernelLoadSave);
  REGISTER_TEST(otbSVMModelGenericKernelsTest);
  REGISTER_TEST(otbSVMKernelsTest);
  REGISTER_TEST(otbSVMInverseCosSpectralAngleKernelFunctorImageModelEstimatorTest);
  REGISTER_TEST(otbSVMInverseCosSpectralAngleKernelFunctorImageClassificationTest);
  REGISTER_TEST(otbSVMModelCopyComposedKernelTest);
}
