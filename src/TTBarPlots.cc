#include <TTBarPlots.h>
#include <URStreamer.h>
#include <Permutation.h>
#include <ttbarxsec.h>

#include <sstream>

using namespace std;
using namespace TMath;

TTBarPlots::TTBarPlots(string prefix) : TTBarPlotsBase(prefix)
{

}

TTBarPlots::~TTBarPlots()
{

}

void TTBarPlots::Init(ttbar* analysis)
{
	TTBarPlotsBase::Init(analysis);
	int ta = 40.;
	double tamin = 6.;
	double tamax = 18.;
	int tb = 40.;
	//double tbmin = -20.;
	//double tbmax = 10.;
	double tbmin = 10.;
	double tbmax = 30.;
	plot1d.AddHist("MET", 500, 0, 2000, "MET", "Events");
	plot1d.AddHist("HT", 600, 0, 6000, "HT", "Events");
	plot1d.AddHist("EvtMass", 600, 0, 6000, "EvtMass", "Events");
	plot1d.AddHist("njets", 15, 0, 15, "additional jets", "Events");
	plot1d.AddHist("btag_blep", 100, 0, 1, "CSVv2", "Events");
	plot1d.AddHist("btag_bhad", 100, 0, 1, "CSVv2", "Events");
	for(int j = 0 ; j < 8 ; ++j)
	{
		stringstream ss;
		ss << "jet_" << j << "_";
		plot1d.AddHist(ss.str()+"pt", 200, 30, 430, "p_{T}("+an->jetnames[j]+") [GeV]", "Events");
		plot1d.AddHist(ss.str()+"pt_fb", an->jetptbins[j], "p_{T}("+an->jetnames[j]+") [GeV]", "Events");
		plot1d.AddHist(ss.str()+"eta", 120, -2.4, 2.4, "#eta("+an->jetnames[j]+")", "Events");
		plot1d.AddHist(ss.str()+"eta_fb", an->jetetabins[j], "|#eta("+an->jetnames[j]+")|", "Events");
		plot1d.AddHist(ss.str()+"dr", 120, 0., 6., "#DeltaR_{t#bar{t}}("+an->jetnames[j]+")", "Events");
		plot1d.AddHist(ss.str()+"dr_fb", an->jetdrbins[j], "#DeltaR_{t#bar{t}}("+an->jetnames[j]+")", "Events");
	}
	plot1d.AddHist("DPhiMET_Nu", 100, 0, 3, "#Delta#Phi(#nu, MET)", "Events");
	plot2d.AddHist("METvsDPhiMET_Nu", 120, 0, 1200, 100, 0, 3, "MET [GeV]", "#Delta#Phi(#nu, MET)");
	plot2d.AddHist("METvsChi", 120, 0, 1200, 25, 0., 100., "MET [GeV]", "#chi");
	plot1d.AddHist("Mt_W", 500, 0, 500, "M_{t}(W) [GeV]", "Events");
	plot1d.AddHist("Mt_t", 500, 0, 1000, "M_{t}(t_{l}) [GeV]", "Events");
	plot1d.AddHist("mttest", 500, 0, 100, "mttest", "Events");
	plot1d.AddHist("masstest", 500, 0, 100, "-log(#lambda_{m})", "Events");
	plot1d.AddHist("nutest", 500, 0, 100, "nutest", "Events");
	plot1d.AddHist("chiqtest", 500, 0, 100, "D_{#nu,min}", "Events");
	plot1d.AddHist("massmttest", 500, 0, 100, "mttest", "Events");
	plot1d.AddHist("massnutest", 500, 0, 100, "-log(#lambda)", "Events");
	plot2d.AddHist("METunc", 100, 0, 0.5, 100, 0., .5, "#sigma(MET_{x})/MET_{x}", "#sigma(MET_{y})/MET_{y}");
	plot2d.AddHist("dphi_deta", 100, 0, Pi(), 12, 0., 6., "#Delta #phi(j,j)", "#Delta #eta(jj)");
	plot2d.AddHist("masst_thadpt", 50, 50, 300, an->topptbins, "M(t_{h}) [GeV]", "p_{T}(t_{h}) [GeV]");
	plot2d.AddHist("massW_thadpt", 50, 0, 150, an->topptbins, "M(W) [GeV]", "p_{T}(t_{h}) [GeV]");
	plot2d.AddHist("masst_thady", 50, 50, 300, an->topybins, "M(t_{h}) [GeV]", "|y(t_{h})|");
	plot2d.AddHist("massW_thady", 50, 0, 150, an->topybins, "M(W) [GeV]", "|y(t_{h})|");
	plot2d.AddHist("masst_tleppt", 50, 50, 300, an->topptbins, "M(t_{h}) [GeV]", "p_{T}(t_{l}) [GeV]");
	plot2d.AddHist("massW_tleppt", 50, 0, 150, an->topptbins, "M(W) [GeV]", "p_{T}(t_{l}) [GeV]");
	plot2d.AddHist("masst_tlepy", 50, 50, 300, an->topybins, "M(t_{h}) [GeV]", "|y(t_{l})|");
	plot2d.AddHist("massW_tlepy", 50, 0, 150, an->topybins, "M(W) [GeV]", "|y(t_{l})|");
	plot2d.AddHist("masst_ttm", 50, 50, 300, an->ttmbins, "M(t_{h}) [GeV]", "");
	plot2d.AddHist("massW_ttm", 50, 0, 150, an->ttmbins, "M(W) [GeV]", "");
	plot2d.AddHist("masst_ttpt", 50, 50, 300, an->ttptbins, "M(t_{h}) [GeV]", "");
	plot2d.AddHist("massW_ttpt", 50, 0, 150, an->ttptbins, "M(W) [GeV]", "");
	plot2d.AddHist("masst_tty", 50, 50, 300, an->ttybins, "M(t_{h}) [GeV]", "");
	plot2d.AddHist("massW_tty", 50, 0, 150, an->ttybins, "M(W) [GeV]", "");
	plot2d.AddHist("masst_njet", 50, 50, 300, an->jetbins, "M(t_{h}) [GeV]", "");
	plot2d.AddHist("massW_njet", 50, 0, 150, an->jetbins, "M(W) [GeV]", "");
	for(int jn : jetbins)
	{
		stringstream jb;
		if(jn != -1) jb << jn << "_";
		plot2d.AddHist("test_"+jb.str()+"testb", ta, tamin, tamax, tb, tbmin, tbmax, "-log(#lambda_{m})", "D_{#nu,min} [GeV]");
		plot2d.AddHist("test_"+jb.str()+"nobin", ta, tamin, tamax, an->nobins, "-log(#lambda_{m})", "all");
		plot2d.AddHist("testb_"+jb.str()+"nobin", tb, tbmin, tbmax, an->nobins, "D_{#nu,min} [GeV]", "all");
		plot2d.AddHist("test_"+jb.str()+"tpt", ta, tamin, tamax, an->topptbins, "-log(#lambda_{m})", "p_{T}(t) [GeV]");
		plot2d.AddHist("testb_"+jb.str()+"tpt", tb, tbmin, tbmax, an->topptbins, "D_{#nu,min} [GeV]", "p_{T}(t) [GeV]");
		plot2d.AddHist("test_"+jb.str()+"ty", ta, tamin, tamax, an->topybins, "-log(#lambda_{m})", "|y(t)|");
		plot2d.AddHist("testb_"+jb.str()+"ty", tb, tbmin, tbmax, an->topybins, "D_{#nu,min} [GeV]", "|y(t)|");
		plot2d.AddHist("test_"+jb.str()+"thadpt", ta, tamin, tamax, an->topptbins, "-log(#lambda_{m})", "p_{T}(t_{h}) [GeV]");
		plot2d.AddHist("testb_"+jb.str()+"thadpt", tb, tbmin, tbmax, an->topptbins, "D_{#nu,min} [GeV]", "p_{T}(t_{h}) [GeV]");
		plot2d.AddHist("test_"+jb.str()+"thady", ta, tamin, tamax, an->topybins, "-log(#lambda_{m})", "|y(t_{h})|");
		plot2d.AddHist("testb_"+jb.str()+"thady", tb, tbmin, tbmax, an->topybins, "D_{#nu,min} [GeV]", "|y(t_{h})|");
		plot2d.AddHist("test_"+jb.str()+"tleppt", ta, tamin, tamax, an->topptbins, "-log(#lambda_{m})", "p_{T}(t_{l}) [GeV]");
		plot2d.AddHist("testb_"+jb.str()+"tleppt", tb, tbmin, tbmax, an->topptbins, "D_{#nu,min} [GeV]", "p_{T}(t_{l}) [GeV]");
		plot2d.AddHist("test_"+jb.str()+"tlepy", ta, tamin, tamax, an->topybins, "-log(#lambda_{m})", "|y(t_{l})|");
		plot2d.AddHist("testb_"+jb.str()+"tlepy", tb, tbmin, tbmax, an->topybins, "D_{#nu,min} [GeV]", "|y(t_{l})|");
		plot2d.AddHist("test_"+jb.str()+"ttm", ta, tamin, tamax, an->ttmbins, "-log(#lambda_{m})", "M(tt) [GeV]");
		plot2d.AddHist("testb_"+jb.str()+"ttm", tb, tbmin, tbmax, an->ttmbins, "D_{#nu,min} [GeV]", "M(tt) [GeV]");
		plot2d.AddHist("test_"+jb.str()+"tty", ta, tamin, tamax, an->ttybins, "-log(#lambda_{m})", "y(tt)");
		plot2d.AddHist("testb_"+jb.str()+"tty", tb, tbmin, tbmax, an->ttybins, "D_{#nu,min} [GeV]", "y(tt)");
		plot2d.AddHist("test_"+jb.str()+"ttpt", ta, tamin, tamax, an->ttptbins, "-log(#lambda_{m})", "p_{T}(tt) [GeV]");
		plot2d.AddHist("testb_"+jb.str()+"ttpt", tb, tbmin, tbmax, an->ttptbins, "D_{#nu,min} [GeV]", "p_{T}(tt) [GeV]");
		plot2d.AddHist("test_"+jb.str()+"costhetastar", ta, tamin, tamax, 10, -1., 1., "-log(#lambda_{m})", "cos(#Theta*)");
		plot2d.AddHist("testb_"+jb.str()+"costhetastar", tb, tbmin, tbmax, 10, -1., 1., "D_{#nu,min} [GeV]", "cos(#Theta*)");
		plot2d.AddHist("test_"+jb.str()+"njet", ta, tamin, tamax, an->jetbins, "-log(#lambda_{m})", "additional jets");
		plot2d.AddHist("testb_"+jb.str()+"njet", tb, tbmin, tbmax, an->jetbins, "D_{#nu,min} [GeV]", "additional jets");
		plot2d.AddHist("test_"+jb.str()+"met", ta, tamin, tamax, an->metbins, "-log(#lambda_{m})", "MET [GeV]");
		plot2d.AddHist("testb_"+jb.str()+"met", tb, tbmin, tbmax, an->metbins, "D_{#nu,min} [GeV]", "MET [GeV]");
	}
}

