#ifndef PERMUTATION_H
#define PERMUTATION_H
#include <vector>
#include <limits>
#include <iostream>
#include <algorithm>
#include <TLorentzVector.h>
#include <URStreamer.h>
#include <IDJet.h>
#include <IDMet.h>

using namespace std;

class TTBarSolver;

class Permutation
{
	private:
		double prob_ = numeric_limits<double>::max();
		double nu_chisq_          = numeric_limits<double>::max();
		double nu_discriminant_   = numeric_limits<double>::max();
		double btag_discriminant_ = numeric_limits<double>::max();
		double mass_discriminant_ = numeric_limits<double>::max();
		double mt_discriminant_ = numeric_limits<double>::max();
		TLorentzVector* owja_ = 0;
		TLorentzVector* owjb_ = 0;
		TLorentzVector* objh_ = 0;
		TLorentzVector* objl_ = 0;
		TLorentzVector* olep_ = 0;
		TLorentzVector* wja_ = 0;
		TLorentzVector* wjb_ = 0;
		TLorentzVector* bjh_ = 0;
		TLorentzVector* bjl_ = 0;
		TLorentzVector* lep_ = 0;
		int lpdgid_ = 0;
		TLorentzVector* met_ = 0;
		bool calculated = false;
		TLorentzVector nu_;
		TLorentzVector whad_;
		TLorentzVector wlep_;
		TLorentzVector thad_;
		TLorentzVector tlep_;
		TLorentzVector tt_;
		TLorentzVector t_cms_;
		bool kinfit_ = false;
		vector<TLorentzVector> improvedobjects;
		vector<TLorentzVector*> addjets;
		
	public:
		void SetImproved(bool improved)
		{
			if(improved && improvedobjects.size() == 6)
			{
				wja_ = &improvedobjects[0]; 
				wjb_ = &improvedobjects[1]; 
				bjh_ = &improvedobjects[2]; 
				bjl_ = &improvedobjects[3]; 
				lep_ = &improvedobjects[4]; 
				nu_ = improvedobjects[5]; 
			}
			else
			{
				wja_ = owja_; 
				wjb_ = owjb_;
				bjh_ = objh_;
				bjl_ = objl_;
				lep_ = olep_;
			}
			calculated = false;
		}
		Permutation() : nu_(0.,0.,0.,-1.){}
		void Init(TLorentzVector* wja, TLorentzVector* wjb, TLorentzVector* bjh, TLorentzVector* bjl, TLorentzVector* lep, int leppdgid, const TLorentzVector& nu);
		void Init(TLorentzVector* wja, TLorentzVector* wjb, TLorentzVector* bjh, TLorentzVector* bjl, TLorentzVector* lep, int leppdgid, IDMet* met);
		void Reset();
		bool IsComplete() const {return(wja_ != 0 && wjb_ != 0 && bjh_ != 0 && bjl_ != 0 && lep_ != 0 && (met_ != 0 || nu_.E() > -0.5)&& wja_ != wjb_ && wja_ != bjh_ && wja_ != bjl_ && wjb_ != bjl_ && wjb_ != bjh_ && bjl_ != bjh_);}
		int NumBJets() const {return((bjl_ != 0 ? 1 : 0) + (bjh_ != 0 ? 1 : 0));}
		int NumWJets() const {return((wja_ != 0 ? 1 : 0) + (wjb_ != 0 ? 1 : 0));}
		int NumTTBarJets() const {return(NumBJets() + NumWJets());}
		double Solve(TTBarSolver& ttsolver, bool kinfit = false);
		TLorentzVector* WJa() const {return(wja_);}
		TLorentzVector* WJb() const {return(wjb_);}
		TLorentzVector* WJPtmin() const
		{
			if(wja_ == nullptr || wjb_ == nullptr){return nullptr;}
			return(wja_->Pt() < wjb_->Pt() ? wja_ : wjb_);
		}
		TLorentzVector* WJPtmax() const 
		{

			if(wja_ == nullptr && wjb_ != nullptr){return wjb_;}
			if(wja_ != nullptr && wjb_ == nullptr){return wja_;}
			if(wja_ == nullptr && wjb_ == nullptr){return nullptr;}
			return(wja_->Pt() >= wjb_->Pt() ? wja_ : wjb_);
		}
		TLorentzVector* BHad() const {return(bjh_);}
		TLorentzVector* BLep() const {return(bjl_);}
		TLorentzVector* L() const {return(lep_);}
		TLorentzVector* MET() const {return(met_);}
		void WJa(TLorentzVector* wja){calculated = false; wja_=wja; owja_=wja;}
		void WJb(TLorentzVector* wjb){calculated = false; wjb_=wjb; owjb_=wjb;}
		void BHad(TLorentzVector* bjh){calculated = false; bjh_=bjh; objh_=bjh;}
		void BLep(TLorentzVector* bjl){calculated = false; bjl_=bjl; objl_=bjl;}
		void L(TLorentzVector* lep, int leppdgid){calculated = false; lep_=lep; olep_=lep; lpdgid_=leppdgid;}
		void Nu(TLorentzVector* nu){calculated = false; nu_=*nu;}
		int LCharge() {return (lpdgid_ < 0 ? 1 : -1);}
		int LPDGId() {return lpdgid_;}
		void MET(TLorentzVector* met){met_=met;}

