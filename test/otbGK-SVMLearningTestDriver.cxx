#include "otbTestMain.h"
void RegisterTests()
{
  REGISTER_TEST(otbGKSVMModelCopyGenericKernelTest);
  REGISTER_TEST(otbGKSVMModelCopyTest);
  REGISTER_TEST(otbGKSVMModelGenericKernelLoadSave);
  REGISTER_TEST(otbGKSVMModelGenericKernelsTest);
  REGISTER_TEST(otbSVMKernelsTest);
  REGISTER_TEST(otbSVMInverseCosSpectralAngleKernelFunctorImageModelEstimatorTest);
  REGISTER_TEST(otbSVMInverseCosSpectralAngleKernelFunctorImageClassificationTest);
  REGISTER_TEST(otbGKSVMModelCopyComposedKernelTest);
}
