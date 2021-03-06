/*****************************************************************************
 * Project: RooFit                                                           *
 *                                                                           *
 * This code was autogenerated by RooClassFactory                            *
 *****************************************************************************/

// Your description goes here...

#include "Riostream.h"

#include "DoubleCrystalBall.h"
#include "RooAbsReal.h"
#include "RooAbsCategory.h"
#include <math.h>
#include "TMath.h"

 DoubleCrystalBall::DoubleCrystalBall(const char *name, const char *title,
                        RooAbsReal& _x,
                        RooAbsReal& _x0,
                        Double_t    _x0Shift,
                        RooAbsReal& _sigma,
                        Double_t    _sigmaShift,
                        RooAbsReal& _alpha,
                        RooAbsReal& _n,
                        RooAbsReal& _alphaPrime,
                        RooAbsReal& _nPrime) :
   RooAbsPdf(name,title),
   x("x","x",this,_x),
   x0("x0","x0",this,_x0),
   x0Shift(_x0Shift),
   sigma("sigma","sigma",this,_sigma),
   sigmaShift(_sigmaShift),
   alpha("alpha","alpha",this,_alpha),
   n("n","n",this,_n),
   alphaPrime("alphaPrime","alphaPrime",this,_alphaPrime),
   nPrime("nPrime","nPrime",this,_nPrime)
 {
 }


 DoubleCrystalBall::DoubleCrystalBall(const DoubleCrystalBall& other, const char* name) :
   RooAbsPdf(other,name),
   x("x",this,other.x),
   x0("x0",this,other.x0),
   x0Shift(other.x0Shift),
   sigma("sigma",this,other.sigma),
   sigmaShift(other.sigmaShift),
   alpha("alpha",this,other.alpha),
   n("n",this,other.n),
   alphaPrime("alphaPrime",this,other.alphaPrime),
   nPrime("nPrime",this,other.nPrime)
 {
 }

 int DoubleCrystalBall::sign(Double_t x) const{
   if(x>=0)
     return 1;
   else
     return -1;
 }

 Double_t DoubleCrystalBall::evaluate() const
 {
   Double_t x0Shifted = x0+x0Shift;
   Double_t sigmaShifted = sigma*sigmaShift;
   Double_t y =sign(alphaPrime)*sign(alpha)*(x-x0Shifted)/sigmaShifted;

   if(y>-fabs(alpha) && y< fabs(alphaPrime))
   return(exp(-0.5*y*y));

   if(y<= -fabs(alpha)){
     Double_t A =  TMath::Power(n/fabs(alpha),n)*TMath::Exp(-0.5*fabs(alpha)*fabs(alpha));
     Double_t B= n/fabs(alpha) - fabs(alpha);
     return ((A/TMath::Power(B - y, n)));

   }

   if(y>= fabs(alphaPrime)){
     Double_t C =  TMath::Power(nPrime/fabs(alphaPrime),nPrime)*TMath::Exp(-0.5*fabs(alphaPrime)*fabs(alphaPrime));
     Double_t D= nPrime/fabs(alphaPrime) - fabs(alphaPrime);
     return((C/TMath::Power(D + y, nPrime)));
   }
   return 0;//won't happen but to eliminate warnings
 }
