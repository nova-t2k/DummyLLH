#include "TemplateLLHGetter.h"

class ExampleExternalLLH : public TemplateLLHGetter {
 public:
  SpecificLLHGetter();
  ~SpecificLLHGetter();

  void init();
  void SetParameters(CovTypes iCov,std::vector<double> vals);
  void SetOscParameters(OscPars oscpars);
  double GetLikelihood();

 private:
  OscPars oscvals;
  
  OscPars trueoscvals;
  OscPars trueoscsigmas;
};
