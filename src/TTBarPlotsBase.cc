#include <TTBarPlotsBase.h>
#include <ttbarxsec.h>
#include <Permutation.h>


using namespace std;
using namespace TMath;

TTBarPlotsBase::TTBarPlotsBase(string prefix) : prefix_(prefix), plot1d(prefix), plot2d(prefix)
{

}

TTBarPlotsBase::~TTBarPlotsBase()
{

}

void TTBarPlotsBase::Init(ttbar* analysis)
{
	an = analysis;
    plot2d.AddHist("bjets_pt", 500, 0., 500., 500, 0., 500., "p_{T}(b)_{min} [GeV]", "p_{T}(b)_{max} [GeV]");
    plot2d.AddHist("bjets_pthad_ptlep", 500, 0., 500., 500, 0., 500., "p_{T}(b_{had}) [GeV]", "p_{T}(b_{lep}) [GeV]");
    plot2d.AddHist("wjets_pt", 500, 0., 500., 500, 0., 500., "p_{T}(j_{W})_{min} [GeV]", "p_{T}(j_{W})_{max} [GeV]");
    plot2d.AddHist("wjets_bjets_pt", 500, 0., 500., 500, 0., 500., "p_{T}(j_{W})_{max} [GeV]", "p_{T}(b_{had}) [GeV]");
    plot2d.AddHist("Whad_M_thad_M", 500, 0., 500., 500, 0., 500., "M(W_{h}) [GeV]", "M(t_{h}) [GeV]");
    plot2d.AddHist("Wlep_M_tlep_M", 500, 0., 500., 500, 0., 500., "M(W_{l}) [GeV]", "M(t_{l}) [GeV]");
    plot2d.AddHist("thad_M_tlep_M", 500, 0., 500., 500, 0., 500., "M(t_{h}) [GeV]", "M(t_{l}) [GeV]");
    plot2d.AddHist("thad_pt_wjwj_dr", 100, 0., 2000., 100, 0., 5., "p_{T}(t_{h}) [GeV]", "#Delta R(j_{W}, j_{W})");
    plot2d.AddHist("thad_pt_wjbj_dr", 100, 0., 2000., 100, 0., 5., "p_{T}(t_{h}) [GeV]", "#Delta R_{min}(j_{W}, b)");
    plot1d.AddHist("lep_pt", 500, 0., 500., "p_{T}(l) [GeV]", "Events");
    plot1d.AddHist("lep_eta", 480, -2.4, 2.4, "#eta(l)", "Events");
    plot1d.AddHist("mu_pt", 500, 0., 500., "p_{T}(#mu) [GeV]", "Events");
    plot1d.AddHist("mu_eta", 480, -2.4, 2.4, "#eta(#mu)", "Events");
    plot1d.AddHist("mu_phi", 100, -Pi(), Pi(), "#phi(#mu)", "Events");
    plot1d.AddHist("el_pt", 500, 0., 500., "p_{T}(e) [GeV]", "Events");
    plot1d.AddHist("el_eta", 480, -2.4, 2.4, "#eta(e)", "Events");
    plot1d.AddHist("el_phi", 100, -Pi(), Pi(), "#phi(e)", "Events");
    plot1d.AddHist("nu_pt", 500, 0., 500., "p_{T}(#nu) [GeV]", "Events");
    plot1d.AddHist("nu_eta", 200, -5, 5., "#eta(#nu)", "Events");
    plot1d.AddHist("nu_phi", 100, -Pi(), Pi(), "#phi(#nu)", "Events");
    plot1d.AddHist("lepp_eta", 200, -5, 5., "#eta(l+)", "Events");
    plot1d.AddHist("lepm_eta", 200, -5, 5., "#eta(l-)", "Events");
    plot1d.AddHist("thad_pt", 500, 0, 1000, "p_{T}(t_{h}) [GeV]", "Events");
    plot1d.AddHist("tlep_pt", 500, 0, 1000, "p_{T}(t_{l}) [GeV]", "Events");
    plot1d.AddHist("thad_eta", 200, -5, 5, "#eta(t_{h})", "Events");
    plot1d.AddHist("tlep_eta", 200, -5, 5, "#eta(t_{l})", "Events");
    plot1d.AddHist("thad_y", 200, 0, 5, "|y(t_{h})|", "Events");
    plot1d.AddHist("tlep_y", 200, 0, 5, "|y(t_{l})|", "Events");
    plot1d.AddHist("tt_M", 1500, 0, 3000, "M(t#bar{t}) [GeV]", "Events");
    plot1d.AddHist("tt_pt", 500, 0, 1000, "p_{T}(t#bar{t}) [GeV]", "Events");
    plot1d.AddHist("tt_y", 200, 0, 10., "|y(t#bar{t})|", "Events");
    plot1d.AddHist("thard_pt", 500, 0, 1000, "p_{T}(t_{hard}) [GeV]", "Events");
    plot1d.AddHist("tsoft_pt", 500, 0, 1000, "p_{T}(t_{soft}) [GeV]", "Events");
    plot1d.AddHist("tt_DeltaPhi", 200, -Pi(), Pi(), "#Delta#Phi(t#bar{t})", "Events");
    plot1d.AddHist("whad_pt", 100, 0, 200, "p_{T}(W_{h}) [GeV]", "Events");
    plot1d.AddHist("wj_dphi", 100, -Pi(), Pi(), "#Delta#phi(j_{whad})", "Events");
    plot1d.AddHist("wj_dr", 100, 0., 5., "#Delta#R(j_{whad})", "Events");
    plot1d.AddHist("bjet_pt", 100, 0., 500., "p_{T}(b) [GeV]", "Events");
    plot1d.AddHist("bjet_eta", 100, -2.5, 2.5, "#eta(b)", "Events");
    plot1d.AddHist("bjet_phi", 100, -Pi(), Pi(), "#phi(b)", "Events");
    plot1d.AddHist("wjet_pt", 100, 0., 500., "p_{T}(wj) [GeV]", "Events");
    plot1d.AddHist("wjet_eta", 100, -2.5, 2.5, "#eta(wj)", "Events");
    plot1d.AddHist("wjet_phi", 100, -Pi(), Pi(), "#phi(wj)", "Events");
	plot1d.AddHist("costhetastar", 20, -1., 1., "cos(#theta*)", "Events");
	plot1d.AddHist("dbeta", 200, 0, 2., "#Delta#beta", "Events");
	plot1d.AddHist("dymp", 200, -4., 4., "y(t)-y(#bar{t})", "Events");
	plot1d.AddHist("dy", 200, -2., 2., "|y(t)|-|y(#bar{t})|", "Events");
    plot2d.AddHist("ttm_dy_all", 100, 0., 4000., 100, -2., 2., "ttm", "dy");
    plot2d.AddHist("ttm_dy_0jet", 100, 0., 4000., 100, -2., 2., "ttm", "dy");
    plot2d.AddHist("ttm_cts_all", 100, 0., 4000., 100, -1., 1., "ttm", "cts");
    plot2d.AddHist("ttm_cts_0jet", 100, 0., 4000., 100, -1., 1., "ttm", "cts");
	plot2d.AddHist("jets_deta_dphi", 50, 0, 5, 50, 0, Pi(), "#Delta#eta", "#Delta#phi");
	plot2d.AddHist("jets_detamax_dphi", 50, 0, 5, 50, 0, Pi(), "#Delta#eta", "#Delta#phi");
	plot2d.AddHist("jets2_deta_dphi", 50, 0, 5, 50, 0, Pi(), "#Delta#eta", "#Delta#phi");
	bool ctssignal;
	//size_t ctssize = an->ctsweights.weights(ctssignal).size();
	size_t ctssize = 40;
	plot1d.AddHist("cts_sig", ctssize, -1, 1, "cts", "Events");
	plot2d.AddHist("cts_ttm_sig", ctssize, -1, 1, 100, 0, 4000,  "cts", "ttm");
	plot2d.AddHist("cts_tty_sig", ctssize, -1, 1, 25, 0, 2.5,  "cts", "tty");
	plot1d.AddHist("cts", ctssize, -1, 1, "cts", "Events");
	plot2d.AddHist("cts_ttm", ctssize, -1, 1, 100, 0, 4000,  "cts", "ttm");
	plot2d.AddHist("cts_tty", ctssize, -1, 1, 25, 0, 2.5,  "cts", "tty");
	for(size_t i = 0 ; i <= ctssize ; ++i)
	{
		plot1d.AddHist("cts_"+to_string(i), ctssize, -1, 1, "cts", "Events");
		plot2d.AddHist("cts_ttm_"+to_string(i), ctssize, -1, 1, 100, 0, 4000,  "cts", "ttm");
		plot2d.AddHist("cts_tty_"+to_string(i), ctssize, -1, 1, 25, 0, 2.5,  "cts", "tty");
	}
}

