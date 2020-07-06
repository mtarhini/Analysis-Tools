/*****************************************************************************
 * Project: RooFit                                                           *
 *                                                                           *
  * This code was autogenerated by RooClassFactory                            *
 *****************************************************************************/

#ifndef POL1OVERPOL2
#define POL1OVERPOL2

#include "RooAbsPdf.h"
#include "RooRealProxy.h"
#include "RooCategoryProxy.h"
#include "RooAbsReal.h"
#include "RooAbsCategory.h"

class Pol1OverPol2 : public RooAbsPdf {
public:
  Pol1OverPol2() {} ;
  Pol1OverPol2(const char *name, const char *title,
	      RooAbsReal& _x,
        RooAbsReal& _a0,
        RooAbsReal& _a1,
        RooAbsReal& _b1,
	      RooAbsReal& _b2);
  Pol1OverPol2(const Pol1OverPol2& other, const char* name=0) ;
  virtual TObject* clone(const char* newname) const { return new Pol1OverPol2(*this,newname); }
  inline virtual ~Pol1OverPol2() { }

protected:

  RooRealProxy x ;
  RooRealProxy a0 ;
  RooRealProxy a1 ;
  RooRealProxy b1 ;
  RooRealProxy b2 ;

  Double_t evaluate() const ;

private:

  ClassDef(Pol1OverPol2,2) // Your description goes here...
};

#endif