enum CovTypes {//We should expand this to have all the T2K and NOvA classes
  kOsc=0,
  kSKdet=1,
  kBANFF=2,
  kXsec=3,
  kND280det=4,
  kNOvAFD=5,
  kNOvAND=6
};

Class OscPars{
 public:
  double dm32,dm21,sth13,sth12,sth23,dcp;
}

class TemplateLLHGetter {
 public:
  TemplateLLHGetter();
  ~TemplateLLHGetter();

  virtual void init();//Some sort of call once init fuction
  virtual void SetParameters(CovTypes iCov, std::vector<double> vals);//Set systematic parameters
  virtual void SetParameters(CovTypes iCov, OscPars oscpars);//Set oscillation parameters
  virtual double GetLikelihood();//Get likelihood

};
