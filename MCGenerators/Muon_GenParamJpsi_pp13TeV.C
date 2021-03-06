//-------------------------------------------------------------------------------------------------//
//                     MC production for muon J/psi analysis in pp at 13 TeV                  	   //
//                                                                                                 //
// MC is for a pure signals of J/psi , with y and pT input shapes tuned on pp collected in 2015    //
// Production should be done on the run-by-run basis. The production is proportional to number of  //
// CMUL7-B-NOPF-MUFAST for a given run.                                                            //
//-------------------------------------------------------------------------------------------------//

#include <Riostream.h>
#include "TRandom.h"
#include "AliGenerator.h"
#include "AliGenCocktail.h"
#include "AliGenEvtGen.h"
#include "AliGenParam.h"

Int_t IpJPsipp13TeV( TRandom *ran);
Double_t PtJPsipp13TeV( const Double_t *px, const Double_t */*dummy*/ );
Double_t YJPsipp13TeV( const Double_t *py, const Double_t */*dummy*/ );
Double_t V2JPsipp13TeV( const Double_t *pv, const Double_t */*dummy*/ );

//-------------------------------------------------------------------------
AliGenerator* CreateGenerator()
{
	AliGenCocktail *gener = new AliGenCocktail();
	gener->UsePerEventRates();

  AliGenParam *JPsiGener = new AliGenParam(1,-1,PtJPsipp13TeV,YJPsipp13TeV,V2JPsipp13TeV,IpJPsipp13TeV);
  JPsiGener->SetMomentumRange(0., 1.e6);
  JPsiGener->SetPtRange(0., 999.);
  JPsiGener->SetYRange(-4.2, -2.3);
  JPsiGener->SetPhiRange(0., 360.);

	JPsiGener->SetTrackingFlag(1);
	JPsiGener->SetForceDecay(kNoDecay);  // JPsi particles decay are switched-off for Pythia

	// evtGen (for radiative decays)
	AliGenEvtGen *evtGener = new AliGenEvtGen();
	evtGener->SetForceDecay(kDiMuon);
	evtGener->SetParticleSwitchedOff(AliGenEvtGen::kCharmPart);

	// add JPsi generator to cocktail
	gener->AddGenerator(JPsiGener,"JPsi",1);
	// add EvtGen generator to cocktail
	gener->AddGenerator(evtGener,"EvtGen",1);

  return gener;
}

//-------------------------------------------------------------------------
Int_t IpJPsipp13TeV( TRandom *)
{
  return 443;
}

//-------------------------------------------------------------------------
Double_t PtJPsipp13TeV( const Double_t *px, const Double_t */*dummy*/ )
{
  // jpsi pT in pp at 13 TeV, tuned on data (2015)
	Double_t x=*px;
	Float_t p0,p1,p2,p3;
	p0 = 1;
	p1 = 4.75208;
	p2 = 1.69247;
	p3 = 4.49224;
	return p0 *x / TMath::Power( 1. + TMath::Power(x/p1,p2), p3 );
}

//-------------------------------------------------------------------------
Double_t YJPsipp13TeV( const Double_t *py, const Double_t */*dummy*/ )
{
  // jpsi y in pp at 13 TeV, tuned on data (2015)
	Double_t y = *py;
	Float_t p0,p1,p2;
	p0 = 1;
	p1 = 0;
	p2 = 2.98887;
	return p0*TMath::Exp(-(1./2.)*TMath::Power(((y-p1)/p2),2));
}

//-------------------------------------------------------------------------
Double_t V2JPsipp13TeV( const Double_t */*dummy*/, const Double_t */*dummy*/ )
{
  //jpsi v2
  return 0.;
}