//void TTBarPlotsBase::Fill(TLorentzVector* Hb, TLorentzVector* Hwa, TLorentzVector* Hwb, TLorentzVector* Lb, TLorentzVector* Ll, TLorentzVector* Ln, int lepcharge, double weight)
void TTBarPlotsBase::Fill(Permutation& per, double weight)
{
	plot2d["thad_pt_wjwj_dr"]->Fill(per.THad().Pt(), per.WJa()->DeltaR(*per.WJb()), weight);
	plot2d["thad_pt_wjbj_dr"]->Fill(per.THad().Pt(), Min(per.BHad()->DeltaR(*per.WJa()), per.BHad()->DeltaR(*per.WJb())), weight);
    plot2d["Whad_M_thad_M"]->Fill(per.WHad().M(), per.THad().M(), weight);
	plot2d["bjets_pt"]->Fill(Min(per.BHad()->Pt(), per.BLep()->Pt()), Max(per.BHad()->Pt(), per.BLep()->Pt()), weight);
	plot2d["bjets_pthad_ptlep"]->Fill(per.BHad()->Pt(), per.BLep()->Pt(), weight);
	plot2d["wjets_pt"]->Fill(Min(per.WJa()->Pt(), per.WJb()->Pt()), Max(per.WJa()->Pt(), per.WJb()->Pt()), weight);
	plot2d["wjets_bjets_pt"]->Fill(Max(per.WJa()->Pt(), per.WJb()->Pt()), per.BHad()->Pt(), weight);
	plot2d["Wlep_M_tlep_M"]->Fill(per.WLep().M(), per.TLep().M(), weight);
	plot2d["thad_M_tlep_M"]->Fill(per.THad().M(), per.TLep().M(), weight);
	if(per.LCharge() > 0) {plot1d["lepp_eta"]->Fill(per.L()->Eta(), weight);}
	if(per.LCharge() < 0) {plot1d["lepm_eta"]->Fill(per.L()->Eta(), weight);}
		plot1d["lep_pt"]->Fill(per.L()->Pt(), weight);
		plot1d["lep_eta"]->Fill(per.L()->Eta(), weight);
	if(abs(per.LPDGId()) == 13)
	{
		plot1d["mu_pt"]->Fill(per.L()->Pt(), weight);
		plot1d["mu_eta"]->Fill(per.L()->Eta(), weight);
		plot1d["mu_phi"]->Fill(per.L()->Phi(), weight);
	}
	if(abs(per.LPDGId()) == 11)
	{
		plot1d["el_pt"]->Fill(per.L()->Pt(), weight);
		plot1d["el_eta"]->Fill(per.L()->Eta(), weight);
		plot1d["el_phi"]->Fill(per.L()->Phi(), weight);
	}
	plot1d["nu_pt"]->Fill(per.Nu().Pt(), weight);
	plot1d["nu_eta"]->Fill(per.Nu().Eta(), weight);
	plot1d["nu_phi"]->Fill(per.Nu().Phi(), weight);
	plot1d["thad_pt"]->Fill(per.THad().Pt(), weight);
	plot1d["tlep_pt"]->Fill(per.TLep().Pt(), weight);
	plot1d["thad_eta"]->Fill(per.THad().Eta(), weight);
	plot1d["tlep_eta"]->Fill(per.TLep().Eta(), weight);
	plot1d["thad_y"]->Fill(Abs(per.THad().Rapidity()), weight);
	plot1d["tlep_y"]->Fill(Abs(per.TLep().Rapidity()), weight);
	plot1d["thard_pt"]->Fill(per.THard().Pt(), weight);
	plot1d["tsoft_pt"]->Fill(per.TSoft().Pt(), weight);
	plot1d["tt_DeltaPhi"]->Fill(per.TLep().DeltaPhi(per.THad()), weight);
	plot1d["tt_M"]->Fill(per.TT().M(), weight);
	plot1d["tt_pt"]->Fill(per.TT().Pt(), weight);
	plot1d["tt_y"]->Fill(Abs(per.TT().Rapidity()), weight);
	plot1d["whad_pt"]->Fill(per.WHad().Pt(), weight);
	plot1d["wj_dphi"]->Fill(per.WJa()->DeltaPhi(*per.WJb()), weight);
	plot1d["wj_dr"]->Fill(per.WJa()->DeltaR(*per.WJb()), weight);
	plot1d["costhetastar"]->Fill(per.CTS(), weight);
	plot1d["bjet_pt"]->Fill(per.BHad()->Pt(), weight);
	plot1d["bjet_pt"]->Fill(per.BLep()->Pt(), weight);
	plot1d["bjet_eta"]->Fill(per.BHad()->Eta(), weight);
	plot1d["bjet_eta"]->Fill(per.BLep()->Eta(), weight);
	plot1d["bjet_phi"]->Fill(per.BHad()->Phi(), weight);
	plot1d["bjet_phi"]->Fill(per.BLep()->Phi(), weight);
	plot1d["wjet_pt"]->Fill(per.WJa()->Pt(), weight);
	plot1d["wjet_pt"]->Fill(per.WJb()->Pt(), weight);
	plot1d["wjet_eta"]->Fill(per.WJa()->Eta(), weight);
	plot1d["wjet_eta"]->Fill(per.WJb()->Eta(), weight);
	plot1d["wjet_phi"]->Fill(per.WJa()->Phi(), weight);
	plot1d["wjet_phi"]->Fill(per.WJb()->Phi(), weight);
	plot1d["dbeta"]->Fill((per.THad().BoostVector() - per.TLep().BoostVector()).Mag(), weight);
	plot1d["dymp"]->Fill(per.T().Rapidity()-per.Tb().Rapidity(), weight);
	plot1d["dy"]->Fill(Abs(per.T().Rapidity())-Abs(per.Tb().Rapidity()), weight);
	plot2d["ttm_dy_all"]->Fill(per.TT().M(), Abs(per.T().Rapidity())-Abs(per.Tb().Rapidity()), weight);
	plot2d["ttm_cts_all"]->Fill(per.TT().M(), per.CTS(), weight);
	if(per.NAddJets() == 0)
	{
		plot2d["ttm_dy_0jet"]->Fill(per.TT().M(), Abs(per.T().Rapidity())-Abs(per.Tb().Rapidity()), weight);
		plot2d["ttm_cts_0jet"]->Fill(per.TT().M(), per.CTS(), weight);
	}
	bool ctssignal;
	const vector<double>& ctsweights = an->ctsweights.weights(ctssignal);
	if(ctssignal)
	{
		plot1d["cts_sig"]->Fill(per.CTS(), weight);
		plot2d["cts_ttm_sig"]->Fill(per.CTS(), per.TT().M(), weight);
		plot2d["cts_tty_sig"]->Fill(per.CTS(), abs(per.TT().Rapidity()), weight);
		for(size_t i = 0 ; i < ctsweights.size() ; ++i)
		{
			plot1d["cts_"+to_string(i)]->Fill(per.CTS(), weight*ctsweights[i]);
			plot2d["cts_ttm_"+to_string(i)]->Fill(per.CTS(), per.TT().M(), weight*ctsweights[i]);
			plot2d["cts_tty_"+to_string(i)]->Fill(per.CTS(), abs(per.TT().Rapidity()), weight*ctsweights[i]);
		}
	}
	plot1d["cts"]->Fill(per.CTS(), weight);
	plot2d["cts_ttm"]->Fill(per.CTS(), per.TT().M(), weight);
	plot2d["cts_tty"]->Fill(per.CTS(), abs(per.TT().Rapidity()), weight);

	double deltaetamax = -1;
	double deltaphimax = -1;
	for(size_t i = 4 ; i < per.NJets() ; ++i)
	{
		const TLorentzVector* jeti = per.GetJet(i);
		for(size_t j = i+1 ; j < per.NJets() ; ++j)
		{
			const TLorentzVector* jetj = per.GetJet(j);
			double deltaeta = abs(jeti->Eta() - jetj->Eta());
			double deltaphi = abs(jeti->DeltaPhi(*jetj));
			plot2d["jets_deta_dphi"]->Fill(deltaeta, deltaphi, weight);		
			if(per.NAddJets() == 2){plot2d["jets2_deta_dphi"]->Fill(deltaeta, deltaphi, weight);}
			if(deltaeta > deltaetamax) {deltaetamax = deltaeta; deltaphimax = deltaphi;}

		}
	}
	plot2d["jets_detamax_dphi"]->Fill(deltaetamax, deltaphimax, weight);		


}