void TTBarPlots::Fill(Permutation& per, double weight)
{
	TTBarPlotsBase::Fill(per, weight);
	double test = per.MassDiscr();
	//double testb = per.BDiscr();
	double testb = per.Prob();
	//double testb = (*per.BLep() + *per.L()).Mt(); 
	if(test == numeric_limits<double>::max()) {test = 0; testb = 0;}
	plot1d["MET"]->Fill(an->met.Pt(), weight);
	plot1d["HT"]->Fill(per.Ht(), weight);
	plot1d["EvtMass"]->Fill(per.EvtMass(), weight);
	plot1d["mttest"]->Fill(per.MTDiscr(), weight);
	plot1d["masstest"]->Fill(test, weight);
	plot1d["nutest"]->Fill(per.NuDiscr(), weight);
	plot1d["chiqtest"]->Fill(Sqrt(per.NuChisq()), weight);
	plot1d["massmttest"]->Fill(per.MTDiscr()+test, weight);
	plot1d["massnutest"]->Fill(per.Prob(), weight);

	const vector<const TLorentzVector*> addjets = per.AddJets();
//	vector<IDJet*> addjets;
//	for(size_t j = 0 ; j < an->cleanedjets.size() ; ++j)
//	{
//		if(!per.IsJetIn(an->cleanedjets[j])){addjets.push_back(an->cleanedjets[j]);}
//	}
//	sort(addjets.begin(), addjets.end(), [](IDJet* A, IDJet* B){return A->Pt() > B->Pt();});
	plot1d["njets"]->Fill(addjets.size(), weight);

	double dphi = -1;
	double deta = -1;
	for(size_t nja = 0 ; nja < addjets.size() ; ++nja)
	{
		const TLorentzVector* ja = addjets[nja];
		for(size_t njb = 0 ; njb < nja ; ++njb)
		{
			const TLorentzVector* jb = addjets[njb];
			double de = Abs(ja->Eta() - jb->Eta());
			if(de > deta) {deta = de; dphi = ja->DeltaPhi(*jb);}

		}
	}
	if(deta > 0.)
	{
		plot2d["dphi_deta"]->Fill(Abs(dphi), deta, weight);
	}
	
	for(int j = 0 ; j < min(per.NJets(), 8) ; ++j)
	{
		stringstream ss;
		ss << "jet_" << j << "_";
		const TLorentzVector* jet = per.GetJet(j);
		plot1d[ss.str()+"pt"]->Fill(jet->Pt(), weight);
		plot1d[ss.str()+"pt_fb"]->Fill(jet->Pt(), weight);
		plot1d[ss.str()+"eta"]->Fill(jet->Eta(), weight);
		plot1d[ss.str()+"eta_fb"]->Fill(abs(jet->Eta()), weight);
		plot1d[ss.str()+"dr"]->Fill(per.DRminTTjets(jet), weight);
		plot1d[ss.str()+"dr_fb"]->Fill(per.DRminTTjets(jet), weight);
	}
	plot2d["METvsChi"]->Fill(an->met.Pt(), testb, weight);
	plot1d["DPhiMET_Nu"]->Fill(Abs(per.Nu().DeltaPhi(an->met)), weight);
	plot2d["METvsDPhiMET_Nu"]->Fill(an->met.Pt(), Abs(per.Nu().DeltaPhi(an->met)), weight);
	plot1d["Mt_W"]->Fill(per.MtWLep(), weight);
	plot1d["Mt_t"]->Fill(per.MttLep(), weight);
	plot2d["METunc"]->Fill(an->met.pxunc()/an->met.Px(), an->met.pyunc()/an->met.Py(), weight);
	plot2d["masst_thadpt"]->Fill(per.THad().M(), per.THad().Pt(),weight);
	plot2d["massW_thadpt"]->Fill(per.WHad().M(), per.THad().Pt(),weight);
	plot2d["masst_thady"]->Fill(per.THad().M(), abs(per.THad().Rapidity()),weight);
	plot2d["massW_thady"]->Fill(per.WHad().M(), abs(per.THad().Rapidity()),weight);
	plot2d["masst_tleppt"]->Fill(per.THad().M(), per.TLep().Pt(),weight);
	plot2d["massW_tleppt"]->Fill(per.WHad().M(), per.TLep().Pt(),weight);
	plot2d["masst_tlepy"]->Fill(per.THad().M(), abs(per.TLep().Rapidity()),weight);
	plot2d["massW_tlepy"]->Fill(per.WHad().M(), abs(per.TLep().Rapidity()),weight);
	plot2d["masst_ttm"]->Fill(per.THad().M(), per.TT().M(),weight);
	plot2d["massW_ttm"]->Fill(per.WHad().M(), per.TT().M(),weight);
	plot2d["masst_ttpt"]->Fill(per.THad().M(), per.TT().Pt(),weight);
	plot2d["massW_ttpt"]->Fill(per.WHad().M(), per.TT().Pt(),weight);
	plot2d["masst_tty"]->Fill(per.THad().M(), abs(per.TT().Rapidity()),weight);
	plot2d["massW_tty"]->Fill(per.WHad().M(), abs(per.TT().Rapidity()),weight);
	plot2d["masst_njet"]->Fill(per.THad().M(), addjets.size(), weight);
	plot2d["massW_njet"]->Fill(per.WHad().M(), addjets.size(), weight);
	for(int jn : jetbins)
	{
		stringstream jb;
		if(jn != -1) jb << jn << "_";
		if((jn == -1) || (an->reducedjets.size() - 4 == size_t(jn)) || (jn == jetbins.back() && an->reducedjets.size() - 4 > size_t(jn)))
		{
			plot2d["test_"+jb.str()+"testb"]->Fill(test, testb, weight);
			plot2d["test_"+jb.str()+"nobin"]->Fill(test, per.THad().Pt(), weight);
			plot2d["testb_"+jb.str()+"nobin"]->Fill(testb, per.THad().Pt(), weight);
			double thadpt = Min(per.THad().Pt(), plot2d["test_"+jb.str()+"thadpt"]->GetYaxis()->GetXmax()-.0001);
			plot2d["test_"+jb.str()+"thadpt"]->Fill(test, thadpt, weight);
			plot2d["testb_"+jb.str()+"thadpt"]->Fill(testb, thadpt, weight);
			double tleppt = Min(per.TLep().Pt(), plot2d["test_"+jb.str()+"tleppt"]->GetYaxis()->GetXmax()-.0001);
			plot2d["test_"+jb.str()+"tleppt"]->Fill(test, tleppt, weight);
			plot2d["testb_"+jb.str()+"tleppt"]->Fill(testb, tleppt, weight);
			plot2d["test_"+jb.str()+"tpt"]->Fill(test, tleppt, weight);
			plot2d["testb_"+jb.str()+"tpt"]->Fill(testb, tleppt, weight);
			plot2d["test_"+jb.str()+"tpt"]->Fill(test, thadpt, weight);
			plot2d["testb_"+jb.str()+"tpt"]->Fill(testb, thadpt, weight);
			double thady = Min(Abs(per.THad().Rapidity()), plot2d["test_"+jb.str()+"thady"]->GetYaxis()->GetXmax()-.0001);
			plot2d["test_"+jb.str()+"thady"]->Fill(test, thady, weight);
			plot2d["testb_"+jb.str()+"thady"]->Fill(testb, thady, weight);
			double tlepy = Min(Abs(per.TLep().Rapidity()), plot2d["test_"+jb.str()+"tlepy"]->GetYaxis()->GetXmax()-.0001);
			plot2d["test_"+jb.str()+"tlepy"]->Fill(test, tlepy, weight);
			plot2d["testb_"+jb.str()+"tlepy"]->Fill(testb, tlepy, weight);
			plot2d["test_"+jb.str()+"ty"]->Fill(test, tlepy, weight);
			plot2d["testb_"+jb.str()+"ty"]->Fill(testb, tlepy, weight);
			plot2d["test_"+jb.str()+"ty"]->Fill(test, thady, weight);
			plot2d["testb_"+jb.str()+"ty"]->Fill(testb, thady, weight);
			double ttm = Min(per.TT().M(), plot2d["test_"+jb.str()+"ttm"]->GetYaxis()->GetXmax()-.0001);
			plot2d["test_"+jb.str()+"ttm"]->Fill(test, ttm, weight);
			plot2d["testb_"+jb.str()+"ttm"]->Fill(testb, ttm, weight);
			double tty = Min(Abs(per.TT().Rapidity()), plot2d["test_"+jb.str()+"tty"]->GetYaxis()->GetXmax()-.0001);
			plot2d["test_"+jb.str()+"tty"]->Fill(test, tty, weight);
			plot2d["testb_"+jb.str()+"tty"]->Fill(testb, tty, weight);
			double ttpt = Min(per.TT().Pt(), plot2d["test_"+jb.str()+"ttpt"]->GetYaxis()->GetXmax()-.0001);
			plot2d["test_"+jb.str()+"ttpt"]->Fill(test, ttpt, weight);
			plot2d["testb_"+jb.str()+"ttpt"]->Fill(testb, ttpt, weight);
			plot2d["test_"+jb.str()+"costhetastar"]->Fill(test, per.T_CMS().CosTheta(), weight);
			plot2d["testb_"+jb.str()+"costhetastar"]->Fill(testb, per.T_CMS().CosTheta(), weight);
			plot2d["test_"+jb.str()+"njet"]->Fill(test, an->cleanedjets.size()-4, weight);
			plot2d["testb_"+jb.str()+"njet"]->Fill(testb, an->cleanedjets.size()-4, weight);
			plot2d["test_"+jb.str()+"met"]->Fill(test, an->met.Pt(), weight);
			plot2d["testb_"+jb.str()+"met"]->Fill(testb, an->met.Pt(), weight);
		}
	}
}


