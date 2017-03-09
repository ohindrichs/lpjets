#ifndef IDJET_H
#define IDJET_H
#include "MCMatchable.h"
#include "URStreamer.h"
#include "IDMuon.h"
#include "IDElectron.h"
#include <TMath.h>
#include <TVector2.h>

#include <iostream>

using namespace std;

class IDJet : public Jet, public MCMatchable
{
	private:
		vector<double> m_sf;
		size_t m_sftype = 0;
		size_t m_maxsf = 0;
	public:
		void SetSF(size_t n, double sf, TVector2& metcorr)
		{
			if(n > m_sf.size()) m_sf.resize(n+1);
			m_sf[n] = sf;
			if(m_sf[m_maxsf] < m_sf[n])
			{
				m_maxsf = n;
				metcorr =  ApplySF(m_maxsf);
			}
		}
		TVector2 ApplySF(size_t sftype)
		{
			if(m_sftype == sftype) return TVector2(0., 0.);
			double sf = m_sf[sftype]/m_sf[m_sftype];
			m_sftype = sftype;
			TVector2 dmet((sf-1.)*Px(), (sf-1.)*Py());
			//SetPxPyPzE(sf*Px(), sf*Py(), sf*Pz(), sf*E());
			return dmet;
		}
	double genpt = 0.;
	IDJet(const Jet el):
		Jet(el),
		MCMatchable(),
		m_sf(3,1.)
		{
		}
	int flavor() const {return (match()) ? match()->pdgId() : partonFlavour();}

	bool ID()
	{
		if(numberOfDaughters() <= 1) {return false;}
		if(neutralHadronEnergyFraction() >= 0.99){return false;}
		if(neutralEmEnergyFraction() >= 0.99){return false;}
		if(TMath::Abs(Eta()) < 2.4)
		{
			if(chargedEmEnergyFraction() >= 0.99){return false;}
			if(chargedHadronEnergyFraction() <= 0.){return false;}
			if(chargedMultiplicity() <= 0.){return false;}
		}
		return(true);
	}
	bool Clean(const vector<IDMuon*>& muons, const vector<IDElectron*>& electrons, double distpar = 0.4)
	{
		for(const IDMuon* mu : muons)
		{
			if(DeltaR(*mu) < distpar)
			{
				return false;
			}
		}
		for(const IDElectron* el : electrons)
		{
			if(DeltaR(*el) < distpar)
			{
				return false;
			}
		}
		return true;
	}

};
#endif
