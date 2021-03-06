/*****************************************************************************
 * Project: RooFit                                                           *
 *                                                                           *
  * This code was autogenerated by RooClassFactory                            *
 *****************************************************************************/

#ifndef DOUBLECRYSTALBALL
#define DOUBLECRYSTALBALL

#include "RooAbsPdf.h"
#include "RooRealProxy.h"
#include "RooCategoryProxy.h"
#include "RooAbsReal.h"
#include "RooAbsCategory.h"

class DoubleCrystalBall : public RooAbsPdf {
public:
  DoubleCrystalBall() {} ;
  DoubleCrystalBall(const char *name, const char *title,
	      RooAbsReal& _x,
	      RooAbsReal& _x0,
        Double_t    _x0Shift,
	      RooAbsReal& _sigma,
        Double_t    _sigmaShift,
	      RooAbsReal& _alpha,
	      RooAbsReal& _n,
	      RooAbsReal& _alphaPrime,
	      RooAbsReal& _nPrime);
  DoubleCrystalBall(const DoubleCrystalBall& other, const char* name=0) ;
  virtual TObject* clone(const char* newname) const { return new DoubleCrystalBall(*this,newname); }
  inline virtual ~DoubleCrystalBall() { }

protected:

  RooRealProxy x ;
  RooRealProxy x0 ;
  Double_t x0Shift;
  RooRealProxy sigma ;
  Double_t sigmaShift;
  RooRealProxy alpha ;
  RooRealProxy n ;
  RooRealProxy alphaPrime ;
  RooRealProxy nPrime ;
  int sign(Double_t x) const;
  Double_t evaluate() const ;

private:

  ClassDef(DoubleCrystalBall,2) // Your description goes here...
};

#endif
