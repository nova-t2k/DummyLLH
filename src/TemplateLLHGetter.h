#ifndef TEMPLATELLHGETTER_H
#define TEMPLATELLHGETTER_H

#include <vector>

enum CovTypes {//We should expand this to have all the T2K and NOvA classes
  kOsc=0,
  kSKdet=1,
  kBANFF=2,
  kXsec=3,
  kND280det=4,
  kNOvAdet=5,
  nCovTypes
};

class OscPars{
 public:
  double dm32,dm21,sth13,sth12,sth23,dcp;
};

class TemplateLLHGetter {
 public:
  TemplateLLHGetter(){};
  virtual ~TemplateLLHGetter() = default;

  virtual void init()=0;//Some sort of call once init fuction
  virtual void SetParameters(CovTypes iCov, std::vector<double> vals)=0;//Set systematic parameters
  virtual void SetOscParameters(OscPars oscpars)=0;//Set oscillation parameters

  virtual void SetDataToAsimov()=0; //Use the current osc/systs to set the asimov fake data
  virtual void SetDataToPoissonStatFluctuations()=0;//As asimov, plus fluctuations
  virtual void ResetToDataFile()=0;
  virtual void ForceDummyLikelihood()=0; //force to set parameters for fake data

  virtual double GetLikelihood()=0;//Get likelihood

};

#endif
