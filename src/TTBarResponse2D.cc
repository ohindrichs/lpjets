#include <TTBarResponse2D.h>
#include <sstream>
#include <iostream>

#include <TDirectory.h>

TTBarResponse2D::TTBarResponse2D(string prefix) : prefix_(prefix), dir(nullptr), plot1d(""), plot2d("")
{
}

TTBarResponse2D::~TTBarResponse2D() {}

void TTBarResponse2D::AddMatrix(string name, const vector<double>& Mbinsx, const vector<double>& Mbinsy, const vector<double>& Tbinsx, const vector<double>& Tbinsy, bool ofx, bool ofy)
{
	TDirectory* olddir = gDirectory;
	bool indir = olddir->cd(prefix_.c_str());
	if(!indir)
	{
		dir = olddir->mkdir(prefix_.c_str());
		dir->cd();
	}
	else
	{
		dir = gDirectory;
	}

	plot2d.AddHist(name + "_truthcontrol", Tbinsx, Tbinsy, "gen", "gen");
	plot2d[name + "_truthcontrol"]->SetBinContent(0,1, ofx ? 1. : 0.);
	plot2d[name + "_truthcontrol"]->SetBinContent(1,0, ofy ? 1. : 0.);
	plot2d.AddHist(name + "_recocontrol", Mbinsx, Mbinsy, "reco", "reco");
	plot2d[name + "_recocontrol"]->SetBinContent(0,1, ofx ? 1. : 0.);
	plot2d[name + "_recocontrol"]->SetBinContent(1,0, ofy ? 1. : 0.);
	int truthbins = (Tbinsx.size()-1)*(Tbinsy.size()-1);
	plot1d.AddHist(name + "_truth", truthbins, 0., truthbins, "gen", "Events");
	int reconbins = (Mbinsx.size()-1)*(Mbinsy.size()-1);
	plot1d.AddHist(name + "_bkg", reconbins, 0, reconbins, "reco", "Events");
	plot1d.AddHist(name + "_all", reconbins, 0, reconbins, "reco", "Events");
	plot2d.AddHist(name + "_matrix", truthbins, 0., truthbins, reconbins, 0, reconbins, "gen", "reco");
	double vrange = 4*abs(Mbinsx[0]-Mbinsx[1]);
	plot2d.AddHist(name + "_res", reconbins, 0., reconbins, 400, -1*vrange, vrange, "reco", "res");

	olddir->cd();
}


int TTBarResponse2D::GetBin(string name, double valx, double valy, bool RECO)
{
	if(RECO)
	{
		name += "_recocontrol";
	}
	else
	{
		name += "_truthcontrol";
	}
	TH2D* hcon = plot2d[name];
	int of = 0;

	int bx = hcon->GetXaxis()->FindFixBin(valx);
	if(bx == 0){of = 1; bx++;}
	else if(bx == hcon->GetXaxis()->GetNbins()+1) {of = 1; bx--;}
	if(of == 1 && hcon->GetBinContent(0,1) == 0.){return(-1);}

	of = 0;
	int by = hcon->GetYaxis()->FindFixBin(valy);
	if(by == 0){of = 1; by++;}
	else if(by == hcon->GetYaxis()->GetNbins()+1) {of = 1; by--;}
	return(hcon->GetXaxis()->GetNbins()*(by-1) + bx);
	if(of == 1 && hcon->GetBinContent(1,0) == 0.){return(-1);}
}

void TTBarResponse2D::FillTruth(string name, double valx, double valy, double weight)
{
	int bin = GetBin(name, valx, valy, false);
	plot1d[name + "_truth"]->Fill(bin-0.5, weight);
}

void TTBarResponse2D::FillBKG(string name, double valx, double valy, double weight)
{
	int bin = GetBin(name, valx, valy, true);
	plot1d[name + "_bkg"]->Fill(bin-0.5, weight);
}

void TTBarResponse2D::FillAll(string name, double valx, double valy, double weight)
{
	int bin = GetBin(name, valx, valy, true);
	plot1d[name + "_all"]->Fill(bin-0.5, weight);
}

void TTBarResponse2D::FillTruthReco(string name, double tvalx, double tvaly, double rvalx, double rvaly, double weight)
{
	int tbin = GetBin(name, tvalx, tvaly, false);
	int rbin = GetBin(name, rvalx, rvaly, true);
	plot2d[name+"_matrix"]->Fill(tbin-0.5, rbin-0.5, weight);
	plot2d[name+"_res"]->Fill(rbin-0.5, rvalx-tvalx, weight);
}


