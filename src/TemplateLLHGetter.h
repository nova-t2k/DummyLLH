#include <vector>

enum CovTypes {//We should expand this to have all the T2K and NOvA classes
  kOsc=0,
  kSKdet=1,
  kBANFF=2,
  kXsec=3,
  kND280det=4,
  kNOvAdet=5,
};

class OscPars{
 public:
  double dm32,dm21,sth13,sth12,sth23,dcp;
};

class TemplateLLHGetter {
 public:
  TemplateLLHGetter(){};
  ~TemplateLLHGetter(){};

  virtual void init()=0;//Some sort of call once init fuction
  virtual void SetParameters(CovTypes iCov, std::vector<double> vals)=0;//Set systematic parameters
  virtual void SetOscParameters(OscPars oscpars)=0;//Set oscillation parameters
  virtual double GetLikelihood()=0;//Get likelihood

};
