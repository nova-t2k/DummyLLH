#include "TemplateLLHGetter.h"

class ExampleExternalLLH : public TemplateLLHGetter {
 public:
  ExampleExternalLLH();
  ~ExampleExternalLLH();

  void init();
  void SetParameters(CovTypes iCov,std::vector<double> vals);
  void SetOscParameters(OscPars oscpars);
  double GetLikelihood();

 private:
  OscPars oscvals;
  
  OscPars trueoscvals;
  OscPars trueoscsigmas;
};
