#include <TTBarResponse.h>
#include <sstream>

#include <ttbarxsec.h>
#include <TDirectory.h>


TTBarResponse::TTBarResponse(string prefix, ttbar* an) : prefix_(prefix), an_(an), dir(nullptr), plot1d(""), plot2d("")
{
}

TTBarResponse::~TTBarResponse() {}

void TTBarResponse::AddMatrix(string name, const vector<double>& Mbins, const vector<double>& Tbins, string label, bool ext)
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

	plot1d.AddHist(name + "_truth", Tbins, label, "Events");
	plot1d.AddHist(name + "_all", Mbins, label, "Events");
	plot1d.AddHist(name + "_bkg", Mbins, label, "Events");
	plot2d.AddHist(name + "_matrix", Tbins, Mbins, "gen " + label, "reco " + label);
	double resbin = 4*Abs(Mbins[1] - Mbins[0]);
	plot2d.AddHist(name + "_res", Tbins, 100, -2*resbin, resbin*2, "gen " + label, "(reco-gen) " + label);
	plot2d.AddHist(name + "_restruth", Tbins, 100, -1*resbin, resbin, "gen " + label, "(reco-gen) " + label);
	withext[name] = ext;
	//for(int njet = 0 ; njet < 4 ; ++njet)
	//{
	//	stringstream hname;
	//	hname << name << "_truth_" << njet;
	//	plot1d.AddHist(hname.str(), Tbins, label, "Events");
	//	hname.str("");
	//	hname << name << "_reco_" << njet;
	//	plot1d.AddHist(hname.str(), Mbins, label, "Events");
	//	hname.str("");
	//	hname << name << "_matrix_" << njet;
	//	plot2d.AddHist(hname.str(), Tbins, Mbins, "gen " + label, "reco " + label);
	//}

	olddir->cd();
}

void TTBarResponse::FillTruth(string name, double val, double weight)
{
	TH1D* hist = plot1d[name + "_truth"];
	if(withext[name] && val <= hist->GetXaxis()->GetXmin()) val = hist->GetXaxis()->GetBinCenter(1);
	else if(withext[name] && val >= hist->GetXaxis()->GetXmax()) val = hist->GetXaxis()->GetBinCenter(hist->GetNbinsX());
	hist->Fill(val, weight);
}

void TTBarResponse::FillAll(string name, double val, double weight)
{
	TH1D* hist = plot1d[name + "_all"];
	if(withext[name] && val <= hist->GetXaxis()->GetXmin()) val = hist->GetXaxis()->GetBinCenter(1);
	else if(withext[name] && val >= hist->GetXaxis()->GetXmax()) val = hist->GetXaxis()->GetBinCenter(hist->GetNbinsX());
	hist->Fill(val, weight);
}

void TTBarResponse::FillBKG(string name, double val, double weight)
{
	TH1D* hist = plot1d[name + "_bkg"];
	if(withext[name] && val <= hist->GetXaxis()->GetXmin()) val = hist->GetXaxis()->GetBinCenter(1);
	else if(withext[name] && val >= hist->GetXaxis()->GetXmax()) val = hist->GetXaxis()->GetBinCenter(hist->GetNbinsX());
	hist->Fill(val, weight);
}

void TTBarResponse::FillTruthReco(string name, double tval, double rval, double weight)
{
	TH2D* hist = plot2d[name + "_matrix"];
	TH2D* histres = plot2d[name + "_res"];
	histres->Fill(tval, rval-tval, weight);
	if(withext[name] && tval <= hist->GetXaxis()->GetXmin()) tval = hist->GetXaxis()->GetBinCenter(1);
	else if(withext[name] && tval >= hist->GetXaxis()->GetXmax()) tval = hist->GetXaxis()->GetBinCenter(hist->GetNbinsX());
	if(withext[name] && rval <= hist->GetYaxis()->GetXmin()) rval = hist->GetYaxis()->GetBinCenter(1);
	else if(withext[name] && rval >= hist->GetYaxis()->GetXmax()) rval = hist->GetYaxis()->GetBinCenter(hist->GetNbinsY());
	hist->Fill(tval, rval, weight);
}

void TTBarResponse::FillRes(string name, double tval, double rval, double weight)
{
	TH2D* hist = plot2d[name + "_restruth"];
	hist->Fill(tval, rval-tval, weight);
}
