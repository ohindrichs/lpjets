#ifndef IDPHOTON_H
#define IDPHOTON_H
#include "URStreamer.h"
#include "MCMatchable.h"

class IDPhoton : public Photon, public MCMatchable
{
private:

public:
	IDPhoton(const Photon ph) : 
		Photon(ph),
		MCMatchable()
	{
	}
	static URStreamer* streamer;
	static bool USEISO;
	enum IDS {MEDIUM_16=1};
	double PFIsoDb() const;
	double CorPFIsolation() const;
	bool ID(IDS idtyp);

};

#endif