		void Calculate()
		{
			if(!calculated)
			{
				calculated = true;
				whad_ = *WJa() + *WJb();
				wlep_ = *L() + Nu();
				thad_ = whad_ + *BHad();
				tlep_ = wlep_ + *BLep();
				tt_ = thad_ + tlep_;
				t_cms_ = T();
				t_cms_.Boost(-1.*TT().BoostVector());
			}
		}

		TLorentzVector& Nu() {return(nu_);}
		TLorentzVector& WHad() {Calculate(); return whad_;}
		TLorentzVector& WLep() {Calculate(); return wlep_;}
		TLorentzVector& THad() {Calculate(); return thad_;}
		TLorentzVector& TLep() {Calculate(); return tlep_;}
		TLorentzVector& TT() {Calculate(); return(tt_);}
		TLorentzVector& T() {return (LCharge() < 0 ? THad() : TLep());}
		TLorentzVector& Tb() {return (LCharge() > 0 ? THad() : TLep());}
		TLorentzVector& THard() {return (THad().Pt() > TLep().Pt() ? THad() : TLep());}
		TLorentzVector& TSoft() {return (THad().Pt() < TLep().Pt() ? THad() : TLep());}
		TLorentzVector& T_CMS() {Calculate(); return t_cms_;}

		double MtWLep();
		double MttLep();

		double Prob() const {return(prob_);}
		double NuChisq() 	 const {return nu_chisq_         ;}
		double NuDiscr() 	 const {return nu_discriminant_  ;}
		double BDiscr()  	 const {return btag_discriminant_;}
		double MassDiscr() const {return mass_discriminant_;}
		double MTDiscr() const {return mt_discriminant_;}

		bool IsValid() const
		{
			if(owja_ != 0 && owja_ == owjb_) {return(false);}
			if(objh_ != 0 && (objh_ == owja_ || objh_ == owjb_)) {return(false);}
			if(objl_ != 0 && (objl_ == objh_ || objl_ == owja_ || objl_ == owjb_)) {return(false);}
			return(true);
		}

		bool AreBsCorrect(const Permutation& other) const //bjets are selected correct, but not necessarily at the right position!!!!!!!!!!
		{
			return((objl_ == other.objl_ && objh_ == other.objh_) || (objh_ == other.objl_ && objl_ == other.objh_));
		}
		bool AreJetsCorrect(const Permutation& other) const
		{
			if(NJets() != other.NJets()){return false;}
			for(size_t j = 0 ; j < NJets() ; ++j)
			{
				if(GetJet(j)->DeltaR(*other.GetJet(j)) > 0.2) {return false;}
			}
			//if(objl_ == other.objl_ && objh_ == other.objh_ && WJPtmin() == other.WJPtmin() && WJPtmax() == other.WJPtmax()){return(true);}
			//if(objl_ != other.objl_ && objl_ != other.objh_ && objl_ != other.owja_ && objl_ != other.owjb_){return(false);}
			//if(objh_ != other.objl_ && objh_ != other.objh_ && objh_ != other.owja_ && objh_ != other.owjb_){return(false);}
			//if(owja_ != other.objl_ && owja_ != other.objh_ && owja_ != other.owja_ && owja_ != other.owjb_){return(false);}
			//if(owjb_ != other.objl_ && owjb_ != other.objh_ && owjb_ != other.owja_ && owjb_ != other.owjb_){return(false);}
			return(true);
		}

		bool AreHadJetsCorrect(const Permutation& other) const
		{
			if(objh_ != other.objh_ && objh_ != other.owja_ && objh_ != other.owjb_){return(false);}
			if(owja_ != other.objh_ && owja_ != other.owja_ && owja_ != other.owjb_){return(false);}
			if(owjb_ != other.objh_ && owjb_ != other.owja_ && owjb_ != other.owjb_){return(false);}
			return(true);
		}

