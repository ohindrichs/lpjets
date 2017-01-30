#include <TTBarGenPlots.h>
#include <URStreamer.h>
#include <Permutation.h>
#include <ttbarxsec.h>

using namespace std;
using namespace TMath;

TTBarGenPlots::TTBarGenPlots(string prefix) : TTBarPlotsBase(prefix)
{

}

TTBarGenPlots::~TTBarGenPlots()
{

}

void TTBarGenPlots::Init(ttbar* analysis)
{
	TTBarPlotsBase::Init(analysis);

    plot1d.AddHist("toppthad", an->topptbins, "toppthad", "Events");
	plot1d.AddHist("topptlep", an->topptbins, "topptlep", "Events");
	plot1d.AddHist("topetahad", an->topybins, "topetahad", "Events");
	plot1d.AddHist("topetalep", an->topybins, "topetalep", "Events");
	plot1d.AddHist("ttm", an->ttmbins, "ttm", "Events");
	plot1d.AddHist("ttpt", an->ttptbins, "ttpt", "Events");

}

void TTBarGenPlots::Fill(Permutation& per, double weight)
{
	TTBarGenPlots::Fill(per, weight);
    plot1d["toppthad"]->Fill(per.THad().Pt(), weight);
	plot1d["topptlep"]->Fill(per.TLep().Pt(), weight);
	plot1d["topetahad"]->Fill(Abs(per.THad().Rapidity()), weight);
	plot1d["topetalep"]->Fill(Abs(per.TLep().Rapidity()), weight);
	plot1d["ttm"]->Fill(per.TT().M(), weight);
	plot1d["ttpt"]->Fill(per.TT().Pt(), weight);
}

