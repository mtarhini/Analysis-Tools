/*****************************************************************************
 * Project: RooFit                                                           *
 *                                                                           *
  * This code was autogenerated by RooClassFactory                            *
 *****************************************************************************/

#ifndef PTDIST
#define PTDIST

#include "RooAbsPdf.h"
#include "RooRealProxy.h"
#include "RooCategoryProxy.h"
#include "RooAbsReal.h"
#include "RooAbsCategory.h"

class PtDist : public RooAbsPdf {
public:
  PtDist() {} ;
  PtDist(const char *name, const char *title,
	      RooAbsReal& _x,
	      RooAbsReal& _p1,
	      RooAbsReal& _p2,
	      RooAbsReal& _p3);
  PtDist(const PtDist& other, const char* name=0) ;
  virtual TObject* clone(const char* newname) const { return new PtDist(*this,newname); }

protected:

  RooRealProxy x ;
  RooRealProxy p1 ;
  RooRealProxy p2 ;
  RooRealProxy p3 ;

  Double_t evaluate() const ;

private:

  ClassDef(PtDist,2) // Your description goes here...
};

#endif