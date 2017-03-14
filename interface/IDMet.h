#ifndef IDMET_H
#define IDMET_H
#include "MCMatchable.h"
#include "URStreamer.h"
#include <TMath.h>
#include <TVector2.h>

//class IDMet : public Nohfmet, public TLorentzVector
//class IDMet : public Met, public TLorentzVector
class IDMet : public Met
{
private: 
public:
	IDMet() {}
	//IDMet(const Nohfmet met):
	IDMet(const Met met):
		//Nohfmet(met), TLorentzVector(met.px(), met.py(), 0., TMath::Sqrt(met.px()*met.px() + met.py()*met.py()))
		//Met(met), TLorentzVector(met.px(), met.py(), 0., TMath::Sqrt(met.px()*met.px() + met.py()*met.py()))
		Met(met)
		{
		}

	void Update(const TVector2& cor)
	{
		SetPx(Px()-cor.Px());
		SetPy(Py()-cor.Py());
		SetE(sqrt(Px()*Px() + Py()*Py()));
	}
};
#endif
