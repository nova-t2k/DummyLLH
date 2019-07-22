#include "ExampleExternalLLH.h"
#include "TMath.h"

ExampleExternalLLH::ExampleExternalLLH(){
}

void ExampleExternalLLH::init(){
  trueoscvals.dcp=-1.601;
  trueoscvals.dm32=-1.601;
  trueoscvals.dm21=-1.601;
  trueoscvals.sth13=-1.601;
  trueoscvals.sth12=-1.601;
  trueoscvals.sth23=-1.601;

  trueoscsigmas.dcp=-1.601;
  trueoscsigmas.dm32=-1.601;
  trueoscsigmas.dm21=-1.601;
  trueoscsigmas.sth13=-1.601;
  trueoscsigmas.sth12=-1.601;
  trueoscsigmas.sth23=-1.601;
  
}

void ExampleExternalLLH::SetParameters(CovTypes iCov,std::vector<double> vals){
}

void ExampleExternalLLH::SetOscParameters(OscPars oscpars){
  oscvals=oscpars;
}

double ExampleExternalLLH::GetLikelihood(){
  double llh=0;
  
  std::vector<double*> oscvec;
  oscvec.push_back(&(oscvals.sth12));
  oscvec.push_back(&(oscvals.sth23));
  oscvec.push_back(&(oscvals.sth13));
  oscvec.push_back(&(oscvals.dm21));
  oscvec.push_back(&(oscvals.dm32));
  oscvec.push_back(&(oscvals.dcp));
  
  std::vector<double*> trueoscvec;
  trueoscvec.push_back(&(trueoscvals.sth12));
  trueoscvec.push_back(&(trueoscvals.sth23));
  trueoscvec.push_back(&(trueoscvals.sth13));
  trueoscvec.push_back(&(trueoscvals.dm21));
  trueoscvec.push_back(&(trueoscvals.dm32));
  trueoscvec.push_back(&(trueoscvals.dcp));

  std::vector<double*> trueoscsigvec;
  trueoscsigvec.push_back(&(trueoscsigmas.sth12));
  trueoscsigvec.push_back(&(trueoscsigmas.sth23));
  trueoscsigvec.push_back(&(trueoscsigmas.sth13));
  trueoscsigvec.push_back(&(trueoscsigmas.dm21));
  trueoscsigvec.push_back(&(trueoscsigmas.dm32));
  trueoscsigvec.push_back(&(trueoscsigmas.dcp));
  
  for(unsigned iPar=0;iPar<oscvec.size();iPar++){
    llh+=TMath::Gaus(*oscvec[iPar],*trueoscvec[iPar],*trueoscsigvec[iPar]);
  }
  

  return llh;
}