		bool IsBLepCorrect(const Permutation& other) const
		{
			//return(BLep() == other.BLep());
			return(objl_ == other.objl_);
		}
		bool IsBHadCorrect(const Permutation& other) const
		{
			//return(BHad() == other.BHad());
			return(objh_ == other.objh_);
		}
		bool IsWHadCorrect(const Permutation& other) const
		{
			//return((WJa() == other.WJa() && WJb() == other.WJb()) || (WJa() == other.WJb() && WJb() == other.WJa()));
			return((owja_ == other.owja_ && owjb_ == other.owjb_) || (owja_ == other.owjb_ && owjb_ == other.owja_));
		}
		bool IsTHadCorrect(const Permutation& other) const
		{
			return(IsBHadCorrect(other) && IsWHadCorrect(other));
		}
		bool IsCorrect(const Permutation& other) const
		{
			return(IsBLepCorrect(other) && IsTHadCorrect(other));
		}
		int IsJetIn(const TLorentzVector* jet) const
		{
			if(jet->DeltaR(*BLep()) < 0.2) return 0;
			if(jet->DeltaR(*BHad()) < 0.2) return 1;
			if(jet->DeltaR(*WJPtmax()) < 0.2) return 2;
			if(jet->DeltaR(*WJPtmin()) < 0.2) return 3;
			for(size_t i = 0 ; i < addjets.size() ; ++i)
			{
				if(jet->DeltaR(*addjets[i]) < 0.2) return i+4;
			}
			
			return -1;
		}
		TLorentzVector* GetJet(size_t n) const
		{
			if(n == 0) return BLep();
			if(n == 1) return BHad();
			if(n == 2) return WJPtmax();
			if(n == 3) return WJPtmin();
			if(n > 3 && n-4 < addjets.size()) return addjets[n-4];

			return nullptr;
		}

	//	void ApplyJetCorrections()
	//	{
	//		TVector2 dmet;
	//		for(size_t j = 0 ; j < NJets() ; ++j)
	//		{
	//			int sftype = 1;
	//			if(j == 2 || j == 3) sftype = 2;
	//			dynamic_cast< IDJet* >(GetJet(j))->ApplySF(sftype, dmet);
	//		}
	//		dynamic_cast< IDMet* >(met_)->Update(dmet);
	//	}

		const TLorentzVector* GetJet(TLorentzVector* jet) const
		{
			int nj = IsJetIn(jet);
			return(GetJet(nj));
		}

		size_t NAddJets() const {return addjets.size();}
		size_t NJets() const {return 4+NAddJets();}
		
		template<typename T, class UnaryPredicate > void SetAdditionalJets(const vector<T*>& jets, UnaryPredicate selection = [](T* obj)->bool{return true;})
		{
			addjets.clear();
			for(T* jet : jets)
			{
				if(IsJetIn(jet) == -1 && selection(jet)){addjets.push_back(jet);}
			}
			sort(addjets.begin(), addjets.end(), [](const TLorentzVector* A, const TLorentzVector* B){return A->Pt() > B->Pt();});
		}

		const vector<TLorentzVector*>& AddJets() const {return addjets;}

		double Ht() const
		{
			double ht = WJa()->Pt() + WJb()->Pt() + BHad()->Pt() + BLep()->Pt();
			for(const TLorentzVector* j: AddJets()) {ht += j->Pt();}
			return ht;
		}
		double EvtMass()
		{
			TLorentzVector all = TT();
			for(const TLorentzVector* j: AddJets()) {all += *j;}
			return all.M();
		}
		double DRminTTjets(const TLorentzVector* jet)
		{
			double drmin = 10000.;
			double dr = jet->DeltaR(*BHad());
			if(dr < drmin && dr > 1.E-8) drmin = dr;
			dr = jet->DeltaR(*BLep());
			if(dr < drmin && dr > 1.E-8) drmin = dr;
			dr = jet->DeltaR(*WJPtmax());
			if(dr < drmin && dr > 1.E-8) drmin = dr;
			dr = jet->DeltaR(*WJPtmin());
			if(dr < drmin && dr > 1.E-8) drmin = dr;
			//for(size_t i = 0 ; i < addjets.size() ; ++i)
			//{
			//	if(jet->DeltaR(*addjets[i]) < drmin) drmin = jet->DeltaR(*addjets[i]);
			//}
			return drmin;
		}
		double DRminTop(const TLorentzVector* jet)
		{
			double drhad = jet->DeltaR(THad());
			double drlep = jet->DeltaR(TLep());
			return drlep < drhad ? drlep : drhad;
		}
};

bool operator<(const Permutation& A, const Permutation& B);
bool operator>(const Permutation& A, const Permutation& B);

#endif
