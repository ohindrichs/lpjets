#include "IDPhoton.h"
#include <iostream>


double IDPhoton::PFIsoDb() const
{
	//return (pfChargedIso() + max(pfNeutralIso() + pfPhotonIso() - 0.5*pfPUIso(), 0.))/Pt();
	return -1;
}

double IDPhoton::CorPFIsolation() const
{
//	double eta = abs(Eta());
//	double effarea = 0.2393;
//	if(eta < 1.){ effarea = 0.1703;}
//	else if(eta < 1.479){ effarea = 0.1715;}
//	else if(eta < 2.){ effarea = 0.1213;}
//	else if(eta < 2.2){ effarea = 0.1230;}
//	else if(eta < 2.3){ effarea = 0.1635;}
//	else if(eta < 2.4){ effarea = 0.1937;}
//
//	if(streamer != 0)
//	{
//		effarea *= max(streamer->rho().value(), 0.);
//	}
//	else {effarea = 0; cerr << "initialize IDElectron::stream = URStreamer object for rho correction" << endl;}
//	return(pfChargedIso() + max(pfNeutralIso() + pfPhotonIso() - effarea, 0.))/Pt();
	return -1;
}

bool IDPhoton::ID(IDS idtyp)
{
//	if(abs(Eta()) > 2.4) return(false);
//	double sceta = abs(SCeta());
//	if(sceta >= 2.4) return(false);
//	if(sceta < 1.566 && sceta > 1.4442) return(false);
//	else if(idtyp == MEDIUM_16)
//	{
//		if(sceta < 1.5)
//		{
//			if(full5x5_sigmaIetaIeta() > 0.011){return(false);}
//			if(hadronicOverEM() > 0.04){return(false);}
//			//if(USEISO && PFIsoDb() > 0.15){return(false);}
//			if(USEISO && CorPFIsolation() > 0.15){return(false);}
//			if(hasPixelSeed()){return(false);}
//			return(true);
//		}
//		if(sceta > 1.5)
//		{
//			if(full5x5_sigmaIetaIeta() > 0.03){return(false);}
//			if(hadronicOverEM() > 0.04){return(false);}
//			//if(USEISO && PFIsoDb() > 0.15){return(false);}
//			if(USEISO && CorPFIsolation() > 0.15){return(false);}
//			if(hasPixelSeed()){return(false);}
//			return(true);
//		}
//	}
	return(false);
}

URStreamer* IDPhoton::streamer = 0;
bool IDPhoton::USEISO = true;

