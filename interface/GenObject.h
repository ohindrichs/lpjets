#ifndef GENOBJECT_H
#define GENOBJECT_H
#include "URStreamer.h"

class GenObject : public TLorentzVector
{
private:
	int pdgId_;
	int status_;
	double isolation_ = -1.;

public:
	GenObject()=default;
//	GenObject(const Genparticle& gp) : TLorentzVector(gp), pdgId_(gp.pdgId()), status_(gp.status())
//	{
//	}
	GenObject(const Pl& gp) : TLorentzVector(gp), pdgId_(gp.pdgId()), status_(gp.status()), isolation_(gp.isoR3())
	{
	}
	GenObject(const Ttgen& gp) : TLorentzVector(gp), pdgId_(gp.pdgId()), status_(gp.status())
	{
	}
	GenObject(const Rivetpl& gp) : TLorentzVector(gp), pdgId_(gp.pdgId()), status_(gp.status())
	{
	}
//	GenObject(const Pstjet& gp) : TLorentzVector(gp), pdgId_(gp.pdgId()), status_(0)
//	{
//	}
//	GenObject(const Pstlepton& gp) : TLorentzVector(gp), pdgId_(gp.pdgId()), status_(0)
//	{
//	}
//	GenObject(const Pstneutrino& gp) : TLorentzVector(gp), pdgId_(gp.pdgId()), status_(0)
//	{
//	}
//	GenObject(const Genjet& jet) : TLorentzVector(jet), pdgId_(0), status_(0)
//	{
//	}
	
	int pdgId() const {return pdgId_;}
	int status() const {return status_;}
	double isolation() const {return isolation_;}

};
#endif
